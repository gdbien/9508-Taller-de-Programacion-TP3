#ifndef CLIENT_H
#define CLIENT_H

#include <cstddef>
#include "common_socket.h"
#include "common_clients_errors.h"

class Client {
private:
	Socket socket;
public:
	Client();
	~Client();
	/*
		Se conecta a un servidor dada una dirección y un servicio o puerto.
		Lanza std::exception en caso de error.
	*/
	void connect(const char *host_name, const char *service);
	/*
		Inicia el ciclo comunicación con el servidor, enviando comandos, y 
		recibiendo mensajes.
	*/
	void run();
};

#endif // CLIENT_H
