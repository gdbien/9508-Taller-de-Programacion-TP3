#include "common_game.h"
#include "common_number_checker.h"

#define ATTMPTS_LEFT 10

const char* InsufAttemptsException:: what() const throw() {
	return "Used all attempts";	
}

const char* InvalidNumberException:: what() const throw() {
	return "Invalid number";	
}

Game::Game(const std::string number, const unsigned int digit_count) : 
		   number(number),
		   digit_count(digit_count),
		   game_res(digit_count),
		   attempts(ATTMPTS_LEFT) {}

Game::~Game() {}

bool Game::guess(const std::string& answer) {
	if (!isValid(answer)) throw InvalidNumberException();
	unsigned int good = 0;
	unsigned int regular = 0;
	for (size_t i = 0; i < digit_count; i++) {
		for (size_t j = 0; j < digit_count; j++) {
			if (number[i] == answer[j]) {
				if (i == j) {
					good++;	
				} else {
					regular++;
				}
				break;
			}
		}	
	}
	game_res.setter(good, regular);
	attempts--;
	if (attempts == 0 && good != digit_count) throw InsufAttemptsException();
	return (good == digit_count) ? true : false;
}

bool Game::isValid(const std::string& answer) {
	bool is_good = NumberChecker::isGood(answer, digit_count);
	if (is_good) return true;
	attempts--;
	if (attempts == 0) {
		throw InsufAttemptsException();
	} else {
		return false;
	}
}

std::string Game::getResult() const {
	return game_res.toStr();
}
