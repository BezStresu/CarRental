#ifndef _Screen_h_
#define _Screen_h_
#ifndef UNICODE
#define UNICODE
#endif
#define WIN32_LEAN_AND_MEAN
#define STRICT
#define _CRT_SECURE_NO_WARNINGS
//#include <optional>
#include <malloc.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
using namespace std;

extern void fullscreen();
extern const string currentDataTime();
extern void gotoxy(int x, int y);
extern void GotoXY(int x, int y);
extern void Boarder();
extern void art();
extern void main_menu_load();
extern void pre_login();
extern void updating_data_base();
extern void pre_logout();
extern void welcome();
extern void exit_imag();




#endif