#pragma once
#include "unit_melee.h"

class melee_akainu : public unit_melee
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
	melee_akainu();
	~melee_akainu();

	virtual HRESULT init(string imageName, int line, int id);

	virtual void attack();

	virtual void setState(int st);
};

