#include "common_command_numb.h"
#include <iostream>
#include <string>
#include <cstring>
#include "common_manager_command.h"

#define NUMBER_SIZE 2

CommandNumb::CommandNumb(const std::string number) : number(number) {}

CommandNumb::~CommandNumb() {}

bool CommandNumb::operator()(Game &game) {
	return game.guess(number);
}

Message CommandNumb::callManager(ManagerCommand &mngr) {
	return mngr(*this);
}

std::vector<char> CommandNumb::encodeData() {
	std::vector<char> enc_data(3);
	enc_data[0] = (char)TypeCommand::NUMBER;
	uint16_t value = htons(std::stoi(number));
	std::memcpy(&enc_data[1], &value, NUMBER_SIZE);
	return enc_data;
}

size_t CommandNumb::encodeSize() {
	return 3;
}