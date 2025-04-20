#include "worker_pool.hpp"



WorkerPool::WorkerPool(int worker_qty)
:_continue(true)
{
	for (int i = 0; i < worker_qty; i ++)
		_workers.push_back(std::thread(&WorkerPool::worker_routine, this));
}

WorkerPool::~WorkerPool()
{
	_continue = false;
	cv.notify_all();

	for (auto & th: _workers)
		if (th.joinable())
			th.join();
}

void WorkerPool::addJob(const std::function<void()>& jobToExecute)
{
	_jobs.push_back(new Job(jobToExecute));
	cv.notify_one();
}

void WorkerPool::worker_routine()
{
	std::unique_lock<std::mutex> lock(_pool_mutex, std::defer_lock);

	while (1)
	{
		lock.lock();
		cv.wait(lock, [this]() {return _jobs.size() > 0  || !_continue;});
		if (!_continue && _jobs.size() == 0)
		{
			lock.unlock();
			return ;
		}
		auto job = _jobs.pop_front();
		lock.unlock();
		job->execute();
		delete job;
	}
}

// Job
Job::Job(const std::function<void()>& task):_task(task){};
void Job::execute(){_task();}
Job Job::operator=(const Job & rhs){_task = rhs._task; return *this;};
Job Job::operator=(Job && rhs){_task = std::move(rhs._task); return *this;};
