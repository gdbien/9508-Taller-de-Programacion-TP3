#include "common_manager_command.h"
#include <utility>
#include "common_server_messages.h"

ManagerCommand::ManagerCommand(std::atomic<bool> &cl_talking,
							   Game &game, GamesStatistics &games_stats) :
							   cl_talking(cl_talking), game(game),
							   games_stats(games_stats) {}

ManagerCommand::~ManagerCommand() {}

Message ManagerCommand::operator()(CommandSurr &cmnd) {
	cmnd();
	cl_talking = false;
	games_stats.addLoser();
	return std::move(Message(lost_msg));
}

Message ManagerCommand::operator()(CommandHelp &cmnd) {
	cmnd();
	return std::move(Message(help_msg));
}

Message ManagerCommand::operator()(CommandNumb &cmnd) {
	try {
		bool guessed_it = cmnd(game);
		if (guessed_it) {
			cl_talking = false;
			games_stats.addWinner();
			return std::move(Message(won_msg));
		} 
		return std::move(Message(game.getResult()));
	} catch (InsufAttemptsException& e) {
		cl_talking = false;
		games_stats.addLoser();
		return std::move(Message(lost_msg));
	} catch (InvalidNumberException& e) {
		return std::move(Message(invld_nber_msg));
	}
}
