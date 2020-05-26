#include "common_game.h"
#include <iostream>

#define NUMBER_SIZE 3
#define ATTMPTS_LEFT 10

const char* InsufAttemptsException:: what() const throw() {
	return "Used all attempts";	
}

Game::Game(const std::string number) : number(number), game_res(NUMBER_SIZE),
									   attempts(ATTMPTS_LEFT) {}

Game::~Game() {}

bool Game::guess(const std::string& answer) {
	size_t good = 0;
	size_t regular = 0;
	for (size_t i = 0; i < NUMBER_SIZE; i++) {
		for (size_t j = 0; j < NUMBER_SIZE; j++) {
			if (number[i] == answer[j]) {
				if (i == j) good++;
				else regular++;
				break;
			}
		}	
	}
	game_res.setter(good, regular);
	attempts--;
	if (attempts == 0 && good != NUMBER_SIZE) throw InsufAttemptsException();
	return (good == NUMBER_SIZE) ? true : false;
}

std::string Game::getResult() const {
	return game_res.toStr();
}



