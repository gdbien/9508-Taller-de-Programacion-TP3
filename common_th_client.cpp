#include "common_th_client.h"
#include <iostream>
#include <utility>
#include "common_protocol.h"
#include "common_command.h"
#include "common_message.h"

ThClient::ThClient(Socket sckt, Game game, GamesStatistics &games_stat) :
				   sckt(std::move(sckt)), keep_talking(true), is_running(true),
				   game(std::move(game)), mnger_cmnd(keep_talking,this->game,
				   games_stat) {}

ThClient::~ThClient() {}

void ThClient::stop() {
	keep_talking = false;
}

bool ThClient::isDead() {
	return !is_running;
}

void ThClient::run() {
	Protocolable *protocolable = NULL;
	while (keep_talking) {
		try {
			Protocol::serverReceive(this->sckt, &protocolable);
			Command *cmnd = static_cast<Command*>(protocolable);
			Message msg = cmnd->callManager(mnger_cmnd);
			delete cmnd;
			Protocol::serverSend(this->sckt, &msg);
		} catch (...) {
			keep_talking = false;
		}
	}
	is_running = false;
}
