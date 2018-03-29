#include "stdafx.h"
#include "cRectangleManager.h"

cRectangleManager::cRectangleManager()
{
#ifdef _DEBUG
	// ���� �׸� ��ġ ����
	D3DXCreateLine(DEVICEMANAGER, &Line);
	// ���� �β� ����
	Line->SetWidth(1.0f);
	// ���� ��Ƽ���ϸ��� ����
	Line->SetAntialias(true);
	// ���ʱ� ���� ��
	RenderOn = false;
#endif
}

cRectangleManager::~cRectangleManager()
{

}

void cRectangleManager::Destory()
{
#ifdef _DEBUG
	Line->Release(); // ���� ����
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

	// ���� ������ ����.
	if (!RenderOn) return;
	IMAGEMANAGER->RenerEnd();

	Line->Begin();   // �׸��� ����
					 //=========================================
	D3DXVECTOR2 TempRect[5];				  // ���� ���� ��ǥ	
	TempRect[0] = D3DXVECTOR2(Left, Top);	  // ���� �� ( ������ ) 
	TempRect[1] = D3DXVECTOR2(Right, Top);	  // ���� �� ���� ������ ������ 
	TempRect[2] = D3DXVECTOR2(Right, Bottom); // ������ ������ ������ �Ʒ�����
	TempRect[3] = D3DXVECTOR2(Left, Bottom);  // ������ �Ʒ����� ���� �Ʒ�����
	TempRect[4] = D3DXVECTOR2(Left, Top);	  // ���� �Ʒ����� ���� ������ (������)

											  // �׸���.
	Line->Draw(TempRect, 5, D3DCOLOR_XRGB(255, 255, 255));

	//=========================================
	Line->End();     // �׸��� ����
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

	//���� ������ ����.
	if (!RenderOn) return;

	IMAGEMANAGER->RenerEnd();

	Line->Begin();   // �׸��� ����
					 //=========================================
	D3DXVECTOR2 TempRect[5];				  // ���� ���� ��ǥ	
	TempRect[0] = D3DXVECTOR2(Left - CAMERAMANAGER->CameraX, Top - CAMERAMANAGER->CameraY);	  // ���� �� ( ������ ) 
	TempRect[1] = D3DXVECTOR2(Right - CAMERAMANAGER->CameraX, Top - CAMERAMANAGER->CameraY);	  // ���� �� ���� ������ ������ 
	TempRect[2] = D3DXVECTOR2(Right - CAMERAMANAGER->CameraX, Bottom - CAMERAMANAGER->CameraY); // ������ ������ ������ �Ʒ�����
	TempRect[3] = D3DXVECTOR2(Left - CAMERAMANAGER->CameraX, Bottom - CAMERAMANAGER->CameraY);  // ������ �Ʒ����� ���� �Ʒ�����
	TempRect[4] = D3DXVECTOR2(Left - CAMERAMANAGER->CameraX, Top - CAMERAMANAGER->CameraY);	  // ���� �Ʒ����� ���� ������ (������)

																							  // �׸���.
	Line->Draw(TempRect, 5, Color);

	//=========================================
	Line->End();     // �׸��� ����
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

	// ���� ������ ����.
	if (!RenderOn) return;
	IMAGEMANAGER->RenerEnd();

	Line->Begin();   // �׸��� ����
					 //=========================================
	float Width = Right - Left;		// ���� ����
	float Height = Bottom - Top;		// ���� ����
	float RadiusX = Width / 2;		// ������ X
	float RadiusY = Height / 2;		// ������ Y

	D3DXVECTOR3 TempRect[5];										 // ���� ���� ��ǥ	
	TempRect[0] = D3DXVECTOR3(-RadiusX, -RadiusY, 0);				 // ���� �� ( ������ ) 
	TempRect[1] = D3DXVECTOR3(Width - RadiusX, -RadiusY, 0);		 // ���� �� ���� ������ ������ 
	TempRect[2] = D3DXVECTOR3(Width - RadiusX, Height - RadiusY, 0); // ������ ������ ������ �Ʒ�����
	TempRect[3] = D3DXVECTOR3(-RadiusX, Height - RadiusY, 0);		 // ������ �Ʒ����� ���� �Ʒ�����
	TempRect[4] = D3DXVECTOR3(-RadiusX, -RadiusY, 0);				 // ���� �Ʒ����� ���� ������ (������)

	D3DXMATRIXA16 World, view, proj;
	DEVICEMANAGER->GetTransform(D3DTS_VIEW, &view);
	DEVICEMANAGER->GetTransform(D3DTS_PROJECTION, &proj);
	World = Rotation(Angle) * Translation(Left + RadiusX - CAMERAMANAGER->CameraX, Top + RadiusY - CAMERAMANAGER->CameraY) *  view * proj;

	// �׸���.
	Line->DrawTransform(TempRect, 5, &World, Color);

	//=========================================
	Line->End();     // �׸��� ����
	IMAGEMANAGER->RenerStart();

#endif
}
