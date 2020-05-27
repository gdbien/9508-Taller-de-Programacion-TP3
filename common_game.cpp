#include "common_game.h"
#include "common_number_checker.h" //chequear desp
#include <iostream>

#define ATTMPTS_LEFT 10

const char* InsufAttemptsException:: what() const throw() {
	return "Used all attempts";	
}

Game::Game(const std::string number, const size_t digit_count) : 
		   number(number),
		   digit_count(digit_count),
		   game_res(digit_count),
		   attempts(ATTMPTS_LEFT) {}

Game::~Game() {}

bool Game::guess(const std::string& answer) {
	size_t good = 0;
	size_t regular = 0;
	for (size_t i = 0; i < digit_count; i++) {
		for (size_t j = 0; j < digit_count; j++) {
			if (number[i] == answer[j]) {
				if (i == j) good++;
				else regular++;
				break;
			}
		}	
	}
	game_res.setter(good, regular);
	attempts--;
	if (attempts == 0 && good != digit_count) throw InsufAttemptsException();
	return (good == digit_count) ? true : false;
}

std::string Game::getResult() const {
	return game_res.toStr();
}



