#pragma once
#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <string>
#include <cstring>
#include <windows.h>
using namespace std;
void witerEdge();
void GameStart();
void MoveCube(int px, int py, int w, int h, int len,int dir, char c, int FlashMode, int speed);

void GUI_Init(int Mode);
void GUI_Clear(int x, int y, int w, int h, int Mode);
void GUI_DrawRect(int x, int y, int w, int h, string arr, int Mode);

void GUI_PaddingAll(char c, int Mode);
void GUI_PaddingPart(int x, int y, int w, int h, char c, int FlashMode, int DisPalyMode);

#endif // !LIB_H