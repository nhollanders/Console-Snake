#include <windows.h>

#include "Vec2d.h"
#include "player_obj.h"

using namespace std;

player_obj::player_obj()
{
    playerPos = {0, 0};
    nextPos = {0, 0};
    moveDist = 1;
}

player_obj::~player_obj()
{

}

// positions //

Vec2d player_obj::getPos() // returns cur position
{ 
    return playerPos; 
}

void player_obj::setPos(Vec2d vecPar) // sets position
{ 
    playerPos = vecPar; 
}

void player_obj::setMoveDist(int dist)
{
    moveDist = dist || 1;
}

int player_obj::getMoveDist()
{
    return moveDist;
}

// next pos handleing //

Vec2d player_obj::getNextPos() // returns nextPos
{ 
    return nextPos; 
}

bool player_obj::posChanged() // returns true/false if the pos will change next move update
{ 
    return nextPos != playerPos; 
}

// Pos Updates //

void player_obj::updateInput() // must be in a while loop
{
    nextPos = playerPos;

    for (int i = 1; i < 5; i++) // key input for all the arrow keys
    {
        if (GetAsyncKeyState(i+36) & 0b1)
        {
            switch (i) // switch is faster than if statment
            {
            case 1: // left
                nextPos.x -= moveDist;
                break;
            case 2: // up
                nextPos.y -= moveDist;
                break;
            case 3: // right
                nextPos.x += moveDist;
                break;
            case 4: // down
                nextPos.y += moveDist;
                break;
            default:
                break;
            }
        }
    }
}

void player_obj::move()
{
    playerPos = nextPos;
}