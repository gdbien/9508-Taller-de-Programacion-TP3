#ifndef COMMON_GAME_H
#define COMMON_GAME_H

#include <string>
#include <exception>
#include "common_game_result.h"

class InsufAttemptsException : public std::exception {
public:
	const char *what() const throw();
};


class Game {
private:
	const std::string number;
	const size_t digit_count;
	GameResult game_res;
	size_t attempts;
public:
	Game(const std::string number, const size_t digit_count);
	~Game();
	bool guess(const std::string &answer);
	std::string getResult() const;
};

#endif // COMMON_GAME_H