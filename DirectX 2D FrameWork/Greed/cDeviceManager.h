#pragma once

#define DEVICEMANAGERBASE	cDeviceManager::GetInstance()
#define DEVICEMANAGER		cDeviceManager::GetInstance()->GetDevice()

class cDeviceManager
{
private:
	// ����̽� �̱�������
	SINGLETONE(cDeviceManager);
	// ����̽��� ������ ��ü ����
	LPDIRECT3D9			m_pD3D;
	// �������� ���� ����̽�
	LPDIRECT3DDEVICE9	m_pD3DDevice;

public:
	// ����̽� ��
	LPDIRECT3DDEVICE9 GetDevice();
	// ����̽� ����
	void Destroy();

};

