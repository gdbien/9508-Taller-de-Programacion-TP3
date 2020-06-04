#include "server.h"
#include <stdbool.h>
#include <arpa/inet.h>
#include <exception>
#include <iostream>
#include <string>
#include "common_protocol.h"
#include "common_file_checker.h"

#define DIGIT_COUNT 3 //De esta forma el server decide de cuanto hacer el juego

Server::Server(const char* file_name) : running(true),
	          						    svr_quitter(running, socket),
	          						    rr_f_rdr(file_name) {
	int ret = FileChecker::isGood(file_name, DIGIT_COUNT);
	if (ret < 0) {
		if (ret == F_CHK_INVL_PATRN) {
			std::cerr << file_nber_rep_msg << std::endl;	
		} else {
			std::cerr << file_nber_oor_msg << std::endl;
		}
		throw std::exception();
	}
	svr_quitter.start();
}

Server::~Server() {
	svr_quitter.join();
}

ThClient& Server::accept() {
	std::string number = rr_f_rdr.getline();
	Game game(number, DIGIT_COUNT);
	ThClient* th_client = new ThClient(socket.accept(), game, games_stats);
	clts_acptd.push_back(th_client);
	return *th_client;
}

void Server::removeClients() {
	for (auto it = clts_acptd.begin(); it != clts_acptd.end(); it++) {
    	ThClient* th_client = *it;
    	th_client->stop();
    	th_client->join();
    	delete th_client;
	}	
}

void Server::removeDead() {
	std::list<ThClient*> tmp;
	for (auto it = clts_acptd.begin(); it != clts_acptd.end(); it++) {
    	ThClient* th_client = *it;
    	if (!th_client->isDead()) {
      		tmp.push_back(*it);
    	} else {
    		th_client->join();
    		delete th_client;
    	}
	}
	clts_acptd.swap(tmp);
}

void Server::bindAndListen(const char *service) {
	socket.bindAndListen(service);
}

void Server::run() {
	try {
		while(running) {
			ThClient& th_client = accept();
			th_client.start();
	   		removeDead();
		}	
	} catch (...) {} //Catch de la excepcion de accept();
	removeClients();
	games_stats.print();
}
