#include "stdafx.h"
#include "cFrame.h"

#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
//timeGetTime 함수를 사용하기 위한 라이브러리 추가
//윈도우가 시작되고 난 뒤의 시간을 리턴

cFrame::cFrame()
{

}

cFrame::~cFrame()
{

}

void cFrame::Setup()
{
	//고성능 타이머 지원여부를 체크한다.
	//고성능 타이머를 지원하면 초당 마이크로세턴드까지 값이 들어간다.   // (1/1000000)
	//시간 측정
	if (QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency))
	{
		//64비트 정수를 사용할 수 있도록 정의한 이유는
		//마이크로세컨드를 (1/1000000)초 까지 측정하여 좀더 정확한 시간값을 저장하기 위함
		_isHardware = true;
		QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime);

		//초당 시간 계산 범위
		_timeScale = 1.0f / _periodFrequency;
	}

	else
	{
		_isHardware = false;
		//밀리세컨드 단위의 시간으로 초당 1000번 카운트
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
	//고성능 타이머를 지원한다면
	if (_isHardware)
	{
		//초 정밀 마이크로초 단위로 계산한다.(1/1000000)
		QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
	}
	else
	{
		//지원하지 않으면 time함수를 이용 밀리세컨드(1/1000)
		_curTime = timeGetTime();
	}

	// 프레임 진행도  // 현재시간과 마지막시간의 경과량
	_timeElapsed = (_curTime - _lastTime) * _timeScale;

	if (lockFPS > 0.0f)
	{
		//고정 프레임의 시간을 만족할때까지 루프시켜라
		while (_timeElapsed < (1.0f / lockFPS))
		{
			if (_isHardware) QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
			else _curTime = timeGetTime();

			//마지막 시간과 현재 시간의 경과량
			_timeElapsed = (_curTime - _lastTime) * _timeScale;
		}
	}

	_lastTime = _curTime;				//마지막 시간을 기록
	FPS_Count++;						//자동으로 프레임 카운트 증가
	_FPStimeElapsed += _timeElapsed;	//초당 프레임 시간 경과량 증가
	_worldTime += _timeElapsed;			//전체 시간 경과량 증가

										//프레임 초기화를 1초마다 진행
	if (_FPStimeElapsed > 1.0f)
	{
		FPS = FPS_Count;
		FPS_Count = 0;
		_FPStimeElapsed = 0.0f;

	}
}
