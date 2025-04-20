#pragma once

#include <functional>
#include <string>
#include <algorithm>
#include <deque>
#include <thread>
#include <mutex>
#include <condition_variable>

class PersistentWorker
{
	using job_type = std::pair<std::string, std::function<void()>>;

	public:
	PersistentWorker();
	~PersistentWorker();
	PersistentWorker(const PersistentWorker &) = delete;
	PersistentWorker(PersistentWorker &&) = delete;
	PersistentWorker operator=(const PersistentWorker &) = delete;
	PersistentWorker operator=(PersistentWorker &&) = delete;
	
	void addTask(const std::string& name, const std::function<void()>& jobToExecute);
	void removeTask(const std::string& name);

	private:
	std::deque<job_type> _jobs;
	std::thread th;
	bool _continue;
	std::condition_variable cv; 
	std::mutex _queue_mutex;
	
	void worker_routine();
};
