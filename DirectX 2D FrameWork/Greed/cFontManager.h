#pragma once
#define FONTMANAGER	cFontManager::GetInstance()


class cFontManager
{
private:
	SINGLETONE(cFontManager);

	// ��Ʈ ���� ��Ƶ� ����ü
	struct sFontData
	{
		LPD3DXFONT  Font;
		double		Width;
		double		Height;
	};

	// ��Ʈ ��Ƶ� ����Ʈ
	map<string, sFontData> Font_List;
	// ��Ʈ ��� ��ġ
	ID3DXSprite* Renderer;

public:

	void Destory();				// ��Ʈ �Ŵ��� ����
	void Destory_List();		// ��Ʈ ����Ʈ ����

	void AddFont(string FontName, int Width, int Height);
	void AddFont(string FontName, string FileRoute, int Width, int Height);

	void Render(string FontName, string Str, int x, int y, double Width, double Height, int Alpa, int R, int G, int B, float Angle);
};
