#include "common_command_help.h"
#include "common_manager_command.h"

#define PROTOCOL_SIZE 1

CommandHelp::CommandHelp() {}

CommandHelp::~CommandHelp() {}

void CommandHelp::operator()() {}

Message CommandHelp::callManager(ManagerCommand &mngr) {
	return mngr(*this);
}

std::vector<char> CommandHelp::encodeData() {
	std::vector<char> enc_data(PROTOCOL_SIZE, (char)TypeCommand::HELP);
	return enc_data;
}
size_t CommandHelp::encodeSize() {
	return PROTOCOL_SIZE;
}
