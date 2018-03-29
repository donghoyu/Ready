#pragma once

//=================================
//		## 디파인 ##
//=================================
#define VECTOR2 D3DXVECTOR2
#define VECTOR3 D3DXVECTOR3
#define MATRIX  D3DXMATRIXA16
//=================================
//		## 벡터 요소 ##
//=================================
static struct VECTORSTATUS
{
public:
	D3DXVECTOR3 Left;
	D3DXVECTOR3 Right;
	D3DXVECTOR3 Up;
	D3DXVECTOR3 Down;
	D3DXVECTOR3 Zero;

	VECTORSTATUS() :
		Left(-1, 0, 0), Right(1, 0, 0), Up(0, 1, 0), Down(0, -1, 0), Zero(0, 0, 0) {}
}VECTOR;
//=================================
//		## 유틸 ##
//=================================
namespace Util
{
	// 렉트 생성
	RECT RectMake(int x, int y, int Width, int Height);
	RECT RectMake(LONG x, LONG y, LONG Width, LONG Height);
	// 포인트 생성
	POINT PointMake(LONG x, LONG y);

	// 행렬 초기화
	D3DXMATRIXA16 Identity();
	// 행렬 크기변환
	D3DXMATRIXA16 Scaling(float x, float y);
	D3DXMATRIXA16 Scaling(double x, double y);
	// 행렬 회전 
	D3DXMATRIXA16 Rotation(float Rote);
	// 행렬 이동 
	D3DXMATRIXA16 Translation(int x, int y);
	D3DXMATRIXA16 Translation(float x, float y);
	D3DXMATRIXA16 Translation(double x, double y);
	D3DXMATRIXA16 Translation(float x, float y, float z);

}

