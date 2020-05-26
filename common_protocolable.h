#ifndef PROTOCOLABLE_H
#define PROTOCOLABLE_H

#include <cstddef>
#include <arpa/inet.h>
#include <vector>

class Protocolable {
public:
	Protocolable();
	~Protocolable();
	virtual std::vector<char> encodeData() = 0;
	virtual size_t encodeSize() = 0;
};

#endif // PROTOCOLABLE_H
