#include "stdafx.h"
#include "cMainGame.h"

#include "cScene_Logo.h"
#include "cScene_Title.h"
#include "cScene_Intro.h"

cMainGame::cMainGame()
{
}


cMainGame::~cMainGame()
{
	RECTANGLEMANAGER->Destory();  // 렉탱글   매니져 해제
	IMAGEMANAGER->Destory();	  // 이미지   매니져 해제
	FRAMEMANAGER->Destory();	  // 프레임   매니져 해제
	FONTMANAGER->Destory();		  // 폰트     매니져 해제
	SCENEMANAGER->Destory();	  // 씬		  매니져 해제
	DEVICEMANAGERBASE->Destroy(); // 디바이스 매니져 해제
}

void cMainGame::Setup()
{
	FONTMANAGER->AddFont("굴림체", 25, 25);

	SCENEMANAGER->AddScene("Logo", new cScene_Logo);
	SCENEMANAGER->AddScene("Title", new cScene_Title);
	SCENEMANAGER->AddScene("Intro", new cScene_Intro);
	 
	SCENEMANAGER->ChangeScene("Logo");


	//LOADINGMANAGER->Set_Loading_State(LOADINGMANAGER->m_Town);
	//LOADINGMANAGER->Start_Loading();

	//// 로딩완료되면 타이틀로 !
	//if (!LOADINGMANAGER->isLoading)
	//{
	//	FADEOUTMANAGER->FadeStart("Title");
	//}

}

void cMainGame::Update()
{
	FADEOUTMANAGER->Update();
	SCENEMANAGER->Update();

}

void cMainGame::Render()
{
	// 후면 버퍼를 검정색으로
	DEVICEMANAGER->Clear(NULL, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	// 렌더링 시작
	DEVICEMANAGER->BeginScene();
	//============================================================
	IMAGEMANAGER->RenerStart();
	//============================================================
	SCENEMANAGER->Render();

	RECTANGLEMANAGER->Render((float)CAMERAMANAGER->CameraRange.left, (float)CAMERAMANAGER->CameraRange.top, (float)CAMERAMANAGER->CameraRange.right, (float)CAMERAMANAGER->CameraRange.bottom, D3DCOLOR_XRGB(255, 0, 255));
	
	//============================================================
	FADEOUTMANAGER->Render();
	IMAGEMANAGER->RenerEnd();
	FRAMEMANAGER->render();
	//============================================================
	// 렌더링 종료
	DEVICEMANAGER->EndScene();
	// 후면 버퍼를 보이는 화면으로 
	DEVICEMANAGER->Present(NULL, NULL, NULL, NULL);

}

LRESULT cMainGame::WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_MOUSEMOVE:
		_ptMouse.x = LOWORD(lParam);
		_ptMouse.y = HIWORD(lParam);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
