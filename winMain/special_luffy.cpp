#include "stdafx.h"
#include "special_luffy.h"


special_luffy::special_luffy()
{
}


special_luffy::~special_luffy()
{
}

HRESULT special_luffy::init(string imageName, int line, int level, int id)
{
	unit::init(imageName, line, level, id);

	// 이동속도
	_speed = 150;

	// 이동사거리
	_sight = 40;

	// x좌표
	_x = 112;

	// 스플레시
	_attack.splash = true;

	// 공격딜레이
	_attack.delay = 1.5;

	// 공격 범위
	_attack.range = 80;

	// 체력
	_currentHP = _maxHP = 420;

	// 공격력
	_damage = 30;

	//레벨
	_level = level;

	if (level == 1)
	{
		_gold = _cost = 380;
	}
	else if (level == 2)
	{
		_gold = _cost = 570;
	}
	else if (level == 2)
	{
		_gold = _cost = 855;
	}
	else if (level == 2)
	{
		_gold = _cost = 1280;
	}
	else if (level == 2)
	{
		_gold = _cost = 1920;
	}

	_exp = 100;

	return S_OK;
}

void special_luffy::attack()
{
	unit::attack();

	if (_attack.running) return; // 이미 공격을 했는지.

	switch (_level)
	{
	case 1:
		if (_index.indexNum != 3) return; // 공격 시점

		break;
	case 2:
		if (_index.indexNum != 7) return;

		break;
	case 3:
		if (_index.indexNum != 7) return;

		break;
	case 4:
		if (_index.indexNum != 12) return;

		break;
	case 5:
		if (_index.indexNum != 15) return;

		break;
	}

	// 공격해야하는 상황.
	for (int i = 0; i < _vShotUnit.size(); i++)
	{
		//if (!_attack.splash) ; // 스플 ㄴㄴ해요
		_vShotUnit[i]->hitDamage(_damage);
		_attack.splash = true;
	}

	_attack.running = true;
}

void special_luffy::setState(int st)
{
	unit::setState(st, "luffy", _level);
}
