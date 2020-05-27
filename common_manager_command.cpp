#include "common_manager_command.h"

ManagerCommand::ManagerCommand(std::atomic<bool> &cl_talking,
							   Game &game) : cl_talking(cl_talking),
							   game(game) {}

ManagerCommand::~ManagerCommand() {}


//Devuelve un message por movimiento
Message ManagerCommand::operator()(CommandSurr &cmnd) {
	std::string msg = "Perdiste";
	cmnd();
	return std::move(Message(msg));

}

Message ManagerCommand::operator()(CommandHelp &cmnd) {
	std::string msg = "Comandos válidos:​ \n\t​ AYUDA: "
					  "despliega la lista de comandos válidos​ \n\t "
					  "​RENDIRSE: pierde el juego automáticamente​ \n\t​ "
					  "XXX: Número de 3 cifras a ser enviado al servidor "
					  "para adivinar el número secreto";
	cmnd();
	return std::move(Message(msg));
}

Message ManagerCommand::operator()(CommandNumb &cmnd) {
	/*	
		FALTA MANEJAR ESTE CASO:
		Si el número recibido es menor a 100, o mayor a 999, o si alguna de las cifras se repiten (por
		ejemplo, se pasa el número 990) se enviará:
		"Número inválido. Debe ser de 3 cifras no repetidas".
		El chequeo tendría que hacerlo aca, y para consumir intentos
		supongo que podria mandarle game.guess("!!!").
		Otra alternativa mejor es crear un checkIfValid(numb) en Game,
		que haga el chequeo y consuma un attempt en caso de ser invalido
		(es la mejor), retorna true si es valido o false, y ahi mando
		el mensaje.
	*/
	try {
		bool guessed_it = cmnd(game);
		if (guessed_it) {
			cl_talking = false;
			return std::move(Message("Ganaste"));
		} 
		return std::move(Message(game.getResult()));
	} catch (...) {
		//Se quedo sin intentos lo lanza cmnd(game)
		cl_talking = false;
		return std::move(Message("Perdiste"));
	} 
}