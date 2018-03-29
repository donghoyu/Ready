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
	RECTANGLEMANAGER->Destory();  // ���ʱ�   �Ŵ��� ����
	IMAGEMANAGER->Destory();	  // �̹���   �Ŵ��� ����
	FRAMEMANAGER->Destory();	  // ������   �Ŵ��� ����
	FONTMANAGER->Destory();		  // ��Ʈ     �Ŵ��� ����
	SCENEMANAGER->Destory();	  // ��		  �Ŵ��� ����
	DEVICEMANAGERBASE->Destroy(); // ����̽� �Ŵ��� ����
}

void cMainGame::Setup()
{
	FONTMANAGER->AddFont("����ü", 25, 25);

	SCENEMANAGER->AddScene("Logo", new cScene_Logo);
	SCENEMANAGER->AddScene("Title", new cScene_Title);
	SCENEMANAGER->AddScene("Intro", new cScene_Intro);
	 
	SCENEMANAGER->ChangeScene("Logo");


	//LOADINGMANAGER->Set_Loading_State(LOADINGMANAGER->m_Town);
	//LOADINGMANAGER->Start_Loading();

	//// �ε��Ϸ�Ǹ� Ÿ��Ʋ�� !
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
	// �ĸ� ���۸� ����������
	DEVICEMANAGER->Clear(NULL, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	// ������ ����
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
	// ������ ����
	DEVICEMANAGER->EndScene();
	// �ĸ� ���۸� ���̴� ȭ������ 
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
