#pragma once
#include "unit_special.h"

class special_luffy : public unit_special
{
private:
	int _level;

public:
	/*
	모든 유닛이 이동은 동일.

	따로 해줘야 할것
	init();		초기화

	attack();	어택
	*/
	special_luffy();
	~special_luffy();

	virtual HRESULT init(string imageName, int line, int level, int id);

	virtual void attack();

	virtual void setState(int st);
};

