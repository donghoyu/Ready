#pragma once
#define RECTANGLEMANAGER cRectangleManager::GetInstance()

class cRectangleManager
{
private:
	// �̱��� ����
	SINGLETONE(cRectangleManager);
	// ���� �׸� ��ġ
	ID3DXLine* Line;

public:
	// ��/���� ������ ����
	bool RenderOn;

	void Destory(); // �Ŵ��� ����

	void Render(float Left, float Top, float Right, float Bottom);								// �׸��� 
	void Render(float Left, float Top, float Right, float Bottom, D3DXCOLOR Color);			// �÷� ���� �߰�
	void Render(float Left, float Top, float Right, float Bottom, D3DXCOLOR Color, float Angle); // ���� ���� �߰�

};
