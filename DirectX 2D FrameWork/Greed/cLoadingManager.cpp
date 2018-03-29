#include "stdafx.h"
#include "cLoadingManager.h"
#include "cLoading.h" 

cLoadingManager::cLoadingManager()
{
	Loading = new cLoading;
}

cLoadingManager::~cLoadingManager()
{

}


void cLoadingManager::Destory()
{
}

void cLoadingManager::Destory_LoadingImage()
{
	// �ε� �̹��� ��� �޾Ƴ� ť �� �������� �ݺ��Ѵ�.
	while (!LoadingList.empty())
	{
		// �̹��� �����ϰ�
		IMAGEMANAGER->Destory_FindImage(LoadingList.front());
		// ť���� ����
		LoadingList.pop();

		//============ TEST =====
		static int number = 0;
		//cout << number++ << " ���� �������..." << endl;	
	}



}

void cLoadingManager::Start_Loading()
{
	// ������ ������ ���̵� ��ȣ 
	DWORD threadID = 0;
	//������� �����Ű�� �ݾ��ش�
	CloseHandle(CreateThread(NULL, 0, Current_Loading, this, NULL, &threadID));
	// �ε� ����
	isLoading = true;
	Loading->Set_isLoading(true);
}

void cLoadingManager::Set_Loading_State(Loading_Stage Stage)
{
	Current_Loading = Stage;
}

DWORD WINAPI cLoadingManager::m_Town(LPVOID lpParam)
{
	cLoadingManager* Temp = (cLoadingManager*)lpParam;

	// �ε� ���̸� ��� ����
	while (Temp->mLoading()->Get_isLoading())
	{
		// �ε� ��� ����
		//Temp->mLoading()->m_Town();
	}

	Temp->isLoading = false;

	return 0;
}

//DWORD WINAPI cLoadingManager::m_EasyDercharge(LPVOID lpParam)
//{
//	return 0;
//}
//
//DWORD WINAPI cLoadingManager::m_HellDercharge(LPVOID lpParam)
//{
//	return 0;
//}

