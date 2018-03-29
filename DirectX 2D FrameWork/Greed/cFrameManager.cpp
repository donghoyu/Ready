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
		// ������ ��� && ������Ʈ 
		_Frame->Update(lock);
	}
}

void cFrameManager::render()
{
	// ����� ��忡���� !!
#ifdef _DEBUG
	if (_Frame != NULL)
	{
		//FPS
		char str[256];
		sprintf_s(str, "FPS : %d", _Frame->getFPS());
		FONTMANAGER->Render("����ü", str, 0, 0, 25, 25, 255, 255, 255, 255, 0);
	}
#endif

}
