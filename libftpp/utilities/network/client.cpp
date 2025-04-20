#include "client.hpp"

Client::Client(){}

Client::~Client(){disconnect();}

Client::Client(Client && rhs)
{
	_conn = rhs._conn;
	_socket = rhs._socket;
	_actions = std::move(rhs._actions);
	rhs._conn = nullptr;
	rhs._socket = -1;
}

Client & Client::operator=(Client && rhs)
{
	_conn = rhs._conn;
	_socket = rhs._socket;
	_actions = std::move(rhs._actions);
	rhs._conn = nullptr;
	rhs._socket = -1;
	return *this;
}

void Client::connect(const std::string& address, const size_t& port)
{
	_connect(address, port);
	if (::connect(_socket, _conn->addr_info->ai_addr, _conn->addr_info->ai_addrlen) == -1)
		error("Connection failure: ", strerror(errno));
}

void Client::send( Message& message)
{
	if (!_conn || _socket == -1)
		error("Logic error: ", " sending message while disconnected");

	std::string msg;
	size_t size = message.compose_net_msg(msg);
	size_t total_sent = 0;

	while (total_sent < size)
	{
		ssize_t sent_bytes = ::send(_socket, msg.c_str() + total_sent, size - total_sent, 0);
		if (sent_bytes == -1)
			error("Sending message: ", strerror(errno));
		total_sent += static_cast<size_t>(sent_bytes);
	}
}

#include <iostream>

namespace 
{
	bool should_read(int sock)
	{
		fd_set readfds;
		FD_ZERO(&readfds);
		FD_SET(sock, &readfds);

		struct timeval timeout = {0, 0};

		int result = select(sock + 1, &readfds, nullptr, nullptr, &timeout);

		return (result > 0 && FD_ISSET(sock, &readfds));
	}
}



void Client::update()
{
	if (!_conn || _socket == -1)
		error("Logic error: ", "client disconnected");
	char str_buff[1001];
	std::stringstream rec_buff{""};
	Message msg;
	ssize_t read_bytes = 0;

	while (1)
	{
		Message::msg_status rta = msg.read_net_message(rec_buff, read_bytes);
		if (rta == Message::msg_status::REC_DONE)
		{
			do_action(msg);
			msg.reset();
			if (!rec_buff.str().empty())
			{
				read_bytes = rec_buff.str().size();
				continue;
			}
			return;
		}
		if (!should_read(_socket))
			return;
		read_bytes = recv(_socket, str_buff, 1000, 0);
		if (read_bytes <= 0)
			return;
		rec_buff.write(str_buff, read_bytes);
	}
}
