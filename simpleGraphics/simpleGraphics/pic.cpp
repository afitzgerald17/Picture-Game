// simpleGraphics.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "pic.h"
#include "manage.h"
#include <vector>
#include "Grid.h"
using namespace std;

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
Grid grid;

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_SIMPLEGRAPHICS, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SIMPLEGRAPHICS));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SIMPLEGRAPHICS));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_SIMPLEGRAPHICS);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, windowWidthMin, windowHeightMin, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   SetTimer(hWnd, ID_TIMER, 30, (TIMERPROC) NULL);
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
//HBITMAP hImage = NULL;
vector <HBITMAP> images;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	int xPos, yPos;
	HWND hButton;	

	switch (message)
	{
	case WM_CREATE:
			hButton = CreateWindow( L"button", L"Label",
                WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
                220, 415, 
                50, 20,
                hWnd, (HMENU) 63,
                hInst, NULL );

			images.push_back((HBITMAP)LoadImage(hInst,L"1.bmp",IMAGE_BITMAP,LR_DEFAULTSIZE ,LR_DEFAULTSIZE ,LR_LOADFROMFILE|LR_CREATEDIBSECTION));
			images.push_back((HBITMAP)LoadImage(hInst,L"2.bmp",IMAGE_BITMAP,LR_DEFAULTSIZE ,LR_DEFAULTSIZE ,LR_LOADFROMFILE|LR_CREATEDIBSECTION));
			images.push_back((HBITMAP)LoadImage(hInst,L"3.bmp",IMAGE_BITMAP,LR_DEFAULTSIZE ,LR_DEFAULTSIZE ,LR_LOADFROMFILE|LR_CREATEDIBSECTION));
			images.push_back((HBITMAP)LoadImage(hInst,L"4.bmp",IMAGE_BITMAP,LR_DEFAULTSIZE ,LR_DEFAULTSIZE ,LR_LOADFROMFILE|LR_CREATEDIBSECTION));
			images.push_back((HBITMAP)LoadImage(hInst,L"5.bmp",IMAGE_BITMAP,LR_DEFAULTSIZE ,LR_DEFAULTSIZE ,LR_LOADFROMFILE|LR_CREATEDIBSECTION));
			images.push_back((HBITMAP)LoadImage(hInst,L"6.bmp",IMAGE_BITMAP,LR_DEFAULTSIZE ,LR_DEFAULTSIZE ,LR_LOADFROMFILE|LR_CREATEDIBSECTION));
			images.push_back((HBITMAP)LoadImage(hInst,L"7.bmp",IMAGE_BITMAP,LR_DEFAULTSIZE ,LR_DEFAULTSIZE ,LR_LOADFROMFILE|LR_CREATEDIBSECTION));
			images.push_back((HBITMAP)LoadImage(hInst,L"8.bmp",IMAGE_BITMAP,LR_DEFAULTSIZE ,LR_DEFAULTSIZE ,LR_LOADFROMFILE|LR_CREATEDIBSECTION));
            images.push_back((HBITMAP)LoadImage(hInst,L"9.bmp",IMAGE_BITMAP,LR_DEFAULTSIZE ,LR_DEFAULTSIZE ,LR_LOADFROMFILE|LR_CREATEDIBSECTION));
			
			break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case ID_FILE_NEW:
			GameReset();
			break;
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		GameDrawBoard(hWnd, hdc);

		

        
		EndPaint(hWnd, &ps);
		break;
	case WM_TIMER:
		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_SIZE:
		RECT r; //make a rectangle object
		//Make sure we don't go below the minimum
		GetWindowRect(hWnd, &r); //Get the window’s rectangle
		if (r.right - r.left < windowWidthMin) {
			SetWindowPos(hWnd, HWND_TOP, r.left, r.top,
				windowWidthMin, r.bottom-r.top,
				SWP_NOZORDER | SWP_NOSENDCHANGING);
		}
		if (r.bottom - r.top < windowHeightMin) {
			SetWindowPos(hWnd, HWND_TOP, r.left, r.top,
				r.right - r.left, windowHeightMin,
				SWP_NOZORDER | SWP_NOSENDCHANGING);
		}
		break;
	case WM_LBUTTONUP:
		//Get the coordinates to the array
		xPos = (LOWORD(lParam) - 100) / 100;
		yPos = (HIWORD(lParam) - 100) / 100;
		
		////Tell the game manager to add a move
		GameSetMove(xPos, yPos);
		//Force a paint message of the gameboard
		InvalidateRect(hWnd, NULL, true);
		//Did someone win?
		GameCheckWinner(hWnd);
		break;
	
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
