#ifndef COMMON_GAME_H
#define COMMON_GAME_H

#include <string>
#include <exception>
#include "common_game_result.h"

class InsufAttemptsException : public std::exception {
public:
	const char *what() const throw();
};

class InvalidNumberException : public std::exception {
public:
	const char *what() const throw();
};

class Game {
private:
	const std::string number;
	const unsigned int digit_count;
	GameResult game_res;
	unsigned int attempts;
	/*
		Chequea si answer es una respuesta válida para el juego.
		Devuelve true si lo es, en caso contrario consume un intento
		y devuelve false.
		Lanza InsufAttemptsException() en caso de que después de chequear
		la cantidad de intentos sea 0.
	*/
	bool isValid(const std::string& answer);
	
public:
	Game(const std::string number, const unsigned int digit_count);
	~Game();
	/*
		Intenta adivinar el número, comparándolo con la respuesta del jugador.
		Devuelve true si el usuario acertó, y false en caso contrario.
		Lanza InsufAttemptsException(), si el usuario se quedó sin intentos. 
		Lanza InvalidNumberException(), si el número es inválido. 
	*/
	bool guess(const std::string &answer);
	/*
		Obtiene el resultado del juego en formato de string.
	*/
	std::string getResult() const;
};

#endif // COMMON_GAME_H
