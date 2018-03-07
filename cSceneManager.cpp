#include "stdafx.h"
#include "cSceneManager.h"
#include "SceneList.h"


cSceneManager::cSceneManager()
{
}


cSceneManager::~cSceneManager()
{
}
//스태틱으로 선언 되어있으므로 초기화는 여기서
SceneList* cSceneManager::_currentScene = NULL;
SceneList* cSceneManager::_loadingScene = NULL;
SceneList* cSceneManager::_readyScene = NULL;

HRESULT cSceneManager::init(void)
{
	_currentScene = NULL;
	_loadingScene = NULL;
	_readyScene = NULL;


	return S_OK;
}

void cSceneManager::release(void)
{
	mapSceneIter miSceneList = _mSceneList.begin();

	for (; miSceneList != _mSceneList.end();) //해당 씬리스트를 찾을떄까지검사
	{
		if (miSceneList->second != NULL)
		{
			if (miSceneList->second == _currentScene) delete miSceneList->second; //<딜리트
			SAFE_DELETE(miSceneList->second);
			miSceneList = _mSceneList.erase(miSceneList);
		}
		else ++miSceneList;
	}

	_mSceneList.clear();
}

void cSceneManager::update(void)
{
	if (_currentScene) _currentScene->update();
}

void cSceneManager::render(void)
{
	if (_currentScene) _currentScene->render();
}

SceneList * cSceneManager::addScene(string sceneName, SceneList * scene)
{
	//씬이 없다면 널값 반환
	if (!scene) return NULL;

	//씬에 키 값을 부여해서 map컨테이너에 담아준다
	_mSceneList.insert(std::map<string, SceneList*>::value_type(sceneName, scene));

	//반환
	return scene;
}

SceneList * cSceneManager::addLoadingScene(string loadingSceneName, SceneList * scene)
{
	return nullptr;
}

HRESULT cSceneManager::changeScene(string sceneName)
{
	//이터레이터에 찾고자하는 씬의 키 값을 대입
	mapSceneIter find = _mSceneList.find(sceneName);

	//이터레이터가 맵의 끝까지 갔다 == 찾고자하는게 없다 실패 반환
	if (find == _mSceneList.end()) return E_FAIL;

	//만약 바꾸려는 씬이 현재 씬이면 그냥 둔다
	if (find->second == _currentScene) return S_OK;

	//성공적으로 씬이 바뀐다면 init함수 실행 
	if (SUCCEEDED(find->second->init()))
	{
		//만약 현재씬에 다른 씬이 있다면 해제 해주고
		if (_currentScene) delete _currentScene;

		//바꾸려는 씬으로 체인지 한다
		_currentScene = find->second;

		//지금 씬 변환하는 이 구조는 여러분이 입맛에 따라 바꿔도 된다
		//디폴트로 만들어 놨지만 위에 구조의 단점이 딱 하나 있는데
		//스테이지1 -> 스테이지2로 씬이 바뀌었을때 스테이지1의 데이터를
		//넘기려고 할때 릴리즈가 먼저 호출이 되서 조금 신경을 써줘야한다

		//뭐 그렇다고.. ㅎ _ㅎ)

		return S_OK;
	}

	return E_FAIL;
}

HRESULT cSceneManager::changeScene(string sceneName, string loadingSceneName)
{
	return E_NOTIMPL;
}
