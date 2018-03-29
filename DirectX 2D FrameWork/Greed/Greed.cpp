//=================================
//		## ��� ���� ##
//=================================
#include "stdafx.h"
#include "cMainGame.h"
//=================================
//		## �ʿ� ������ ##
//=================================
cMainGame* _MainGame;
HINSTANCE  _hInstance;
HWND	   _hWnd;
POINT	_ptMouse = { 0,0 };
//HDC		   _hdc;
//=================================
//		## �Լ� ���� ���� ##
//=================================
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//void setWindowSize(HWND hwnd, int x, int y, int width, int height);
//=========================================================================
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{

	_hInstance = hInstance;

	// ������ Ŭ����
	WNDCLASS wndClass;

	wndClass.cbClsExtra = 0;										//������ Ŭ�������� ����ϰ��� �ϴ� ������ �޸𸮾��� ����Ʈ ������ ����
	wndClass.cbWndExtra = 0;										//cbClsExtra �����ϵ� ���� �����쿡�� ����ϰ��� �ϴ� ������ �޸𸮾��� ����
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//�������� �۾������� ĥ�� ��� �귯�ø� ����
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					//Ŭ���� Ŀ���� ����
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				//Ÿ��Ʋ���� �»�ܿ� ������ �����ܰ� �����찡 �ּ�ȭ �Ǿ����� ������ �������� ����
	wndClass.hInstance = hInstance;									//������ Ŭ������ ����� �������α׷��� �ν��Ͻ� �ڵ�
	wndClass.lpfnWndProc = (WNDPROC)WndProc;						//�޼����� ó���Ѵ� �Լ��� ����(������ ���ν���)
	wndClass.lpszClassName = WINNAME;								//����ϰ��� �ϴ� ������ Ŭ�����̸�
	wndClass.lpszMenuName = NULL;									//Ŭ�����κ��� ������� �����찡 ����� �޴��� ����
	wndClass.style = CS_HREDRAW | CS_VREDRAW;						//������ Ŭ������ ��Ÿ���� ����

																	//������ Ŭ���� ���
	RegisterClass(&wndClass);

	// ������â ����
	HWND hWnd = CreateWindow(WINNAME, WINNAME, WS_POPUP, WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY, nullptr, nullptr, hInstance, nullptr);

	// ���� ���н� ���� 
	if (!hWnd) { return FALSE; }
	// ������ �ڵ��� ���� �صд�.
	_hWnd = hWnd;
	//_hdc = GetDC(_hWnd);

	//// Ŭ���̾�Ʈ ������ ����
	//setWindowSize(hWnd, WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);

	// ������ �����ֱ�
	ShowWindow(hWnd, nCmdShow);

	//MSG : �ü������ �߻��ϴ� �޼��� ������ �����ϱ� ���� ����ü
	MSG msg;

	// ���ΰ��� �Ҵ�
	_MainGame = new cMainGame;
	_MainGame->Setup();

	// ���� ���� 
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

	// ���� ����� ���ΰ��� ����
	delete _MainGame;
	//������ Ŭ���� �������
	UnregisterClass(WINNAME, hInstance);

	return (int)msg.wParam;
}

//hWnd : ��� �����쿡�� �߻��� �޼������� ����
//iMessage : �޼��� ���й�ȣ
//wParam : unsigned int ���콺 ��ư�� ����, Ű���� ����Ű�� ���¸� �����Ѵ�.
//lParam : unsigned long ���콺 Ŭ�� ��ǥ�� ����
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return _MainGame->WndProc(hWnd, message, wParam, lParam);
}

//===================================================================
//		������ ������ ����
//===================================================================
//void setWindowSize(HWND hwnd, int x, int y, int width, int height)
//{
//	RECT rc;
//	rc.left = 0;
//	rc.top = 0;
//	rc.right = width;
//	rc.bottom = height;
//
//	//���� ������ ũ�� ����
//	AdjustWindowRect(&rc, WS_CAPTION | WS_SYSMENU, false);
//	//�� RECT ������ ������ ������ ����
//	SetWindowPos(hwnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top),
//		SWP_NOZORDER | SWP_NOMOVE);
//}