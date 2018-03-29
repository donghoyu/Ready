#include "stdafx.h"
#include "cFadeOutManager.h"

cFadeOutManager::cFadeOutManager()
	:FadeStatus(NONE)
	, FadeAlpa(0)
	, ChageSetMode(false)
{
	IMAGEMANAGER->addImage("FadeOut", "images/FadeOut.png", 800, 600);
}

cFadeOutManager::~cFadeOutManager()
{
}

void cFadeOutManager::Update()
{
	switch (FadeStatus)
	{
	case ON:
		if (Fade(FadeAlpa))
		{
			if (ChageSetMode)SCENEMANAGER->ChangeScene(ChangeSceneName, PlayerPos, CameraPos);
			else SCENEMANAGER->ChangeScene(ChangeSceneName);

			Fade = FadeOut;
			FadeStatus = OFF;
		}
		break;
	case OFF:
		if (Fade(FadeAlpa))
		{
			FadeStatus = NONE;
		}
		break;
	default:
		return;
	}

}

void cFadeOutManager::Render()
{
	switch (FadeStatus)
	{
	case ON:
		IMAGEMANAGER->AlpaRender("FadeOut", 0, 0, WINSIZEX, WINSIZEY, FadeAlpa);
		break;
	case OFF:
		IMAGEMANAGER->AlpaRender("FadeOut", 0, 0, WINSIZEX, WINSIZEY, FadeAlpa);
		break;
	default:
		return;
	}
}

void cFadeOutManager::Render(double SizeX, double SizeY)
{
	switch (FadeStatus)
	{
	case ON:
		IMAGEMANAGER->AlpaRender("FadeOut", 0, 0, SizeX, SizeY, FadeAlpa);
		break;
	case OFF:
		IMAGEMANAGER->AlpaRender("FadeOut", 0, 0, SizeX, SizeY, FadeAlpa);
		break;
	default:
		return;
	}
}

void cFadeOutManager::FadeStart(string ChangeScene)
{
	if (FadeStatus != NONE) return;

	FadeStatus = ON;
	Fade = FadeIn;
	FadeAlpa = 0;
	ChangeSceneName = ChangeScene;
	ChageSetMode = false;
}

void cFadeOutManager::FadeStart(string ChangeScene, POINT Ppos, POINT Cpos)
{
	if (FadeStatus != NONE) return;

	FadeStatus = ON;
	Fade = FadeIn;
	FadeAlpa = 0;
	ChangeSceneName = ChangeScene;
	PlayerPos = Ppos;
	CameraPos = Cpos;
	ChageSetMode = true;
}

bool cFadeOutManager::FadeIn(int& Value)
{
	Value += 3;
	if (Value >= 255) return true;
	else return false;
}

bool cFadeOutManager::FadeOut(int& Value)
{
	Value -= 3;
	if (Value <= 0) return true;
	else return false;

}
