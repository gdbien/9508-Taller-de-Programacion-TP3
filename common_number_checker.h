#ifndef NUMBER_CHECKER_H
#define NUMBER_CHECKER_H

#include <string>

class NumberChecker {
public:
	NumberChecker();
	~NumberChecker();
	/*
		Chequea si el número (number) es válido para el juego, pasándole una 
		cantidad de digitos determinada (digit_count).
		Devuelve true si es válido, false en caso contrario.
	*/
	static bool isGood(const std::string &number,
					   const unsigned int digit_count);
	/*
		Chequea si el número (number) tiene un rango válido para el juego,
		pasándole una cantidad de digitos determinada (digit_count).
		Devuelve true si es válido, false en caso contrario.
	*/
	static bool rangeIsGood(const std::string &number,
						    const unsigned int digit_count);
	/*
		Chequea si el número (number) tiene un patrón válido (sin repetidos)
		para el juego, pasándole una cantidad de digitos determinada
		(digit_count).
		Devuelve true si es válido, false en caso contrario.
	*/
	static bool patternIsGood(const std::string &number,
							  const unsigned int digit_count);
};

#endif // NUMBER_CHECKER_H
