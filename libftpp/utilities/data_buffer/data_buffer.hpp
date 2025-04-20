#pragma once

#include <vector>
#include <stdexcept>
#include <cstring>

class DataBuffer
{
	public:
	DataBuffer();
	DataBuffer(const DataBuffer & src);
	DataBuffer(DataBuffer && src);
	~DataBuffer();

	DataBuffer & operator=(const DataBuffer & rhs);
	DataBuffer & operator=(DataBuffer && rhs);

	template<typename T>
	DataBuffer & operator<<(const T& value);

	template<typename T>
	DataBuffer & operator>>(T& value);

	DataBuffer & operator<<(const std::string & str);
	DataBuffer & operator>>(std::string & str);

	private:
	std::vector<uint8_t> buffer;

	void insert_bytes(const void *ptr, uint32_t size);
	void extract_bytes(void *ptr, uint32_t size);
	
};

template<typename T>
DataBuffer & DataBuffer::operator<<(const T & value)
{
	insert_bytes(&value, sizeof(T));
	return *this;
}

template<typename T>
DataBuffer & DataBuffer::operator>>(T & value)
{
	extract_bytes(&value, sizeof(T));
	return *this;
}
