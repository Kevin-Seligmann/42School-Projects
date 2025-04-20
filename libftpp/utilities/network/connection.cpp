#include "connection.hpp"

Connection::Connection(std::string address, const size_t& port, int flags)
:addr_info(nullptr)
{
	set_hints(flags);
	int connection_result;

	if (address.empty())
	{
		connection_result = 
			getaddrinfo(nullptr, std::to_string(htons(port)).c_str(), &hints, &addr_info);
	}
	else
	{
		connection_result = 
			getaddrinfo(address.c_str(), std::to_string(htons(port)).c_str(), &hints, &addr_info);
	}
	if (connection_result != 0)
		throw std::runtime_error(gai_strerror(connection_result));
}

Connection::~Connection(){freeaddrinfo(addr_info);}

void Connection::set_hints(int flags)
{
	memset(&hints, 0, sizeof (hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = flags;
}
