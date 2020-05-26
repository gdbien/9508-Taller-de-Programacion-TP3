#ifndef TH_CLIENT_H
#define TH_CLIENT_H

#include <atomic>
#include "common_socket.h"
#include "common_thread.h"
#include "common_manager_command.h"


class ThClient : public Thread {
private:
	Socket sckt;
	std::atomic<bool> keep_talking;
	std::atomic<bool> is_running;
	Game game;
	ManagerCommand mnger_cmnd;
public:
	ThClient(Socket sckt, Game game);
	~ThClient();
	void run() override;
	bool isDead();
	void stop();
};

#endif // TH_CLIENT_H