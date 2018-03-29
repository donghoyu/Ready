#include "stdafx.h"
#include "cDeviceManager.h"


cDeviceManager::cDeviceManager()
{
	// 디바이스를 생성하기 위한 객체 생성
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	// 디바이스 성능에 대한 정보 구조체
	D3DCAPS9	d3dCaps;

	int nVertexProcessing;

	// 디바이스에 대한 정보를 저장한다.
	//                 디스플레이 어댑터(장치) 장치의 종류  장치를 사용할 주소
	m_pD3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &d3dCaps);

	// 버텍스 프로세싱 셋팅 
	if (d3dCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
	{
		// 하드웨어를 이용하겟다.
		nVertexProcessing = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	}
	else
	{
		// 소프트웨어를 이용하겟다.
		nVertexProcessing = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
	}

	// 디바이스 생성을 위한 구조체
	D3DPRESENT_PARAMETERS d3dPP;
	// 반드시 구조체를 꺠끗하게 밀어야함
	ZeroMemory(&d3dPP, sizeof(D3DPRESENT_PARAMETERS));
	// 가장 효율 적인 SWAP 효과
	d3dPP.SwapEffect = D3DSWAPEFFECT_DISCARD;
	// 창모드로 생성
	d3dPP.Windowed = TRUE;
	// 현재 바탕화면 모드에 맞춰 후면 버퍼를 생성
	d3dPP.BackBufferFormat = D3DFMT_UNKNOWN;
	// 애플맄케이션의 깊이 버퍼를 관리하도록 한다.
	d3dPP.EnableAutoDepthStencil = TRUE;
	// 유효한 깊이 버퍼 포맷으로 설정한다.
	d3dPP.AutoDepthStencilFormat = D3DFMT_D16;

	// 디바이스 생성
	m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, // 디스플레이 어댑터(장치)
		D3DDEVTYPE_HAL,						 // 장치의 종류
		_hWnd,							     // 윈도우 핸들
		nVertexProcessing | D3DCREATE_MULTITHREADED,					 // 장치를 생성 할때 필요한 옵션
		&d3dPP,								 // 장치를 생성하는데 필요한 파라메터 구조체
		&m_pD3DDevice);						 // 리턴 받을 장치 인터페이스 주소 


}


cDeviceManager::~cDeviceManager()
{
}


LPDIRECT3DDEVICE9 cDeviceManager::GetDevice()
{
	// 디바이스 반환 
	return m_pD3DDevice;
}



void cDeviceManager::Destroy()
{
	//// 디바이스 해제
	//m_pD3D->Release();
	//m_pD3DDevice->Release();

	m_pD3D->Release();
	ULONG ul = m_pD3DDevice->Release();
	assert(ul == 0 && "													      디바이스를 이용하고 해제 안한거있음");
}
