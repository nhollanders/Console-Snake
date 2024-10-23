#include <iostream>
#include <windows.h>
#include <cstdio>
#include <vector>
#include <random>
#include <ctime>

#include "includes/Vec2d.h"

using namespace std;

void printScene(Vec2d minPos, Vec2d maxPos, Vec2d playerPos, Vec2d pointPos, int score, HANDLE stdHandle)
{
    SetConsoleCursorPosition(stdHandle, {0, 0});

    cout << '+';
    for (int i = 1; i < maxPos.x + 1; i++)
    {
        cout << '-';
    }
    cout << '+' << endl;
    for (int y = minPos.y; y < maxPos.y + 1; y++)
    {
        cout << '|';
        for (int x = minPos.x; x < maxPos.x + 1; x++)
        {
            if (x == playerPos.x && y == playerPos.y)
            {
                SetConsoleTextAttribute(stdHandle, 0x04); // sets color for next print to console
                cout << '#';
                SetConsoleTextAttribute(stdHandle, 0x0F); // returns to normal
            }
            else if (x == pointPos.x && y == pointPos.y)
            {
                SetConsoleTextAttribute(stdHandle, 0x02); // sets color for next print to console
                cout << 'X';
                SetConsoleTextAttribute(stdHandle, 0x0F); // returns to normal
            }
            else
            {
                cout << ' ';
            }
        }
        cout << '|' << endl;
    }
    cout << '+';
    for (int i = 1; i < maxPos.x + 1; i++)
    {
        cout << '-';
    }
    cout << '+' << endl;
    cout << "[ " << playerPos.x << " : " << playerPos.y << " ]" << endl;
    cout << "[ Score: " << score << "]" << endl;
}

int main()
{
    srand(time(NULL));

    bool isRunning = true;
    HANDLE stdHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO ci;
    GetConsoleCursorInfo(stdHandle, &ci);
    //ci.bVisible = 0;
    SetConsoleCursorInfo(stdHandle, &ci);

    int moveDist = 1; // how far each move lets you go

    struct Vec2d pointCurPos = {10, 10};

    struct Vec2d minPos = {1, 1};
    struct Vec2d maxPos = {40, 20};

    struct Vec2d playerPos = {1, 1};

    int score = 0;

    printScene(minPos, maxPos, playerPos, pointCurPos, score, stdHandle); // display the first scene

    while (isRunning) // game loop
    {
        for (int i = 1; i < 5; i++) // key input for all the arrow keys
        {
            if (GetAsyncKeyState(i+36) & 0b1)
            {
                switch (i) // switch is faster than if statment
                {
                case 1: // left
                    playerPos.x = max(playerPos.x - moveDist, minPos.x);
                    break;
                case 2: // up
                    playerPos.y = max(playerPos.y - moveDist, minPos.y);
                    break;
                case 3: // right
                    playerPos.x = min(playerPos.x + moveDist, maxPos.x);
                    break;
                case 4: // down
                    playerPos.y = min(playerPos.y + moveDist, maxPos.y);
                    break;
                default:
                    break;
                }

                if ( playerPos.x == pointCurPos.x && playerPos.y == pointCurPos.y )
                {
                    score += 1;

                    pointCurPos.x = minPos.x + rand() % (maxPos.x - minPos.x + 1);
                    pointCurPos.y = minPos.y + rand() % (maxPos.y - minPos.y + 1);
                }

                printScene(minPos, maxPos, playerPos, pointCurPos, score, stdHandle);
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

// while (!(GetAsyncKeyState(VK_ESCAPE) & 0b1))
// {
//     for (int i = 0; i < 256; i++)
//     {
//         if (GetAsyncKeyState(i) & 0b1)
//         {
//             if (isupper(i))
//             {
//                 cout << (char)i;
//             }
//             else if (i == VK_RETURN)
//             {
//                 cout << endl;
//             }
//         }
//     }
// }