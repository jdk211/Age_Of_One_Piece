#pragma once
#include "unit_special.h"

class special_blackbeard : public unit_special
{
private:
	int _level;

public:
	/*
	��� ������ �̵��� ����.

	���� ����� �Ұ�
	init();		�ʱ�ȭ

	attack();	����
	*/
	special_blackbeard();
	~special_blackbeard();

	virtual HRESULT init(string imageName, int line, int level, int id);

	virtual void attack();

	virtual void setState(int st);
};

