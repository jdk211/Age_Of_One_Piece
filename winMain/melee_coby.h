#pragma once
#include "unit_melee.h"
class melee_coby : public unit_melee
{
private:
public:
	/*
	��� ������ �̵��� ����.

	���� ����� �Ұ�
	init();		�ʱ�ȭ
	render();	���

	attack();	����
	*/
	melee_coby();
	~melee_coby();
	virtual HRESULT init(string imageName, int line, int id);

	virtual void attack();

	virtual void setState(int st);
};

