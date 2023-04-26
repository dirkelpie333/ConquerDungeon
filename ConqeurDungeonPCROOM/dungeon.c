#include "header.h"

extern Save p;


/*
	���� ���� �ҽ����� ���� �����߰���? ������
	���ʹ� ��ų ���? �̰� ������ ���θ� �ؾ��ҵ�? ��ų���� �Լ��� ������ �ϳ�
*/


Monster setMonster()
{
	Monster rat = { 0, };

	strcpy(rat.name, "�ñ���");
	rat.lv = 1;
	rat.exp = 5;
	rat.hp = 15 + rand() % 3;
	rat.mp = 0;
	rat.df = 0;
	rat.atk = 2;
	rat.money = 10;
	rat.crit = 5;
	rat.agil = 5;

	strcpy(rat.image[0],  "                      ");
	strcpy(rat.image[1],  "                      ");
	strcpy(rat.image[2],  "                      ");
	strcpy(rat.image[3],  "                      ");
	strcpy(rat.image[4],  "                      ");
	strcpy(rat.image[5],  "                      ");
	strcpy(rat.image[6],  "                      ");
	strcpy(rat.image[7],  "                      ");
	strcpy(rat.image[8],  "                      ");
	strcpy(rat.image[9],  "                      ");
	strcpy(rat.image[10], "                      ");
	strcpy(rat.image[11], "      _,  ,_          ");
	strcpy(rat.image[12], "     ((|  |))         ");
	strcpy(rat.image[13], "      /--- Y     _    ");
	strcpy(rat.image[14], "     /@  @  )     )    ");
	strcpy(rat.image[15], "   =O___=   Y_   (    ");
	strcpy(rat.image[16], "     UU |     \"   )   ");
	strcpy(rat.image[17], "        j      )_/    ");
	strcpy(rat.image[18], "       m-m---\"\"       ");
	strcpy(rat.image[19], "                      ");

	Monster rabbit = { 0, };

	strcpy(rabbit.name, "�Ŵ��䳢");
	rabbit.lv = 2;
	rabbit.exp = 9;
	rabbit.hp = 35 + rand() % 5;
	rabbit.mp = 0;
	rabbit.df = 0;
	rabbit.atk = 4;
	rabbit.money = 15;
	rabbit.crit = 15;
	rabbit.agil = 0;

	strcpy(rabbit.image[0], "                      ");
	strcpy(rabbit.image[1], "             ,        ");
	strcpy(rabbit.image[2], "            /|     __,");
	strcpy(rabbit.image[3], "           / |   // / ");
	strcpy(rabbit.image[4], "          Y  |  // /  ");
	strcpy(rabbit.image[5], "          |  | // /   ");
	strcpy(rabbit.image[6], "          >---/ L/    ");
	strcpy(rabbit.image[7], "         /       Y    ");
	strcpy(rabbit.image[8], "        j  @  @  |    ");
	strcpy(rabbit.image[9], "       ( =  ^  = )    ");
	strcpy(rabbit.image[10], "        >._    _/     ");
	strcpy(rabbit.image[11], "       /        Y     ");
	strcpy(rabbit.image[12], "      Y     /   |     ");
	strcpy(rabbit.image[13], "      | ;--/    l     ");
	strcpy(rabbit.image[14], "     /l/   ___/  \"    ");
	strcpy(rabbit.image[15], "    (,,(,,/    .- Y   ");
	strcpy(rabbit.image[16], "      /       /    Y  ");
	strcpy(rabbit.image[17], "     (       (     !, ");
	strcpy(rabbit.image[18], "     _]       ]    ; )");
	strcpy(rabbit.image[19], "    (,,_.~---(,,__/ \" ");

	Monster dog = { 0, };

	strcpy(dog.name, "�鰳");
	dog.lv = 3;
	dog.exp = 14;
	dog.hp = 50 + rand() % 5;
	dog.mp = 0;
	dog.df = 0;
	dog.atk = 7;
	dog.money = 25;
	dog.crit = 10;
	dog.agil = 15;

	strcpy(dog.image[0], "                      ");
	strcpy(dog.image[1], "                      ");
	strcpy(dog.image[2], "                      ");
	strcpy(dog.image[3], "                      ");
	strcpy(dog.image[4], "                      ");
	strcpy(dog.image[5], "                      ");
	strcpy(dog.image[6], "                      ");
	strcpy(dog.image[7], "                      ");
	strcpy(dog.image[8], "                      ");
	strcpy(dog.image[9], "                      ");
	strcpy(dog.image[10], "                      ");
	strcpy(dog.image[11], "                      ");
	strcpy(dog.image[12], "                      ");
	strcpy(dog.image[13], "      /) /)           ");
	strcpy(dog.image[14], "     / @ @ -o        ,");
	strcpy(dog.image[15], "    <    ww_/      ,/;");
	strcpy(dog.image[16], "    <\"    /_____   | |");
	strcpy(dog.image[17], "     |    \"     '\",/ |");
	strcpy(dog.image[18], " ___//      __|  |__/ ");
	strcpy(dog.image[19], "(,,(,,__/_(,,____/    ");

	switch (rand()%3)
	{
	case 0:
		return rat;
		break;
	case 1:
		return rabbit;
		break;
	case 2:
		return dog;
		break;
	}
}



