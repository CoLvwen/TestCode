#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void menu()
{
	printf("***********************\n");
	printf("***1.play     0.exit***\n");
	printf("***********************\n\n");
	printf("������:");
}


int game()
{
	printf("\nwelcome\n");
	char board[ROW][LIN]={0};
	Initboard(board,ROW,LIN);
	Disboard(board,ROW,LIN);
	while (1)
	{
		/*int a = -1;*/
		int ret=0;
		Player(board,ROW,LIN);
		ret = Ju(board, ROW, LIN);
		if (ret == 1)
		{
			printf("��ϲ�㣬��Ӯ��");
			break;
		}
		else if (ret == 2)
		{
			printf("�ܵܣ�������");
			break;
		}
		/*a = Judge(board, ROW, LIN);
		if (a == 1)
		{
			printf("��ϲ�㣬��Ӯ��\n");
			break;
		}
		else if (a = 0)
		{
			printf("�ܵܣ�������\n");
			break;
		}*/
		AIPlayer(board, ROW, LIN);
		ret = Ju(board, ROW, LIN);
		if (ret == 1)
		{
			printf("��ϲ�㣬��Ӯ��");
			break;
		}
		else if (ret == 2)
		{
			printf("�ܵܣ�������");
			break;
		}
		/*a=Judge(board, ROW, LIN);
		if (a == 1)
		{
			printf("��ϲ�㣬��Ӯ��\n");
			break;
		}
		else if (a = 0)
		{
			printf("�ܵܣ�������\n");
			break;
		}*/
	}
	printf("\n1.�������˵� 0.�˳�\n");
	printf("�����룺");
	int i = 0;
	scanf("%d", &i);
	if (i == 1)
		return 1;
	else
		return 0;
}

int test()
{
	
	int input = 0;
	int a = 0;
	do
	{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			a=game();
			if (a == 1)
			{
				return 1;
			}
			return 0;
		case 0:
			break;
		default:
			printf("�����롰1����0��\n");
			break;
		}
	} while (input);
	return 0;
}

int main()
{
	srand((unsigned int)time(NULL));
	int i = 1;
	while (i == 1)
	{
		i = 0;
		menu();
		int a = test();

		if (a == 1)
		{
			i = 1;
		}
	} 
	printf("�˳�\n");
	return 0;
}

