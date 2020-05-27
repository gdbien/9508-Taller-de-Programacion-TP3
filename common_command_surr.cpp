#include "common_command_surr.h"
#include <iostream>
#include "common_manager_command.h"


CommandSurr::CommandSurr() {}

CommandSurr::~CommandSurr() {}

void CommandSurr::operator()() {}

Message CommandSurr::callManager(ManagerCommand &mngr) {
	return mngr(*this);
}

std::vector<char> CommandSurr::encodeData() {
	std::vector<char> enc_data(1, (char)TypeCommand::SURRENDER);
	return enc_data;
}
size_t CommandSurr::encodeSize() {
	return 1;
}
