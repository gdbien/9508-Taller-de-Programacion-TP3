#ifndef SERVER_QUITTER_H
#define SERVER_QUITTER_H

#include <atomic>
#include "common_thread.h"
#include "common_socket.h"

class Server;

class ServerQuitter : public Thread {
private:
	std::atomic<bool> &svr_running;
	Socket &svr_sckt;
public:
	ServerQuitter(std::atomic<bool> &svr_running, Socket &svr_sckt);
	~ServerQuitter();
	void run() override;
};

#endif // SERVER_QUITTER_H