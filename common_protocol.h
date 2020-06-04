#ifndef COMMON_PROTOCOL_H
#define COMMON_PROTOCOL_H

#include <cstddef>
#include "common_socket.h"
#include "common_protocolable.h"

class Protocol {
public:
	Protocol();
	~Protocol();
	/*
		Se encarga de enviar por Socket un Protocolable, del client al server.
		Devuelve la cantidad de bytes enviados que representa el Protocolable.
	*/
	static size_t clientSend(Socket& sckt, Protocolable *prtble);
	/*
		Se encarga de recibir por Socket un Protocolable, del client al server.
		Devuelve la cantidad de bytes recibidos que representa el Protocolable.
	*/
	static size_t clientReceive(Socket& sckt, Protocolable **prtble);
	/*
		Se encarga de enviar por Socket un Protocolable, del server al client.
		Devuelve la cantidad de bytes enviados que representa el Protocolable.
	*/
	static size_t serverSend(Socket& sckt, Protocolable *prtble);
	/*
		Se encarga de enviar por Socket un Protocolable, del server al client.
		Devuelve la cantidad de bytes recibidos que representa el Protocolable.
	*/
	static size_t serverReceive(Socket& sckt, Protocolable **prtble);
};

#endif // COMMON_PROTOCOL_H
