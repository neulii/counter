#include "game.h"


Game::Game()
{
	//wxLogDebug(std::to_string(players.size()).c_str());
	



}

Game::Game(std::vector<Player*> players) 
	:players(players)
{

}

Game::Game(const Game* game)
{
	this->gameRuns = game->gameRuns;
	this->players = game->players;


}

void Game::startGame() {
	gameRuns = true;

}


//void Game::startNewGame(std::vector<Player*> players)
//{
//	
//
//}

void Game::addPlayer(Player* player)
{
	players.push_back(player);

}

void Game::saveGame(std::string fileName)
{

}

void Game::openGame(std::string fileName)
{

}

int Game::checkIfPlayerHasWon()
{
	return -1;
}

bool Game::isGameRunning()
{
	return gameRuns;
}

void Game::addPlayer(std::string playerName)
{
	Player* tempPlayer = new Player(playerName);
	players.push_back(tempPlayer);

}

std::vector<Player*>& Game::getPlayers()
{
	return players;

}
