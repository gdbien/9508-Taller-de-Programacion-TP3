#include "common_message.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include "common_server_messages.h"

#define NUMBER_SIZE 4

Message::Message(const std::string msg) : msg(msg) {}

Message::~Message() {}

std::vector<char> Message::encodeData() {
	uint32_t msg_len = msg.length();
	std::vector<char> enc_data(NUMBER_SIZE);
	msg_len = htonl(msg_len);
	std::memcpy(enc_data.data(), &msg_len, NUMBER_SIZE);
	std::copy(msg.begin(), msg.end(), std::back_inserter(enc_data));
	return enc_data;
}

size_t Message::encodeSize() {
	return NUMBER_SIZE + msg.length();
}

void Message::print() const {
	std::cout << msg << std::endl;
}

bool Message::gameIsOver() const {
	if (std::strcmp(msg.data(), lost_msg) == 0) return true;
	if (std::strcmp(msg.data(), won_msg) == 0) return true;
	return false;
}