void menu()
{
	while (1)
	{
		system("cls");
		save(saveN);
		drawFloor();
		printf("\n\n    Ž��\n\n    ����\n\n    ����\n\n    �޴��� ������");
		switch (arrow(1, 3, 4))
		{
		case 1:
			fight(setMonster());
			break;
		case 2:
			stat(p);
			break;
		case 3:
			save(saveN);
			break;
		case 4:
			return;
			break;
		}
	}

}

void fight(Monster monster)
{
	char chat[200];
	int i;
	int curAtk;

	int mCurHp = monster.hp;
	//���׸���
	system("cls");
	drawFloor();
	color(GRAY);
	gotoxy(0, 6);
	printf("________________________");
	gotoxy(0, 15);
	printf("________________________");
	gotoxy(0, 22);
	printf("_________________________________________________");
	for (i = 2; i < 23; i++)
	{
		gotoxy(24, i);
		printf("|");
	}

	color(WHITE);
	while (mCurHp >= 0)
	{
		clearBattle(0);
		//monster's information
		drawMonster(monster, WHITE);
		color(WHITE);
		gotoxy(3, 3);
		printf("Lv. %d %s", monster.lv, monster.name);
		gotoxy(2, 5);
		for (i = 1; i <= mCurHp * 10 / monster.hp; i++) printf("��");
		for (; i <= 10; i++) printf("��");
		//player's information
		gotoxy(3, 17);
		printf("Lv. %d %s", p.lv, p.name);
		gotoxy(2, 19);
		for (i = 1; i <= p.curHp * 10 / p.hp; i++) printf("��");
		for (; i <= 10; i++) printf("��");
		gotoxy(2, 21);
		color(JADE);
		for (i = 1; i <= p.curMp * 10 / p.mp; i++) printf("��");
		for (; i <= 10; i++) printf("��");
		color(WHITE);

		// player's turn
		gotoxy(0, 8);
		printf("    ����\n\n    ���\n\n    ������ ���");
		switch (arrow(1, 8, 3)) 
		{
		case 1:
			clearBattle(1);
			gotoxy(0, 8);
			printf("    �ķ�ġ��\n\n    %s\n\n    %s\n\n    �ڷ� ����","��ų ����","��ų ����");
			switch (arrow(1, 8, 4))
			{
			case 1:
				if ( rand()%100 >= p.crit ) 
				{
					curAtk = p.atk + rand() % 3;
					sprintf(chat,"�ķ��ļ� %d ���ظ� �������ϴ�!", curAtk);
					queueLog(chat);
					printLog();
					mCurHp -= curAtk;
				}
				else 
				{
					curAtk = p.atk * 2 + rand() % 3;
					sprintf(chat,"ġ��Ÿ! �ķ��ļ� %d ���ظ� �������ϴ�!",curAtk);
					queueLog(chat);
					printLog();
					mCurHp -= curAtk;
				}
				break;
			case 2:
				skill(p.skill1);
				break;
			case 3:
				skill(p.skill2);
				break;
			case 4:
				break;
			}
			break;
		}

		//monster's turn


	}
	resetLog();
}

void skill(int n)
{
	if (n == 0)
	{
		queueLog("������ ��ų�� �����ϴ�.");
		printLog();
	}
}

void stat(Save p)
{
	int i;
	system("cls");
	drawFloor();
	printf("\n\n  Lv. %d  %s\n\n  ", p.lv, p.name);
	for (i = 1; i <= p.curHp * 10 / p.hp; i++) printf("��");
	for (; i <= 10; i++) printf("��");
	printf("  HP : %d / %d  \n\n  ", p.curHp, p.hp);
	color(JADE);
	for (i = 1; i <= p.curMp * 10 / p.mp; i++) printf("��");
	for (; i <= 10; i++) printf("��");
	printf("  MP : %d / %d  \n\n  ", p.curMp, p.mp);
	color(WHITE);
	printf("���ݷ� : %d\n\n  ���� : %d", p.atk, p.df);
	getch();
}
