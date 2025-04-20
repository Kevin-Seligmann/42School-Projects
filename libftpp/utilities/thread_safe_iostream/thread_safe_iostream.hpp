#pragma once

#include <iostream>
#include <istream>
#include <ostream>
#include <mutex>
#include <stdexcept>

class ThreadSafeIOStream
{
	public:
	ThreadSafeIOStream(std::iostream & stream);
	ThreadSafeIOStream(std::istream & stream);
	ThreadSafeIOStream(std::ostream & stream);
	~ThreadSafeIOStream();
	ThreadSafeIOStream(ThreadSafeIOStream & src);
	ThreadSafeIOStream(ThreadSafeIOStream && src);
	ThreadSafeIOStream & operator=(ThreadSafeIOStream & rhs);
	ThreadSafeIOStream & operator=(ThreadSafeIOStream && rhs);

	template<typename T>
	std::ostream & operator<<(T & src);

	template<typename T>
	std::istream & operator>>(T & src);

	std::ostream & operator<<(std::ostream & (*manip)(std::ostream &));
	std::istream & operator>>(std::istream & (*manip)(std::istream &));



	void setPrefix(const std::string& prefix);

	void setIOstream(std::iostream & stream);
	void setIstream(std::istream & stream);
	void setOstream(std::ostream & stream);

	template<typename T>
	void prompt(const std::string& question, T& dest);

	private:
	static std::mutex thread_safe_io_mutex;

	std::string _prefix;
	std::iostream * _iostream;
	std::istream * _istream;
	std::ostream * _ostream;

};

extern thread_local ThreadSafeIOStream threadSafeCout;

template<typename T>
std::ostream & ThreadSafeIOStream::operator<<(T & src)
{
	std::lock_guard<std::mutex> guard(thread_safe_io_mutex);

	if (_iostream)
	{
		(*_iostream) << _prefix << src;
		return *_iostream;
	}
	else if (_ostream)
	{
		(*_ostream) << _prefix << src;
		return *_ostream;
	}
	else
		throw std::runtime_error("No output stream for insertor");
}

template<typename T>
std::istream & ThreadSafeIOStream::operator>>(T & src)
{
	std::lock_guard<std::mutex> guard(thread_safe_io_mutex);

	if (_iostream)
	{
		(*_iostream) << _prefix << src;
		return *_iostream;
	}
	else if (_istream)
	{
		(*_istream) << src;
		return *_istream;
	}
	else
		throw std::runtime_error("No input stream for extractor");
}

template<typename T>
void ThreadSafeIOStream::prompt(const std::string& question, T& dest)
{
	*this << question;
	*this >> dest;
}
