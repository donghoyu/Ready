#pragma once
#define FADEOUTMANAGER	cFadeOutManager::GetInstance()


class cFadeOutManager
{
private:
	// �̱��� ȭ
	SINGLETONE(cFadeOutManager);

	// ���̵�ƿ� ����
	enum FADESTATUS
	{
		NONE,
		ON,
		OFF
	};

	// ������ �Լ�
	bool(*Fade)(int& Value);
	// �� ü������ ���� ���
	bool ChageSetMode;
	// ���̵�ƿ� ���� �̳ѹ�
	FADESTATUS FadeStatus;
	// ������ ���̵�� ���İ�
	int FadeAlpa;
	// ������ �� �̸�
	string ChangeSceneName;
	// ������ �� ���� ��ġ��
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
