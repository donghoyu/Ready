#pragma once
#include "cScene.h"

class cScene_Logo : public cScene
{
private:
	float CoffeeY;

public:
	cScene_Logo();
	~cScene_Logo();

	void Release();
	void Setup();
	void Update();
	void Render();
};
