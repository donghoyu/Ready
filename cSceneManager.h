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
	static SceneList* _currentScene;	//���� ��
	static SceneList* _loadingScene;	//�ε� ��(�Ⱦ��ϵ�)
	static SceneList* _readyScene;		//��� ��

	mapSceneList _mSceneList;
	mapSceneList _mLoadingSceneList;

	DWORD _loadingThreadID;			//Ȥ�� ���� �־���� ������� ID

public:


	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	//�� �߰� �Լ�
	SceneList* addScene(string sceneName, SceneList* scene);
	SceneList* addLoadingScene(string loadingSceneName, SceneList* scene);

	//�� ����
	HRESULT changeScene(string sceneName);
	HRESULT changeScene(string sceneName, string loadingSceneName);

	//friend�� �����ϸ� Ŭ������ private���� �׳� ���� ������ �Ѵ�
	//�����ϸ� �ȵǴµ�, ������ ���� 1~2�������� �صθ� ���� �� ������ �ص���
	friend DWORD CALLBACK loadingThread(LPVOID prc);
};

