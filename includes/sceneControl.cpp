#include <iostream>
#include <windows.h>

#include "sceneControl.h"
#include "Vec2d.h"

using namespace std;

void printScene(Vec2d minPos, Vec2d maxPos, Vec2d playerPos, Vec2d pointPos, int score, HANDLE stdHandle) // prints the scene depending on positions of game elements.
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
                cout << '0';
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

bool IsProgramFocused() // true for program in focus, false for not being in focus.
{
    HWND hWnd = GetForegroundWindow(); 
    if (hWnd == NULL) {
        return false;
    }

    DWORD processId;
    GetWindowThreadProcessId(hWnd, &processId);

    DWORD currentProcessId = GetCurrentProcessId();

    return processId == currentProcessId;
}