// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

//=================================
//		## DirectX 라이브러리 ##
//=================================
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
//=================================
//		## Window 속성 ##
//=================================
#define WINNAME L"이름" // 타이틀창 이름
#define WINSIZEX 800	// 윈도우창 가로 사이즈
#define WINSIZEY 600    // 윈도우창 세로 사이즈
#define WINSTARTX 200	// 윈도우창 등장 x 좌표
#define WINSTARTY 100   // 윈도우창 등장 y 좌표
//=================================
//		## 자주 쓰는 헤더 ##
//=================================
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <assert.h>

#include "Utill.h"
//=================================
//		## 네임 스페이스 ##
//=================================
using namespace std;
using namespace Util;
//=================================
//		## 디파인문 ##
//=================================
#define SINGLETONE(class_name)	 private:	class_name(); ~class_name(); public : static class_name* GetInstance(){ static class_name instance; return &instance; } 
#define SAFE_DELETE(p)  { if(p) delete p; p = NULL; }
#define SAFE_RELEASE(p) { if(p) p->Release(); p = NULL; }
//=================================
//		## 전역 변수 ##
//=================================
extern HWND  _hWnd;
extern POINT _ptMouse;
//=================================
//		## 매니져 ##
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
//	## 콘솔창 필요하면 주석 해제 ##
//=====================================
//#include <iostream>
//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console" )