#ifndef GAME_H
#define GAME_H

#include <wx/wx.h>
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
	Game(std::vector<Player*> players);

	void startNewGame(std::vector<Player*> players);
	void addPlayer(Player* player);
	void addPlayer(std::string playerName);
	void saveGame(std::string fileName);
	void openGame(std::string fileName);
	int checkIfPlayerHasWon();

	bool isGameRunning();



};
#endif // !GAME_H
