#include "thread.hpp"

Thread::Thread(const std::string& name, std::function<void()> functToExecute)
:_name(name), _functToExecute(functToExecute), _started(false)
{
	threadSafeCout.setPrefix(_name);
	threadSafeCout << " Constructed" << std::endl;
}

Thread::~Thread()
{
	threadSafeCout.setPrefix(_name);
	threadSafeCout << " Destructed" << std::endl;
	if (_thread.joinable())
	{
		threadSafeCout << " Joined" << std::endl;
		_thread.join();
	}
}

void Thread::start()
{
	std::lock_guard<std::mutex> lock(_lock);
	if (_started)
		throw std::runtime_error("Tried to start a running thread");
	threadSafeCout.setPrefix(_name);
	threadSafeCout << " Starting" << std::endl;
	_thread = std::thread(_functToExecute);
	_started = true;
}

void Thread::stop()
{
	std::lock_guard<std::mutex> lock(_lock);
	if (!_started)
		throw std::runtime_error("Tried to stop an unstarted thread");
	threadSafeCout.setPrefix(_name);
	threadSafeCout << " Joined" << std::endl;
	_thread.join();
}
