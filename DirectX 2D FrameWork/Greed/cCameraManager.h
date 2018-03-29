#pragma once
#define CAMERAMANAGER cCameraManager::GetInstance()

class cCameraManager
{
private:
	SINGLETONE(cCameraManager);

	float CameraX, CameraY;
	RECT  CameraRange;
public:
	void CameraMove(float x, float y);
	void CameraPosition(float x, float y);

};
