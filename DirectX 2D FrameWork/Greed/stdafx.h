// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

//=================================
//		## DirectX ���̺귯�� ##
//=================================
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
//=================================
//		## Window �Ӽ� ##
//=================================
#define WINNAME L"�̸�" // Ÿ��Ʋâ �̸�
#define WINSIZEX 800	// ������â ���� ������
#define WINSIZEY 600    // ������â ���� ������
#define WINSTARTX 200	// ������â ���� x ��ǥ
#define WINSTARTY 100   // ������â ���� y ��ǥ
//=================================
//		## ���� ���� ��� ##
//=================================
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <assert.h>

#include "Utill.h"
//=================================
//		## ���� �����̽� ##
//=================================
using namespace std;
using namespace Util;
//=================================
//		## �����ι� ##
//=================================
#define SINGLETONE(class_name)	 private:	class_name(); ~class_name(); public : static class_name* GetInstance(){ static class_name instance; return &instance; } 
#define SAFE_DELETE(p)  { if(p) delete p; p = NULL; }
#define SAFE_RELEASE(p) { if(p) p->Release(); p = NULL; }
//=================================
//		## ���� ���� ##
//=================================
extern HWND  _hWnd;
extern POINT _ptMouse;
//=================================
//		## �Ŵ��� ##
//=================================
#include "cDeviceManager.h"
#include "cFontManager.h"
#include "cFrameManager.h"
#include "cimageManager.h"
#include "cKeyManager.h"
#include "cSceneManager.h"
#include "cRectangleManager.h"
#include "cLoadingManager.h"
#include "cFadeOutManager.h"
#include "cCameraManager.h"
//=====================================
//	## �ܼ�â �ʿ��ϸ� �ּ� ���� ##
//=====================================
//#include <iostream>
//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console" )