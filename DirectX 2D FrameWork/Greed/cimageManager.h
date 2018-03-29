#pragma once

#define IMAGEMANAGER cimageManager::GetInstance()

class cimage;
class cimageManager
{
private:
	// �̱��� ����
	SINGLETONE(cimageManager);
	// �̹��� ��Ƶ� ����Ʈ
	map<string, cimage*> image_List;
	// �̹��� ��� ��ġ
	ID3DXSprite* Renderer;
public:
	void Destory();			  // �̹��� �Ŵ��� ����
	void Destory_imageList(); // �̹��� ����Ʈ ����
	void Destory_FindImage(string KeyName); // ���ϴ� �̹��� ����

	cimage* findImage(string KeyName); //�̹��� Ű������ ã��

									   // �̹��� �߰� �Լ���
	void addImage(const char* KeyName, const char* FileName);
	void addImage(const char* KeyName, const char* FileName, int width, int height);
	void addImage(const char* KeyName, const char* FileName, int width, int height, int FrameX, int FrameY);
	void addImage(const char* KeyName, const char* FileName, int width, int height, int FrameX, int FrameY, D3DCOLOR Color);

	//===============================================
	//		## �Ϲݷ��� ##
	//===============================================
	// 0,0 ���� ��� 
	void Render(const char* KeyName);
	// ��ǥ ���� �߰� 
	void Render(const char* KeyName, float x, float y);
	// �̹��� ������ ���� �߰� 
	void Render(const char* KeyName, float x, float y, double sizeX, double sizeY);
	// �̹��� ȸ�� �߰�
	void Render(const char* KeyName, float x, float y, double sizeX, double sizeY, float Angle);
	// �̹��� �¿� ���� �߰�
	void Render(const char* KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse);
	// �̹��� ���� ���� �߰�
	void Render(const char* KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp);
	// �̹��� �׸� ������ ���� �߰�
	void Render(const char* KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, RECT Sour);

	//===============================================
	//		## ���� ���� ##
	//===============================================
	// 0,0 ���� ��� 
	void AlpaRender(const char* KeyName, int alpa);
	// ��ǥ ���� �߰� 
	void AlpaRender(const char* KeyName, float x, float y, int alpa);
	// �̹��� ������ ���� �߰� 
	void AlpaRender(const char* KeyName, float x, float y, double sizeX, double sizeY, int alpa);
	// �̹��� ȸ�� �߰�
	void AlpaRender(const char* KeyName, float x, float y, double sizeX, double sizeY, float Angle, int alpa);
	// �̹��� �¿� ���� �߰�
	void AlpaRender(const char* KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, int alpa);
	// �̹��� ���� ���� �߰�
	void AlpaRender(const char* KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, int alpa);
	// �̹��� �׸� ������ ���� �߰�
	void AlpaRender(const char* KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, RECT Sour, int alpa);
	//===============================================
	//		## ���� ���� ##
	//===============================================
	void LoopRender(const char* KeyName, RECT Range, int& offsetX, int& offsetY);
	void LoopRender(const char* KeyName, RECT Range, int& offsetX, int& offsetY, int Alpa);
	//===============================================
	//		## ������ ���� ##
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
