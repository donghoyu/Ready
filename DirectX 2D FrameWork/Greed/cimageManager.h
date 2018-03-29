#pragma once

#define IMAGEMANAGER cimageManager::GetInstance()

class cimage;
class cimageManager
{
private:
	// 싱글톤 설정
	SINGLETONE(cimageManager);
	// 이미지 모아둘 리스트
	map<string, cimage*> image_List;
	// 이미지 출력 장치
	ID3DXSprite* Renderer;
public:
	void Destory();			  // 이미지 매니져 해제
	void Destory_imageList(); // 이미지 리스트 해제
	void Destory_FindImage(string KeyName); // 원하는 이미지 해제

	cimage* findImage(string KeyName); //이미지 키값으로 찾기

									   // 이미지 추가 함수들
	void addImage(const char* KeyName, const char* FileName);
	void addImage(const char* KeyName, const char* FileName, int width, int height);
	void addImage(const char* KeyName, const char* FileName, int width, int height, int FrameX, int FrameY);
	void addImage(const char* KeyName, const char* FileName, int width, int height, int FrameX, int FrameY, D3DCOLOR Color);

	//===============================================
	//		## 일반렌더 ##
	//===============================================
	// 0,0 에서 출력 
	void Render(const char* KeyName);
	// 좌표 지정 추가 
	void Render(const char* KeyName, float x, float y);
	// 이미지 사이즈 조절 추가 
	void Render(const char* KeyName, float x, float y, double sizeX, double sizeY);
	// 이미지 회전 추가
	void Render(const char* KeyName, float x, float y, double sizeX, double sizeY, float Angle);
	// 이미지 좌우 반전 추가
	void Render(const char* KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse);
	// 이미지 상하 반전 추가
	void Render(const char* KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp);
	// 이미지 그릴 영역만 렌더 추가
	void Render(const char* KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, RECT Sour);

	//===============================================
	//		## 알파 렌더 ##
	//===============================================
	// 0,0 에서 출력 
	void AlpaRender(const char* KeyName, int alpa);
	// 좌표 지정 추가 
	void AlpaRender(const char* KeyName, float x, float y, int alpa);
	// 이미지 사이즈 조절 추가 
	void AlpaRender(const char* KeyName, float x, float y, double sizeX, double sizeY, int alpa);
	// 이미지 회전 추가
	void AlpaRender(const char* KeyName, float x, float y, double sizeX, double sizeY, float Angle, int alpa);
	// 이미지 좌우 반전 추가
	void AlpaRender(const char* KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, int alpa);
	// 이미지 상하 반전 추가
	void AlpaRender(const char* KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, int alpa);
	// 이미지 그릴 영역만 렌더 추가
	void AlpaRender(const char* KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, RECT Sour, int alpa);
	//===============================================
	//		## 루프 렌더 ##
	//===============================================
	void LoopRender(const char* KeyName, RECT Range, int& offsetX, int& offsetY);
	void LoopRender(const char* KeyName, RECT Range, int& offsetX, int& offsetY, int Alpa);
	//===============================================
	//		## 프레임 렌더 ##
	//===============================================
	void frameRender(const char* KeyName, float x, float y, int currentFrameX, int currentFrameY);
	void frameRender(const char* KeyName, float x, float y, double sizeX, double sizeY, int currentFrameX, int currentFrameY);
	void frameRender(const char* KeyName, float x, float y, double sizeX, double sizeY, float Angle, int currentFrameX, int currentFrameY);
	void frameRender(const char* KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, int currentFrameX, int currentFrameY);
	void frameRender(const char* KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, int currentFrameX, int currentFrameY);

	void RenerStart();
	void RenerEnd();
	ID3DXSprite* GetRenderer() { return Renderer; }

};
