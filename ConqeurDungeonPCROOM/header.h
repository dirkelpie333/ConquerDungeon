#pragma once

#ifndef __STDIO_H__
#define __STDIO_H__

#include<stdio.h>

#endif


#ifndef __STDLIB_H__
#define __STDLIB_H__

#include<stdlib.h>

#endif


#ifndef __STRING_H__
#define __STRING_H__

#include<string.h>

#endif


#ifndef __CONIO_H__
#define __CONIO_H__

#include<conio.h>

#endif


#ifndef __WINDOWS_H__
#define __WINDOWS_H__

#include<windows.h>

#endif


#ifndef __TIME_H__
#define __TIME_H__

#include<time.h>

#endif


#ifndef KEY_CODE
#define KEY_CODE

#define UP 72
#define DOWN 80
#define BACKSPACE 8
#define ENTER 13
#define ESC 27
#define SPACE 32

#endif


#ifndef UTIL
#define UTIL

#define SRAND srand((unsigned int)time(NULL));

#endif


#ifndef COLOR_CODE
#define COLOR_CODE

#define BLACK    0
#define FBLUE    1
#define FGREEN   2
#define FJADE    3
#define FRED     4
#define FPURPLE  5
#define FYELLOW  6
#define FWHITE   7
#define GRAY     8
#define BLUE     9
#define GREEN   10
#define JADE    11
#define RED     12
#define PURPLE  13
#define YELLOW  14
#define WHITE   15

#endif

int saveN; // 현재 세이브파일의 번호

typedef struct _SaveFile {
	char name[20];
	int lv, exp, curHp, hp, curMp, mp, df, atk, karma, money, crit, agil, con, floor, skill1, skill2;
} Save;



typedef struct _Monster {
	char name[20];
	int lv, exp, hp, mp, df, atk, money, crit, agil, con;
	char skill[3][200];
	char image[20][23];
} Monster;



//main.c
void drawTitle();
void gameInfo();

//dungeon.c
Monster setMonster();
void menu();
void fight(Monster);
void skill(int);
void stat();

//save.c
void checkFile();
void load();
void save(int);
void saveSelect();
void accSave(int);
void makeSave(int);

//util.c
void clearBattle(int);
void queueLog(char[]);
void printLog();
void drawMonster(Monster, int);
void makeCon();
void drawFloor();
void off();
void err();
int arrow(int check, int y, int l); // 시작선택지, 첫번째 화살표의 x좌표, 선택지 개수 
void gotoxy(int, int);
void cursorView(int);
void color(int);



