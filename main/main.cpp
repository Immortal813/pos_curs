#include <Windows.h>
#include <TlHelp32.h>
#include <Wingdi.h>
#include <iostream>
#include <string>
#include <chrono>

/*bool findAndOpenWin() {

	HWND hWnd = FindWindow( NULL, TEXT( "Безымянный - Paint" ) );
	bool check;
	POINT pt;
	if ( hWnd == NULL ) {

		MessageBox( hWnd, TEXT( "Need open Paint" ), TEXT( "Error" ), MB_OK | MB_ICONSTOP );
		check = 0;
	}
	else {
		//Разворачивает окно, елси оно свернуто 
		ShowWindow( hWnd, SW_RESTORE );
		//Функция делает активным необходимое окно
		SetForegroundWindow( hWnd );
		check = 1;
	}

	while ( 1 ) {

		GetCursorPos( &pt );
		//Берет координаты относительно выбранного окна 
		ScreenToClient( hWnd, &pt );

		std::cout << "X: " << pt.x << std::endl << "Y: " << pt.y << std::endl;
		std::cout << "==================" << std::endl;
		Sleep( 2000 );

	}

	return check;

}*/

/*/void mouseClick() {

	SetCursorPos( 30, 33 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 30, 33, 0, 0 );
	//=========
	Sleep( 500 );
	SetCursorPos( 84, 423 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 84, 423, 0, 0 );
	Sleep( 500 );
	//=========
	SetCursorPos( 851, 654 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 851, 654, 0, 0 );
	Sleep( 500 );
	//=========
	SetCursorPos( 993, 658 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 993, 658, 0, 0 );
	//=========
	SetCursorPos( 530, 64 );
	mouse_event( MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 530, 64, 0, 0 );
	//=========ЗАЖАТЬ
	SetCursorPos( 316, 331 );
	mouse_event( MOUSEEVENTF_LEFTDOWN, 316, 331, 0, 0 );
	//=========ОТПУСТИТЬ
	SetCursorPos( 526, 449 );
	mouse_event( MOUSEEVENTF_LEFTUP, 30, 33, 0, 0 );
	//=========



}*/

LRESULT CALLBACK WindowProc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam );

int WINAPI wWinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow ) {

	const wchar_t CLASS_NAME[] = L"Sample Window Class";
	WNDCLASS wc = {};

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;
	RegisterClass( &wc );

	//======
	int wHeight = 100;
	int x, y;
	POINT pt;
	//======
	
	HWND hWnd = CreateWindowEx(0, CLASS_NAME, NULL, NULL, NULL, NULL, wHeight, wHeight, NULL, NULL, hInstance, NULL );

	if ( hWnd == NULL ) {
	
		MessageBox( hWnd, TEXT( "hWnd = LOL" ), TEXT( "Error" ), MB_OK | MB_ICONSTOP );
		return 0;

	}

	ShowWindow( hWnd, nCmdShow );
	MSG msg = {};

	std::string str;
	while ( GetMessage( &msg, NULL, 0, 0 ) > 0 ) {
		

		GetCursorPos( &pt );

		SetWindowPos( hWnd, HWND_TOPMOST, pt.x+10, pt.y, NULL, NULL, NULL );

		//TranslateMessage( &msg );
		//DispatchMessage( &msg );

	}
	
	
	
	return 0;
}

//===============
LRESULT CALLBACK WindowProc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	switch ( uMsg )
	{
	case WM_DESTROY:
		PostQuitMessage( 0 );
		return 0;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint( hwnd, &ps );

		// All painting occurs here, between BeginPaint and EndPaint.

		FillRect( hdc, &ps.rcPaint, (HBRUSH)( COLOR_WINDOW + 1 ) );

		EndPaint( hwnd, &ps );
	}
	return 0;

	}
	return DefWindowProc( hwnd, uMsg, wParam, lParam );
}