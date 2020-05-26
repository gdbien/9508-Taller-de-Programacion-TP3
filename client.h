#ifndef CLIENT_H
#define CLIENT_H

#include "common_socket.h"
#include <cstddef>

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
	/*
 		Cierra la comunicación de lectura y escritura
		Lanza std::exception en caso de error.
	*/
	void shutdown();
};

#endif // CLIENT_H
