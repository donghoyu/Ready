#pragma once
 
class cMainGame
{
private:
 
 

public:
	cMainGame();
	~cMainGame();

	void Setup();
	void Update();
	void Render();

	LRESULT WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};

