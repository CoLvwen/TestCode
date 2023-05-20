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
		//玩家排雷
		int i = 0, j = 0;
		do
		{
			if (a > 0)
			{
				printf("\n坐标不存在\n");
			}
			printf("请输入坐标;>");
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
		//判断
		int res = Ju(play, mine, board, board2, i - 1, j - 1);
		if (res == 1)
		{
			printf("你输了，弟弟\n");
			break;
		}
		else if (res == 0)
		{
			printf("你赢了，太强了\n");
			break;
		}
	} while (1);
	printf("\n\n\n1.回主菜单 0.退出游戏\n");
	printf("请输入;>");
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
		printf("请输入:>");
		scanf("%d", &i);
		int* p = &i;
		switch (i)
		{
		case 1:
			printf("\n开始游戏\n\n");
			game(p);
			break;
		case 0:
			break;
		default:
			printf("请重新选择\n");
			break;
		}
	} while (i);
	system("cls");
	printf("退出游戏\n");
	return 0;
}