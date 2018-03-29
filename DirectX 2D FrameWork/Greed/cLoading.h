#pragma once


class cLoading
{
private:
	// 로딩 중인지 끝난는지 판단할 변수
	bool isLoading;
public:
	cLoading();
	~cLoading();

	// 이미지 추가 함수
	string AddImage(string KeyName);

	// 로딩 중인지 아닌지 체크 변수 겟&&셋
	bool Get_isLoading() { return isLoading; }
	void Set_isLoading(bool num) { isLoading = num; }

	//void m_Town();		    // 세리아방 && 마을 로딩
	//void m_EasyDercharge();  // 일반 던젼 로딩
	//void m_HellDercharge();  // 헬   던젼 로딩
};
