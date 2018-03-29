#include "stdafx.h"
#include "cimage.h"
#include "cimageManager.h"

cimageManager::cimageManager()
{
	// �̹��� �����ġ ����
	D3DXCreateSprite(DEVICEMANAGER, &Renderer);

}

cimageManager::~cimageManager()
{
}

void cimageManager::Destory()
{
	Destory_imageList();	// �̹��� ����Ʈ   ����
	Renderer->Release();	// �̹��� �����ġ ����
}

void cimageManager::Destory_imageList()
{
	// �̹��� ����Ʈ ���鼭 
	for each(auto p in image_List)
	{
		SAFE_DELETE(p.second);					// �ʿ� �����Ҵ� �صξ��� �̹��� Ŭ���� ����
	}
	// �� �������� �� Ŭ����.
	image_List.clear();
}

void cimageManager::Destory_FindImage(string KeyName)
{
	// ã������
	if (image_List.find(KeyName) != image_List.end())
	{
		// �̹��� �Ҵ� �����ϰ�
		SAFE_DELETE(image_List.find(KeyName)->second);
		// �ʿ��� �����.
		image_List.erase(image_List.find(KeyName)->first);
	}

}

cimage * cimageManager::findImage(string KeyName)
{
	assert(image_List.find(KeyName) != image_List.end() && "                �߰��� ���� �̹����� ã������");
	// ��ã������
	if (image_List.find(KeyName) == image_List.end())
	{
		// �ι�ȯ
		return NULL;
	}

	// ã������ ã���� ��ȯ 
	return image_List[KeyName];
}

void cimageManager::addImage(const char* KeyName, const char * FileName)
{
	assert(image_List.find(KeyName) == image_List.end() && "         �̹��� �߰��ߴµ� �Ȱ����� �߰��Ҷ���");

	//  �̹� �ִ� �̹����� ����
	if (image_List.find(KeyName) != image_List.end()) return;

	// ���� �Ҵ����ְ�
	cimage* img = new cimage;
	// �ʱ�ȭ ���ְ�
	img->SetUp(FileName);

	// ����Ʈ�� �߰�
	image_List[KeyName] = img;
}

void cimageManager::addImage(const char* KeyName, const char * FileName, int width, int height)
{
	assert(image_List.find(KeyName) == image_List.end() && "         �̹��� �߰��ߴµ� �Ȱ����� �߰��Ҷ���");

	//  �̹� �ִ� �̹����� ����
	if (image_List.find(KeyName) != image_List.end()) return;

	// ���� �Ҵ����ְ�
	cimage* img = new cimage;
	// �ʱ�ȭ ���ְ�
	img->SetUp(FileName, width, height);

	// ����Ʈ�� �߰�
	image_List[KeyName] = img;
}

void cimageManager::addImage(const char* KeyName, const char * FileName, int width, int height, int FrameX, int FrameY)
{
	assert(image_List.find(KeyName) == image_List.end() && "         �̹��� �߰��ߴµ� �Ȱ����� �߰� �Ҷ���");

	//  �̹� �ִ� �̹����� ����
	if (image_List.find(KeyName) != image_List.end()) return;

	// ���� �Ҵ����ְ�
	cimage* img = new cimage;
	// �ʱ�ȭ ���ְ�
	img->SetUp(FileName, width, height, FrameX, FrameY);

	// ����Ʈ�� �߰�
	image_List[KeyName] = img;
}

void cimageManager::addImage(const char * KeyName, const char * FileName, int width, int height, int FrameX, int FrameY, D3DCOLOR Color)
{
	assert(image_List.find(KeyName) == image_List.end() && "         �̹��� �߰��ߴµ� �Ȱ����� �߰� �Ҷ���");

	//  �̹� �ִ� �̹����� ����
	if (image_List.find(KeyName) != image_List.end()) return;

	// ���� �Ҵ����ְ�
	cimage* img = new cimage;
	// �ʱ�ȭ ���ְ�
	img->SetUp(FileName, width, height, FrameX, FrameY, Color);

	// ����Ʈ�� �߰�
	image_List[KeyName] = img;
}

void cimageManager::Render(const char * KeyName)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        �̹��� �߰� ���س��� ���� �ҷ���_�Ϲݷ���");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->Render();
}

void cimageManager::Render(const char * KeyName, float x, float y)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        �̹��� �߰� ���س��� ���� �ҷ���_�Ϲݷ���");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->Render(x, y);
}

void cimageManager::Render(const char * KeyName, float x, float y, double sizeX, double sizeY)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        �̹��� �߰� ���س��� ���� �ҷ���_�Ϲݷ���");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->Render(x, y, sizeX, sizeY);
}

