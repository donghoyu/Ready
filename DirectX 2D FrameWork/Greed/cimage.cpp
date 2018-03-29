#include "stdafx.h"
#include "cimage.h"

cimage::cimage()
{
	Renderer = IMAGEMANAGER->GetRenderer();
}

cimage::~cimage()
{
	SAFE_RELEASE(_imageInfo._Image_Texture);
}

void cimage::SetUp(const char * FileName)
{
	// 불러올 폴더이름 + 파일 이름
	string   Temp = FileName;
	// 유니코드로 변환 
	wstring	 TempName(Temp.begin(), Temp.end());
	// 이미지 파일 로드
	D3DXCreateTextureFromFileEx(
		DEVICEMANAGER,
		TempName.c_str(),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 255, 255),
		NULL,
		NULL,
		&_imageInfo._Image_Texture);

}

void cimage::SetUp(const char * FileName, int width, int height)
{
	// 불러올 폴더이름 + 파일 이름
	string   Temp = FileName;
	// 유니코드로 변환 
	wstring	 TempName(Temp.begin(), Temp.end());
	// 이미지 파일 로드
	D3DXCreateTextureFromFileEx(
		DEVICEMANAGER,
		TempName.c_str(),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 255, 255),
		NULL,
		NULL,
		&_imageInfo._Image_Texture);

	_imageInfo._Image_Width = width;
	_imageInfo._Image_Height = height;
}

void cimage::SetUp(const char * FileName, int width, int height, int FrameX, int FrameY)
{
	// 불러올 폴더이름 + 파일 이름
	string   Temp = FileName;
	// 유니코드로 변환 
	wstring	 TempName(Temp.begin(), Temp.end());
	// 이미지 파일 로드
	D3DXCreateTextureFromFileEx(
		DEVICEMANAGER,
		TempName.c_str(),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 255, 255),
		NULL,
		NULL,
		&_imageInfo._Image_Texture);

	_imageInfo._Image_Width = width;
	_imageInfo._Image_Height = height;
	_imageInfo._Image_MaxFrameX = FrameX - 1;
	_imageInfo._Image_MaxFrameY = FrameY - 1;
	_imageInfo._Image_FrameWidth = width / FrameX;
	_imageInfo._Image_FrameHeight = height / FrameY;
}

void cimage::SetUp(const char * FileName, int width, int height, int FrameX, int FrameY, D3DCOLOR Color)
{
	// 불러올 폴더이름 + 파일 이름
	string   Temp = FileName;
	// 유니코드로 변환 
	wstring	 TempName(Temp.begin(), Temp.end());
	// 이미지 파일 로드
	D3DXCreateTextureFromFileEx(
		DEVICEMANAGER,
		TempName.c_str(),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_DEFAULT,
		Color,
		NULL,
		NULL,
		&_imageInfo._Image_Texture);

	_imageInfo._Image_Width = width;
	_imageInfo._Image_Height = height;
	_imageInfo._Image_MaxFrameX = FrameX - 1;
	_imageInfo._Image_MaxFrameY = FrameY - 1;
	_imageInfo._Image_FrameWidth = width / FrameX;
	_imageInfo._Image_FrameHeight = height / FrameY;
}

void cimage::Render()
{
	Renderer->Draw(_imageInfo._Image_Texture, 0, 0, 0, D3DCOLOR_ARGB(255, 255, 255, 255));
}


void cimage::Render(float x, float y)
{
	Renderer->Draw(_imageInfo._Image_Texture, 0, 0, &D3DXVECTOR3(x - CAMERAMANAGER->CameraX, y - CAMERAMANAGER->CameraY, 0), D3DCOLOR_ARGB(255, 255, 255, 255));
}

void cimage::Render(float x, float y, double sizeX, double sizeY)
{
	double TempX, TempY;

	TempX = sizeX / _imageInfo._Image_Width;
	TempY = sizeY / _imageInfo._Image_Height;


	Renderer->SetTransform(&(Scaling(TempX, TempY) * (Translation(x - CAMERAMANAGER->CameraX, y - CAMERAMANAGER->CameraY))));
	Renderer->Draw(_imageInfo._Image_Texture, 0, 0, 0, D3DCOLOR_ARGB(255, 255, 255, 255));

	Renderer->SetTransform(&Identity());
}

