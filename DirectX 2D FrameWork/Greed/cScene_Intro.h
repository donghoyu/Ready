#pragma once
#include "cScene.h"

class cScene_Intro : public cScene
{
private:

public:
	cScene_Intro();
	~cScene_Intro();

	void Release();
	void Setup();
	void Update();
	void Render();
};
