#include <windows.h>

#include "Vec2d.h"
#include "player_obj.h"

using namespace std;

player_obj::player_obj()
{
    playerPos = {0, 0};
    nextPos = {0, 0};
}

player_obj::~player_obj() { }

Vec2d player_obj::getPos() { return playerPos; } // returns cur position
void player_obj::setPos(Vec2d vecPar) { playerPos = vecPar; } // sets position

Vec2d player_obj::getNextPos() { return nextPos; } // returns nextPos
bool player_obj::posChanged()
{
    return nextPos != playerPos;
}