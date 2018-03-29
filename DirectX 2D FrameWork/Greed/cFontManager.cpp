#include "stdafx.h"
#include "cFontManager.h"

cFontManager::cFontManager()
{
	// �̹��� �����ġ ����
	D3DXCreateSprite(DEVICEMANAGER, &Renderer);
}

cFontManager::~cFontManager()
{
}

void cFontManager::Destory()
{
	Destory_List();			// ��Ʈ   ����Ʈ  ����
	Renderer->Release();	// �̹��� �����ġ ����
}

void cFontManager::Destory_List()
{
	// ��Ʈ ����Ʈ ���鼭 
	for each(auto p in Font_List)
	{
		p.second.Font->Release(); // ���� �Ͽ��� ��Ʈ ����
	}
	// �� �������� �� Ŭ����.
	Font_List.clear();

}

void cFontManager::AddFont(string FontName, int Width, int Height)
{
	// �ߺ������ʴ� ���ο� ��Ʈ��. // ��Ʈ����Ʈ�� ����.
	if (Font_List.find(FontName) == Font_List.end())
	{
		// ���� �� ��ȯ
		wstring TempStr(FontName.begin(), FontName.end());

		D3DXFONT_DESC Font_Data;						// ��Ʈ�� ������ ��Ƶ� ����ü
		ZeroMemory(&Font_Data, sizeof(D3DXFONT_DESC));  // �ѹ� �Ʋ��ϰ� �о��ش�.
		Font_Data.Width = Width;						// ��Ʈ�� ���� (����)
		Font_Data.Height = Height;					    // ��Ʈ�� ���� (����)
		Font_Data.Weight = FW_BOLD;						// ��Ʈ�� �β� 
		Font_Data.Italic = false;						// ��Ʈ�� ����
		Font_Data.CharSet = DEFAULT_CHARSET;			// �����ڵ�� ������ �������踦 �����ϴ� ���ڼ�
		Font_Data.OutputPrecision = OUT_DEFAULT_PRECIS; // ��� ��Ȯ���� ����
		Font_Data.PitchAndFamily = FF_DONTCARE;			// ��Ʈ�� ��ġ�� ����
		wcscpy_s(Font_Data.FaceName, TempStr.c_str());

		// ��Ʈ ����
		sFontData TempFontData;
		TempFontData.Width = Font_Data.Width;
		TempFontData.Height = Font_Data.Height;
		D3DXCreateFontIndirect(DEVICEMANAGER, &Font_Data, &TempFontData.Font);

		// ����Ʈ�� �߰�
		Font_List[FontName] = TempFontData;
	}
	// �̹� �����ϴ� ��Ʈ�� ����
	else
		return;
}

void cFontManager::AddFont(string FontName, string FileRoute, int Width, int Height)
{

	// �ߺ������ʴ� ���ο� ��Ʈ��. // ��Ʈ����Ʈ�� ����.
	if (Font_List.find(FontName) == Font_List.end())
	{
		// �ܺ� ���� ��η� ��Ʈ �߰�   
		wstring TempFileRoute(FileRoute.begin(), FileRoute.end());
		AddFontResourceEx(TempFileRoute.c_str(), FR_PRIVATE, 0);

		// ���� �� ��ȯ
		wstring TempStr(FontName.begin(), FontName.end());

		D3DXFONT_DESC Font_Data;						// ��Ʈ�� ������ ��Ƶ� ����ü
		ZeroMemory(&Font_Data, sizeof(D3DXFONT_DESC));  // �ѹ� �Ʋ��ϰ� �о��ش�.
		Font_Data.Width = Width;						// ��Ʈ�� ���� (����)
		Font_Data.Height = Height;					    // ��Ʈ�� ���� (����)
		Font_Data.Weight = FW_BOLD;						// ��Ʈ�� �β� 
		Font_Data.Italic = false;						// ��Ʈ�� ����
		Font_Data.CharSet = DEFAULT_CHARSET;			// �����ڵ�� ������ �������踦 �����ϴ� ���ڼ�
		Font_Data.OutputPrecision = OUT_DEFAULT_PRECIS; // ��� ��Ȯ���� ����
		Font_Data.PitchAndFamily = FF_DONTCARE;			// ��Ʈ�� ��ġ�� ����
		wcscpy_s(Font_Data.FaceName, TempStr.c_str());

		// ��Ʈ ����
		sFontData TempFontData;
		TempFontData.Width = Font_Data.Width;
		TempFontData.Height = Font_Data.Height;
		D3DXCreateFontIndirect(DEVICEMANAGER, &Font_Data, &TempFontData.Font);

		// ����Ʈ�� �߰�
		Font_List[FontName] = TempFontData;
	}
	// �̹� ��Ʈ�� ����
	else
		return;
}

void cFontManager::Render(string FontName, string Str, int x, int y, double Width, double Height, int Alpa, int R, int G, int B, float Angle)
{
	assert(Font_List.find(FontName) != Font_List.end() && "                �߰� ���� ��Ʈ�� ���� ����");

	// ������ ��ȯ ���� ���� �ӽ� ����
	double TempX, TempY;

	// ������ �ִ� ������� ��ȯ�� ����� ����ؼ�
	TempX = Width / Font_List[FontName].Width;
	TempY = Height / Font_List[FontName].Height;

	// ��ķ� ������ �����ش�.  // ũ�� ��ȯ        *   ȸ�� ��       *       �̵�
	Renderer->SetTransform(&(Scaling(TempX, TempY) * Rotation(Angle) * Translation(x, y)));
	Renderer->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);	// �ؽ��� �׸��� ���� !

																		// ���� ���ϴ� ��Ʈ�� ã�� ������ ���� �׸���.
	Font_List[FontName].Font->DrawTextA(Renderer, Str.c_str(), -1, &RectMake(0, 0, WINSIZEX, WINSIZEY), DT_NOCLIP, D3DCOLOR_ARGB(Alpa, R, G, B));

	Renderer->End();							// �ؽ��� �׸��� ����.
}
