#ifndef GAME_RESULT_H
#define GAME_RESULT_H

#include <cstddef>
#include <string>

class GameResult {
private:
	size_t good;
	size_t regular;
	const size_t game_size;
public:
	GameResult(const size_t game_size);
	~GameResult();
	void setter(const size_t good, const size_t regular);
	std::string toStr() const;
};

#endif // GAME_RESULT_H