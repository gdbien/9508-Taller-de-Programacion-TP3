#include "common_command_surr.h"
#include <iostream>
#include "common_manager_command.h"

#define PROTOCOL_SIZE 1

CommandSurr::CommandSurr() {}

CommandSurr::~CommandSurr() {}

void CommandSurr::operator()() {}

Message CommandSurr::callManager(ManagerCommand &mngr) {
	return mngr(*this);
}

std::vector<char> CommandSurr::encodeData() {
	std::vector<char> enc_data(PROTOCOL_SIZE, (char)TypeCommand::SURRENDER);
	return enc_data;
}

size_t CommandSurr::encodeSize() {
	return PROTOCOL_SIZE;
}
