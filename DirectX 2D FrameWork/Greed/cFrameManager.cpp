#include "stdafx.h"
#include "cFrameManager.h"

cFrameManager::cFrameManager()
{
	_Frame = new cFrame;
	_Frame->Setup();
}

cFrameManager::~cFrameManager()
{
}


void cFrameManager::Destory()
{
	if (_Frame != nullptr)
	{
		SAFE_DELETE(_Frame);
		_Frame = nullptr;
	}
}

void cFrameManager::update(float lock)
{
	if (_Frame != nullptr)
	{
		// 프레임 계산 && 업데이트 
		_Frame->Update(lock);
	}
}

void cFrameManager::render()
{
	// 디버그 모드에서만 !!
#ifdef _DEBUG
	if (_Frame != NULL)
	{
		//FPS
		char str[256];
		sprintf_s(str, "FPS : %d", _Frame->getFPS());
		FONTMANAGER->Render("굴림체", str, 0, 0, 25, 25, 255, 255, 255, 255, 0);
	}
#endif

}
