#pragma once

class cimage
{
private:

	// �̹��� ���� ��Ƶ� ����ü
	typedef struct S_IMAGE_INFO
	{
		LPDIRECT3DTEXTURE9  _Image_Texture;		   // �̹��� ���� ���� ����
		int					_Image_Width;		   // �̹��� ���� ũ��
		int					_Image_Height;		   // �̹��� ���� ũ��
		int					_Image_CurrentFrameX;  // �̹��� ����   ������ X
		int					_Image_CurrentFrameY;  // �̹��� ����   ������ Y
		int					_Image_MaxFrameX;	   // �̹��� ������ ������ X
		int					_Image_MaxFrameY;	   // �̹��� ������ ������ Y
		int					_Image_FrameWidth;	   // �̹��� 1�����Ӵ� ���� ũ��
		int					_Image_FrameHeight;	   // �̹��� 1�����Ӵ� ���� ũ��

												   // �ʱ�ȭ
		S_IMAGE_INFO()
		{
			_Image_Texture = NULL;
			_Image_Width = 0;
			_Image_Height = 0;
			_Image_CurrentFrameX = 0;
			_Image_CurrentFrameY = 0;
			_Image_MaxFrameX = 0;
			_Image_MaxFrameY = 0;
			_Image_FrameWidth = 0;
			_Image_FrameHeight = 0;
		}

	} IMAGE_INFO;

	// �̹��� ��� ��ġ
	ID3DXSprite* Renderer;
	// �̹��� ���� ����ü
	IMAGE_INFO _imageInfo;
public:
	cimage();
	~cimage();

	// ======= �̹��� �ε� �Լ��� =========
	// �Ϲ� �ε� // �̹����� ���� ũ��ۿ� ��¸��Ѵ�.
	void SetUp(const char* FileName);
	// �̹��� ũ�� ������ �ε� // �̹��� ���� ũ�� , �̹��� ���� ũ��
	void SetUp(const char* FileName, int width, int height);
	// ������ ������ �ε� // �̹��� ���� ũ�� , �̹��� ���� ũ�� , �̹��� ������ ���� x , y
	void SetUp(const char* FileName, int width, int height, int FrameX, int FrameY);
	// ������ ������ �ε� // �̹��� ���� ũ�� , �̹��� ���� ũ�� , �̹��� ������ ���� x , y // ������ ���� 
	void SetUp(const char* FileName, int width, int height, int FrameX, int FrameY, D3DCOLOR Color);

	//===============================================
	//		## �Ϲݷ��� ##
	//===============================================
	// 0,0 ���� ��� 
	void Render();
	// ��ǥ ���� �߰� 
	void Render(float x, float y);
	// �̹��� ������ ���� �߰� 
	void Render(float x, float y, double sizeX, double sizeY);
	// �̹��� ȸ�� �߰�
	void Render(float x, float y, double sizeX, double sizeY, float Angle);
	// �̹��� �¿� ���� �߰�
	void Render(float x, float y, double sizeX, double sizeY, float Angle, bool Reverse);
	// �̹��� ���� ���� �߰�
	void Render(float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp);
	// �̹��� �׸� ������ ���� �߰�
	void Render(float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, RECT Sour);
	//===============================================
	//		## ���� ���� ##
	//===============================================
	// 0,0 ���� ��� 
	void AlpaRender(int alpa);
	// ��ǥ ���� �߰� 
	void AlpaRender(float x, float y, int alpa);
	// �̹��� ������ ���� �߰� 
	void AlpaRender(float x, float y, double sizeX, double sizeY, int alpa);
	// �̹��� ȸ�� �߰�
	void AlpaRender(float x, float y, double sizeX, double sizeY, float Angle, int alpa);
	// �̹��� �¿� ���� �߰�
	void AlpaRender(float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, int alpa);
	// �̹��� ���� ���� �߰�
	void AlpaRender(float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, int alpa);
	// �̹��� �׸� ������ ���� �߰�
	void AlpaRender(float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, RECT Sour, int alpa);
	//===============================================
	//		## ���� ���� ##
	//===============================================
	void LoopRender(RECT Range, int& offsetX, int& offsetY);
	void LoopRender(RECT Range, int& offsetX, int& offsetY, int Alpa);
	//===============================================
	//		## ������ ���� ##
	//===============================================
	// ��ǥ ���� �߰� 
	void frameRender(float x, float y, int currentFrameX, int currentFrameY);
	// �̹��� ������ ���� �߰� 
	void frameRender(float x, float y, double sizeX, double sizeY, int currentFrameX, int currentFrameY);
	// �̹��� ȸ�� �߰�
	void frameRender(float x, float y, double sizeX, double sizeY, float Angle, int currentFrameX, int currentFrameY);
	// �̹��� �¿� ���� �߰�
	void frameRender(float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, int currentFrameX, int currentFrameY);
	// �̹��� ���� ���� �߰�
	void frameRender(float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, int currentFrameX, int currentFrameY);

	//===============================================
	//		## ������ ������ �Լ��� ##
	//===============================================
	// �̹��� ���� ���� ũ��
	inline int GetWidth() { return _imageInfo._Image_Width; }
	inline int GetHeight() { return _imageInfo._Image_Height; }
	// 1������ ���� ���� ũ��
	inline int GetFrameWidth() { return _imageInfo._Image_FrameWidth; }
	inline int GetFrameHeight() { return _imageInfo._Image_FrameHeight; }
	// �ƽ� ������ ��ȯ
	inline int GetMaxFrameX() { return _imageInfo._Image_MaxFrameX; }
	inline int GetMaxFrameY() { return _imageInfo._Image_MaxFrameY; }
	// ���� ������ ��ȯ
	inline int GetFrameX() { return _imageInfo._Image_CurrentFrameX; }
	inline int GetFrameY() { return _imageInfo._Image_CurrentFrameY; }

	// ���� ������ ����
	void SetFrameX(int frameX);
	void SetFrameY(int frameY);

};
