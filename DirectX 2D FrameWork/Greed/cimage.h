#pragma once

class cimage
{
private:

	// 이미지 정보 모아둔 구조체
	typedef struct S_IMAGE_INFO
	{
		LPDIRECT3DTEXTURE9  _Image_Texture;		   // 이미지 정보 받을 변수
		int					_Image_Width;		   // 이미지 가로 크기
		int					_Image_Height;		   // 이미지 세로 크기
		int					_Image_CurrentFrameX;  // 이미지 현재   프레임 X
		int					_Image_CurrentFrameY;  // 이미지 현재   프레임 Y
		int					_Image_MaxFrameX;	   // 이미지 마지막 프레임 X
		int					_Image_MaxFrameY;	   // 이미지 마지막 프레임 Y
		int					_Image_FrameWidth;	   // 이미지 1프레임당 가로 크기
		int					_Image_FrameHeight;	   // 이미지 1프레임당 세로 크기

												   // 초기화
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

	// 이미지 출력 장치
	ID3DXSprite* Renderer;
	// 이미지 정보 구조체
	IMAGE_INFO _imageInfo;
public:
	cimage();
	~cimage();

	// ======= 이미지 로드 함수들 =========
	// 일반 로드 // 이미지의 원본 크기밖에 출력못한다.
	void SetUp(const char* FileName);
	// 이미지 크기 조절용 로드 // 이미지 가로 크기 , 이미지 세로 크기
	void SetUp(const char* FileName, int width, int height);
	// 프레임 렌더용 로드 // 이미지 가로 크기 , 이미지 세로 크기 , 이미지 프레임 갯수 x , y
	void SetUp(const char* FileName, int width, int height, int FrameX, int FrameY);
	// 프레임 렌더용 로드 // 이미지 가로 크기 , 이미지 세로 크기 , 이미지 프레임 갯수 x , y // 제외할 색상 
	void SetUp(const char* FileName, int width, int height, int FrameX, int FrameY, D3DCOLOR Color);

	//===============================================
	//		## 일반렌더 ##
	//===============================================
	// 0,0 에서 출력 
	void Render();
	// 좌표 지정 추가 
	void Render(float x, float y);
	// 이미지 사이즈 조절 추가 
	void Render(float x, float y, double sizeX, double sizeY);
	// 이미지 회전 추가
	void Render(float x, float y, double sizeX, double sizeY, float Angle);
	// 이미지 좌우 반전 추가
	void Render(float x, float y, double sizeX, double sizeY, float Angle, bool Reverse);
	// 이미지 상하 반전 추가
	void Render(float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp);
	// 이미지 그릴 영역만 렌더 추가
	void Render(float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, RECT Sour);
	//===============================================
	//		## 알파 렌더 ##
	//===============================================
	// 0,0 에서 출력 
	void AlpaRender(int alpa);
	// 좌표 지정 추가 
	void AlpaRender(float x, float y, int alpa);
	// 이미지 사이즈 조절 추가 
	void AlpaRender(float x, float y, double sizeX, double sizeY, int alpa);
	// 이미지 회전 추가
	void AlpaRender(float x, float y, double sizeX, double sizeY, float Angle, int alpa);
	// 이미지 좌우 반전 추가
	void AlpaRender(float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, int alpa);
	// 이미지 상하 반전 추가
	void AlpaRender(float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, int alpa);
	// 이미지 그릴 영역만 렌더 추가
	void AlpaRender(float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, RECT Sour, int alpa);
	//===============================================
	//		## 루프 렌더 ##
	//===============================================
	void LoopRender(RECT Range, int& offsetX, int& offsetY);
	void LoopRender(RECT Range, int& offsetX, int& offsetY, int Alpa);
	//===============================================
	//		## 프레임 렌더 ##
	//===============================================
	// 좌표 지정 추가 
	void frameRender(float x, float y, int currentFrameX, int currentFrameY);
	// 이미지 사이즈 조절 추가 
	void frameRender(float x, float y, double sizeX, double sizeY, int currentFrameX, int currentFrameY);
	// 이미지 회전 추가
	void frameRender(float x, float y, double sizeX, double sizeY, float Angle, int currentFrameX, int currentFrameY);
	// 이미지 좌우 반전 추가
	void frameRender(float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, int currentFrameX, int currentFrameY);
	// 이미지 상하 반전 추가
	void frameRender(float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, int currentFrameX, int currentFrameY);

	//===============================================
	//		## 데이터 수정용 함수들 ##
	//===============================================
	// 이미지 가로 세로 크기
	inline int GetWidth() { return _imageInfo._Image_Width; }
	inline int GetHeight() { return _imageInfo._Image_Height; }
	// 1프레임 가로 세로 크기
	inline int GetFrameWidth() { return _imageInfo._Image_FrameWidth; }
	inline int GetFrameHeight() { return _imageInfo._Image_FrameHeight; }
	// 맥스 프레임 반환
	inline int GetMaxFrameX() { return _imageInfo._Image_MaxFrameX; }
	inline int GetMaxFrameY() { return _imageInfo._Image_MaxFrameY; }
	// 현재 프레임 반환
	inline int GetFrameX() { return _imageInfo._Image_CurrentFrameX; }
	inline int GetFrameY() { return _imageInfo._Image_CurrentFrameY; }

	// 현재 프레임 셋팅
	void SetFrameX(int frameX);
	void SetFrameY(int frameY);

};
