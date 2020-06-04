#include "common_game_result.h"
#include <sstream>

GameResult::GameResult(const unsigned int game_size) : good(0), regular(0),
												       game_size(game_size) {}

GameResult::~GameResult() {}

void GameResult::setter(const unsigned int good, const unsigned int regular) {
	this->good = good;
	this->regular = regular;
}

std::string GameResult::toStr() const {
	std::stringstream ss;
	if (good > 0) {
		ss << good << " bien";
		if (regular > 0) {
			ss << ", ";
			ss << regular << " regular";	
		}
	} else {
		if (regular > 0) ss << regular << " regular";	
	} 
	if (good + regular == 0) ss << game_size << " mal";
	std::string str = ss.str();
	return str;
}

