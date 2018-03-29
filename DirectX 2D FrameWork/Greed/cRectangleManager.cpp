#include "stdafx.h"
#include "cRectangleManager.h"

cRectangleManager::cRectangleManager()
{
#ifdef _DEBUG
	// 라인 그릴 장치 생성
	D3DXCreateLine(DEVICEMANAGER, &Line);
	// 라인 두께 설정
	Line->SetWidth(1.0f);
	// 라인 안티에일리어 설정
	Line->SetAntialias(true);
	// 렉탱글 렌더 온
	RenderOn = false;
#endif
}

cRectangleManager::~cRectangleManager()
{

}

void cRectangleManager::Destory()
{
#ifdef _DEBUG
	Line->Release(); // 라인 해제
#endif
}

void cRectangleManager::Render(float Left, float Top, float Right, float Bottom)
{
#ifdef _DEBUG
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		if (RenderOn) RenderOn = false;
		else RenderOn = true;
	}

	// 렌더 오프면 종료.
	if (!RenderOn) return;
	IMAGEMANAGER->RenerEnd();

	Line->Begin();   // 그리기 시작
					 //=========================================
	D3DXVECTOR2 TempRect[5];				  // 선을 이을 좌표	
	TempRect[0] = D3DXVECTOR2(Left, Top);	  // 왼쪽 위 ( 시작점 ) 
	TempRect[1] = D3DXVECTOR2(Right, Top);	  // 왼쪽 위 부터 오른쪽 위까지 
	TempRect[2] = D3DXVECTOR2(Right, Bottom); // 오른쪽 위부터 오른쪽 아래까지
	TempRect[3] = D3DXVECTOR2(Left, Bottom);  // 오른쪽 아래부터 왼쪽 아래까지
	TempRect[4] = D3DXVECTOR2(Left, Top);	  // 왼쪽 아래부터 왼쪽 위까지 (시작점)

											  // 그린다.
	Line->Draw(TempRect, 5, D3DCOLOR_XRGB(255, 255, 255));

	//=========================================
	Line->End();     // 그리기 종료
	IMAGEMANAGER->RenerStart();

#endif
}

void cRectangleManager::Render(float Left, float Top, float Right, float Bottom, D3DXCOLOR Color)
{
#ifdef _DEBUG
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		if (RenderOn) RenderOn = false;
		else RenderOn = true;
	}

	//렌더 오프면 종료.
	if (!RenderOn) return;

	IMAGEMANAGER->RenerEnd();

	Line->Begin();   // 그리기 시작
					 //=========================================
	D3DXVECTOR2 TempRect[5];				  // 선을 이을 좌표	
	TempRect[0] = D3DXVECTOR2(Left - CAMERAMANAGER->CameraX, Top - CAMERAMANAGER->CameraY);	  // 왼쪽 위 ( 시작점 ) 
	TempRect[1] = D3DXVECTOR2(Right - CAMERAMANAGER->CameraX, Top - CAMERAMANAGER->CameraY);	  // 왼쪽 위 부터 오른쪽 위까지 
	TempRect[2] = D3DXVECTOR2(Right - CAMERAMANAGER->CameraX, Bottom - CAMERAMANAGER->CameraY); // 오른쪽 위부터 오른쪽 아래까지
	TempRect[3] = D3DXVECTOR2(Left - CAMERAMANAGER->CameraX, Bottom - CAMERAMANAGER->CameraY);  // 오른쪽 아래부터 왼쪽 아래까지
	TempRect[4] = D3DXVECTOR2(Left - CAMERAMANAGER->CameraX, Top - CAMERAMANAGER->CameraY);	  // 왼쪽 아래부터 왼쪽 위까지 (시작점)

																							  // 그린다.
	Line->Draw(TempRect, 5, Color);

	//=========================================
	Line->End();     // 그리기 종료
	IMAGEMANAGER->RenerStart();

#endif
}

void cRectangleManager::Render(float Left, float Top, float Right, float Bottom, D3DXCOLOR Color, float Angle)
{
#ifdef _DEBUG
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		if (RenderOn) RenderOn = false;
		else RenderOn = true;
	}

	// 렌더 오프면 종료.
	if (!RenderOn) return;
	IMAGEMANAGER->RenerEnd();

	Line->Begin();   // 그리기 시작
					 //=========================================
	float Width = Right - Left;		// 가로 넓이
	float Height = Bottom - Top;		// 세로 넓이
	float RadiusX = Width / 2;		// 반지름 X
	float RadiusY = Height / 2;		// 반지름 Y

	D3DXVECTOR3 TempRect[5];										 // 선을 이을 좌표	
	TempRect[0] = D3DXVECTOR3(-RadiusX, -RadiusY, 0);				 // 왼쪽 위 ( 시작점 ) 
	TempRect[1] = D3DXVECTOR3(Width - RadiusX, -RadiusY, 0);		 // 왼쪽 위 부터 오른쪽 위까지 
	TempRect[2] = D3DXVECTOR3(Width - RadiusX, Height - RadiusY, 0); // 오른쪽 위부터 오른쪽 아래까지
	TempRect[3] = D3DXVECTOR3(-RadiusX, Height - RadiusY, 0);		 // 오른쪽 아래부터 왼쪽 아래까지
	TempRect[4] = D3DXVECTOR3(-RadiusX, -RadiusY, 0);				 // 왼쪽 아래부터 왼쪽 위까지 (시작점)

	D3DXMATRIXA16 World, view, proj;
	DEVICEMANAGER->GetTransform(D3DTS_VIEW, &view);
	DEVICEMANAGER->GetTransform(D3DTS_PROJECTION, &proj);
	World = Rotation(Angle) * Translation(Left + RadiusX - CAMERAMANAGER->CameraX, Top + RadiusY - CAMERAMANAGER->CameraY) *  view * proj;

	// 그린다.
	Line->DrawTransform(TempRect, 5, &World, Color);

	//=========================================
	Line->End();     // 그리기 종료
	IMAGEMANAGER->RenerStart();

#endif
}