void cimage::Render(float x, float y, double sizeX, double sizeY, float Angle)
{
	double TempX, TempY;

	TempX = sizeX / _imageInfo._Image_Width;
	TempY = sizeY / _imageInfo._Image_Height;

	Renderer->SetTransform(&(Scaling(TempX, TempY) *  Rotation(Angle) * Translation(x + sizeX / 2 - CAMERAMANAGER->CameraX, y + sizeY / 2 - CAMERAMANAGER->CameraY)));
	Renderer->Draw(_imageInfo._Image_Texture, 0, &VECTOR3((float)_imageInfo._Image_Width / 2, (float)_imageInfo._Image_Height / 2, 0), 0, D3DCOLOR_ARGB(255, 255, 255, 255));

	Renderer->SetTransform(&Identity());
}

void cimage::Render(float x, float y, double sizeX, double sizeY, float Angle, bool Reverse)
{
	double TempX, TempY;

	TempX = sizeX / _imageInfo._Image_Width;
	TempY = sizeY / _imageInfo._Image_Height;

	if (Reverse) Renderer->SetTransform(&(Scaling(-TempX, TempY) *  Rotation(Angle) * Translation(x + sizeX / 2 - CAMERAMANAGER->CameraX, y + sizeY / 2 - CAMERAMANAGER->CameraY)));
	else Renderer->SetTransform(&(Scaling(TempX, TempY) *  Rotation(Angle) * Translation(x + sizeX / 2 - CAMERAMANAGER->CameraX, y + sizeY / 2 - CAMERAMANAGER->CameraY)));

	Renderer->Draw(_imageInfo._Image_Texture, 0, &VECTOR3((float)_imageInfo._Image_Width / 2, (float)_imageInfo._Image_Height / 2, 0), 0, D3DCOLOR_ARGB(255, 255, 255, 255));

	Renderer->SetTransform(&Identity());
}

void cimage::Render(float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp)
{
	double TempX, TempY;

	TempX = sizeX / _imageInfo._Image_Width;
	TempY = sizeY / _imageInfo._Image_Height;

	float ReverseX, ReverseY;

	if (Reverse) ReverseX = -1.0f;
	else ReverseX = 1.0f;

	if (Filp) ReverseY = -1.0f;
	else ReverseY = 1.0f;

	Renderer->SetTransform(&(Scaling(TempX * ReverseX, TempY * ReverseY) *  Rotation(Angle) * Translation(x + sizeX / 2 - CAMERAMANAGER->CameraX, y + sizeY / 2 - CAMERAMANAGER->CameraY)));
	Renderer->Draw(_imageInfo._Image_Texture, 0, &VECTOR3((float)_imageInfo._Image_Width / 2, (float)_imageInfo._Image_Height / 2, 0), 0, D3DCOLOR_ARGB(255, 255, 255, 255));

	Renderer->SetTransform(&Identity());
}

void cimage::Render(float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, RECT Sour)
{
	double TempX, TempY;

	TempX = sizeX / _imageInfo._Image_Width;
	TempY = sizeY / _imageInfo._Image_Height;

	float ReverseX, ReverseY;

	if (Reverse) ReverseX = -1.0f;
	else ReverseX = 1.0f;

	if (Filp) ReverseY = -1.0f;
	else ReverseY = 1.0f;

	if (Sour.right > _imageInfo._Image_Width) Sour.right = _imageInfo._Image_Width;
	if (Sour.bottom > _imageInfo._Image_Height) Sour.bottom = _imageInfo._Image_Height;

	Renderer->SetTransform(&(Scaling(TempX * ReverseX, TempY * ReverseY) *  Rotation(Angle) * Translation(x + sizeX / 2 - CAMERAMANAGER->CameraX, y + sizeY / 2 - CAMERAMANAGER->CameraY)));
	Renderer->Draw(_imageInfo._Image_Texture, &Sour, &VECTOR3((float)_imageInfo._Image_Width / 2, (float)_imageInfo._Image_Height / 2, 0), 0, D3DCOLOR_ARGB(255, 255, 255, 255));

	Renderer->SetTransform(&Identity());
}

