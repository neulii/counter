#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <vector>
#include <iostream>


class Game
{
private:

	bool gameRuns = false;
	std::vector<Player*> players;

public:
	Game();

	void startNewGame(std::vector<Player*> players);
	void saveGame(std::string fileName);
	void openGame(std::string fileName);
	int checkIfPlayerHasWon();



};
#endif // !GAME_H
