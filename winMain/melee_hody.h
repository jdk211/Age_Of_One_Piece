#pragma once
#include "unit_melee.h"
class melee_hody: public unit_melee
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
	melee_hody();
	~melee_hody();
	virtual HRESULT init( string imageName, int line, int id );

	virtual void attack();

	virtual void setState( int st );
};
