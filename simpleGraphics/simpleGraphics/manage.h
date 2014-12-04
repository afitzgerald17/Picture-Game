#include "stdafx.h"
#include <CommDlg.h>
#include <vector>
using namespace std;




extern bool board[3][3];	//A tic-tac-toe board is just a 3X3 grid
extern bool gameOver;		//Is the game over?
extern char key;
extern vector<HBITMAP> images;


void GameReset();	//Start the game over
void GameDrawBoard(HWND hwnd, HDC hdc);	//Draw the game board, with X's and O's
void GameSetMove(int i, int j);	//Set the next move
void GameCheckWinner(HWND hwnd);	//Is there a winner?
void DrawPic(HDC hdc, int i, int j );

void GameSetKey(WPARAM wParam);
