#pragma once

#include <functional>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cstring>
#include "connection.hpp"
#include "message.hpp"

template <typename... Args>
class NetActionable
{
	public:
	using action_type = std::pair<int, std::function<void(Message &, Args...)>>;

	NetActionable();
	~NetActionable(){};
	void defineAction(int messageType, const std::function<void(Message &, Args...)>& action);
	void disconnect();

	protected:
	void do_action(Message & msg, Args...);
	void error(const std::string prefix, const std::string motive);
	void _connect(const std::string& address, const size_t& port, int flags = 0);

	std::vector<action_type> _actions;
	int _socket;
	Connection * _conn;
};

template <typename... Args>
NetActionable<Args...>::NetActionable():_socket{-1}, _conn{nullptr}{}

template <typename... Args>
void NetActionable<Args...>::defineAction(int messageType, const std::function<void(Message &, Args...)>& action)
{
	auto it = std::find_if(_actions.begin(),
	_actions.end(), [&messageType](action_type & action){return messageType == action.first;});
	if (it != _actions.end())
		_actions.erase(it);
	_actions.emplace_back(std::make_pair(messageType, action));
}

template <typename... Args>
void NetActionable<Args...>::do_action(Message & msg, Args... args)
{
	int messageType = msg.getType();

	auto it = std::find_if(_actions.begin(),
	_actions.end(), [&messageType](action_type & action){return messageType == action.first;});
	if (it == _actions.end())
		throw std::runtime_error("Executing action: not found");
	it->second(msg, std::forward<Args>(args)...);
}

template <typename... Args>
void NetActionable<Args...>::disconnect()
{
	if (_conn)
	{
		delete _conn;
		_conn = nullptr;
	}
	if (_socket > -1)
	{
		shutdown(_socket, 2);
		_socket = -1;
	}
}

template <typename... Args>
void NetActionable<Args...>::error(const std::string prefix, const std::string motive)
{
	disconnect();
	throw std::runtime_error(prefix + motive);
}

template <typename... Args>
void NetActionable<Args...>::_connect(const std::string& address, const size_t& port, int flags)
{
	if (_conn || _socket > -1)
		error("Logic error: ", "already connected");

	try
	{
		_conn = new Connection(address, port, flags);
	}
	catch (std::runtime_error & e)
	{
		error("Getting addr info: ", e.what());
	}

	_socket = socket(_conn->addr_info->ai_family, _conn->addr_info->ai_socktype, _conn->addr_info->ai_protocol);
	if (_socket == -1)
		error("Socket failure: ", strerror(errno));
}
