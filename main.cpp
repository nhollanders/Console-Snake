#include <iostream>
#include <windows.h>
#include <cstdio>

using namespace std;

int main()
{
    bool isRunning = true;

    int moveDist = 1; // how far each move lets you go

    int minPosX = 1;
    int minPosY = 1;

    int maxPosX = 10;
    int maxPosY = 10;

    int playerPosX = 1;
    int playerPosY = 1;

    while (isRunning) // game loop
    {
        for (int i = 1; i < 5; i++) // key input for all the arrow keys
        {
            if (GetAsyncKeyState(i+36) & 0b1)
            {
                switch (i) // switch is faster than if statment
                {
                case 1: // left
                    playerPosX = max(playerPosX - moveDist, minPosX);
                    break;
                case 2: // up
                    playerPosY = max(playerPosY - moveDist, minPosY);
                    break;
                case 3: // right
                    playerPosX = min(playerPosX + moveDist, maxPosX);
                    break;
                case 4: // down
                    playerPosY = min(playerPosY + moveDist, maxPosY);
                    break;
                default:
                    break;
                }

                // something changed so we can bother updating the screen now
                system("cls"); // clear console

                for (int y = minPosY; y < maxPosY + 1; y++)
                {
                    for (int x = minPosX; x < maxPosX + 1; x++)
                    {
                        if (x == playerPosX && y == playerPosY)
                        {
                            cout << '0';
                        }
                        else
                        {
                            cout << ' ';
                        }
                    }

                    cout << '|' << endl;
                }

                for (int i = 1; i < maxPosX + 1; i++)
                {
                    cout << '-';
                }
                cout << '+' << endl;

                cout << "[ " << playerPosX << " : " << playerPosY << " ]" << endl;
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