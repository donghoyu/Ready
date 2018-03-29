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
	// 로딩 이미지 목록 받아논 큐 가 빌때까지 반복한다.
	while (!LoadingList.empty())
	{
		// 이미지 해제하고
		IMAGEMANAGER->Destory_FindImage(LoadingList.front());
		// 큐에서 제거
		LoadingList.pop();

		//============ TEST =====
		static int number = 0;
		//cout << number++ << " 번쨰 지우는중..." << endl;	
	}



}

void cLoadingManager::Start_Loading()
{
	// 쓰레드 실행할 아이디 번호 
	DWORD threadID = 0;
	//쓰레드는 실행시키고 닫아준다
	CloseHandle(CreateThread(NULL, 0, Current_Loading, this, NULL, &threadID));
	// 로딩 시작
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

	// 로딩 중이면 계속 실행
	while (Temp->mLoading()->Get_isLoading())
	{
		// 로딩 계속 진행
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

