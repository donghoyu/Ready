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
	// �ҷ��� �����̸� + ���� �̸�
	string   Temp = FileName;
	// �����ڵ�� ��ȯ 
	wstring	 TempName(Temp.begin(), Temp.end());
	// �̹��� ���� �ε�
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
	// �ҷ��� �����̸� + ���� �̸�
	string   Temp = FileName;
	// �����ڵ�� ��ȯ 
	wstring	 TempName(Temp.begin(), Temp.end());
	// �̹��� ���� �ε�
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
	// �ҷ��� �����̸� + ���� �̸�
	string   Temp = FileName;
	// �����ڵ�� ��ȯ 
	wstring	 TempName(Temp.begin(), Temp.end());
	// �̹��� ���� �ε�
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
	// �ҷ��� �����̸� + ���� �̸�
	string   Temp = FileName;
	// �����ڵ�� ��ȯ 
	wstring	 TempName(Temp.begin(), Temp.end());
	// �̹��� ���� �ε�
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
	//offset���� ������ ��� �����ϱ�
	if (offsetX < 0) offsetX = _imageInfo._Image_Width + (offsetX % _imageInfo._Image_Width);
	if (offsetY < 0) offsetY = _imageInfo._Image_Height + (offsetY % _imageInfo._Image_Height);

	//�׷����� �ҽ��� ����(�̹���)�� ������ ����
	RECT rcSour;
	int sourWidth;
	int sourHeight;

	//�׷����� DC ����
	RECT rcDest;

	//�׷��� �� ��ü ����

	int drawAreaX = Range.left;
	int drawAreaY = Range.top;
	int drawAreaW = (Range.right - Range.left);
	int drawAreaH = Range.bottom - Range.top;

	//���� ���� ����
	for (int y = 0; y < drawAreaH; y += sourHeight)
	{
		//�ҽ� ������ ���� ���
		rcSour.top = (y + offsetY) % _imageInfo._Image_Height;
		rcSour.bottom = _imageInfo._Image_Height;
		sourHeight = rcSour.bottom - rcSour.top;

		//�ҽ� ������ �׸��� ȭ���� �Ѿ� ���ٸ�(ȭ�� ������ ��������)
		if (y + sourHeight > drawAreaH)
		{
			//�Ѿ �׸��� ����ŭ ���� ���� �÷��ش�.
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}

		//�׷����� ����
		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;

		//���� ���� ����
		for (int x = 0; x < drawAreaW; x += sourWidth)
		{
			//�ҽ� ������ ���� ���
			rcSour.left = (x + offsetX) % _imageInfo._Image_Width;
			rcSour.right = _imageInfo._Image_Width;
			sourWidth = rcSour.right - rcSour.left;

			//�ҽ� ������ �׸��� ȭ���� �Ѿ��
			if (x + sourWidth > drawAreaW)
			{
				//�Ѿ �� ��ŭ ����Ʈ ���� ��������
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}

			//�׷����� ����
			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;

			//�׸���
			Render((float)rcDest.left, (float)rcDest.top, _imageInfo._Image_Width, _imageInfo._Image_Height, 0.0f, false, false, RectMake(rcSour.left, rcSour.top, rcSour.right - rcSour.left, rcSour.bottom - rcSour.top));
		}
	}

}

void cimage::LoopRender(RECT Range, int & offsetX, int & offsetY, int Alpa)
{
	//offset���� ������ ��� �����ϱ�
	if (offsetX < 0) offsetX = _imageInfo._Image_Width + (offsetX % _imageInfo._Image_Width);
	if (offsetY < 0) offsetY = _imageInfo._Image_Height + (offsetY % _imageInfo._Image_Height);

	//�׷����� �ҽ��� ����(�̹���)�� ������ ����
	RECT rcSour;
	int sourWidth;
	int sourHeight;

	//�׷����� DC ����
	RECT rcDest;

	//�׷��� �� ��ü ����
	int drawAreaX = Range.left;
	int drawAreaY = Range.top;
	int drawAreaW = Range.right - Range.left;
	int drawAreaH = Range.bottom - Range.top;

	//���� ���� ����
	for (int y = 0; y < drawAreaH; y += sourHeight)
	{
		//�ҽ� ������ ���� ���
		rcSour.top = (y + offsetY) % _imageInfo._Image_Height;
		rcSour.bottom = _imageInfo._Image_Height;
		sourHeight = rcSour.bottom - rcSour.top;

		//�ҽ� ������ �׸��� ȭ���� �Ѿ� ���ٸ�(ȭ�� ������ ��������)
		if (y + sourHeight > drawAreaH)
		{
			//�Ѿ �׸��� ����ŭ ���� ���� �÷��ش�.
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}

		//�׷����� ����
		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;

		//���� ���� ����
		for (int x = 0; x < drawAreaW; x += sourWidth)
		{
			//�ҽ� ������ ���� ���
			rcSour.left = (x + offsetX) % _imageInfo._Image_Width;
			rcSour.right = _imageInfo._Image_Width;
			sourWidth = rcSour.right - rcSour.left;

			//�ҽ� ������ �׸��� ȭ���� �Ѿ��
			if (x + sourWidth > drawAreaW)
			{
				//�Ѿ �� ��ŭ ����Ʈ ���� ��������
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}

			//�׷����� ����
			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;

			//�׸���
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
