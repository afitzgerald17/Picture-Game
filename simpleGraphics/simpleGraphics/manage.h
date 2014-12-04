#include "stdafx.h"
#include <CommDlg.h>
#include <vector>
using namespace std;

//Character values for the board array
const char EMPTY = '\0';	//no one's moved here 
const char X = 'x';			//an X is here
const char O = 'o';			//an O is here

const int XBALLSTART = 177;
const int YBALLSTART = 277;
const int XBALLINC = 3;
const int YBALLINC = 3;
const int BALLWIDTH = 20;
const int BALLHEIGHT = 20;

extern bool board[3][3];	//A tic-tac-toe board is just a 3X3 grid
extern bool xMove;			//Is it X's turn?
extern bool gameOver;		//Is the game over?
extern int xRect, yRect;	//Rectangle to draw ball in
extern int xInc, yInc;		//How much to move ball on each timer tick
//extern HFONT fntChosen;
extern char key;
extern vector<HBITMAP> images;


void GameReset();	//Start the game over
void GameDrawBoard(HWND hwnd, HDC hdc);	//Draw the game board, with X's and O's
void GameSetMove(int i, int j);	//Set the next move
void GameCheckWinner(HWND hwnd);	//Is there a winner?
void DrawPic(HDC hdc, int i, int j );
void GameDrawX(HDC hdc, int i, int j);
void GameDrawO(HDC hdc, int i, int j);
void GameDrawBall(HWND hwnd, HDC hdc);
//void GameCreateFont();
void GameSetKey(WPARAM wParam);
