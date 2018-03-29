#include "stdafx.h"
#include "cFrame.h"

#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
//timeGetTime �Լ��� ����ϱ� ���� ���̺귯�� �߰�
//�����찡 ���۵ǰ� �� ���� �ð��� ����

cFrame::cFrame()
{

}

cFrame::~cFrame()
{

}

void cFrame::Setup()
{
	//���� Ÿ�̸� �������θ� üũ�Ѵ�.
	//���� Ÿ�̸Ӹ� �����ϸ� �ʴ� ����ũ�μ��ϵ���� ���� ����.   // (1/1000000)
	//�ð� ����
	if (QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency))
	{
		//64��Ʈ ������ ����� �� �ֵ��� ������ ������
		//����ũ�μ����带 (1/1000000)�� ���� �����Ͽ� ���� ��Ȯ�� �ð����� �����ϱ� ����
		_isHardware = true;
		QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime);

		//�ʴ� �ð� ��� ����
		_timeScale = 1.0f / _periodFrequency;
	}

	else
	{
		_isHardware = false;
		//�и������� ������ �ð����� �ʴ� 1000�� ī��Ʈ
		_lastTime = timeGetTime();
		_timeScale = 0.001f;
	}

	FPS = 0;
	FPS_Count = 0;
	_FPStimeElapsed = 0.0f;
	_worldTime = 0;

}

void cFrame::Update(float lockFPS)
{
	//���� Ÿ�̸Ӹ� �����Ѵٸ�
	if (_isHardware)
	{
		//�� ���� ����ũ���� ������ ����Ѵ�.(1/1000000)
		QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
	}
	else
	{
		//�������� ������ time�Լ��� �̿� �и�������(1/1000)
		_curTime = timeGetTime();
	}

	// ������ ���൵  // ����ð��� �������ð��� �����
	_timeElapsed = (_curTime - _lastTime) * _timeScale;

	if (lockFPS > 0.0f)
	{
		//���� �������� �ð��� �����Ҷ����� �������Ѷ�
		while (_timeElapsed < (1.0f / lockFPS))
		{
			if (_isHardware) QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
			else _curTime = timeGetTime();

			//������ �ð��� ���� �ð��� �����
			_timeElapsed = (_curTime - _lastTime) * _timeScale;
		}
	}

	_lastTime = _curTime;				//������ �ð��� ���
	FPS_Count++;						//�ڵ����� ������ ī��Ʈ ����
	_FPStimeElapsed += _timeElapsed;	//�ʴ� ������ �ð� ����� ����
	_worldTime += _timeElapsed;			//��ü �ð� ����� ����

										//������ �ʱ�ȭ�� 1�ʸ��� ����
	if (_FPStimeElapsed > 1.0f)
	{
		FPS = FPS_Count;
		FPS_Count = 0;
		_FPStimeElapsed = 0.0f;

	}
}
