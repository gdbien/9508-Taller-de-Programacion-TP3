#include "common_command_surr.h"
#include <iostream>

CommandSurr::CommandSurr() {}

CommandSurr::~CommandSurr() {}

void CommandSurr::operator()() {}

std::vector<char> CommandSurr::encodeData() {
	std::vector<char> enc_data(1, (char)TypeCommand::SURRENDER);
	return enc_data;
}
size_t CommandSurr::encodeSize() {
	return 1;
}
