#ifndef GAMES_STATISTICS_H
#define GAMES_STATISTICS_H

class GamesStatistics {
private:
	unsigned int winners;
	unsigned int losers;
public:
	GamesStatistics();
	~GamesStatistics();
	void addWinner();
	void addLoser();
	void print() const;
};

#endif
