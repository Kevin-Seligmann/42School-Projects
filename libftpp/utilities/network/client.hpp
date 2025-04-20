#pragma once

#include <string>
#include <sstream>
#include <functional>
#include <cstring>
#include <stdexcept>
#include "message.hpp"
#include "connection.hpp"
#include "net_actionable.hpp"

class Client : public NetActionable<>
{
	public:
	Client();
	~Client();
	Client(const Client &) = delete;
	Client & operator=(const Client &) = delete;
	Client(Client && rhs);
	Client & operator=(Client && rhs);

	void connect(const std::string& address, const size_t& port);
	void send( Message& message);
	void update();
};
