#include "data_buffer.hpp"

DataBuffer::DataBuffer(){}
DataBuffer::DataBuffer(const DataBuffer & src):buffer(src.buffer){}
DataBuffer::DataBuffer(DataBuffer && src):buffer(std::move(src.buffer)){}
DataBuffer::~DataBuffer(){}

DataBuffer & DataBuffer::operator=(const DataBuffer & rhs){buffer = rhs.buffer; return *this;}
DataBuffer & DataBuffer::operator=(DataBuffer && rhs)
{if (this != &rhs) buffer = std::move(rhs.buffer); return *this;}

void DataBuffer::insert_bytes(const void *ptr, uint32_t size)
{
	buffer.insert(buffer.end(), (uint8_t *) ptr, ((uint8_t *) ptr + size));
}

void DataBuffer::extract_bytes(void *ptr, uint32_t size)
{
	if (buffer.begin() + size > buffer.end())
		throw std::runtime_error("Invalid extraction: Out of bounds");
	memcpy(ptr, &(*(buffer.begin())), size);
	buffer.erase(buffer.begin(), buffer.begin() + size);
}


DataBuffer & DataBuffer::operator<<(const std::string & str)
{
	uint32_t size = str.size();
	*this << size;
	insert_bytes((void *) str.c_str(), size);
	return *this;
}

DataBuffer & DataBuffer::operator>>(std::string & str)
{
	uint32_t size;
	*this >> size;
	str.resize(size);
	extract_bytes(&str[0], size);
	return *this;
}
