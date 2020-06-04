#ifndef COMMON_MESSAGE_H
#define COMMON_MESSAGE_H

#include <string>
#include <vector>
#include "common_protocolable.h"

class Message : public Protocolable {
private:
	const std::string msg;
public:
	explicit Message(const std::string msg);
	virtual ~Message();
	std::vector<char> encodeData() override;
	size_t encodeSize() override;
	void print() const;
	bool gameIsOver() const;
};

#endif // COMMON_MESSAGE_H
