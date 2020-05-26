#include "server.h"
#include <stdbool.h>
#include <arpa/inet.h>
#include "common_protocol.h"

Server::Server(const char* file_name) : running(true),
	          						    svr_quitter(running, socket),
	          						    rr_f_rdr(file_name) {
	svr_quitter.start();
}

Server::~Server() {
	svr_quitter.join();
}

ThClient& Server::accept() {
	std::string number = rr_f_rdr.getline();
	Game game(number);
	ThClient* th_client = new ThClient(socket.accept(), game);
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
	//ACA FALTA IMPRIMIR LAS ESTADISTICAS
}
