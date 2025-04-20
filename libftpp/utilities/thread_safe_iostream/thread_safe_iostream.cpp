#include "thread_safe_iostream.hpp"

thread_local ThreadSafeIOStream threadSafeCout{std::cout};

std::mutex ThreadSafeIOStream::thread_safe_io_mutex;

ThreadSafeIOStream::ThreadSafeIOStream(std::iostream & stream):_iostream{&stream}{}
ThreadSafeIOStream::ThreadSafeIOStream(std::istream & stream):_istream{&stream}{}
ThreadSafeIOStream::ThreadSafeIOStream(std::ostream & stream):_ostream{&stream}{}
ThreadSafeIOStream::~ThreadSafeIOStream(){}

ThreadSafeIOStream::ThreadSafeIOStream(ThreadSafeIOStream & src)
:_prefix(src._prefix), _iostream(src._iostream),_istream(src._istream),_ostream(src._ostream){}

ThreadSafeIOStream::ThreadSafeIOStream(ThreadSafeIOStream && src)
:_prefix(std::move(src._prefix)), _iostream(src._iostream),_istream(src._istream),_ostream(src._ostream)
{
	src._iostream = nullptr;
	src._istream = nullptr;
	src._ostream = nullptr;
}

ThreadSafeIOStream & ThreadSafeIOStream::operator=(ThreadSafeIOStream & rhs)
{
	_prefix = rhs._prefix;
	_iostream = rhs._iostream;
	_istream = rhs._istream;
	_ostream = rhs._ostream;
	return *this;
}

ThreadSafeIOStream & ThreadSafeIOStream::operator=(ThreadSafeIOStream && rhs)
{
	_prefix = std::move(rhs._prefix);
	_iostream = rhs._iostream;
	_istream = rhs._istream;
	_ostream = rhs._ostream;
	rhs._iostream = nullptr;
	rhs._istream = nullptr;
	rhs._ostream = nullptr;
	return *this;
}


void ThreadSafeIOStream::setIOstream(std::iostream & stream){_iostream = &stream;}
void ThreadSafeIOStream::setIstream(std::istream & stream){_istream = &stream;}
void ThreadSafeIOStream::setOstream(std::ostream & stream){_ostream = &stream;}
void ThreadSafeIOStream::setPrefix(const std::string& prefix){_prefix = prefix;}


std::ostream & ThreadSafeIOStream::operator<<(std::ostream& (*manip)(std::ostream&))
{
	std::lock_guard<std::mutex> guard(ThreadSafeIOStream::thread_safe_io_mutex);

	if (_iostream)
	{
		manip(*_iostream);
		return *_iostream;
	}
	else if (_ostream)
	{
		manip(*_ostream);
		return *_ostream;
	}
	else
		throw std::runtime_error("No output stream for insertor");
}

std::istream & ThreadSafeIOStream::operator>>(std::istream& (*manip)(std::istream&))
{
	std::lock_guard<std::mutex> guard(ThreadSafeIOStream::thread_safe_io_mutex);

	if (_iostream)
	{
		manip(*_iostream);
		return *_iostream;
	}
	else if (_istream)
	{
		manip(*_istream);
		return *_istream;
	}
	else
		throw std::runtime_error("No input stream for extractor");
}

