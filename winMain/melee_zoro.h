#pragma once
#include "unit_melee.h"
class melee_zoro : public unit_melee
{
private:
public:
	/*
	��� ������ �̵��� ����.

	���� ����� �Ұ�
	init();		�ʱ�ȭ

	attack();	����
	*/
	melee_zoro();
	~melee_zoro();
	virtual HRESULT init(string imageName, int line,int id);

	virtual void attack();

	virtual void setState(int st);
};

