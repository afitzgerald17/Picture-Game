#include "stdafx.h"
#include "manage.h"

bool board[3][3];	//A tic-tac-toe board is just a 3X3 grid
bool gameOver;		//Is the game over?



//Start the game over
void GameReset() {
	gameOver = false;
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			board[i][j] = false;
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


	


	//Draw the Plays
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			if (board[i][j] == true)
				DrawPic(hdc, i, j);
		}		
	}
}


void DrawPic(HDC hdc, int i, int j)
{
	
		BITMAP bmp;
		HGDIOBJ oldBitmap;
		HDC hdcMem;
		hdcMem = CreateCompatibleDC(hdc);
		oldBitmap = SelectObject(hdcMem, images[0]);

        GetObject(images[0], sizeof(bmp), &bmp);
        BitBlt(hdc, 100, 100, bmp.bmWidth, bmp.bmHeight, hdcMem, 0, 0, SRCCOPY);

		SelectObject(hdcMem, oldBitmap);
        DeleteDC(hdcMem);

}
//Set the next move
void GameSetMove(int i, int j) {
	board[i][j] = true;
	//Make sure the move is legal
	//if (i >= 0 && i <= 2 && j >= 0 && j <= 2) {
	//	//Make sure the game is still playing
	//	if (gameOver == false) {
	//		if (xMove)
	//			board[i][j] = true;
	//		else
	//			board[i][j] = O;

	//		//Next player's turn
	//		xMove = !xMove;
		//}
	//}
}
//Is there a winner?
void GameCheckWinner(HWND hwnd) 
{
}

