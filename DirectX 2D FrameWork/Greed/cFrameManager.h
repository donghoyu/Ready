#pragma once
#include "cFrame.h"

#define FRAMEMANAGER cFrameManager::GetInstance()

class cFrameManager
{
private:
	// ������ �Ŵ��� �̱��� ȭ
	SINGLETONE(cFrameManager);
	// ������ �˻��� Ŭ����
	cFrame* _Frame;

public:

	void Destory();
	void update(float lock = 0.0f);
	void render();

	//�� ������ ����ð� �������� 1/60
	float getElapsedTime() const { return _Frame->getElapsedTime(); }
	//��ü �ð� ����� ��������
	float getWorldTime() const { return _Frame->getWorldTime(); }

};
