#ifndef MANAGER_COMMAND_H
#define MANAGER_COMMAND_H

#include <atomic>
#include "common_game.h"
#include "common_message.h"
#include "common_command_surr.h"
#include "common_command_help.h"
#include "common_command_numb.h"

class ManagerCommand {
private:
	std::atomic<bool> &cl_talking;
	Game &game;
public:
	ManagerCommand(std::atomic<bool> &cl_talking, Game &game);
	~ManagerCommand();
	//Devuelve un message por movimiento
	Message operator()(CommandSurr &cmnd);
	Message operator()(CommandHelp &cmnd);
	Message operator()(CommandNumb &cmnd);
};

#endif // MANAGER_COMMAND_H