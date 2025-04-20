#include "message.hpp"

Message::Message():_type{-1}{}

Message::Message(int type):_type{type}{receiving_size = 0; received_length = 0;}

Message::Message(const Message & src)
:_type{src._type} {_stream << src.getMessage();}

Message::Message(Message && src)
:_type(std::move(src._type)), _stream(std::move(src._stream)){}

Message & Message::operator=(const Message & rhs)
{
	if (this == &rhs)
		return *this;
	_type = rhs._type;
	_stream.clear();
	_stream.str("");
	_stream << rhs.getMessage();
	return *this;
}

Message & Message::operator=(Message && rhs)
{
	if (this == &rhs)
		return *this;
	_type = std::move(rhs._type);
	_stream = std::move(rhs._stream);
	return *this;
}

std::stringstream & Message::operator<<(std::ostream & (*manip)(std::ostream &))
{
	manip(_stream);
	return _stream;
}

std::stringstream & Message::operator>>(std::istream & (*manip)(std::istream &))
{
	manip(_stream);
	return _stream;
}

int Message::getType() const {return _type;}
std::string Message::getMessage() const {return _stream.str();};


void Message::reset()
{
	_type = 0;
	_stream.str("");
	_stream.clear();
	received_length = 0;
	receiving_size = 0;
}

size_t Message::get_header_length() const { return sizeof(size_t) + sizeof(_type); }

#include <iostream>
Message::msg_status Message::read_net_message(std::stringstream & rec_buffer, ssize_t & read_bytes)
{
	if (received_length + read_bytes < get_header_length())
	{
		received_length += read_bytes;
		return Message::msg_status::REC_INCOMPLETE;
	}
	
	received_length += read_bytes;
	if (received_length - read_bytes < get_header_length())
	{
        rec_buffer.read(reinterpret_cast<char *>(&receiving_size), sizeof(receiving_size));
        rec_buffer.read(reinterpret_cast<char *>(&_type), sizeof(_type));
	}
	if (received_length < receiving_size)
		return Message::msg_status::REC_INCOMPLETE;

    size_t body_size = receiving_size - get_header_length();
	std::string msg(body_size, '\0');
 	rec_buffer.read(&msg[0], body_size);
	_stream << msg;

	rec_buffer.seekg(0, std::ios::cur);

	std::streampos pos = rec_buffer.tellg();
	if (pos == -1)
	{
		read_bytes = 0;
		rec_buffer.clear();
		rec_buffer.str("");
	}
	else
	{
		std::string leftover = rec_buffer.str().substr(static_cast<size_t>(pos));
		read_bytes = leftover.size();
		std::stringstream new_buffer(std::move(leftover));
		rec_buffer.swap(new_buffer);
	}

	return Message::msg_status::REC_DONE;
}


size_t Message::compose_net_msg(std::string & dst) const
{
	std::string msg = _stream.str();
	size_t length = get_header_length() + msg.length();

	dst.clear();
	dst.reserve(length);

	dst.append(reinterpret_cast<const char*>(&length), sizeof(length));
	dst.append(reinterpret_cast<const char*>(&_type), sizeof(_type));
	dst.append(msg);

	return length;
}
