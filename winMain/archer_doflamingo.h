#pragma once
#include "unit_archer.h"

class archer_doflamingo : public unit_archer
{
private:
public:
	/*
	모든 유닛이 이동은 동일.

	따로 해줘야 할것
	init();		초기화

	attack();	어택
	*/
	archer_doflamingo();
	~archer_doflamingo();

	virtual HRESULT init(string imageName, int line, int id);

	virtual void attack();

	virtual void setState(int st);


};
