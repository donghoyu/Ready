#pragma once
#define FONTMANAGER	cFontManager::GetInstance()


class cFontManager
{
private:
	SINGLETONE(cFontManager);

	// 폰트 정보 담아둘 구조체
	struct sFontData
	{
		LPD3DXFONT  Font;
		double		Width;
		double		Height;
	};

	// 폰트 모아둔 리스트
	map<string, sFontData> Font_List;
	// 폰트 출력 장치
	ID3DXSprite* Renderer;

public:

	void Destory();				// 폰트 매니져 해제
	void Destory_List();		// 폰트 리스트 해제

	void AddFont(string FontName, int Width, int Height);
	void AddFont(string FontName, string FileRoute, int Width, int Height);

	void Render(string FontName, string Str, int x, int y, double Width, double Height, int Alpa, int R, int G, int B, float Angle);
};
