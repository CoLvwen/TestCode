#include "game.h"

void INIboard(char board[ROW][LIN], int row, int lin)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < lin; j++)
		{
			board[i][j] = '*';
		}
	}
}

void DPboard(char board[ROW][LIN], int row, int lin)
{
	printf("\n\n");
	for (int a = 0; a <= row; a++)
	{
		printf("%d   ", a);
	}
	printf("\n\n");
	for (int i = 0; i < row; i++)
	{
		printf("%d   ", i+1);
		for (int j = 0; j < lin; j++)
		{
			printf("%c   ", board[i][j]);
		}
		printf("\n\n");
	}
}

void INImine(int mine[ROW][LIN], int row, int lin)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < lin; j++)
		{
			mine[i][j] = 0;
		}
	}
	int a = 0;
	do
	{
		int i = rand() % 10;
		int j = rand() % 10;
		if (mine[i][j] == 0)
		{
			mine[i][j] = 1;
			a++;
		}
	} while (a < 10);//布雷10个
}

void INIplay(int play[ROW][LIN], int row, int lin)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < lin; j++)
		{
			play[i][j] = -1;
		}
	}
}

void DPmine(int mine[ROW][LIN], int row, int lin)
{
	printf("\n\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < lin; j++)
		{
			printf("%d   ", mine[i][j]);
		}
		printf("\n\n");
	}
}

//void Player(char board[ROW][LIN],  int play[ROW][LIN], int row, int lin)
//{
//	do
//	{
//		if (board[row - 1][lin - 1] == '*' )
//		{
//			play[row - 1][lin - 1] = 1;
//			break;
//		}
//		printf("请重新输入:>");
//		break;
//	} while (1);
//}

//int Judge(int play[ROW][LIN], int mine[ROW][LIN], char board[ROW][LIN], int i, int j)
//{
//	if (play[i][j] == mine[i][j])
//	{
//		return 1;
//	}
//	
//	/*if (i > 0 && j > 0 && i < ROW - 1 && j < LIN - 1)
//	{*/
//	int num = 0;
//		num = count(mine,i,j);
//		if (num == 0)
//		{
//			board[i][j] = '0';
//			for (int row=i-1; row <= i + 1; row++)
//			{
//				for (int lin=j-1; lin <= j + 1; lin++)
//				{
//					if (row == i && lin == j)
//					{
//						continue;
//					}
//					if (lin<0 || lin>LIN - 1|| row<0 || row>ROW - 1)
//					{
//						continue;
//					}
//					check(board, mine, row, lin);
//				}
//			}
//			
//		}
//		else if(num>0)
//		{
//			board[i][j] = num+'0';
//		}
//	//}
//		return 2;
//}
//
int count(int mine[ROW][LIN],int i,int j)
{
	int num = 0;
	for (int row = i - 1; row <= i + 1; row++)
	{
		if ( row<0 || row>ROW - 1)
		{
			continue;
		}
		for (int lin = j - 1; lin <= j + 1; lin++)
		{
			if (lin<0 || lin>LIN - 1)
			{
				continue;
			}
			if (mine[row][lin] == 1)
			{
				num++;
			}
		}
	}
	return num;
}
//
//void check(char board[ROW][LIN], int mine[ROW][LIN], int row, int lin)
//{
//	int num = count(mine, row, lin);
//	if (num == 0)
//	{
//		board[row][lin] = '0';
//		for (int i = row - 1; i <= row + 1; i++)
//		{
//			if (i<0 || i>ROW - 1)
//			{
//				continue;
//			}
//			for (int j = lin - 1; j<= lin + 1; j++)
//			{
//				if (row == i && lin == j)
//				{
//					continue;
//				}
//				if (j<0 || j>LIN - 1)
//				{
//					continue;
//				}
//				check(board, mine, i, j);
//			}
//		}
//
//	}
//	else if (num > 0)
//	{
//		board[row][lin] = num + '0';
//	}
//}

