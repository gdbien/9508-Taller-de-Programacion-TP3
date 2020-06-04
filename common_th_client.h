#ifndef TH_CLIENT_H
#define TH_CLIENT_H

#include <atomic>
#include "common_socket.h"
#include "common_thread.h"
#include "common_manager_command.h"
#include "common_games_statistics.h"


class ThClient : public Thread {
private:
	Socket sckt;
	std::atomic<bool> keep_talking;
	std::atomic<bool> is_running;
	Game game;
	ManagerCommand mnger_cmnd;
	
public:
	ThClient(Socket sckt, Game game, GamesStatistics &games_stats);
	~ThClient();
	/*
		Ciclo de interacción con el client.
	*/
	void run() override;
	/*
		Devuelve true si el client esta corriendo, y false en caso contrario.
	*/
	bool isDead();
	/*
		Settea keep_talking a false, cortando el ciclo de comunicación.
	*/
	void stop();
};

#endif // TH_CLIENT_H
