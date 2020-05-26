#include "common_message.h"
#include <iostream>
#include <cstring>

#define NUMBER_SIZE 4

Message::Message(std::string msg) : msg(msg) {}

Message::~Message() {}

std::vector<char> Message::encodeData() {
	uint32_t msg_len = msg.length();
	std::vector<char> enc_data(NUMBER_SIZE);
	msg_len = htonl(msg_len);
	std::memcpy(&enc_data[0], &msg_len, NUMBER_SIZE);
	std::copy(msg.begin(), msg.end(), std::back_inserter(enc_data));
	return enc_data;
}

size_t Message::encodeSize() {
	return NUMBER_SIZE + msg.length();
}

void Message::print() {
	std::cout << msg << std::endl;
}