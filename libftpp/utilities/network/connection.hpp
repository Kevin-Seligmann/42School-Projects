#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <string>
#include <netdb.h>
#include <string.h>
#include <stdexcept>

struct Connection
{
	Connection(std::string address, const size_t& port, int flags = 0);
	~Connection();

	struct addrinfo hints;
	struct addrinfo *addr_info;

	private:
	void set_hints(int flags);
};
