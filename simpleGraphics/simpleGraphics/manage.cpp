#include "stdafx.h"
#include "manage.h"

char board[3][3];	//A tic-tac-toe board is just a 3X3 grid
bool gameOver;		//Is the game over?



//Start the game over
void GameReset() {
	gameOver = false;
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			board[i][j] = EMPTY;
		}
	}
}

//Draw the game board, 
void GameDrawBoard(HWND hwnd, HDC hdc) {
	

	//Add the title
	
	TextOut(hdc, 192, 40, _T("Guess the Picture"), 17);// last number outputs the number of characters
	


	MoveToEx(hdc,200,100,NULL); LineTo(hdc,200,400); // draws board
	MoveToEx(hdc,300,100,NULL); LineTo(hdc,300,400);
	MoveToEx(hdc,100,200,NULL); LineTo(hdc,400,200);
	MoveToEx(hdc,100,300,NULL); LineTo(hdc,400,300);


	HBITMAP hImage= (HBITMAP)LoadImage(NULL,L"C:\\Users\\hzeitler15\\Documents\\GitHub\\Picture-Game\\simpleGraphics\\simpleGraphics\\whole_pic",IMAGE_BITMAP,LR_DEFAULTSIZE ,LR_DEFAULTSIZE ,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
            SendMessage(hwnd,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)hImage);


	//Draw the Plays
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			int A;
			//if(board[i][j] == A)
			DrawPic(hdc, i, j, A);
			//Draw PIC
		}
	}
}


void DrawPic(HDC hdc, int i, int j, int A)
{
	
}

//Is there a winner?
void GameCheckWinner(HWND hwnd) 
{
}

