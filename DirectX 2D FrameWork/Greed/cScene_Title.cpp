#include "stdafx.h"
#include "cScene_Title.h"

cScene_Title::cScene_Title()
{
}

cScene_Title::~cScene_Title()
{
}

void cScene_Title::Release()
{
}

void cScene_Title::Setup()
{
}

void cScene_Title::Update()
{
	if(KEYMANAGER->isOnceKeyDown(VK_SPACE)) FADEOUTMANAGER->FadeStart("Intro");
}

void cScene_Title::Render()
{

	FONTMANAGER->Render("����ü", "����� Ÿ��Ʋ���̴�.", WINSIZEX / 2 - 180, WINSIZEY / 2, 20, 20, 255, 255, 255, 255, 0.0f);
	
}