void cimageManager::Render(const char * KeyName, float x, float y, double sizeX, double sizeY, float Angle)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        �̹��� �߰� ���س��� ���� �ҷ���_�Ϲݷ���");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->Render(x, y, sizeX, sizeY, Angle);
}

void cimageManager::Render(const char * KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        �̹��� �߰� ���س��� ���� �ҷ���_�Ϲݷ���");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->Render(x, y, sizeX, sizeY, Angle, Reverse);
}

void cimageManager::Render(const char * KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        �̹��� �߰� ���س��� ���� �ҷ���_�Ϲݷ���");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->Render(x, y, sizeX, sizeY, Angle, Reverse, Filp);
}

void cimageManager::Render(const char * KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, RECT Sour)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        �̹��� �߰� ���س��� ���� �ҷ���_�Ϲݷ���");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->Render(x, y, sizeX, sizeY, Angle, Reverse, Filp, Sour);
}


void cimageManager::AlpaRender(const char * KeyName, int alpa)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        �̹��� �߰� ���س��� ���� �ҷ���_���ķ���");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->AlpaRender(alpa);
}

void cimageManager::AlpaRender(const char * KeyName, float x, float y, int alpa)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        �̹��� �߰� ���س��� ���� �ҷ���_���ķ���");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->AlpaRender(x, y, alpa);
}

void cimageManager::AlpaRender(const char * KeyName, float x, float y, double sizeX, double sizeY, int alpa)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        �̹��� �߰� ���س��� ���� �ҷ���_���ķ���");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->AlpaRender(x, y, sizeX, sizeY, alpa);
}

void cimageManager::AlpaRender(const char * KeyName, float x, float y, double sizeX, double sizeY, float Angle, int alpa)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        �̹��� �߰� ���س��� ���� �ҷ���_���ķ���");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->AlpaRender(x, y, sizeX, sizeY, Angle, alpa);
}

void cimageManager::AlpaRender(const char * KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, int alpa)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        �̹��� �߰� ���س��� ���� �ҷ���_���ķ���");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->AlpaRender(x, y, sizeX, sizeY, Angle, Reverse, alpa);
}

void cimageManager::AlpaRender(const char * KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, int alpa)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        �̹��� �߰� ���س��� ���� �ҷ���_���ķ���");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->AlpaRender(x, y, sizeX, sizeY, Angle, Reverse, Filp, alpa);
}

void cimageManager::AlpaRender(const char * KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, RECT Sour, int alpa)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        �̹��� �߰� ���س��� ���� �ҷ���_���ķ���");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->AlpaRender(x, y, sizeX, sizeY, Angle, Reverse, Filp, Sour, alpa);
}

void cimageManager::LoopRender(const char * KeyName, RECT Range, int & offsetX, int & offsetY)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        �̹��� �߰� ���س��� ���� �ҷ���_��������");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->LoopRender(Range, offsetX, offsetY);
}

void cimageManager::LoopRender(const char * KeyName, RECT Range, int & offsetX, int & offsetY, int Alpa)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        �̹��� �߰� ���س��� ���� �ҷ���_��������");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->LoopRender(Range, offsetX, offsetY, Alpa);
}


void cimageManager::frameRender(const char * KeyName, float x, float y, int currentFrameX, int currentFrameY)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        �̹��� �߰� ���س��� ���� �ҷ���_��������");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->frameRender(x, y, currentFrameX, currentFrameY);
}

void cimageManager::frameRender(const char * KeyName, float x, float y, double sizeX, double sizeY, int currentFrameX, int currentFrameY)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        �̹��� �߰� ���س��� ���� �ҷ���_��������");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->frameRender(x, y, sizeX, sizeY, currentFrameX, currentFrameY);
}

void cimageManager::frameRender(const char * KeyName, float x, float y, double sizeX, double sizeY, float Angle, int currentFrameX, int currentFrameY)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        �̹��� �߰� ���س��� ���� �ҷ���_��������");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->frameRender(x, y, sizeX, sizeY, Angle, currentFrameX, currentFrameY);
}

void cimageManager::frameRender(const char * KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, int currentFrameX, int currentFrameY)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        �̹��� �߰� ���س��� ���� �ҷ���_��������");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->frameRender(x, y, sizeX, sizeY, Angle, Reverse, currentFrameX, currentFrameY);
}

void cimageManager::frameRender(const char * KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, int currentFrameX, int currentFrameY)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        �̹��� �߰� ���س��� ���� �ҷ���_��������");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->frameRender(x, y, sizeX, sizeY, Angle, Reverse, Filp, currentFrameX, currentFrameY);
}




void cimageManager::RenerStart()
{
	Renderer->Begin(D3DXSPRITE_ALPHABLEND);
}

void cimageManager::RenerEnd()
{
	Renderer->End();
}
