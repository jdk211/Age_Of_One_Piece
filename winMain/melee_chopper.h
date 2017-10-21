#pragma once
#include "unit_melee.h"

class melee_chopper : public unit_melee
{
public:
	melee_chopper();
	~melee_chopper();

	virtual HRESULT init(string imageName, int line, int id);

	virtual void attack();

	virtual void setState(int st);
};

