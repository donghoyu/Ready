#include "stdafx.h"
#include "cScene_Intro.h"

cScene_Intro::cScene_Intro()
{
}

cScene_Intro::~cScene_Intro()
{
}

void cScene_Intro::Release()
{
}

void cScene_Intro::Setup()
{
}

void cScene_Intro::Update()
{
 
}

void cScene_Intro::Render()
{
	FONTMANAGER->Render("굴림체", "여기는 인트로씬이다.", WINSIZEX / 2 - 180, WINSIZEY / 2, 20, 20, 255, 255, 255, 255, 0.0f);
}
