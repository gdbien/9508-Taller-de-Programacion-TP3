#ifndef SERVER_H
#define SERVER_H

#include <atomic>
#include <list>
#include "common_socket.h"
#include "common_th_client.h"
#include "server_quitter.h"
#include "common_rr_file_reader.h"
#include "common_server_errors.h"

class Server {
private:
	Socket socket;
	std::atomic<bool> running;
	std::list<ThClient*> clts_acptd;
	ServerQuitter svr_quitter;
	RRFileReader rr_f_rdr;
	GamesStatistics games_stats;
	/*
		Acepta un cliente, asignando memoria dinámica para un ThClient, y lo
		inserta en la lista.
		Se lee un numero del archivo, y se lo asigna al game que se le pasa
		al cliente.
		Devuelve un ThClient&, o lanza excepcion en caso de que falle accept.
	*/
	ThClient& accept();
	/*
		Remueve los ThClients de la lista, haciendoles: stop, join y delete.
	*/
	void removeClients();
	/*
		Remueve los ThClients que estan muertos de la lista, haciendoles:
		join y delete.
	*/
	void removeDead();

public:
	/*
		Hace el chequeo del archivo e inicia a ServerQuitter.
		Lanza std::exception() en caso de que el archivo sea inválido,
		imprimiendo la causa.
	*/
	explicit Server(const char* file_name);
	/*
		Hace join de ServerQuitter.

	*/
	~Server();
	/*
 		Pone al servidor a correr en el puerto service.
 		Lanza std::exception en caso de error.
	*/
	void bindAndListen(const char *service);
	/*
		Ciclo de interacción con el cliente, ServerQuitter es el que se encarga
		de hacer que termine.
	*/
	void run();
};

#endif // SERVER_H
