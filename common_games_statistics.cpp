#include "common_games_statistics.h"
#include <iostream>

GamesStatistics::GamesStatistics() : winners(0), losers(0) {}

GamesStatistics::~GamesStatistics() {}

void GamesStatistics::addWinner() {
	winners++;
}

void GamesStatistics::addLoser(){
	losers++;
}

void GamesStatistics::print() const {
	std::cout << "Estadísticas:" << std::endl;
	std::cout << "\tGanadores:  " << winners << std::endl;
	//Los perdedores nunca se imprimen.
	//std::cout << "\tPerdedores: " << losers << std::endl;
}
