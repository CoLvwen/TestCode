#include "game.h"

void menu()
{
	printf("*******************\n");
	printf("***1.play 0.exit***\n");
	printf("*******************\n");
}
 
game(int* p)
{
	char board[ROW][LIN] = { 0 };
	int mine[ROW][LIN] = { 0 };
	int play[ROW][LIN] = { 0 };
	char board2[ROW][LIN] = { 0 };
	INIboard(board,ROW,LIN);
	INImine(mine, ROW, LIN);
	INIplay(play, ROW, LIN);
	//DPmine(mine, ROW, LIN);
	INIboard2(mine,board2, ROW, LIN);
	//DPboard2(board2, ROW, LIN);
	int a = 0;
	do 
	{
		DPboard(board, ROW, LIN);
		//�������
		int i = 0, j = 0;
		do
		{
			if (a > 0)
			{
				printf("\n���겻����\n");
			}
			printf("����������;>");
			scanf("%d%d", &i, &j);
			if (board[i - 1][j - 1] == '*')
			{
				play[i - 1][j - 1] = 1;
				break;
			}
			a++;
		} while (i < 1 || i > ROW || j < 1 || j > LIN);
		//Player(board, play, i,j);
		//int res = Judge(play, mine,board, i - 1, j - 1);
		//�ж�
		int res = Ju(play, mine, board, board2, i - 1, j - 1);
		if (res == 1)
		{
			printf("�����ˣ��ܵ�\n");
			break;
		}
		else if (res == 0)
		{
			printf("��Ӯ�ˣ�̫ǿ��\n");
			break;
		}
	} while (1);
	printf("\n\n\n1.�����˵� 0.�˳���Ϸ\n");
	printf("������;>");
	scanf("%d", p);
	system("cls");
}
int main()
{
	srand((unsigned int)time(NULL));
	int i = 0;
	do
	{
		menu();
		printf("������:>");
		scanf("%d", &i);
		int* p = &i;
		switch (i)
		{
		case 1:
			printf("\n��ʼ��Ϸ\n\n");
			game(p);
			break;
		case 0:
			break;
		default:
			printf("������ѡ��\n");
			break;
		}
	} while (i);
	system("cls");
	printf("�˳���Ϸ\n");
	return 0;
}