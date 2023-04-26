#include "header.h"

extern Save p;

int main() {

	color(WHITE);
	cursorView(0);
	SRAND

	checkFile();
	makeCon();
	load();
	drawTitle();

	return 0;
}

void drawTitle()
{
	int a;
	while (1)
	{
		saveN = 0;
		color(WHITE);
		system("cls");
		printf("\n");
		printf(" @----------------------------------------------@ \n\n");
		printf(" 888    d8P  8888888 888      888                 \n");
		printf(" 888   d8P     888   888      888                 \n");
		printf(" 888  d8P      888   888      888    ____  _ ___  \n");
		printf(" 888d88K       888   888      888     | |__| |__  \n");
		printf(" 8888888b      888   888      888     | |  | |__  \n");
		printf(" 888  Y88b     888   888      888                 \n");
		printf(" 888   Y88b    888   888      888                 \n");
		printf(" 888    Y88b 8888888 88888888 88888888            \n\n\n");
                    
		printf(" 8sss    8sss.  8ss.     s888s    s8888s   8ss  8\n");
		printf(" 8   \"o  8    b 8  \"8   8     8  8      8  8 \"8 8\n");
		printf(" 8     b 8    P 8   `b 8        8        8 8  \"88\n");
		printf(" 8     8 8ss8'  8 s888 8        8        8 8   '8\n");
		printf(" 8     P 8   8  8    8 8    ss8 8        8 8    8\n");
		printf(" 8    8  8    8 8    8  8     8  8      8  8    8\n");
		printf(" 8sss\"   8    8 8    8   \"sss\"    \"ssss\"   8    8\n\n");
		printf(" @----------------------------------------------@ \n\n");
		printf("\n    플레이\n\n    게임 정보\n\n    종료");
		color(JADE);
		gotoxy(34, 14);	printf(" ssss ");
		gotoxy(33, 15); printf(" 888888 ");
		gotoxy(33, 16); printf(" 888888 ");
		gotoxy(33, 17); printf(" 888888 ");
		gotoxy(34, 18); printf(" 8888 ");
		color(WHITE);
		a = arrow(1, 24, 3);
		switch (a)
		{
		case 1: saveSelect(); break;
		case 2: gameInfo(); break;
		case 3: off(); break;
		}
	}
}


void gameInfo()
{
	system("cls");
	printf("\n\n                  김영준 1인개발\n\n\n\n            Special Thanks to - Ppudumi");
	getch();
}