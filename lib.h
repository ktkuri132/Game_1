#pragma once
#ifndef LIB_H
#define LIB_H

#include <iostream>
#include <string>
#include <cstring>
#include <windows.h>

#define ConsoleLength	209
#define ConsoleWidth	56

typedef struct Cube
{
	CHAR_INFO sCube;
	int px;
	int py;
	int w;
	int h;
	int len;
	int dir;
	char c;
	int speed;
};

using namespace std;

void Guicout(const char* arr, int m, int n);



COORD GetConsoleSize();

void ReadConsoleInputExample();


void full_screen();
void SetSize(unsigned uCol, unsigned uLine);

void GUI_printf(int FlashMode, int len, int ecx, int ecy, int Color, const char* str, ...);


int CheckConsoleEncoding();
std::string utf8_to_gbk(const std::string& utf8_str);


void witerEdge();
void GameStart();
void MoveCube(int FlashMode, Cube* cube);

void RefreshScreen();
void GUI_Init(int Mode);
void GUI_Clear(int x, int y, int w, int h, int Mode);
void GUI_DrawRect(int x, int y, int w, int h, string arr, int Mode);

void GUI_PaddingAll(char c, int Mode);
void GUI_PaddingPart(int x, int y, int w, int h, char c, int FlashMode, int DisPalyMode);

#endif // !LIB_H