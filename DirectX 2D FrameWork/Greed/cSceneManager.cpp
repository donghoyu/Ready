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

{	// 씬 리스트 돌면서 
	for each(auto p in Scene_List)
	{
		SAFE_DELETE(p.second);					// 맵에 동적할당 해두었던 씬 클래스 해제
	}
	// 다 지웠으니 맵 클리어.
	Scene_List.clear();
}


cScene * cSceneManager::FindScene(string KeyName)
{
	if (Scene_List.find(KeyName) != Scene_List.end()) return Scene_List[KeyName];

	return NULL;
}

void cSceneManager::AddScene(string KeyName, cScene * Scene)
{
	assert(Scene_List.find(KeyName) == Scene_List.end() && "         씬 추가했는데 똑같은거 추가 할라함");

	//  이미 있는 씬이면 종료
	if (Scene_List.find(KeyName) != Scene_List.end()) return;

	// 리스트에 추가
	Scene_List[KeyName] = Scene;
}

void cSceneManager::ChangeScene(string KeyName)
{
	if (Scene_List.find(KeyName) == Scene_List.end())
	{
		assert(Scene_List.find(KeyName) != Scene_List.end() && "		   씬 추가도 안해놓고 부르려고함");
		return;
	}

	if (Scene_List.find(KeyName)->second == CurrentScene)
	{
		assert(Scene_List.find(KeyName)->second != CurrentScene && "         이미 재생중인 씬인데 또 그거로 바꾸라함");
		return;
	}

	// 현재씬이 이미 있으면 해제해준다.
	if (CurrentScene)
	{
		//// 씬클래스 할당 해제하고
		SAFE_DELETE(CurrentScene);
		// 맵에서 지운다.
		Scene_List.erase(Scene_List.find(CurrentSceneName)->first);

	}

	// 체인지한 씬 이름 저장해둔다.
	CurrentSceneName = KeyName;
	// 여기까지왔으면 문제없으니 바꿀씬 초기화
	Scene_List.find(KeyName)->second->Setup();
	// 현재씬을 바꿀씬으로 ! 
	CurrentScene = Scene_List.find(KeyName)->second;
}

void cSceneManager::ChangeScene(string KeyName, POINT PlayerPos, POINT CameraPos)
{
	if (Scene_List.find(KeyName) == Scene_List.end())
	{
		assert(Scene_List.find(KeyName) != Scene_List.end() && "		   씬 추가도 안해놓고 부르려고함");
		return;
	}

	if (Scene_List.find(KeyName)->second == CurrentScene)
	{
		assert(Scene_List.find(KeyName)->second != CurrentScene && "         이미 재생중인 씬인데 또 그거로 바꾸라함");
		return;
	}

	// 현재씬이 이미 있으면 해제해준다.
	if (CurrentScene) CurrentScene->Release();

	// 체인지한 씬 이름 저장해둔다.
	CurrentSceneName = KeyName;
	// 여기까지왔으면 문제없으니 바꿀씬 초기화
	Scene_List.find(KeyName)->second->Setup();
	// 현재씬을 바꿀씬으로 ! 
	CurrentScene = Scene_List.find(KeyName)->second;

	//CurrentScene->GetPlayer()->SetPostision(PlayerPos.x, PlayerPos.y);
	CAMERAMANAGER->CameraPosition(CameraPos.x, CameraPos.y);
}

void cSceneManager::Update()
{
	assert(CurrentScene != NULL && "											추가도 안한 씬을 재생시키려함");
	CurrentScene->Update();
}

void cSceneManager::Render()
{
	assert(CurrentScene != NULL && "											추가도 안한 씬을 재생시키려함");
	CurrentScene->Render();
}


