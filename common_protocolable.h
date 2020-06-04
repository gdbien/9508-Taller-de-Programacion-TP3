#ifndef PROTOCOLABLE_H
#define PROTOCOLABLE_H

#include <cstddef>
#include <arpa/inet.h>
#include <vector>

class Protocolable {
public:
	Protocolable();
	~Protocolable();
	/*
		Devuelve un vector que es la representación encodeada (para protocolo)
		del objeto.
	*/
	virtual std::vector<char> encodeData() = 0;
	/*
		Devuelve el size de la representación encodeada (para protocolo)
		del objeto.
	*/
	virtual size_t encodeSize() = 0;
};

#endif // PROTOCOLABLE_H
