#include <iostream>
#include <windows.h>
#include <cstdio>
#include <random>
#include <ctime>

#include "includes/Vec2d.h"
#include "includes/player_obj.h"
#include "includes/sceneControl.h"

using namespace std;

int main()
{
    srand(time(NULL));

    bool isRunning = true;
    HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO ci;
    GetConsoleCursorInfo(stdHandle, &ci);
    ci.bVisible = false;
    SetConsoleCursorInfo(stdHandle, &ci);

    player_obj player = player_obj();
    player.setPos({1,1});

    int moveDist = 1; // how far each move lets you go

    struct Vec2d pointCurPos = {10, 10};

    struct Vec2d minPos = {1, 1};
    struct Vec2d maxPos = {40, 20};

    int score = 0;

    printScene(minPos, maxPos, player.getPos(), pointCurPos, score, stdHandle); // display the first scene

    while (isRunning) // game loop
    {
        if (!IsProgramFocused())
        {
            continue;
        }

        player.updateInput();

        if (player.posChanged())
        {   
            // bound collision
            Vec2d nextPos = player.getNextPos();

            if ((nextPos.x >= minPos.x && nextPos.x <= maxPos.x) && ((nextPos.y >= minPos.y && nextPos.y <= maxPos.y)))
            {
                player.move(); // makes the player actually move

                if ( player.getPos() == pointCurPos )
                {
                    score += 1;
                    
                    pointCurPos.x = minPos.x + rand() % (maxPos.x - minPos.x + 1);
                    pointCurPos.y = minPos.y + rand() % (maxPos.y - minPos.y + 1);
                }

                printScene(minPos, maxPos, player.getPos(), pointCurPos, score, stdHandle);      
            }
        }

        if (GetAsyncKeyState(VK_ESCAPE) & 0b1)
        {
            isRunning = false;
            break;
        }
    }

    return 0;
}