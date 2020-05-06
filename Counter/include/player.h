#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>

class Player
{
private:

    std::string name;
    int actualPoints;
    std::vector<int> *pointList;

public:

	//Player with Name -> points are set to 0
    Player(std::string name);

	//Player with Name and Points
	Player(std::string name, int points);

	std::string& getName();
};

#endif