void cimage::AlpaRender(int alpa)
{
	Renderer->Draw(_imageInfo._Image_Texture, 0, 0, 0, D3DCOLOR_ARGB(alpa, 255, 255, 255));
}

void cimage::AlpaRender(float x, float y, int alpa)
{
	Renderer->Draw(_imageInfo._Image_Texture, 0, 0, &D3DXVECTOR3(x - CAMERAMANAGER->CameraX, y - CAMERAMANAGER->CameraY, 0), D3DCOLOR_ARGB(alpa, 255, 255, 255));
}

void cimage::AlpaRender(float x, float y, double sizeX, double sizeY, int alpa)
{
	double TempX, TempY;

	TempX = sizeX / _imageInfo._Image_Width;
	TempY = sizeY / _imageInfo._Image_Height;


	Renderer->SetTransform(&(Scaling(TempX, TempY) * (Translation(x - CAMERAMANAGER->CameraX, y - CAMERAMANAGER->CameraY))));
	Renderer->Draw(_imageInfo._Image_Texture, 0, 0, 0, D3DCOLOR_ARGB(alpa, 255, 255, 255));

	Renderer->SetTransform(&Identity());
}

void cimage::AlpaRender(float x, float y, double sizeX, double sizeY, float Angle, int alpa)
{
	double TempX, TempY;

	TempX = sizeX / _imageInfo._Image_Width;
	TempY = sizeY / _imageInfo._Image_Height;

	Renderer->SetTransform(&(Scaling(TempX, TempY) *  Rotation(Angle) * Translation(x + sizeX / 2 - CAMERAMANAGER->CameraX, y + sizeY / 2 - CAMERAMANAGER->CameraY)));
	Renderer->Draw(_imageInfo._Image_Texture, 0, &VECTOR3((float)_imageInfo._Image_Width / 2, (float)_imageInfo._Image_Height / 2, 0), 0, D3DCOLOR_ARGB(alpa, 255, 255, 255));

	Renderer->SetTransform(&Identity());
}

void cimage::AlpaRender(float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, int alpa)
{
	double TempX, TempY;

	TempX = sizeX / _imageInfo._Image_Width;
	TempY = sizeY / _imageInfo._Image_Height;

	if (Reverse) Renderer->SetTransform(&(Scaling(-TempX, TempY) *  Rotation(Angle) * Translation(x + sizeX / 2 - CAMERAMANAGER->CameraX, y + sizeY / 2 - CAMERAMANAGER->CameraY)));
	else Renderer->SetTransform(&(Scaling(TempX, TempY) *  Rotation(Angle) * Translation(x + sizeX / 2 - CAMERAMANAGER->CameraX, y + sizeY / 2 - CAMERAMANAGER->CameraY)));

	Renderer->Draw(_imageInfo._Image_Texture, 0, &VECTOR3((float)_imageInfo._Image_Width / 2, (float)_imageInfo._Image_Height / 2, 0), 0, D3DCOLOR_ARGB(alpa, 255, 255, 255));

	Renderer->SetTransform(&Identity());
}

void cimage::AlpaRender(float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, int alpa)
{
	double TempX, TempY;

	TempX = sizeX / _imageInfo._Image_Width;
	TempY = sizeY / _imageInfo._Image_Height;

	float ReverseX, ReverseY;

	if (Reverse) ReverseX = -1.0f;
	else ReverseX = 1.0f;

	if (Filp) ReverseY = -1.0f;
	else ReverseY = 1.0f;

	Renderer->SetTransform(&(Scaling(TempX * ReverseX, TempY * ReverseY) *  Rotation(Angle) * Translation(x + sizeX / 2 - CAMERAMANAGER->CameraX, y + sizeY / 2 - CAMERAMANAGER->CameraY)));
	Renderer->Draw(_imageInfo._Image_Texture, 0, &VECTOR3((float)_imageInfo._Image_Width / 2, (float)_imageInfo._Image_Height / 2, 0), 0, D3DCOLOR_ARGB(alpa, 255, 255, 255));

	Renderer->SetTransform(&Identity());
}

