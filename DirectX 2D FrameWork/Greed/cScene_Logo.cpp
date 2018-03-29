#include "stdafx.h"
#include "cScene_Logo.h"

cScene_Logo::cScene_Logo()
{
	// 처음 시작 이후 안쓰일 이미지들이니 해제한다.
	IMAGEMANAGER->Destory_FindImage("Intro_BackGround");
	IMAGEMANAGER->Destory_FindImage("Intro_BackGround2");
	IMAGEMANAGER->Destory_FindImage("Intro_Loading_Back");
	IMAGEMANAGER->Destory_FindImage("Intro_Loading");
}

cScene_Logo::~cScene_Logo()
{
}

void cScene_Logo::Release()
{
}

void cScene_Logo::Setup()
{
	IMAGEMANAGER->addImage("Logo_Coffee", "images/Logo/Logo_Coffee.png", 800, 600);
	IMAGEMANAGER->addImage("Logo_LongStraw", "images/Logo/Logo_LongStraw.png", 238, 348);
	IMAGEMANAGER->addImage("Logo_Name", "images/Logo/Logo_Name.png", 800, 600);
	IMAGEMANAGER->addImage("Logo_BackGround", "images/Logo/Logo_BackGround.png", 800, 600);
	IMAGEMANAGER->addImage("Logo_ShotStraw", "images/Logo/Logo_ShotStraw.png", 238, 348);
	IMAGEMANAGER->addImage("Logo_Humun", "images/Logo/Logo_Humun.png", 292, 600);

	CoffeeY = 0.0f;
}

void cScene_Logo::Update()
{
	if(CoffeeY < WINSIZEY ) CoffeeY += 3.0f;
	else FADEOUTMANAGER->FadeStart("Title");
}

void cScene_Logo::Render()
{
	IMAGEMANAGER->Render("Logo_LongStraw", WINSIZEX / 2 - 50, 180, 240, 300); 
	IMAGEMANAGER->Render("Logo_Name", 0, 0); 
	IMAGEMANAGER->Render("Logo_Coffee", 0, CoffeeY); 
	IMAGEMANAGER->Render("Logo_BackGround", 0, 0); 
	IMAGEMANAGER->Render("Logo_ShotStraw", WINSIZEX / 2 - 50, 180 , 240 , 300); 
	IMAGEMANAGER->Render("Logo_Humun", WINSIZEX - 235, -120 ,300,510 , -0.7f); 
}
