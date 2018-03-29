#pragma once
#define LOADINGMANAGER cLoadingManager::GetInstance()

class cLoading;
class cLoadingManager
{
private:
	// 싱글톤화
	SINGLETONE(cLoadingManager);

	// 로딩중인 스테이지
	typedef DWORD(WINAPI *Loading_Stage)(LPVOID lpParam);
	Loading_Stage Current_Loading;

	// 로딩 했던 이미지 목록
	queue<string> LoadingList;
	// 로딩 중인지 끝난는지 판단할 변수
	bool isLoading;
	// 로딩 클래스.
	cLoading* Loading;
public:

	cLoading* mLoading() { return Loading; }

	// 해제
	void Destory();
	void Destory_LoadingImage();

	// 이미지 로딩 시작
	void Start_Loading();
	// 로딩할 스테이지 셋팅	
	void Set_Loading_State(Loading_Stage Stage);

	static DWORD WINAPI m_Town(LPVOID lpParam);			  // 세리아방 && 마을 로딩
	//static DWORD WINAPI m_EasyDercharge(LPVOID lpParam);  // 일반 던젼 로딩
	//static DWORD WINAPI m_HellDercharge(LPVOID lpParam);  // 헬   던젼 로딩
};


