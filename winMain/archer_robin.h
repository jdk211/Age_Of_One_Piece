#pragma once
#include "unit_archer.h"
#include <vector>

class archer_robin : public unit_archer
{
private:

public:
	/*
	��� ������ �̵��� ����.

	���� ����� �Ұ�
	init();		�ʱ�ȭ

	attack();	����
	*/
	archer_robin();
	~archer_robin();

	virtual HRESULT init(string imageName, int line, int id);

	virtual void attack();

	virtual void setState(int st);
};
