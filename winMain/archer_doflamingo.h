#pragma once
#include "unit_archer.h"

class archer_doflamingo : public unit_archer
{
private:
public:
	/*
	��� ������ �̵��� ����.

	���� ����� �Ұ�
	init();		�ʱ�ȭ

	attack();	����
	*/
	archer_doflamingo();
	~archer_doflamingo();

	virtual HRESULT init(string imageName, int line, int id);

	virtual void attack();

	virtual void setState(int st);


};
