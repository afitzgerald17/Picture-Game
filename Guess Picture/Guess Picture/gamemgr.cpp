#include "stdafx.h"
#include "gamemgr.h"

char board[3][3];	//A tic-tac-toe board is just a 3X3 grid
bool xMove;			//Is it X's turn?
bool gameOver;		//Is the game over?

//HFONT fntChosen;
//char key;

//Start the game over
void GameReset() {
	gameOver = false;
	xMove = true;
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			board[i][j] = EMPTY;
		}
	}

	
}

//Draw the game board, with X's and O's
void GameDrawBoard(HWND hwnd, HDC hdc) {
	//GameDrawBall(hwnd, hdc);

	//Add the title
	HGDIOBJ fntOld = SelectObject(hdc, fntChosen);
	TextOut(hdc, 100, 10, _T("Tic-Tac-Toe"), 11); // guess the picture
	/*if (key != 0) {
		TCHAR s[20];
		int cb = 1;
		TextOut(hdc, 100, 50, _T("Key:"), 4);
		switch (key) {
		case VK_UP:
			s[0] = _T('U'); s[1] = _T('P'); s[2] = '\0';
			cb = 2;
			break;
		default:
			s[0] = key; s[1] = '\0';
			cb = 1;
		}
		TextOut(hdc, 170, 50, s, cb);
	}*/
	SelectObject(hdc, fntOld);

	MoveToEx(hdc,200,100,NULL); LineTo(hdc,200,400);// draw grid
	MoveToEx(hdc,300,100,NULL); LineTo(hdc,300,400);
	MoveToEx(hdc,100,200,NULL); LineTo(hdc,400,200);
	MoveToEx(hdc,100,300,NULL); LineTo(hdc,400,300);

	//Draw the Plays
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			if (board[i][j] == X)
				GameDrawX(hdc, i, j); //just need GameDrawPic
			else if (board[i][j] == O)
				GameDrawO(hdc, i, j);
		}
	}
}

//Set the next move
void GameSetMove(int i, int j) {
	//Make sure the move is legal
	if (i >= 0 && i <= 2 && j >= 0 && j <= 2) {
		//Make sure the game is still playing
		if (gameOver == false) {
			if (xMove)
				board[i][j] = X;
			else
				board[i][j] = O;

			//Next player's turn
			xMove = !xMove;
		}
	}
}

//Is there a winner?
void GameCheckWinner(HWND hwnd) 
{
	if (gameOver) return;

	bool winner = false;
	for (int i = 0; i < 3; i++) {
		if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2])
			winner = true;
	}
	for (int i = 0; i < 3; i++) {
		if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[1][i] == board[2][i])
			winner = true;
	}
	if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2])
		winner = true;
	if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		winner = true;

	if (winner) {
		MessageBox(hwnd, _T("Well done, you rock!"), _T("winner"), MB_OK);
		gameOver = true;
	}
}

//void GameDrawX(HDC hdc, int i, int j) {
//	HPEN pen = CreatePen(PS_SOLID, 3, RGB(255,0,0));
//	HGDIOBJ penOld;
//	
//	penOld = SelectObject(hdc, pen);
//
//	MoveToEx(hdc, 110 + (100*i), 110 + (100*j), NULL);
//	LineTo(hdc, 190 + (100*i), 190 + (100*j));
//	MoveToEx(hdc, 190 + (100*i), 110 + (100*j), NULL);
//	LineTo(hdc, 110 + (100*i), 190 + (100*j));
//
//	SelectObject(hdc, penOld);
//	DeleteObject(pen);
//
//}
//void GameDrawO(HDC hdc, int i, int j) {
//	HPEN pen = CreatePen(PS_SOLID, 3, RGB(0,0,0));
//	HBRUSH brush = CreateHatchBrush(HS_DIAGCROSS, RGB(255,0,0));
//	HGDIOBJ penOld, brushOld;
//
//	penOld = SelectObject(hdc, pen);
//	brushOld = SelectObject(hdc, brush);
//
//	Ellipse(hdc, 110 + (100*i), 110 + (100*j),
//		190 + (100*i), 190 + (100*j));
//
//	SelectObject(hdc, brushOld);
//	SelectObject(hdc, penOld);
//
//	DeleteObject(brush);
//	DeleteObject(pen);
//
//}

//void GameDrawBall(HWND hwnd, HDC hdc) {
//	RECT r;
//	GetClientRect(hwnd, &r);
//
//	if (xRect < xInc)
//		xInc = XBALLINC;
//	if (yRect < yInc)
//		yInc = XBALLINC;
//	if (xRect > (r.right - r.left) - BALLWIDTH)
//		xInc = -XBALLINC;
//	if (yRect > (r.bottom - r.top) - BALLHEIGHT)
//		yInc = -YBALLINC;
//	xRect += xInc;
//	yRect += yInc;
//
//	RoundRect(hdc, xRect, yRect,
//          xRect+BALLWIDTH, yRect+BALLHEIGHT, 2, 2);
//}

//void GameCreateFont() 
//{ 
//    CHOOSEFONT cf; 
//    LOGFONT lf; 
// 
//    cf.lStructSize = sizeof(CHOOSEFONT); 
//    cf.hwndOwner = (HWND)NULL; 
//    cf.hDC = (HDC)NULL; 
//    cf.lpLogFont = &lf; 
//    cf.iPointSize = 0; 
//    cf.Flags = CF_SCREENFONTS; 
//    cf.rgbColors = RGB(0,0,0); 
//    cf.lCustData = 0L; 
//    cf.lpfnHook = (LPCFHOOKPROC)NULL; 
//    cf.lpTemplateName = (LPWSTR)NULL; 
//    cf.hInstance = (HINSTANCE) NULL; 
//    cf.lpszStyle = (LPWSTR)NULL; 
//    cf.nFontType = SCREEN_FONTTYPE; 
//    cf.nSizeMin = 0; 
//    cf.nSizeMax = 0; 
// 
//    ChooseFont(&cf); 
// 
//    fntChosen = CreateFontIndirect(cf.lpLogFont); 
//} 

void GameSetKey(WPARAM wParam) {
	key = (char) wParam;
}