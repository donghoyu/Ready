#include "stdafx.h"
#include "cDeviceManager.h"


cDeviceManager::cDeviceManager()
{
	// ����̽��� �����ϱ� ���� ��ü ����
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	// ����̽� ���ɿ� ���� ���� ����ü
	D3DCAPS9	d3dCaps;

	int nVertexProcessing;

	// ����̽��� ���� ������ �����Ѵ�.
	//                 ���÷��� �����(��ġ) ��ġ�� ����  ��ġ�� ����� �ּ�
	m_pD3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &d3dCaps);

	// ���ؽ� ���μ��� ���� 
	if (d3dCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
	{
		// �ϵ��� �̿��ϰٴ�.
		nVertexProcessing = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	}
	else
	{
		// ����Ʈ��� �̿��ϰٴ�.
		nVertexProcessing = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
	}

	// ����̽� ������ ���� ����ü
	D3DPRESENT_PARAMETERS d3dPP;
	// �ݵ�� ����ü�� �Ʋ��ϰ� �о����
	ZeroMemory(&d3dPP, sizeof(D3DPRESENT_PARAMETERS));
	// ���� ȿ�� ���� SWAP ȿ��
	d3dPP.SwapEffect = D3DSWAPEFFECT_DISCARD;
	// â���� ����
	d3dPP.Windowed = TRUE;
	// ���� ����ȭ�� ��忡 ���� �ĸ� ���۸� ����
	d3dPP.BackBufferFormat = D3DFMT_UNKNOWN;
	// ���Ð����̼��� ���� ���۸� �����ϵ��� �Ѵ�.
	d3dPP.EnableAutoDepthStencil = TRUE;
	// ��ȿ�� ���� ���� �������� �����Ѵ�.
	d3dPP.AutoDepthStencilFormat = D3DFMT_D16;

	// ����̽� ����
	m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, // ���÷��� �����(��ġ)
		D3DDEVTYPE_HAL,						 // ��ġ�� ����
		_hWnd,							     // ������ �ڵ�
		nVertexProcessing | D3DCREATE_MULTITHREADED,					 // ��ġ�� ���� �Ҷ� �ʿ��� �ɼ�
		&d3dPP,								 // ��ġ�� �����ϴµ� �ʿ��� �Ķ���� ����ü
		&m_pD3DDevice);						 // ���� ���� ��ġ �������̽� �ּ� 


}


cDeviceManager::~cDeviceManager()
{
}


LPDIRECT3DDEVICE9 cDeviceManager::GetDevice()
{
	// ����̽� ��ȯ 
	return m_pD3DDevice;
}



void cDeviceManager::Destroy()
{
	//// ����̽� ����
	//m_pD3D->Release();
	//m_pD3DDevice->Release();

	m_pD3D->Release();
	ULONG ul = m_pD3DDevice->Release();
	assert(ul == 0 && "													      ����̽��� �̿��ϰ� ���� ���Ѱ�����");
}