void INIboard2(int mine[ROW][LIN], char board2[ROW][LIN], int row, int lin)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < LIN; j++)
		{
			if (mine[i][j] == 1)
			{
				board2[i][j] = '*';
				continue;
			}
			int num = count(mine, i, j);
			board2[i][j] = num + '0';
		}
	}
}

void DPboard2(char board2[ROW][LIN], int row, int lin)
{
	printf("\n\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < lin; j++)
		{
			printf("%c   ", board2[i][j]);
		}
		printf("\n\n");
	}
}

int Ju(int play[ROW][LIN], int mine[ROW][LIN], char board[ROW][LIN], char board2[ROW][LIN], int i, int j)
{
	char mid[ROW][LIN] = {0};
	INIboard(mid, ROW, LIN);
	if(play[i][j]==mine[i][j])
	{
		return 1;
	}
	if (board2[i][j] != '0')
	{
		board[i][j] = board2[i][j];
		return 2;
	}
	board[i][j] = board2[i][j];
	mid[i][j] = '1';
	for (int row = i - 1; row <= i + 1; row++)
	{
		if (row<0 || row>ROW - 1)
		{
			continue;
		}
		for (int lin = j - 1; lin <= j + 1; lin++)
		{
			if (row == i && lin == j)
			{
				continue;
			}
			if (lin<0 || lin>LIN - 1)
			{
				continue;
			}
			if (board2[row][lin] == '0')
			{
				board[row][lin] = '0';
				Safe(board, board2,mid, row, lin);
			}
		}
	}
	int w = 0;
	while (w<17)
	{
		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < LIN; j++)
			{
				if (board[i][j] == '0')
				{
					for (int row = i - 1; row <= i + 1; row++)
					{
						if (row<0 || row>ROW - 1)
						{
							continue;
						}
						for (int lin = j - 1; lin <= j + 1; lin++)
						{
							
							if (lin<0 || lin>LIN - 1)
							{
								continue;
							}
							board[row][lin] = board2[row][lin];
							
						}
					}
				}
			}
		}
		w++;
	}
	int num = 0;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < LIN; j++)
		{
			if (board[i][j] == '*' || board[i][j] == '!')
			{
				num++;
			}
		}
	}
	if (num == 10)
	{
		return 0;
	}
	/*while (1)
	{
		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < LIN; j++)
			{
				if (board[i][j] == '0')
				{
					for (int row = i - 1; row <= i + 1; row++)
					{
						if (row<0 || row>ROW - 1)
						{
							continue;
						}
						for (int lin = j - 1; lin <= j + 1; lin++)
						{
							if (lin<0 || lin>LIN - 1)
							{
								continue;
							}
							if (board[i][j] == '*')
							{
								board[i][j] = board2[i][j];
								continue;
							}
							goto zh;
						}
					}
				}
			}

		}
	}
	zh:*/
	return 2;
}

void Safe(char board[ROW][LIN], char board2[ROW][LIN],char mid[ROW][LIN], int i, int j)
{
	if (mid[i][j] != '1')
	{
		for (int row = i - 1; row <= i + 1; row++)
		{
			if (row<0 || row>ROW - 1)
			{
				continue;
			}
			for (int lin = j - 1; lin <= j + 1; lin++)
			{
				if (row == i && lin == j)
				{
					continue;
				}
				if (lin<0 || lin>LIN - 1)
				{
					continue;
				}
				if (board[row][lin] == '0')
				{
					continue;
				}
				if (board2[row][lin] == '0')
				{
					
					mid[row][lin] = '1';
					/*for (int a = row - 1; a <= row + 1; a++)
					{
						if (a<0 || a>ROW - 1)
						{
							continue;
						}
						for (int b = lin - 1; b <= lin + 1; b++)
						{
							if (b<0 || b>LIN - 1)
							{
								continue;
							}
							board[a][b] = board2[a][b];
						}*/
					board[row][lin] = '0';
					//}
					Safe(board, board2,mid, row, lin);
				}
			}
		}
	}
}