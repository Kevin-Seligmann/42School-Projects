#include "persistent_worker.hpp"


PersistentWorker::PersistentWorker():th{&PersistentWorker::worker_routine, this}, _continue(true){}

PersistentWorker::~PersistentWorker()
{
	std::unique_lock<std::mutex> lock(_queue_mutex);
	_jobs.clear();
	_continue = false;
	lock.unlock();

	cv.notify_one();
	if (th.joinable())
		th.join();
}

void PersistentWorker::addTask(const std::string& name, const std::function<void()>& jobToExecute)
{
	std::lock_guard<std::mutex> lock(_queue_mutex);

	_jobs.emplace_back(name, jobToExecute); cv.notify_one();
}

void PersistentWorker::removeTask(const std::string& name)
{
	std::lock_guard<std::mutex> lock(_queue_mutex);

	auto job = std::find_if(_jobs.begin(), _jobs.end(), [&name](job_type & job){return name == job.first;});
	if (job != _jobs.end())
		_jobs.erase(job);
}

void PersistentWorker::worker_routine()
{
	std::unique_lock<std::mutex> lock(_queue_mutex, std::defer_lock);

	while (1)
	{
		lock.lock();
		cv.wait(lock, [this]() {return _jobs.size() > 0  || !_continue;});
		if (!_continue && _jobs.size() == 0)
		{
			lock.unlock();
			return ;
		}
		auto job = *(_jobs.begin());
		_jobs.pop_front();
		_jobs.emplace_back(job);
		lock.unlock();
		job.second();
	}
}
