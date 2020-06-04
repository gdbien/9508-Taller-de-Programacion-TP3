#ifndef COMMAND_NUMB_H
#define COMMAND_NUMB_H

#include <string>
#include <vector>
#include "common_command.h"
#include "common_game.h"
#include "common_message.h"

class CommandNumb : public Command {
private:
	const std::string number;
public:
	explicit CommandNumb(const std::string number);
	~CommandNumb();
	/*
		Realiza un guess del juego.
		Devuelve true si se adivino el numero, false en caso contrario.
		Lanza InsufAttemptsException(), si se quedó sin intentos, y
		InvalidNumberException(), si el numero es inválido.
	*/
	bool operator()(Game &game);
	Message callManager(ManagerCommand &mngr) override;
	std::vector<char> encodeData() override;
	size_t encodeSize() override;
};

#endif // COMMAND_NUMB_H
