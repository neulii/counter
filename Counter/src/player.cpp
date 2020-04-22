#include "player.h"
#include "wx/wx.h"


Player::Player(std::string name)
    : name(name),actualPoints(0) 
{

    pointList = new std::vector<int>();
   
    //wxLogDebug(std::to_string(pointList->size()).c_str());
}

Player::Player(std::string name, int points)
    : Player(name)
   
{
    actualPoints = points;


}

std::string& Player::getName()
{
	return name;
}
