#pragma once


class cLoading
{
private:
	// �ε� ������ �������� �Ǵ��� ����
	bool isLoading;
public:
	cLoading();
	~cLoading();

	// �̹��� �߰� �Լ�
	string AddImage(string KeyName);

	// �ε� ������ �ƴ��� üũ ���� ��&&��
	bool Get_isLoading() { return isLoading; }
	void Set_isLoading(bool num) { isLoading = num; }

	//void m_Town();		    // �����ƹ� && ���� �ε�
	//void m_EasyDercharge();  // �Ϲ� ���� �ε�
	//void m_HellDercharge();  // ��   ���� �ε�
};
