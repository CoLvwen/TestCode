#define _CRT_SECURE_NO_WARNINGS
#define ROW 3
#define LIN 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void INIboard(char board[ROW][LIN], int row, int lin);
void DPboard(char board[ROW][LIN], int row, int lin);
void INImine(int mine[ROW][LIN], int row, int lin);
void INIplay(int play[ROW][LIN], int row, int lin);
void DPmine(int mine[ROW][LIN], int row, int lin);
void INIboard2(int mine[ROW][LIN], char board2[ROW][LIN], int row, int lin);
void DPboard2(char board2[ROW][LIN], int row, int lin);
//void Player(char board[ROW][LIN], int play[ROW][LIN], int row, int lin);
//int Judge(int play[ROW][LIN], int mine[ROW][LIN], char board[ROW][LIN], int i, int j);
int count(int mine[ROW][LIN], int row, int lin);
//void check(char board[ROW][LIN], int mine[ROW][LIN], int row, int lin);
int Ju(int play[ROW][LIN], int mine[ROW][LIN], char board[ROW][LIN], char board2[ROW][LIN], int i, int j);
void Safe(char board[ROW][LIN], char board2[ROW][LIN], char mid[ROW][LIN], int i, int j);