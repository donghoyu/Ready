#pragma once
#define SCENEMANAGER		cSceneManager::GetInstance()
#include <map>
#include <string>
class SceneList;
class cSceneManager
{
private:
	SINGLETONE(cSceneManager);
	typedef map<string, SceneList*>					mapSceneList;
	typedef map<string, SceneList*>::iterator		mapSceneIter;

public:
	static SceneList* _currentScene;	//현재 씬
	static SceneList* _loadingScene;	//로딩 씬(안쓰일듯)
	static SceneList* _readyScene;		//대기 씬

	mapSceneList _mSceneList;
	mapSceneList _mLoadingSceneList;

	DWORD _loadingThreadID;			//혹시 몰라 넣어놓는 쓰레드용 ID

public:


	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	//씬 추가 함수
	SceneList* addScene(string sceneName, SceneList* scene);
	SceneList* addLoadingScene(string loadingSceneName, SceneList* scene);

	//씬 변경
	HRESULT changeScene(string sceneName);
	HRESULT changeScene(string sceneName, string loadingSceneName);

	//friend란 선언하면 클래스의 private까지 그냥 접근 가능케 한다
	//남발하면 안되는데, 구조상 왠지 1~2개정도는 해두면 좋을 것 같으면 해도됨
	friend DWORD CALLBACK loadingThread(LPVOID prc);
};

