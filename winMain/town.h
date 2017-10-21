#pragma once
#include "unit.h"
#include "progressBar.h"

class town : public unit
{
private:
	int _level;
	int _imageIndex[5];
	int _oldExp;

	progressBar* _hpbar;

public:
	town();
	~town();

	virtual HRESULT init(int team);
	virtual void release();
	virtual void update(int dx);
	virtual void render();

	virtual void townUpgrade();

	virtual int getLevel() { return _level; }
};

