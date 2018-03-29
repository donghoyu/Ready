#pragma once
#include "cFrame.h"

#define FRAMEMANAGER cFrameManager::GetInstance()

class cFrameManager
{
private:
	// 프레임 매니져 싱글톤 화
	SINGLETONE(cFrameManager);
	// 프레임 검사할 클래스
	cFrame* _Frame;

public:

	void Destory();
	void update(float lock = 0.0f);
	void render();

	//한 프레임 경과시간 가져오기 1/60
	float getElapsedTime() const { return _Frame->getElapsedTime(); }
	//전체 시간 경과량 가져오기
	float getWorldTime() const { return _Frame->getWorldTime(); }

};
