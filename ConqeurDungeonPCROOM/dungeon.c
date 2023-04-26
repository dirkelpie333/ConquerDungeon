#include "header.h"

extern Save p;


/*
	몬스터 저장 소스파일 따로 만들어야겠지? 귀찮다
	몬스터당 스킬 어떻게? 이건 포인터 공부를 해야할듯? 스킬별로 함수를 만들어야 하나
*/


Monster setMonster()
{
	Monster rat = { 0, };

	strcpy(rat.name, "시궁쥐");
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

	strcpy(rabbit.name, "거대토끼");
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

	strcpy(dog.name, "들개");
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
		printf("\n\n    탐색\n\n    상태\n\n    저장\n\n    메뉴로 나가기");
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
	//선그리기
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
		for (i = 1; i <= mCurHp * 10 / monster.hp; i++) printf("■");
		for (; i <= 10; i++) printf("□");
		//player's information
		gotoxy(3, 17);
		printf("Lv. %d %s", p.lv, p.name);
		gotoxy(2, 19);
		for (i = 1; i <= p.curHp * 10 / p.hp; i++) printf("■");
		for (; i <= 10; i++) printf("□");
		gotoxy(2, 21);
		color(JADE);
		for (i = 1; i <= p.curMp * 10 / p.mp; i++) printf("■");
		for (; i <= 10; i++) printf("□");
		color(WHITE);

		// player's turn
		gotoxy(0, 8);
		printf("    공격\n\n    방어\n\n    아이템 사용");
		switch (arrow(1, 8, 3)) 
		{
		case 1:
			clearBattle(1);
			gotoxy(0, 8);
			printf("    후려치기\n\n    %s\n\n    %s\n\n    뒤로 가기","스킬 없음","스킬 없음");
			switch (arrow(1, 8, 4))
			{
			case 1:
				if ( rand()%100 >= p.crit ) 
				{
					curAtk = p.atk + rand() % 3;
					sprintf(chat,"후려쳐서 %d 피해를 입혔습니다!", curAtk);
					queueLog(chat);
					printLog();
					mCurHp -= curAtk;
				}
				else 
				{
					curAtk = p.atk * 2 + rand() % 3;
					sprintf(chat,"치명타! 후려쳐서 %d 피해를 입혔습니다!",curAtk);
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
		queueLog("장착한 스킬이 없습니다.");
		printLog();
	}
}

void stat(Save p)
{
	int i;
	system("cls");
	drawFloor();
	printf("\n\n  Lv. %d  %s\n\n  ", p.lv, p.name);
	for (i = 1; i <= p.curHp * 10 / p.hp; i++) printf("■");
	for (; i <= 10; i++) printf("□");
	printf("  HP : %d / %d  \n\n  ", p.curHp, p.hp);
	color(JADE);
	for (i = 1; i <= p.curMp * 10 / p.mp; i++) printf("■");
	for (; i <= 10; i++) printf("□");
	printf("  MP : %d / %d  \n\n  ", p.curMp, p.mp);
	color(WHITE);
	printf("공격력 : %d\n\n  방어력 : %d", p.atk, p.df);
	getch();
}
