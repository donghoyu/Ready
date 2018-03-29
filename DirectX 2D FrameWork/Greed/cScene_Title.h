#pragma once
#include "cScene.h"

class cScene_Title : public cScene
{
private:


public:
	cScene_Title();
	~cScene_Title();

	void Release();
	void Setup();
	void Update();
	void Render();
};
