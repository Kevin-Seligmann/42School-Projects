#pragma once

#include <mutex>
#include <deque>
#include <stdexcept>

template<typename TType>
class ThreadSafeQueue
{
	public:
	ThreadSafeQueue();
	~ThreadSafeQueue();
	ThreadSafeQueue(const ThreadSafeQueue & src);
	ThreadSafeQueue(ThreadSafeQueue && src);
	ThreadSafeQueue & operator=(const ThreadSafeQueue & rhs);
	ThreadSafeQueue & operator=(ThreadSafeQueue && rhs);

	void push_back(const TType& newElement);
	void push_front(const TType& newElement);
	TType pop_back();
	TType pop_front();

	size_t size();

	private:
	std::mutex thread_safe_queue_mutex;
	std::deque<TType> _deque;
};

template<typename TType>
ThreadSafeQueue<TType>::ThreadSafeQueue(){}

template<typename TType>
ThreadSafeQueue<TType>::~ThreadSafeQueue(){}

template<typename TType>
ThreadSafeQueue<TType>::ThreadSafeQueue(const ThreadSafeQueue & src)
{
	std::lock_guard<std::mutex> lock_src(src.thread_safe_queue_mutex);
	std::lock_guard<std::mutex> lock_this(thread_safe_queue_mutex);
	_deque = src._deque;
}

template<typename TType>
ThreadSafeQueue<TType>::ThreadSafeQueue(ThreadSafeQueue && src)
{
	std::lock_guard<std::mutex> lock_src(src.thread_safe_queue_mutex);
	std::lock_guard<std::mutex> lock_this(thread_safe_queue_mutex);
	_deque = std::move(src._deque);
}

template<typename TType>
ThreadSafeQueue<TType> & ThreadSafeQueue<TType>::operator=(const ThreadSafeQueue & rhs)
{
	if (this == &rhs)
		return *this;

	std::lock_guard<std::mutex> lock_rhs(rhs.thread_safe_queue_mutex);
	std::lock_guard<std::mutex> lock_this(thread_safe_queue_mutex);
	_deque = rhs._deque;
	return *this;
}

template<typename TType>
ThreadSafeQueue<TType> & ThreadSafeQueue<TType>::operator=(ThreadSafeQueue && rhs)
{
	if (this == &rhs)
		return *this;

	std::lock_guard<std::mutex> lock_rhs(rhs.thread_safe_queue_mutex);
	std::lock_guard<std::mutex> lock_this(thread_safe_queue_mutex);
	_deque = std::move(rhs._deque);
	return *this;
}

template<typename TType>
void ThreadSafeQueue<TType>::push_back(const TType& newElement)
{
	std::lock_guard<std::mutex> guard(thread_safe_queue_mutex);
	_deque.push_back(newElement);
}

template<typename TType>
void ThreadSafeQueue<TType>::push_front(const TType& newElement)
{
	std::lock_guard<std::mutex> guard(thread_safe_queue_mutex);
	_deque.push_front(newElement);
}

template<typename TType>
TType ThreadSafeQueue<TType>::pop_back()
{
	std::lock_guard<std::mutex> guard(thread_safe_queue_mutex);
	if (_deque.empty())
		throw std::runtime_error("Empty queue");

	TType var = std::move(_deque.back());
	_deque.pop_back();
	return var;
}

template<typename TType>
TType ThreadSafeQueue<TType>::pop_front()
{
	std::lock_guard<std::mutex> guard(thread_safe_queue_mutex);
	if (_deque.empty())
		throw std::runtime_error("Empty queue");

	TType var = std::move(_deque.front());
	_deque.pop_front();
	return var;
}

template<typename TType>
size_t ThreadSafeQueue<TType>::size()
{
	std::lock_guard<std::mutex> guard(thread_safe_queue_mutex);
	return _deque.size();
}
