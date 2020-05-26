#include "common_th_client.h"
#include <iostream>
#include "common_protocol.h"
#include "common_command.h"
#include "common_message.h"

ThClient::ThClient(Socket sckt, Game game) : sckt(std::move(sckt)),
											 keep_talking(true),
								  			 is_running(true),
								  			 game(std::move(game)),
								  			 mnger_cmnd(keep_talking,
								  			 this->game) {}

ThClient::~ThClient() {}

void ThClient::stop() {
	keep_talking = false;
}

bool ThClient::isDead() {
	return !is_running;
}

void ThClient::run() {
	Protocolable *prtble = NULL;
	while (keep_talking) {
		try {
			Protocol::serverReceive(this->sckt, &prtble);
			Command *cmnd = static_cast<Command*>(prtble);
			Message msg = mnger_cmnd(*cmnd); //NO SE ESTA COMPORTANDO POLIMORFICAMENTE
			delete cmnd;
			Protocol::serverSend(this->sckt, &msg);
		} catch (...) {
			keep_talking = false;
		}
	}
	is_running = false;
}