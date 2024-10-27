#ifndef _sceneControl
#define _sceneControl

#include <iostream>
#include <windows.h>

#include "Vec2d.h"

void printScene(Vec2d minPos, Vec2d maxPos, Vec2d playerPos, Vec2d pointPos, int score, HANDLE stdHandle);
bool IsProgramFocused();

#endif