#include "stdafx.h"
#include "cSceneManager.h"
#include "cScene.h"
#include "cPlayer.h"

cSceneManager::cSceneManager()
{
}

cSceneManager::~cSceneManager()
{
}

void cSceneManager::Destory()

{	// �� ����Ʈ ���鼭 
	for each(auto p in Scene_List)
	{
		SAFE_DELETE(p.second);					// �ʿ� �����Ҵ� �صξ��� �� Ŭ���� ����
	}
	// �� �������� �� Ŭ����.
	Scene_List.clear();
}


cScene * cSceneManager::FindScene(string KeyName)
{
	if (Scene_List.find(KeyName) != Scene_List.end()) return Scene_List[KeyName];

	return NULL;
}

void cSceneManager::AddScene(string KeyName, cScene * Scene)
{
	assert(Scene_List.find(KeyName) == Scene_List.end() && "         �� �߰��ߴµ� �Ȱ����� �߰� �Ҷ���");

	//  �̹� �ִ� ���̸� ����
	if (Scene_List.find(KeyName) != Scene_List.end()) return;

	// ����Ʈ�� �߰�
	Scene_List[KeyName] = Scene;
}

void cSceneManager::ChangeScene(string KeyName)
{
	if (Scene_List.find(KeyName) == Scene_List.end())
	{
		assert(Scene_List.find(KeyName) != Scene_List.end() && "		   �� �߰��� ���س��� �θ�������");
		return;
	}

	if (Scene_List.find(KeyName)->second == CurrentScene)
	{
		assert(Scene_List.find(KeyName)->second != CurrentScene && "         �̹� ������� ���ε� �� �װŷ� �ٲٶ���");
		return;
	}

	// ������� �̹� ������ �������ش�.
	if (CurrentScene)
	{
		//// ��Ŭ���� �Ҵ� �����ϰ�
		SAFE_DELETE(CurrentScene);
		// �ʿ��� �����.
		Scene_List.erase(Scene_List.find(CurrentSceneName)->first);

	}

	// ü������ �� �̸� �����صд�.
	CurrentSceneName = KeyName;
	// ������������� ���������� �ٲܾ� �ʱ�ȭ
	Scene_List.find(KeyName)->second->Setup();
	// ������� �ٲܾ����� ! 
	CurrentScene = Scene_List.find(KeyName)->second;
}

void cSceneManager::ChangeScene(string KeyName, POINT PlayerPos, POINT CameraPos)
{
	if (Scene_List.find(KeyName) == Scene_List.end())
	{
		assert(Scene_List.find(KeyName) != Scene_List.end() && "		   �� �߰��� ���س��� �θ�������");
		return;
	}

	if (Scene_List.find(KeyName)->second == CurrentScene)
	{
		assert(Scene_List.find(KeyName)->second != CurrentScene && "         �̹� ������� ���ε� �� �װŷ� �ٲٶ���");
		return;
	}

	// ������� �̹� ������ �������ش�.
	if (CurrentScene) CurrentScene->Release();

	// ü������ �� �̸� �����صд�.
	CurrentSceneName = KeyName;
	// ������������� ���������� �ٲܾ� �ʱ�ȭ
	Scene_List.find(KeyName)->second->Setup();
	// ������� �ٲܾ����� ! 
	CurrentScene = Scene_List.find(KeyName)->second;

	//CurrentScene->GetPlayer()->SetPostision(PlayerPos.x, PlayerPos.y);
	CAMERAMANAGER->CameraPosition(CameraPos.x, CameraPos.y);
}

void cSceneManager::Update()
{
	assert(CurrentScene != NULL && "											�߰��� ���� ���� �����Ű����");
	CurrentScene->Update();
}

void cSceneManager::Render()
{
	assert(CurrentScene != NULL && "											�߰��� ���� ���� �����Ű����");
	CurrentScene->Render();
}


