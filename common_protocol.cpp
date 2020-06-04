#include "common_protocol.h"
#include <cstring>
#include <string>
#include <vector>
#include "common_types_command.h"
#include "common_command_surr.h"
#include "common_command_help.h"
#include "common_command_numb.h"
#include "common_message.h"

#define BYTE_MSG_SZ 4
#define BYTE_NUMB_SZ 2
#define BYTE_CMND_TYPE 1

Protocol::Protocol() {}

Protocol::~Protocol() {}

size_t Protocol::clientSend(Socket &sckt, Protocolable *prtble) {
	return sckt.send((const char*)prtble->encodeData().data(),
					 prtble->encodeSize());
}

size_t Protocol::clientReceive(Socket &sckt, Protocolable **prtble) {
	std::vector<char> buf(BYTE_MSG_SZ);
	sckt.receive(buf.data(), BYTE_MSG_SZ);
	uint32_t msg_len;
	std::memcpy(&msg_len, buf.data(), BYTE_MSG_SZ);
	msg_len = ntohl(msg_len);
	buf.resize(msg_len + 1);
	sckt.receive(buf.data(), msg_len);
	buf[msg_len] = '\0';
	std::string msg(buf.begin(), buf.end() - 1);
	*prtble = new Message(msg);
	return BYTE_MSG_SZ + msg_len;
}

size_t Protocol::serverSend(Socket &sckt, Protocolable *prtble) {
	return sckt.send((const char*)prtble->encodeData().data(),
					 prtble->encodeSize());
}

size_t Protocol::serverReceive(Socket &sckt, Protocolable **prtble) {
	size_t count = BYTE_CMND_TYPE;
	std::vector<char> buf(BYTE_CMND_TYPE);
	sckt.receive(buf.data(), BYTE_CMND_TYPE);
	char type_cmnd = buf[0];
	if (type_cmnd == (char)TypeCommand::HELP) *prtble = new CommandHelp();
	if (type_cmnd == (char)TypeCommand::SURRENDER) *prtble = new CommandSurr();
	if (type_cmnd == (char)TypeCommand::NUMBER) {
		count += BYTE_NUMB_SZ;
		buf.resize(BYTE_NUMB_SZ);
		sckt.receive(buf.data(), BYTE_NUMB_SZ);
		uint16_t number;
		std::memcpy(&number, buf.data(), BYTE_NUMB_SZ);
		number = ntohs(number);
		*prtble = new CommandNumb(std::to_string(number));
	}
	return count;
}
