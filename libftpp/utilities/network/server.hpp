#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string>
#include <vector>
#include <sstream>
#include <thread>
#include <atomic>
#include <algorithm>
#include <iostream>
#include "net_actionable.hpp"
#include "connection.hpp"

class Server : public NetActionable<long long>
{
	public:
	Server();
	~Server();

	void start(const size_t& p_port);
	void sendTo( Message& message, long long clientID);
	void sendToArray( Message& message, std::vector<long long> clientIDs);
	void sendToAll( Message& message);
	void update();

	private:
	size_t _active_port;
	std::vector<long long> _client_ids;
	std::atomic<int> _client_count{0};
	std::atomic<int> _clients_updates{0};
	bool _continue;

	void worker_routine(int _sock);
	void listen_routine();
};
