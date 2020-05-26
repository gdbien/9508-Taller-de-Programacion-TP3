#ifndef COMMON_MESSAGE_H
#define COMMON_MESSAGE_H

#include "common_protocolable.h"
#include <string>

class Message : public Protocolable {
private:
	std::string msg;
public:
	Message(const std::string msg);
	virtual ~Message();
	std::vector<char> encodeData() override;
	size_t encodeSize() override;
	void print();
};

#endif // COMMON_MESSAGE_H