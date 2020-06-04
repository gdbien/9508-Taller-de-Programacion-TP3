#ifndef GAME_RESULT_H
#define GAME_RESULT_H

#include <string>

class GameResult {
private:
	unsigned int good;
	unsigned int regular;
	const unsigned int game_size;
public:
	explicit GameResult(const unsigned int game_size);
	~GameResult();
	void setter(const unsigned int good, const unsigned int regular);
	/*
		Pasa el resultado del juego a un string imprimible (sin \n)
	*/
	std::string toStr() const;
};

#endif // GAME_RESULT_H
