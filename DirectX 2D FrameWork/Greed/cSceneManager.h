#pragma once
#define SCENEMANAGER cSceneManager::GetInstance()

class cScene;
class cSceneManager
{
private:
	// �̱��� ����
	SINGLETONE(cSceneManager);
	// �� ��Ƶ� ����Ʈ
	map<string, cScene*> Scene_List;
	// ���� ��
	cScene*	CurrentScene;
	string CurrentSceneName;
public:

	void Destory();			   // �� �Ŵ��� ����

	cScene* FindScene(string KeyName);
	void AddScene(string KeyName, cScene* Scene);
	void ChangeScene(string KeyName);
	void ChangeScene(string KeyName, POINT PlayerPos, POINT CameraPos);

	void Update();
	void Render();


};
