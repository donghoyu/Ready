#pragma once

#define DEVICEMANAGERBASE	cDeviceManager::GetInstance()
#define DEVICEMANAGER		cDeviceManager::GetInstance()->GetDevice()

class cDeviceManager
{
private:
	// 디바이스 싱글톤으로
	SINGLETONE(cDeviceManager);
	// 디바이스를 생성할 객체 변수
	LPDIRECT3D9			m_pD3D;
	// 렌더링에 사용될 디바이스
	LPDIRECT3DDEVICE9	m_pD3DDevice;

public:
	// 디바이스 겟
	LPDIRECT3DDEVICE9 GetDevice();
	// 디바이스 해제
	void Destroy();

};

