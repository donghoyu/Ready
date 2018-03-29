#include "stdafx.h"
#include "cCameraManager.h"

cCameraManager::cCameraManager()
	:CameraX(0)
	, CameraY(0)
{
	CameraRange = RectMake(CameraX, CameraY, WINSIZEX, WINSIZEY);
}

cCameraManager::~cCameraManager()
{
}

void cCameraManager::CameraMove(float x, float y)
{
	CameraX += x;
	CameraY += y;

	CameraRange = RectMake(CameraX, CameraY, WINSIZEX, WINSIZEY);
}

void cCameraManager::CameraPosition(float x, float y)
{
	if (x > WINSIZEX / 2) CameraX = x - WINSIZEX / 2;
	else CameraX = 0;

	if (y > WINSIZEY / 2) CameraY = y - WINSIZEY / 2;
	else CameraY = 0;

	CameraRange = RectMake(CameraX, CameraY, WINSIZEX, WINSIZEY);
}
