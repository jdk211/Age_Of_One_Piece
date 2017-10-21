#include "stdafx.h"
#include "town.h"


town::town()
{
}


town::~town()
{
}

HRESULT town::init(int team)
{
	_level = 1;
	_gold = 10000;
	
	_currentHP = _maxHP = 2000;

	switch (team) {
	case 0:
		unit::init("castle", 0, 1001);

		_x = 32 * 4;
		_y = 32 * 13;

		_imageIndex[0] = 0;
		_imageIndex[1] = 1;
		_imageIndex[2] = 2;
		_imageIndex[3] = 3;
		_imageIndex[4] = 4;

		_hpbar = new progressBar;
		_hpbar->init(VIEWMANAGER->getPtx(_x), _y - IMAGEMANAGER->findImage("castle")->getFrameHeight() - 40, 200, 5);
		break;
	case 1:
		unit::init("castle", 0, 1002);

		_x = 32 * (50 - 4);
		_y = 32 * 13;

		_imageIndex[0] = 0;
		_imageIndex[1] = 1;
		_imageIndex[2] = 2;
		_imageIndex[3] = 3;
		_imageIndex[4] = 4;

		_hpbar = new progressBar;
		_hpbar->init(VIEWMANAGER->getPtx(_x), _y - IMAGEMANAGER->findImage("castle")->getFrameHeight() - 40, 200, 5);
		break;
	}

	_oldExp = _exp = 0;

	

	return S_OK;
}

void town::release()
{
}

void town::update(int dx)
{
	townUpgrade();

	_hpbar->setGauge(_currentHP, _maxHP);
	_hpbar->update();
}

void town::render()
{
	_image->frameRender(getMemDC(),
		VIEWMANAGER->getPtx(_x) - IMAGEMANAGER->findImage("castle")->getFrameWidth() / 2,
		VIEWMANAGER->getPty(_y) - 100 * IMAGEMANAGER->findImage("castle")->getFrameHeight() / 135,
		_imageIndex[_level] % 4, _imageIndex[_level] / 4);

	_hpbar->render(VIEWMANAGER->getPtx(_x));
}

void town::townUpgrade()
{
	/*
	450 / 500 ->

	950 / 1000 ->

	타워가 업그레이드 될때 타워의 체력이 회복되는지?
	-> 20 / 500
	-> 520 / 1000
	bool level1 = false;

	int oldExp;
	*/
	//_oldExp = 3900;
	//_exp = 4100;

	if (_oldExp < 4000 && _exp >= 4000) { // 타워업글
		_level = 2;
		int backHP = _maxHP - _currentHP;
		_maxHP = 3000;
		_currentHP = _maxHP - backHP;
	}
	else if (_oldExp < 8000 && _exp >= 8000)
	{
		_level = 3;
		int backHP = _maxHP - _currentHP;
		_maxHP = 4500;
		_currentHP = _maxHP - backHP;
	}
	else if (_oldExp < 12000 && _exp >= 12000)
	{
		_level = 4;
		int backHP = _maxHP - _currentHP;
		_maxHP = 6000;
		_currentHP = _maxHP - backHP;
	}
	else if (_oldExp < 16000 && _exp >= 16000)
	{
		_level = 5;
		int backHP = _maxHP - _currentHP;
		_maxHP = 8500;
		_currentHP = _maxHP - backHP;
	}

	_oldExp = _exp;
}
/*
if (_exp < 4000 && level1 == false)
{
_level = 1;
_maxHP = 500;
level1 = true;
}
else if (_exp >= 4000 && _exp < 8000)
{
_level = 2;
_maxHP = 1000;
}
else if (_exp >= 8000 && _exp < 12000)
{
_level = 3;
_maxHP = 1500;
}
else if (_exp >= 12000 && _exp < 16000)
{
_level = 4;
_maxHP = 2000;
}
else
{
_level = 5;
_maxHP = 2500;
}
*/