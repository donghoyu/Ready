#pragma once

class cPlayer;
class cMap;
class cScene
{
protected:
	cPlayer* _Player;
	cMap*	 _Map;

public:
	cScene();
	virtual ~cScene();

	virtual void Release() = 0;
	virtual void Setup() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

	cPlayer* GetPlayer() { return _Player; }
	void SetPlayer(cPlayer* p_mPlayer) { _Player = p_mPlayer; }
};
