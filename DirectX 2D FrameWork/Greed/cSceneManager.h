#pragma once
#define SCENEMANAGER cSceneManager::GetInstance()

class cScene;
class cSceneManager
{
private:
	// ½Ì±ÛÅæ ¼³Á¤
	SINGLETONE(cSceneManager);
	// ¾À ¸ð¾ÆµÑ ¸®½ºÆ®
	map<string, cScene*> Scene_List;
	// ÇöÀç ¾À
	cScene*	CurrentScene;
	string CurrentSceneName;
public:

	void Destory();			   // ¾À ¸Å´ÏÁ® ÇØÁ¦

	cScene* FindScene(string KeyName);
	void AddScene(string KeyName, cScene* Scene);
	void ChangeScene(string KeyName);
	void ChangeScene(string KeyName, POINT PlayerPos, POINT CameraPos);

	void Update();
	void Render();


};
