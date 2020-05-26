#ifndef COMMON_PROTOCOL_H
#define COMMON_PROTOCOL_H

#include <cstddef>
#include "common_socket.h"
#include "common_protocolable.h"

class Protocol {
public:
	Protocol();
	~Protocol();
	static size_t clientSend(Socket& sckt, Protocolable *prtble);
	static size_t clientReceive(Socket& sckt, Protocolable **prtble);
	static size_t serverSend(Socket& sckt, Protocolable *prtble);
	static size_t serverReceive(Socket& sckt, Protocolable **prtble);
};

#endif // COMMON_PROTOCOL_H