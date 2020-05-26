#include "server_quitter.h"
#include <iostream>

#define QUIT 'q'

ServerQuitter::ServerQuitter(std::atomic<bool> &svr_running, Socket &svr_sckt)
							: svr_running(svr_running), svr_sckt(svr_sckt) {}
						     

ServerQuitter::~ServerQuitter() {}

void ServerQuitter::run() {
	char c;
	do {
		std::cin >> c;
		if (c == QUIT) break;
	} while (true);
	this->svr_running = false;
	svr_sckt.shutdown(SHUT_RDWR);
}