void cimage::AlpaRender(float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, RECT Sour, int alpa)
{
	double TempX, TempY;

	TempX = sizeX / _imageInfo._Image_Width;
	TempY = sizeY / _imageInfo._Image_Height;

	float ReverseX, ReverseY;

	if (Reverse) ReverseX = -1.0f;
	else ReverseX = 1.0f;

	if (Filp) ReverseY = -1.0f;
	else ReverseY = 1.0f;

	if (Sour.right > _imageInfo._Image_Width) Sour.right = _imageInfo._Image_Width;
	if (Sour.bottom > _imageInfo._Image_Height) Sour.bottom = _imageInfo._Image_Height;

	Renderer->SetTransform(&(Scaling(TempX * ReverseX, TempY * ReverseY) *  Rotation(Angle) * Translation(x + sizeX / 2 - CAMERAMANAGER->CameraX, y + sizeY / 2 - CAMERAMANAGER->CameraY)));
	Renderer->Draw(_imageInfo._Image_Texture, &Sour, &VECTOR3((float)_imageInfo._Image_Width / 2, (float)_imageInfo._Image_Height / 2, 0), 0, D3DCOLOR_ARGB(alpa, 255, 255, 255));

	Renderer->SetTransform(&Identity());
}

void cimage::LoopRender(RECT Range, int& offsetX, int& offsetY)
{
	//offset값이 음수인 경우 보정하기
	if (offsetX < 0) offsetX = _imageInfo._Image_Width + (offsetX % _imageInfo._Image_Width);
	if (offsetY < 0) offsetY = _imageInfo._Image_Height + (offsetY % _imageInfo._Image_Height);

	//그려지는 소스의 영역(이미지)를 셋팅할 변수
	RECT rcSour;
	int sourWidth;
	int sourHeight;

	//그려지는 DC 영역
	RECT rcDest;

	//그려야 할 전체 영역

	int drawAreaX = Range.left;
	int drawAreaY = Range.top;
	int drawAreaW = (Range.right - Range.left);
	int drawAreaH = Range.bottom - Range.top;

	//세로 루프 영역
	for (int y = 0; y < drawAreaH; y += sourHeight)
	{
		//소스 영역의 높이 계산
		rcSour.top = (y + offsetY) % _imageInfo._Image_Height;
		rcSour.bottom = _imageInfo._Image_Height;
		sourHeight = rcSour.bottom - rcSour.top;

		//소스 영역이 그리는 화면을 넘어 갔다면(화면 밖으로 나갔을때)
		if (y + sourHeight > drawAreaH)
		{
			//넘어간 그름의 값만큼 바텀 값을 올려준다.
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}

		//그려지는 영역
		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;

		//가로 로프 영역
		for (int x = 0; x < drawAreaW; x += sourWidth)
		{
			//소스 영역의 가로 계산
			rcSour.left = (x + offsetX) % _imageInfo._Image_Width;
			rcSour.right = _imageInfo._Image_Width;
			sourWidth = rcSour.right - rcSour.left;

			//소스 영역이 그리는 화면을 넘어가면
			if (x + sourWidth > drawAreaW)
			{
				//넘어간 양 만큼 라이트 값을 왼쪽으로
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}

			//그려지는 영역
			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;

			//그리자
			Render((float)rcDest.left, (float)rcDest.top, _imageInfo._Image_Width, _imageInfo._Image_Height, 0.0f, false, false, RectMake(rcSour.left, rcSour.top, rcSour.right - rcSour.left, rcSour.bottom - rcSour.top));
		}
	}

}

