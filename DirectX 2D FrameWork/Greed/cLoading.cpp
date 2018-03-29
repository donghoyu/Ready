#include "stdafx.h"
#include "cLoading.h"

cLoading::cLoading()
	:isLoading(false)
{
}

cLoading::~cLoading()
{
}

string cLoading::AddImage(string KeyName)
{
	LOADINGMANAGER->LoadingList.push(KeyName);

	return KeyName;
}

//void cLoading::m_Town()
//{
//	// ===== TEST ======
//	for (int i = 0; i < 1000; i++)
//	{
//		char str[256];
//		ZeroMemory(str, size(str));
//		sprintf_s(str, "test%d", i);
//		IMAGEMANAGER->addImage(AddImage(str).c_str(), "images/test.png", 91, 101);
//		//cout << i << " 번쨰 로딩중..." << endl;
//	}
//
//	// ============= 로딩 시작
//
//	// ex)
//	//IMAGEMANAGER->addImage("Title_Start_In", "images/Title/Title_Start_In.png", 117, 43);
//	//IMAGEMANAGER->addImage("Title_Start_Out", "images/Title/Title_Start_Out.png", 117, 43);
//
//	// ============= 로딩 끝
//	isLoading = false;
//}

 