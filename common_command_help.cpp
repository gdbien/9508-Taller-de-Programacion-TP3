#include "common_command_help.h"
#include <iostream>
#include "common_manager_command.h"

CommandHelp::CommandHelp() {}

CommandHelp::~CommandHelp() {}

void CommandHelp::operator()() {}

Message CommandHelp::callManager(ManagerCommand &mngr) {
	return mngr(*this);
}

std::vector<char> CommandHelp::encodeData() {
	std::vector<char> enc_data(1, (char)TypeCommand::HELP);
	return enc_data;
}
size_t CommandHelp::encodeSize() {
	return 1;
}
