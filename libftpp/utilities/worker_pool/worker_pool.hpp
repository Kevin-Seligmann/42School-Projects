#pragma once

#include <functional>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include "libftpp.hpp"

class IJob
{
	public:
	virtual ~IJob() = default;
	virtual void execute() = 0;
};

class Job : public IJob
{
	public:
	Job(const std::function<void()>& task);
	void execute();

	Job(const Job &) = default;
	Job(Job &&) = default;
	Job operator=(const Job & rhs);
	Job operator=(Job && rhs);

	private:
	std::function<void()> _task;
};

class WorkerPool
{
	public:
	WorkerPool(int workers_qty);
	~WorkerPool();
	WorkerPool(const WorkerPool &) = delete;
	WorkerPool(WorkerPool &&) = delete;
	WorkerPool operator=(const WorkerPool &) = delete;
	WorkerPool operator=(WorkerPool &&) = delete;

	void addJob(const std::function<void()>& jobToExecute);

	private:
	std::vector<std::thread> _workers;
	ThreadSafeQueue<IJob *> _jobs;
	std::condition_variable cv; 
	std::mutex _pool_mutex;
	bool _continue;

	void worker_routine();
};
