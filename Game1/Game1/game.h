#pragma once
#define ROW 3
#define LIN 3
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Initboard(char board[ROW][LIN], int row, int lin);
void Disboard(char board[ROW][LIN], int row, int lin);
void Player(char board[ROW][LIN], int row, int lin);
void AIPlayer(char board[ROW][LIN], int row, int lin);
// Judge(char board[ROW][LIN],int row,int lin);
int Ju(char board[ROW][LIN], int row, int lin);