#include "stdafx.h"
#include "cFontManager.h"

cFontManager::cFontManager()
{
	// 이미지 출력장치 생성
	D3DXCreateSprite(DEVICEMANAGER, &Renderer);
}

cFontManager::~cFontManager()
{
}

void cFontManager::Destory()
{
	Destory_List();			// 폰트   리스트  제거
	Renderer->Release();	// 이미지 출력장치 제거
}

void cFontManager::Destory_List()
{
	// 폰트 리스트 돌면서 
	for each(auto p in Font_List)
	{
		p.second.Font->Release(); // 생성 하였던 폰트 해제
	}
	// 다 지웠으니 맵 클리어.
	Font_List.clear();

}

void cFontManager::AddFont(string FontName, int Width, int Height)
{
	// 중복되지않는 새로운 폰트다. // 폰트리스트에 없다.
	if (Font_List.find(FontName) == Font_List.end())
	{
		// 파일 형 변환
		wstring TempStr(FontName.begin(), FontName.end());

		D3DXFONT_DESC Font_Data;						// 폰트의 정보를 담아둘 구조체
		ZeroMemory(&Font_Data, sizeof(D3DXFONT_DESC));  // 한번 꺠끗하게 밀어준다.
		Font_Data.Width = Width;						// 폰트의 길이 (가로)
		Font_Data.Height = Height;					    // 폰트의 높이 (세로)
		Font_Data.Weight = FW_BOLD;						// 폰트의 두께 
		Font_Data.Italic = false;						// 폰트의 기울기
		Font_Data.CharSet = DEFAULT_CHARSET;			// 문자코드와 문자의 대응관계를 정의하는 문자셋
		Font_Data.OutputPrecision = OUT_DEFAULT_PRECIS; // 출력 정확도를 설정
		Font_Data.PitchAndFamily = FF_DONTCARE;			// 폰트의 피치를 설정
		wcscpy_s(Font_Data.FaceName, TempStr.c_str());

		// 폰트 생성
		sFontData TempFontData;
		TempFontData.Width = Font_Data.Width;
		TempFontData.Height = Font_Data.Height;
		D3DXCreateFontIndirect(DEVICEMANAGER, &Font_Data, &TempFontData.Font);

		// 리스트에 추가
		Font_List[FontName] = TempFontData;
	}
	// 이미 존재하는 폰트면 종료
	else
		return;
}

void cFontManager::AddFont(string FontName, string FileRoute, int Width, int Height)
{

	// 중복되지않는 새로운 폰트다. // 폰트리스트에 없다.
	if (Font_List.find(FontName) == Font_List.end())
	{
		// 외부 파일 경로로 폰트 추가   
		wstring TempFileRoute(FileRoute.begin(), FileRoute.end());
		AddFontResourceEx(TempFileRoute.c_str(), FR_PRIVATE, 0);

		// 파일 형 변환
		wstring TempStr(FontName.begin(), FontName.end());

		D3DXFONT_DESC Font_Data;						// 폰트의 정보를 담아둘 구조체
		ZeroMemory(&Font_Data, sizeof(D3DXFONT_DESC));  // 한번 꺠끗하게 밀어준다.
		Font_Data.Width = Width;						// 폰트의 길이 (가로)
		Font_Data.Height = Height;					    // 폰트의 높이 (세로)
		Font_Data.Weight = FW_BOLD;						// 폰트의 두께 
		Font_Data.Italic = false;						// 폰트의 기울기
		Font_Data.CharSet = DEFAULT_CHARSET;			// 문자코드와 문자의 대응관계를 정의하는 문자셋
		Font_Data.OutputPrecision = OUT_DEFAULT_PRECIS; // 출력 정확도를 설정
		Font_Data.PitchAndFamily = FF_DONTCARE;			// 폰트의 피치를 설정
		wcscpy_s(Font_Data.FaceName, TempStr.c_str());

		// 폰트 생성
		sFontData TempFontData;
		TempFontData.Width = Font_Data.Width;
		TempFontData.Height = Font_Data.Height;
		D3DXCreateFontIndirect(DEVICEMANAGER, &Font_Data, &TempFontData.Font);

		// 리스트에 추가
		Font_List[FontName] = TempFontData;
	}
	// 이미 폰트면 종료
	else
		return;
}

void cFontManager::Render(string FontName, string Str, int x, int y, double Width, double Height, int Alpa, int R, int G, int B, float Angle)
{
	assert(Font_List.find(FontName) != Font_List.end() && "                추가 안한 폰트를 쓰라 했음");

	// 사이즈 변환 정보 받을 임시 변수
	double TempX, TempY;

	// 가지고 있던 사이즈와 변환할 사이즈를 계산해서
	TempX = Width / Font_List[FontName].Width;
	TempY = Height / Font_List[FontName].Height;

	// 행렬로 비율을 맞춰준다.  // 크기 변환        *   회전 값       *       이동
	Renderer->SetTransform(&(Scaling(TempX, TempY) * Rotation(Angle) * Translation(x, y)));
	Renderer->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);	// 텍스쳐 그리기 시작 !

																		// 내가 원하는 폰트를 찾아 정보를 토대로 그린다.
	Font_List[FontName].Font->DrawTextA(Renderer, Str.c_str(), -1, &RectMake(0, 0, WINSIZEX, WINSIZEY), DT_NOCLIP, D3DCOLOR_ARGB(Alpa, R, G, B));

	Renderer->End();							// 텍스쳐 그리기 종료.
}
