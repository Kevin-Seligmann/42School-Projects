#include "server.hpp"

Server::Server():_active_port{0}, _continue{true}{};

Server::~Server(){disconnect(); _continue = false;};

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

void Server::worker_routine(int sock)
{
	if (!_conn)
		error("Logic error: ", "server not connected");
	char str_buff[1001];
	std::stringstream rec_buff{""};
	Message msg;
	ssize_t read_bytes = 0;

	while (1)
	{
		Message::msg_status rta = msg.read_net_message(rec_buff, read_bytes);
		if (rta == Message::msg_status::REC_DONE)
		{
			do_action(msg, sock);
			msg.reset();
			if (!rec_buff.str().empty())
			{
				read_bytes = rec_buff.str().size();
				continue;
			}
			return;
		}
		if (!should_read(sock))
			return;
		read_bytes = recv(sock, str_buff, 1000, 0);
		if (read_bytes <= 0)
			return;
		rec_buff.write(str_buff, read_bytes);
	}
}

void Server::listen_routine()
{
	while (_continue)
	{
		int client_socket = accept(_socket, nullptr, nullptr);
		if (client_socket == -1)
		{
			if (!_continue)
				break;
			error("Accept failed: ", strerror(errno));
			continue;
		}
		_client_ids.push_back(client_socket);
	}
}

void Server::start(const size_t& p_port)
{
	if (_active_port > 0)
		error("Logic error: ", "already started");
	_connect("", p_port, AI_PASSIVE);
	if (bind(_socket, _conn->addr_info->ai_addr, _conn->addr_info->ai_addrlen))
		error("Bind failure: ", strerror(errno));
	if (listen(_socket, SOMAXCONN) == -1)
		error("Listening failure: ", strerror(errno));
	_active_port = p_port;

	_continue = true;
	std::thread th(&Server::listen_routine, this);
	th.detach();
}

void Server::update()
{
	if (_active_port == 0 || !_conn || _socket == -1)
		error("Logic error: ", "server not running");
	for (auto client: _client_ids)
		worker_routine(client);
}

void Server::sendTo( Message& message, long long clientID)
{
	if (!_conn || _socket == -1)
		error("Logic error: ", " sending message while disconnected");

	std::string msg;
	size_t size = message.compose_net_msg(msg);
	size_t total_sent = 0;

	while (total_sent < size)
	{
		ssize_t sent_bytes = ::send(clientID, msg.c_str() + total_sent, size - total_sent, 0);
		if (sent_bytes == -1)
			error("Sending message: ", strerror(errno));
		total_sent += static_cast<size_t>(sent_bytes);
	}
}

void Server::sendToArray( Message& message, std::vector<long long> clientIDs)
{
	for (auto it = clientIDs.begin(); it != clientIDs.end(); it ++)
		sendTo(message, *it);
}

void Server::sendToAll( Message& message)
{sendToArray(message, _client_ids);}
