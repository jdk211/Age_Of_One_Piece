#pragma once
#include "unit_melee.h"

class melee_lucci : public unit_melee
{
public:
	melee_lucci();
	~melee_lucci();
	/*
	모든 유닛이 이동은 동일.

	따로 해줘야 할것
	init();		초기화
	render();	출력

	attack();	어택
	*/
	virtual HRESULT init(string imageName, int line, int id);

	virtual void attack();

	virtual void setState(int st);
};

