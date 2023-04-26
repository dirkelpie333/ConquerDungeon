#include "header.h"


Save reset()
{
	Save p;
	p.lv = 1;
	p.exp = 0;
	p.curHp = 30;
	p.hp = 30;
	p.curMp = 20;
	p.mp = 20;
	p.df = 2;
	p.atk = 5;
	p.karma = 0;
	p.money = 100;
	p.crit = 10;
	p.agil = 10;
	p.con = 0;
	p.floor = 1;
	p.skill1 = 0;
	p.skill2 = 0;
	return p;
}

extern Save p;

char name[3][50] = { "빈 세이브파일", "빈 세이브파일", "빈 세이브파일" };

/*
	to-do list
	
	 - delete savefile

*/

void checkFile()
{
	// name, data1, data2, data3;

	FILE* fp;

	fp = fopen("name.dat", "wb");
	fread(&name[1], &name[2], &name[3], sizeof(name), 3, fp);
	fclose(fp);
	printf("%s %s %s", name[1], name[2], name[3]);

}

void load()
{

	FILE* save = fopen("savename.txt", "r");

	if (save) //load 1st savefile 
	{
		for (int i = 1; i <= 3; i++)
		{
			fscanf(save, "%[^\n] %[^\n] %[^\n]", &name[1], &name[2], &name[3]);
		}
		fclose(save);
	}
	else
	{
		save = fopen("savename.txt", "w");
		fprintf(save, "빈 세이브파일\n빈 세이브파일\n빈 세이브파일\n");
		fclose(save);
	}

}

void save(int n)
{
	FILE* save;

	switch (n)
	{
	case 1:
		save = fopen("save1.txt", "w");
		break;
	case 2:
		save = fopen("save2.txt", "w");
		break;
	case 3:
		save = fopen("save3.txt", "w");
		break;
	}
	fprintf(save, "%s\n%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", p.name, p.lv, p.exp, p.curHp, p.hp, p.curMp, p.mp, p.df, p.atk, p.karma, p.money, p.crit, p.agil, p.con, p.floor, p.skill1, p.skill2);
	fclose(save);
}

void saveSelect()
{
	system("cls");
	printf("\n\n    1. %s", name[1]);
	printf("\n\n    2. %s", name[2]);
	printf("\n\n    3. %s", name[3]);

	accSave(arrow(1, 2, 3));
}

void accSave(int n)
{
	FILE* save;
	switch (n)
	{
	case 1:
		saveN = 1;
		if (!strcmp(name[1], "빈 세이브파일")) makeSave(n);
		else save = fopen("save3.txt", "r");
		break;
	case 2:
		saveN = 2;
		if (!strcmp(name[2], "빈 세이브파일")) makeSave(n);
		else save = fopen("save3.txt", "r");
		break;
	case 3:
		saveN = 3;
		if (!strcmp(name[3], "빈 세이브파일")) makeSave(n);
		else save = fopen("save3.txt", "r");
		break;
		fscanf(save, "%s\n%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &p.name, &p.lv, &p.exp, &p.curHp, &p.hp, &p.curMp, &p.mp, &p.df, & p.atk, &p.karma, &p.money, &p.crit, &p.agil, &p.con, &p.floor, &p.skill1, &p.skill2);
		fclose(save);
	
	}
	menu();
}

void makeSave(int n)
{
	system("cls");
	printf("\n\n    던전을 정복하고 사악한 용을 물리치십시오!\n\n    용사님의 이름을 입력해주세요 : \n\n\n    ");
	cursorView(1);
	fflush(stdin);
	scanf("%[^\n]", p.name);
	strcpy(name[n], p.name);
	cursorView(0);
}