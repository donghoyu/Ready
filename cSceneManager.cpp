#include "stdafx.h"
#include "cSceneManager.h"
#include "SceneList.h"


cSceneManager::cSceneManager()
{
}


cSceneManager::~cSceneManager()
{
}
//����ƽ���� ���� �Ǿ������Ƿ� �ʱ�ȭ�� ���⼭
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

	for (; miSceneList != _mSceneList.end();) //�ش� ������Ʈ�� ã���������˻�
	{
		if (miSceneList->second != NULL)
		{
			if (miSceneList->second == _currentScene) delete miSceneList->second; //<����Ʈ
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
	//���� ���ٸ� �ΰ� ��ȯ
	if (!scene) return NULL;

	//���� Ű ���� �ο��ؼ� map�����̳ʿ� ����ش�
	_mSceneList.insert(std::map<string, SceneList*>::value_type(sceneName, scene));

	//��ȯ
	return scene;
}

SceneList * cSceneManager::addLoadingScene(string loadingSceneName, SceneList * scene)
{
	return nullptr;
}

HRESULT cSceneManager::changeScene(string sceneName)
{
	//���ͷ����Ϳ� ã�����ϴ� ���� Ű ���� ����
	mapSceneIter find = _mSceneList.find(sceneName);

	//���ͷ����Ͱ� ���� ������ ���� == ã�����ϴ°� ���� ���� ��ȯ
	if (find == _mSceneList.end()) return E_FAIL;

	//���� �ٲٷ��� ���� ���� ���̸� �׳� �д�
	if (find->second == _currentScene) return S_OK;

	//���������� ���� �ٲ�ٸ� init�Լ� ���� 
	if (SUCCEEDED(find->second->init()))
	{
		//���� ������� �ٸ� ���� �ִٸ� ���� ���ְ�
		if (_currentScene) delete _currentScene;

		//�ٲٷ��� ������ ü���� �Ѵ�
		_currentScene = find->second;

		//���� �� ��ȯ�ϴ� �� ������ �������� �Ը��� ���� �ٲ㵵 �ȴ�
		//����Ʈ�� ����� ������ ���� ������ ������ �� �ϳ� �ִµ�
		//��������1 -> ��������2�� ���� �ٲ������ ��������1�� �����͸�
		//�ѱ���� �Ҷ� ����� ���� ȣ���� �Ǽ� ���� �Ű��� ������Ѵ�

		//�� �׷��ٰ�.. �� _��)

		return S_OK;
	}

	return E_FAIL;
}

HRESULT cSceneManager::changeScene(string sceneName, string loadingSceneName)
{
	return E_NOTIMPL;
}
