#pragma once
#include "unit_archer.h"
#include <vector>

class archer_enel : public unit_archer
{
private:

public:
	/*
	��� ������ �̵��� ����.

	���� ����� �Ұ�
	init();		�ʱ�ȭ

	attack();	����
	*/
	archer_enel();
	~archer_enel();

	virtual HRESULT init(string imageName, int line, int id);

	virtual void attack();

	virtual void setState(int st);

};