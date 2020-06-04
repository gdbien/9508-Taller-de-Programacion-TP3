#ifndef MANAGER_COMMAND_H
#define MANAGER_COMMAND_H

#include <atomic>
#include "common_game.h"
#include "common_message.h"
#include "common_command_surr.h"
#include "common_command_help.h"
#include "common_command_numb.h"
#include "common_games_statistics.h"

class ManagerCommand {
private:
	std::atomic<bool> &cl_talking;
	Game &game;
	GamesStatistics &games_stats;
public:
	ManagerCommand(std::atomic<bool> &cl_talking, Game &game,
				   GamesStatistics &games_stats);
	~ManagerCommand();
	/*
		Ejecuta el cnmd, y realiza las operaciones necesarias.
		Devuelve un Message por movimiento.
	*/
	Message operator()(CommandSurr &cmnd);
	/*
		Ejecuta el cnmd, y realiza las operaciones necesarias.
		Devuelve un Message por movimiento.
	*/
	Message operator()(CommandHelp &cmnd);
	/*
		Ejecuta el cnmd, y realiza las operaciones necesarias.
		Devuelve un Message por movimiento.
	*/
	Message operator()(CommandNumb &cmnd);
};

#endif // MANAGER_COMMAND_H
