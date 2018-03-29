#include "stdafx.h"
#include "cimage.h"
#include "cimageManager.h"

cimageManager::cimageManager()
{
	// 이미지 출력장치 생성
	D3DXCreateSprite(DEVICEMANAGER, &Renderer);

}

cimageManager::~cimageManager()
{
}

void cimageManager::Destory()
{
	Destory_imageList();	// 이미지 리스트   제거
	Renderer->Release();	// 이미지 출력장치 제거
}

void cimageManager::Destory_imageList()
{
	// 이미지 리스트 돌면서 
	for each(auto p in image_List)
	{
		SAFE_DELETE(p.second);					// 맵에 동적할당 해두었던 이미지 클래스 해제
	}
	// 다 지웠으니 맵 클리어.
	image_List.clear();
}

void cimageManager::Destory_FindImage(string KeyName)
{
	// 찾았으면
	if (image_List.find(KeyName) != image_List.end())
	{
		// 이미지 할당 해제하고
		SAFE_DELETE(image_List.find(KeyName)->second);
		// 맵에서 지운다.
		image_List.erase(image_List.find(KeyName)->first);
	}

}

cimage * cimageManager::findImage(string KeyName)
{
	assert(image_List.find(KeyName) != image_List.end() && "                추가도 안한 이미지를 찾고있음");
	// 못찾았으면
	if (image_List.find(KeyName) == image_List.end())
	{
		// 널반환
		return NULL;
	}

	// 찾았으면 찾은놈 반환 
	return image_List[KeyName];
}

void cimageManager::addImage(const char* KeyName, const char * FileName)
{
	assert(image_List.find(KeyName) == image_List.end() && "         이미지 추가했는데 똑같은거 추가할라함");

	//  이미 있는 이미지면 종료
	if (image_List.find(KeyName) != image_List.end()) return;

	// 새로 할당해주고
	cimage* img = new cimage;
	// 초기화 해주고
	img->SetUp(FileName);

	// 리스트에 추가
	image_List[KeyName] = img;
}

void cimageManager::addImage(const char* KeyName, const char * FileName, int width, int height)
{
	assert(image_List.find(KeyName) == image_List.end() && "         이미지 추가했는데 똑같은거 추가할라함");

	//  이미 있는 이미지면 종료
	if (image_List.find(KeyName) != image_List.end()) return;

	// 새로 할당해주고
	cimage* img = new cimage;
	// 초기화 해주고
	img->SetUp(FileName, width, height);

	// 리스트에 추가
	image_List[KeyName] = img;
}

void cimageManager::addImage(const char* KeyName, const char * FileName, int width, int height, int FrameX, int FrameY)
{
	assert(image_List.find(KeyName) == image_List.end() && "         이미지 추가했는데 똑같은거 추가 할라함");

	//  이미 있는 이미지면 종료
	if (image_List.find(KeyName) != image_List.end()) return;

	// 새로 할당해주고
	cimage* img = new cimage;
	// 초기화 해주고
	img->SetUp(FileName, width, height, FrameX, FrameY);

	// 리스트에 추가
	image_List[KeyName] = img;
}

void cimageManager::addImage(const char * KeyName, const char * FileName, int width, int height, int FrameX, int FrameY, D3DCOLOR Color)
{
	assert(image_List.find(KeyName) == image_List.end() && "         이미지 추가했는데 똑같은거 추가 할라함");

	//  이미 있는 이미지면 종료
	if (image_List.find(KeyName) != image_List.end()) return;

	// 새로 할당해주고
	cimage* img = new cimage;
	// 초기화 해주고
	img->SetUp(FileName, width, height, FrameX, FrameY, Color);

	// 리스트에 추가
	image_List[KeyName] = img;
}

void cimageManager::Render(const char * KeyName)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        이미지 추가 안해놓고 렌더 할려함_일반렌더");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->Render();
}

void cimageManager::Render(const char * KeyName, float x, float y)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        이미지 추가 안해놓고 렌더 할려함_일반렌더");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->Render(x, y);
}

void cimageManager::Render(const char * KeyName, float x, float y, double sizeX, double sizeY)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        이미지 추가 안해놓고 렌더 할려함_일반렌더");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->Render(x, y, sizeX, sizeY);
}

void cimageManager::Render(const char * KeyName, float x, float y, double sizeX, double sizeY, float Angle)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        이미지 추가 안해놓고 렌더 할려함_일반렌더");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->Render(x, y, sizeX, sizeY, Angle);
}

