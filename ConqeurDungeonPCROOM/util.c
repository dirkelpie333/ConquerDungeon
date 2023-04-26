#include "header.h"

extern Save p;

char log[10][200]={"",};

void makeCon()
{
	system("mode con cols=50 lines=32"); //�ܼ�ũ������
	system("title ConquerDungeon! 2022.10.06.01"); //��������
}


void drawFloor()
{
	int i;
	color(WHITE);
	for (i = 1; i <= 10; i++)
	{
		gotoxy(26+(i*2), 1);
		if (i <= p.floor) {
			printf("��");
		}
		else {
			printf("��");
		}
	}
	if (p.floor >= 10) {
		gotoxy(46, 1);
		printf("��");
	}
	else {
		gotoxy(46, 1);
		printf("��");
	}
	gotoxy(0, 0);
	printf("\n ----------- %d�� ---------- ", p.floor);
}


void off() //���� ���� 
{
	int a;
	system("cls");
	printf("\n ������ �����Ͻðڽ��ϱ�?\n\n    ��\n\n    �ƴϿ�");
	a = arrow(2, 3, 2);
	switch (a)
	{
	case 1: save(saveN); exit(0); break;
	case 2: return; break;
	}
}

void clearBattle(int set)
{
	if (set == 0) {
		for (int i = 2; i < 6; i++) {
			gotoxy(0, i);
			printf("                        \n");
		}
		for (int i = 16; i < 22; i++) {
			gotoxy(0, i);
			printf("                        \n");
		}
	}
	for (int i = 7; i < 15; i++) {
		gotoxy(0, i);
		printf("                        \n");
	}
	/*
	for (int i = 23; i < 32; i++) {
		gotoxy(0, i);
		printf("                                                  \n");
	}
	*/
}

void queueLog(char chat[200])
{
	for (int i = 8; i >= 0; i--) {
		strcpy(log[i + 1], log[i]);
	}
	strcpy(log[0], chat);
}

void printLog()
{
	int i;
	for (i = 24; i <= 30; i++) {
		gotoxy(0, i);
		printf("                                                  ");
	}
	for (i = 0; i <= 3; i++) {

		switch (i) {
		case 0:
		case 1:
		case 2:
			color(GRAY);
			break;
		case 3:
			color(WHITE);
			break;
		}

		gotoxy(0, 24 + i * 2);
		printf("%s",log[3-i]);

	}
}

void resetLog()
{
	for (int i = 0; i < 10; i++)
	{
		strcpy(log[i], "");
	}
}

void drawMonster(Monster monster,int monsterColor)
{
	color(monsterColor);
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 23; j++)
		{
			gotoxy(j + 25, i + 2);
			if (monster.image[i][j] == '@') color(JADE);
			printf("%c", monster.image[i][j]);
			color(monsterColor);
		}

	}
}

void err()
{
	system("cls");
	printf("\n �߸��� �Է��Դϴ�.\n\n");
	getch();
	system("cls");
}


int arrow(int check, int y, int l)//���� ȭ��ǥ ��� 
{
	char a = '0';
	y += (check - 1) * 2;
	gotoxy(1, y);
	printf("��");
	while (a != ENTER && a != SPACE)
	{
		fflush(stdin);//Ű���� �Է°� �ʱ�ȭ 
		a = getch();
		if (a == UP)
		{
			if (check != 1)
			{
				gotoxy(1, y);
				printf("  ");
				y -= 2;
				gotoxy(1, y);
				printf("��");
				check--;
			}
			else
			{
				gotoxy(1, y);
				printf("  ");
				l--;
				y += 2 * l;
				l++;
				gotoxy(1, y);
				printf("��");
				check = l;
			}
		}
		if (a == DOWN)
		{
			if (check < l)
			{
				gotoxy(1, y);
				printf("  ");
				y += 2;
				gotoxy(1, y);
				printf("��");
				check++;
			}
			else
			{
				gotoxy(1, y);
				printf("  ");
				l--;
				y -= 2 * l;
				l++;
				gotoxy(1, y);
				printf("��");
				check = 1;
			}
		}
	}
	gotoxy(1, y);
	printf("  ");
	return check;
}


void gotoxy(int x, int y)//��ġ�̵� 
{
	COORD posXY = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posXY);
}


void cursorView(int show)//Ŀ�� �����
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void color(int a)//���ڻ� ���� 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

