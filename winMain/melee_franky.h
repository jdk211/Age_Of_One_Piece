#pragma once

#include "unit_melee.h"

class melee_franky : public unit_melee
{
private:
public:
	/*
	��� ������ �̵��� ����.

	���� ����� �Ұ�
	init();		�ʱ�ȭ

	attack();	����
	*/
	melee_franky();
	~melee_franky();

	virtual HRESULT init( string imageName, int line, int id );
	virtual void attack();
	virtual void setState( int st );
};

