#pragma once
#include "unit_melee.h"

class melee_lucci : public unit_melee
{
public:
	melee_lucci();
	~melee_lucci();
	/*
	��� ������ �̵��� ����.

	���� ����� �Ұ�
	init();		�ʱ�ȭ
	render();	���

	attack();	����
	*/
	virtual HRESULT init(string imageName, int line, int id);

	virtual void attack();

	virtual void setState(int st);
};

