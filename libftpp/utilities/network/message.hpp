#pragma once

#include <sstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

class Message
{
	public:
	enum class msg_status {REC_DONE, REC_INCOMPLETE};

	Message();
	Message(int type);
	~Message() = default;
	Message(const Message &);
	Message(Message &&);
	Message & operator=(const Message &);
	Message & operator=(Message &&);

	int getType() const;
	std::string getMessage() const;
	size_t compose_net_msg(std::string & dst) const;
	size_t get_header_length() const;
	msg_status read_net_message(std::stringstream & rec_buffer, ssize_t & read_bytes);
	void reset();

	template<typename T>
	std::stringstream & operator<<(const T & inp);
	template<typename T>
	std::stringstream & operator>>(T & out);
	std::stringstream & operator<<(std::ostream & (*manip)(std::ostream &));
	std::stringstream & operator>>(std::istream & (*manip)(std::istream &));


	private:
	int _type;
	std::stringstream _stream{""};

	size_t receiving_size{0};
	size_t received_length{0};
};

template<typename T>
std::stringstream & Message::operator<<(const T & inp)
{
	_stream << inp;
	return _stream;
}

template<typename T>
std::stringstream & Message::operator>>(T & out)
{
	_stream >> out;
	return _stream;
}
