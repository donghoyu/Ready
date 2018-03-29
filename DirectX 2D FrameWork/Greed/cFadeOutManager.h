#pragma once
#define FADEOUTMANAGER	cFadeOutManager::GetInstance()


class cFadeOutManager
{
private:
	// 싱글톤 화
	SINGLETONE(cFadeOutManager);

	// 페이드아웃 상태
	enum FADESTATUS
	{
		NONE,
		ON,
		OFF
	};

	// 진행할 함수
	bool(*Fade)(int& Value);
	// 씬 체인지에 쓰일 모드
	bool ChageSetMode;
	// 페이드아웃 상태 이넘문
	FADESTATUS FadeStatus;
	// 검은색 페이드용 알파값
	int FadeAlpa;
	// 변경할 씬 이름
	string ChangeSceneName;
	// 변경할 씬 상태 위치값
	POINT PlayerPos, CameraPos;
public:

	void Update();
	void Render();
	void Render(double SizeX, double SizeY);

	void FadeStart(string ChangeScene);
	void FadeStart(string ChangeScene, POINT Ppos, POINT Cpos);
	static bool FadeIn(int& Value);
	static bool FadeOut(int& Value);

};