void cimage::LoopRender(RECT Range, int & offsetX, int & offsetY, int Alpa)
{
	//offset값이 음수인 경우 보정하기
	if (offsetX < 0) offsetX = _imageInfo._Image_Width + (offsetX % _imageInfo._Image_Width);
	if (offsetY < 0) offsetY = _imageInfo._Image_Height + (offsetY % _imageInfo._Image_Height);

	//그려지는 소스의 영역(이미지)를 셋팅할 변수
	RECT rcSour;
	int sourWidth;
	int sourHeight;

	//그려지는 DC 영역
	RECT rcDest;

	//그려야 할 전체 영역
	int drawAreaX = Range.left;
	int drawAreaY = Range.top;
	int drawAreaW = Range.right - Range.left;
	int drawAreaH = Range.bottom - Range.top;

	//세로 루프 영역
	for (int y = 0; y < drawAreaH; y += sourHeight)
	{
		//소스 영역의 높이 계산
		rcSour.top = (y + offsetY) % _imageInfo._Image_Height;
		rcSour.bottom = _imageInfo._Image_Height;
		sourHeight = rcSour.bottom - rcSour.top;

		//소스 영역이 그리는 화면을 넘어 갔다면(화면 밖으로 나갔을때)
		if (y + sourHeight > drawAreaH)
		{
			//넘어간 그름의 값만큼 바텀 값을 올려준다.
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}

		//그려지는 영역
		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;

		//가로 로프 영역
		for (int x = 0; x < drawAreaW; x += sourWidth)
		{
			//소스 영역의 가로 계산
			rcSour.left = (x + offsetX) % _imageInfo._Image_Width;
			rcSour.right = _imageInfo._Image_Width;
			sourWidth = rcSour.right - rcSour.left;

			//소스 영역이 그리는 화면을 넘어가면
			if (x + sourWidth > drawAreaW)
			{
				//넘어간 양 만큼 라이트 값을 왼쪽으로
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}

			//그려지는 영역
			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;

			//그리자
			AlpaRender((float)rcDest.left, (float)rcDest.top, _imageInfo._Image_Width, _imageInfo._Image_Height, 0.0f, false, false, RectMake(rcSour.left, rcSour.top, rcSour.right - rcSour.left, rcSour.bottom - rcSour.top), Alpa);
		}
	}

}

void cimage::frameRender(float x, float y, int currentFrameX, int currentFrameY)
{
	Renderer->Draw(_imageInfo._Image_Texture, &RectMake(currentFrameX * _imageInfo._Image_FrameWidth, currentFrameY * _imageInfo._Image_FrameHeight, _imageInfo._Image_FrameWidth, _imageInfo._Image_FrameHeight), 0, &D3DXVECTOR3(x - CAMERAMANAGER->CameraX, y - CAMERAMANAGER->CameraY, 0), D3DCOLOR_ARGB(255, 255, 255, 255));
}

void cimage::frameRender(float x, float y, double sizeX, double sizeY, int currentFrameX, int currentFrameY)
{
	double TempX, TempY;

	TempX = sizeX / _imageInfo._Image_FrameWidth;
	TempY = sizeY / _imageInfo._Image_FrameHeight;


	Renderer->SetTransform(&(Scaling(TempX, TempY) * (Translation(x - CAMERAMANAGER->CameraX, y - CAMERAMANAGER->CameraY))));
	Renderer->Draw(_imageInfo._Image_Texture, &RectMake(currentFrameX * _imageInfo._Image_FrameWidth, currentFrameY * _imageInfo._Image_FrameHeight, _imageInfo._Image_FrameWidth, _imageInfo._Image_FrameHeight), 0, 0, D3DCOLOR_ARGB(255, 255, 255, 255));

	Renderer->SetTransform(&Identity());
}