void cimageManager::Render(const char * KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        이미지 추가 안해놓고 렌더 할려함_일반렌더");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->Render(x, y, sizeX, sizeY, Angle, Reverse);
}

void cimageManager::Render(const char * KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        이미지 추가 안해놓고 렌더 할려함_일반렌더");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->Render(x, y, sizeX, sizeY, Angle, Reverse, Filp);
}

void cimageManager::Render(const char * KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, RECT Sour)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        이미지 추가 안해놓고 렌더 할려함_일반렌더");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->Render(x, y, sizeX, sizeY, Angle, Reverse, Filp, Sour);
}


void cimageManager::AlpaRender(const char * KeyName, int alpa)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        이미지 추가 안해놓고 렌더 할려함_알파렌더");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->AlpaRender(alpa);
}

void cimageManager::AlpaRender(const char * KeyName, float x, float y, int alpa)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        이미지 추가 안해놓고 렌더 할려함_알파렌더");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->AlpaRender(x, y, alpa);
}

void cimageManager::AlpaRender(const char * KeyName, float x, float y, double sizeX, double sizeY, int alpa)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        이미지 추가 안해놓고 렌더 할려함_알파렌더");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->AlpaRender(x, y, sizeX, sizeY, alpa);
}

void cimageManager::AlpaRender(const char * KeyName, float x, float y, double sizeX, double sizeY, float Angle, int alpa)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        이미지 추가 안해놓고 렌더 할려함_알파렌더");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->AlpaRender(x, y, sizeX, sizeY, Angle, alpa);
}

void cimageManager::AlpaRender(const char * KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, int alpa)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        이미지 추가 안해놓고 렌더 할려함_알파렌더");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->AlpaRender(x, y, sizeX, sizeY, Angle, Reverse, alpa);
}

void cimageManager::AlpaRender(const char * KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, int alpa)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        이미지 추가 안해놓고 렌더 할려함_알파렌더");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->AlpaRender(x, y, sizeX, sizeY, Angle, Reverse, Filp, alpa);
}

void cimageManager::AlpaRender(const char * KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, RECT Sour, int alpa)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        이미지 추가 안해놓고 렌더 할려함_알파렌더");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->AlpaRender(x, y, sizeX, sizeY, Angle, Reverse, Filp, Sour, alpa);
}

void cimageManager::LoopRender(const char * KeyName, RECT Range, int & offsetX, int & offsetY)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        이미지 추가 안해놓고 렌더 할려함_루프렌더");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->LoopRender(Range, offsetX, offsetY);
}

void cimageManager::LoopRender(const char * KeyName, RECT Range, int & offsetX, int & offsetY, int Alpa)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        이미지 추가 안해놓고 렌더 할려함_루프렌더");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->LoopRender(Range, offsetX, offsetY, Alpa);
}


void cimageManager::frameRender(const char * KeyName, float x, float y, int currentFrameX, int currentFrameY)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        이미지 추가 안해놓고 렌더 할려함_루프렌더");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->frameRender(x, y, currentFrameX, currentFrameY);
}

void cimageManager::frameRender(const char * KeyName, float x, float y, double sizeX, double sizeY, int currentFrameX, int currentFrameY)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        이미지 추가 안해놓고 렌더 할려함_루프렌더");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->frameRender(x, y, sizeX, sizeY, currentFrameX, currentFrameY);
}

void cimageManager::frameRender(const char * KeyName, float x, float y, double sizeX, double sizeY, float Angle, int currentFrameX, int currentFrameY)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        이미지 추가 안해놓고 렌더 할려함_루프렌더");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->frameRender(x, y, sizeX, sizeY, Angle, currentFrameX, currentFrameY);
}

void cimageManager::frameRender(const char * KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, int currentFrameX, int currentFrameY)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        이미지 추가 안해놓고 렌더 할려함_루프렌더");

	if (image_List.find(KeyName) != image_List.end())
		image_List[KeyName]->frameRender(x, y, sizeX, sizeY, Angle, Reverse, currentFrameX, currentFrameY);
}

void cimageManager::frameRender(const char * KeyName, float x, float y, double sizeX, double sizeY, float Angle, bool Reverse, bool Filp, int currentFrameX, int currentFrameY)
{
	//assert(image_List.find(KeyName) != image_List.end() && "        이미지 추가 안해놓고 렌더 할려함_루프렌더");

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
