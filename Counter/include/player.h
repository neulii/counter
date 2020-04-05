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
    
    Player(std::string name);
    Player(std::string name, int points);
    
    
};

#endif

