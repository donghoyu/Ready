#include "stdafx.h"

RECT Util::RectMake(int x, int y, int Width, int Height)
{
	RECT Temp = { x, y , x + Width , y + Height };

	return Temp;
}

RECT Util::RectMake(LONG x, LONG y, LONG Width, LONG Height)
{
	RECT Temp = { x, y , x + Width , y + Height };

	return Temp;
}

POINT Util::PointMake(LONG x, LONG y)
{
	POINT Temp;
	Temp.x = x;
	Temp.y = y;

	return Temp;
}

// 행렬 초기화
D3DXMATRIXA16 Util::Identity()
{
	D3DXMATRIXA16 Temp;
	D3DXMatrixIdentity(&Temp);
	return Temp;
}
// 행렬 크기변환
D3DXMATRIXA16 Util::Scaling(float x, float y)
{
	D3DXMATRIXA16 Temp;
	D3DXMatrixScaling(&Temp, x, y, 1.0f);
	return Temp;
}
// 행렬 크기변환
D3DXMATRIXA16 Util::Scaling(double x, double y)
{
	D3DXMATRIXA16 Temp;
	D3DXMatrixScaling(&Temp, (float)x, (float)y, 1.0f);
	return Temp;
}
// 행렬 회전 
D3DXMATRIXA16 Util::Rotation(float Rote)
{
	D3DXMATRIXA16 Temp;
	D3DXMatrixRotationZ(&Temp, Rote);
	return Temp;
}
D3DXMATRIXA16 Util::Translation(int x, int y)
{
	D3DXMATRIXA16 Temp;
	D3DXMatrixTranslation(&Temp, (float)x, (float)y, 0.0f);
	return Temp;
}
// 행렬 이동 
D3DXMATRIXA16 Util::Translation(float x, float y)
{
	D3DXMATRIXA16 Temp;
	D3DXMatrixTranslation(&Temp, x, y, 0.0f);
	return Temp;
}

D3DXMATRIXA16 Util::Translation(double x, double y)
{
	D3DXMATRIXA16 Temp;
	D3DXMatrixTranslation(&Temp, (float)x, (float)y, 0.0f);
	return Temp;
}

D3DXMATRIXA16 Util::Translation(float x, float y, float z)
{
	D3DXMATRIXA16 Temp;
	D3DXMatrixTranslation(&Temp, x, y, z);
	return Temp;
}


