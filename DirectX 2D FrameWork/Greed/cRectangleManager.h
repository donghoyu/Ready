#pragma once
#define RECTANGLEMANAGER cRectangleManager::GetInstance()

class cRectangleManager
{
private:
	// 싱글톤 설정
	SINGLETONE(cRectangleManager);
	// 라인 그릴 장치
	ID3DXLine* Line;

public:
	// 온/오프 설정용 변수
	bool RenderOn;

	void Destory(); // 매니져 해제

	void Render(float Left, float Top, float Right, float Bottom);								// 그리기 
	void Render(float Left, float Top, float Right, float Bottom, D3DXCOLOR Color);			// 컬러 지정 추가
	void Render(float Left, float Top, float Right, float Bottom, D3DXCOLOR Color, float Angle); // 각도 지정 추가

};
