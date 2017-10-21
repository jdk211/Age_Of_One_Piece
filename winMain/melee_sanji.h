#pragma once

#include "unit_melee.h"

class melee_sanji: public unit_melee
{
private:
public:
	/*
	모든 유닛이 이동은 동일.

	따로 해줘야 할것
	init();		초기화

	attack();	어택
	*/
	melee_sanji();
	~melee_sanji();

	virtual HRESULT init( string imageName, int line, int id );
	virtual void attack();
	virtual void setState( int st );
};

