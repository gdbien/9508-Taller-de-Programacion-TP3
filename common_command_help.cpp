#include "common_command_help.h"
#include <iostream>

CommandHelp::CommandHelp() {}

CommandHelp::~CommandHelp() {}

void CommandHelp::operator()() {}

std::vector<char> CommandHelp::encodeData() {
	std::vector<char> enc_data(1, (char)TypeCommand::HELP);
	return enc_data;
}
size_t CommandHelp::encodeSize() {
	return 1;
}
