//=================================
//		## 헤더 파일 ##
//=================================
#include "stdafx.h"
#include "cMainGame.h"
//=================================
//		## 필요 변수들 ##
//=================================
cMainGame* _MainGame;
HINSTANCE  _hInstance;
HWND	   _hWnd;
POINT	_ptMouse = { 0,0 };
//HDC		   _hdc;
//=================================
//		## 함수 전방 선언 ##
//=================================
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//void setWindowSize(HWND hwnd, int x, int y, int width, int height);
//=========================================================================
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{

	_hInstance = hInstance;

	// 윈도우 클래스
	WNDCLASS wndClass;

	wndClass.cbClsExtra = 0;										//윈도우 클래스에서 사용하고자 하는 여분의 메모리양을 바이트 단위로 지정
	wndClass.cbWndExtra = 0;										//cbClsExtra 유사하되 개별 윈도우에서 사용하고자 하는 여분의 메모리양을 지정
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//윈도우의 작업영역에 칠할 배경 브러시를 지정
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					//클래스 커서를 지정
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				//타이틀바의 좌상단에 보여줄 아이콘과 윈도우가 최소화 되었을때 보여줄 아이콘을 지정
	wndClass.hInstance = hInstance;									//윈도우 클래스를 등록한 응용프로그램의 인스턴스 핸들
	wndClass.lpfnWndProc = (WNDPROC)WndProc;						//메세지를 처리한는 함수를 지정(윈도우 프로시져)
	wndClass.lpszClassName = WINNAME;								//등록하고자 하는 윈도우 클래스이름
	wndClass.lpszMenuName = NULL;									//클래스로부터 만들어진 윈도우가 사용할 메뉴를 지정
	wndClass.style = CS_HREDRAW | CS_VREDRAW;						//윈도우 클래스의 스타일을 지정

																	//윈도우 클래스 등록
	RegisterClass(&wndClass);

	// 윈도우창 생성
	HWND hWnd = CreateWindow(WINNAME, WINNAME, WS_POPUP, WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY, nullptr, nullptr, hInstance, nullptr);

	// 생성 실패시 종료 
	if (!hWnd) { return FALSE; }
	// 생성한 핸들을 저장 해둔다.
	_hWnd = hWnd;
	//_hdc = GetDC(_hWnd);

	//// 클라이언트 사이즈 셋팅
	//setWindowSize(hWnd, WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);

	// 윈도우 보여주기
	ShowWindow(hWnd, nCmdShow);

	//MSG : 운영체제에서 발생하는 메세지 정보를 저장하기 위한 구조체
	MSG msg;

	// 메인게임 할당
	_MainGame = new cMainGame;
	_MainGame->Setup();

	// 게임 루프 
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			FRAMEMANAGER->update(60.0f);
			_MainGame->Update();
			_MainGame->Render();
		}
	}

	// 게임 종료시 메인게임 해제
	delete _MainGame;
	//윈도우 클래스 등록해제
	UnregisterClass(WINNAME, hInstance);

	return (int)msg.wParam;
}

//hWnd : 어느 윈도우에서 발생한 메세지인지 구분
//iMessage : 메세지 구분번호
//wParam : unsigned int 마우스 버튼의 상태, 키보드 조합키의 상태를 전달한다.
//lParam : unsigned long 마우스 클릭 좌표를 전달
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return _MainGame->WndProc(hWnd, message, wParam, lParam);
}

//===================================================================
//		윈도우 사이즈 셋팅
//===================================================================
//void setWindowSize(HWND hwnd, int x, int y, int width, int height)
//{
//	RECT rc;
//	rc.left = 0;
//	rc.top = 0;
//	rc.right = width;
//	rc.bottom = height;
//
//	//실제 윈도우 크기 조정
//	AdjustWindowRect(&rc, WS_CAPTION | WS_SYSMENU, false);
//	//위 RECT 정보로 윈도우 사이즈 셋팅
//	SetWindowPos(hwnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top),
//		SWP_NOZORDER | SWP_NOMOVE);
//}