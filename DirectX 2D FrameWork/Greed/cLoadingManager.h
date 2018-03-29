#pragma once
#define LOADINGMANAGER cLoadingManager::GetInstance()

class cLoading;
class cLoadingManager
{
private:
	// �̱���ȭ
	SINGLETONE(cLoadingManager);

	// �ε����� ��������
	typedef DWORD(WINAPI *Loading_Stage)(LPVOID lpParam);
	Loading_Stage Current_Loading;

	// �ε� �ߴ� �̹��� ���
	queue<string> LoadingList;
	// �ε� ������ �������� �Ǵ��� ����
	bool isLoading;
	// �ε� Ŭ����.
	cLoading* Loading;
public:

	cLoading* mLoading() { return Loading; }

	// ����
	void Destory();
	void Destory_LoadingImage();

	// �̹��� �ε� ����
	void Start_Loading();
	// �ε��� �������� ����	
	void Set_Loading_State(Loading_Stage Stage);

	static DWORD WINAPI m_Town(LPVOID lpParam);			  // �����ƹ� && ���� �ε�
	//static DWORD WINAPI m_EasyDercharge(LPVOID lpParam);  // �Ϲ� ���� �ε�
	//static DWORD WINAPI m_HellDercharge(LPVOID lpParam);  // ��   ���� �ε�
};


