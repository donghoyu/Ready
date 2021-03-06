#pragma once

class cFrame
{
private:
	bool _isHardware;			//고성능 타이머를 지원하냐?

	float _timeScale;			//시간 경과량
	float _timeElapsed;			//한 프레임당 경과량

	__int64 _curTime;			//현재시간
	__int64 _lastTime;			//마지막시간
	__int64 _periodFrequency;	//시간주기

	unsigned long FPS;			//FPS
	unsigned long FPS_Count;	//FPS 카운트
	float _FPStimeElapsed;		//FPS 마지막시간과 현재 시간의 경과량

	float _worldTime;			//전체 시간 경과량
public:
	cFrame();
	~cFrame();

	//타이머 초기화	
	void Setup();
	//현재 시간 계산
	void Update(float lockFPS = 0.0f);

	//현재 FPS 가져오기
	unsigned long getFPS() const { return FPS; }
	//한프레임당 경과 시간
	float getElapsedTime() const { return _timeElapsed; }
	//전체 경과 시간 가져오기
	float getWorldTime() const { return _worldTime; }
};
