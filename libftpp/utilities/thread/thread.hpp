#pragma once

#include <functional>
#include <string>
#include <thread>
#include <stdexcept>
#include <mutex>
#include "libftpp.hpp"

class Thread
{
	public:
	Thread(const std::string& name, std::function<void()> functToExecute);
	~Thread();

	Thread(const Thread &) = delete;
	Thread(Thread &&)= delete;
	Thread & operator=(const Thread &) = delete;
	Thread & operator=(Thread &&) = delete;

	void start();
	void stop();

	private:
	std::string _name;
	std::function<void()> _functToExecute;
	bool _started;
	std::thread _thread;
	std::mutex _lock;
};
