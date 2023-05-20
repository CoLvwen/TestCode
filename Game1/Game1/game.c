#define _CRT_SECURE_NO_WARNINGS
#include "game.h"


void Initboard(char board[ROW][LIN], int row, int lin)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < lin; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void Disboard(char board[ROW][LIN], int row, int lin)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < lin; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < lin - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int a = 0; a < lin; a++)
			{
				printf("---");
				if (a < lin - 1)
				{
					printf("|");
				}

			}
		}
		printf("\n");
	}
}

void Player(char board[ROW][LIN], int row, int lin)
{
	int x = 0;
	int y = 0;
	printf(" 玩家回合\n");
	while (1)
	{
		printf("请输入坐标：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && y >= 1 && x <= ROW && y <= LIN)
		{
			if (board[y - 1][x - 1] == ' ')
			{
				board[y - 1][x - 1] = '*';
				break;
			}
			else
			{
				printf("\n该坐标已被占用\n");
			}
		}
		else
		{
			printf("坐标不存在\n");
		}
	}
	Disboard(board, ROW, LIN);
}

void AIPlayer(char board[ROW][LIN], int row, int lin)
{
	printf("电脑回合\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;
		y = rand() % row;
		if (board[y - 1][x - 1] == ' ')
		{
			board[y - 1][x - 1] = '#';
			break;
		}
	}
	Disboard(board, ROW, LIN);
}

//int Judge(char board[ROW][LIN], int row, int lin)
//{
//	for (int i = 0;i < row; i++)
//	{
//		int j = 0;
//		if (board[i][j] == board[i][j + 1]&& board[i][j] == board[i][j + 2]&& board[i][j] == '*')
//		{
//			return 1;
//		}
//		else if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == 'o')
//		{
//			return 0;
//		}
//	}
//	for (int i = 0; i < row; i++)
//	{
//		int j = 0;
//		if (board[j][i] == board[j + 1][i] && board[j][i] == board[j + 2][i] && board[j][i] == '*')
//		{
//			return 1;
//		}
//		else if (board[j][i] == board[j + 1][i] && board[j][i] == board[j + 2][i] && board[j][i] == 'o')
//		{
//			return 0;
//		}
//	}
//	if (board[1][1] == board[2][2] && board[1][1] == board[3][3] && board[1][1] == '*')
//	{
//		return 1;
//	}
//	else if (board[1][1] == board[2][2] && board[1][1] == board[3][3] && board[1][1] == 'o')
//	{
//		return 0;
//	}
//	return -1;
//}

int Ju(char board[ROW][LIN], int row, int lin)
{
	for (int i = 0; i < row-1; i++)
	{
		if (board[i][i] != board[i + 1][i + 1]&& board[i][lin - 1 - i] != board[i + 1][lin - 1 - i - 1])
		{
			break;
		}
		
		if (i == row - 2)
		{
			if (board[i][i] == '*'|| board[i][lin - 1 - i]=='*')
			{
				return 1;
			}
			else if (board[i][i] == '#' || board[i][lin - 1 - i] == '#')
			{
				return 2;
			}
		}
		
	}
	for (int i = 0; i < row - 1; i++)
	{
		for (int j = 0; j < lin - 1; j++)
		{
			if (board[i][j] != board[i][j + 1])
			{
				break;
			}
			if (j == lin - 2)
			{
				if (board[i][j] == '*')
				{
					return 1;
				}
				else if(board[i][j] == '#')
				{
					return 2;
				}
			}
		}
	}
	for (int i = 0; i < row - 1; i++)
	{
		for (int j = 0; j < lin - 1; j++)
		{
			if (board[j][i] != board[j+1][i])
			{
				break;
			}
			if (j == lin - 2)
			{
				if (board[j][i] == '*')
				{
					return 1;
				}
				else if (board[j][i] == '#')
				{
					return 2;
				}
			}
		}
	}
	return 0;
}