void cimage::frameRender(float x, float y, double sizeX, double sizeY, float Angle, int currentFrameX, int currentFrameY)
{
	double TempX, TempY;

	TempX = sizeX / _imageInfo._Image_FrameWidth;
	TempY = sizeY / _imageInfo._Image_FrameHeight;

	Renderer->SetTransform(&(Scaling(TempX, TempY) *  Rotation(Angle) * Translation(x + sizeX / 2 - CAMERAMANAGER->CameraX, y + sizeY / 2 - CAMERAMANAGER->CameraY)));
	Renderer->Draw(_imageInfo._Image_Texture, &RectMake(currentFrameX * _imageInfo._Image_FrameWidth, currentFrameY * _imageInfo._Image_FrameHeight, _imageInfo._Image_FrameWidth, _imageInfo._Image_FrameHeight), &VECTOR3((float)_imageInfo._Image_FrameWidth / 2, (float)_imageInfo._Image_FrameHeight / 2, 0), 0, D3DCOLOR_ARGB(255, 255, 255, 255));

	Renderer->SetTransform(&Identity());
}

void cimage::frameRender(float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, int currentFrameX, int currentFrameY)
{
	double TempX, TempY;

	TempX = sizeX / _imageInfo._Image_FrameWidth;
	TempY = sizeY / _imageInfo._Image_FrameHeight;

	if (Reverse) Renderer->SetTransform(&(Scaling(-TempX, TempY) *  Rotation(Angle) * Translation(x + sizeX / 2 - CAMERAMANAGER->CameraX, y + sizeY / 2 - CAMERAMANAGER->CameraY)));
	else Renderer->SetTransform(&(Scaling(TempX, TempY) *  Rotation(Angle) * Translation(x + sizeX / 2 - CAMERAMANAGER->CameraX, y + sizeY / 2 - CAMERAMANAGER->CameraY)));

	Renderer->Draw(_imageInfo._Image_Texture, &RectMake(currentFrameX * _imageInfo._Image_FrameWidth, currentFrameY * _imageInfo._Image_FrameHeight, _imageInfo._Image_FrameWidth, _imageInfo._Image_FrameHeight), &VECTOR3((float)_imageInfo._Image_FrameWidth / 2, (float)_imageInfo._Image_FrameHeight / 2, 0), 0, D3DCOLOR_ARGB(255, 255, 255, 255));

	Renderer->SetTransform(&Identity());
}

void cimage::frameRender(float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, int currentFrameX, int currentFrameY)
{
	double TempX, TempY;

	TempX = sizeX / _imageInfo._Image_FrameWidth;
	TempY = sizeY / _imageInfo._Image_FrameHeight;

	float ReverseX, ReverseY;

	if (Reverse) ReverseX = -1.0f;
	else ReverseX = 1.0f;

	if (Filp) ReverseY = -1.0f;
	else ReverseY = 1.0f;

	Renderer->SetTransform(&(Scaling(TempX * ReverseX, TempY * ReverseY) *  Rotation(Angle) * Translation(x + sizeX / 2 - CAMERAMANAGER->CameraX, y + sizeY / 2 - CAMERAMANAGER->CameraY)));
	Renderer->Draw(_imageInfo._Image_Texture, &RectMake(currentFrameX * _imageInfo._Image_FrameWidth, currentFrameY * _imageInfo._Image_FrameHeight, _imageInfo._Image_FrameWidth, _imageInfo._Image_FrameHeight), &VECTOR3((float)_imageInfo._Image_FrameWidth / 2, (float)_imageInfo._Image_FrameHeight / 2, 0), 0, D3DCOLOR_ARGB(255, 255, 255, 255));

	Renderer->SetTransform(&Identity());
}

void cimage::SetFrameX(int frameX)
{
	_imageInfo._Image_CurrentFrameX = frameX;
	if (frameX > _imageInfo._Image_MaxFrameX) _imageInfo._Image_CurrentFrameX = _imageInfo._Image_MaxFrameX;
}

void cimage::SetFrameY(int frameY)
{
	_imageInfo._Image_CurrentFrameY = frameY;
	if (frameY > _imageInfo._Image_MaxFrameY) _imageInfo._Image_CurrentFrameY = _imageInfo._Image_MaxFrameY;
}
