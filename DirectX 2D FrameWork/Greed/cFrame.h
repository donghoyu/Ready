#pragma once

class cFrame
{
private:
	bool _isHardware;			//���� Ÿ�̸Ӹ� �����ϳ�?

	float _timeScale;			//�ð� �����
	float _timeElapsed;			//�� �����Ӵ� �����

	__int64 _curTime;			//����ð�
	__int64 _lastTime;			//�������ð�
	__int64 _periodFrequency;	//�ð��ֱ�

	unsigned long FPS;			//FPS
	unsigned long FPS_Count;	//FPS ī��Ʈ
	float _FPStimeElapsed;		//FPS �������ð��� ���� �ð��� �����

	float _worldTime;			//��ü �ð� �����
public:
	cFrame();
	~cFrame();

	//Ÿ�̸� �ʱ�ȭ	
	void Setup();
	//���� �ð� ���
	void Update(float lockFPS = 0.0f);

	//���� FPS ��������
	unsigned long getFPS() const { return FPS; }
	//�������Ӵ� ��� �ð�
	float getElapsedTime() const { return _timeElapsed; }
	//��ü ��� �ð� ��������
	float getWorldTime() const { return _worldTime; }
};
