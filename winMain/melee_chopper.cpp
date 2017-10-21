#include "stdafx.h"
#include "melee_chopper.h"


melee_chopper::melee_chopper()
{
}


melee_chopper::~melee_chopper()
{
}
HRESULT melee_chopper::init(string imageName, int line, int id)
{
	unit::init(imageName, line, id);

	// 이동속도
	_speed = 150;

	// 이동사거리
	_sight = 40;

	// x좌표
	_x = 112;

	// 스플레시
	_attack.splash = false;

	// 공격딜레이
	_attack.delay = 1.5;

	// 공격 범위
	_attack.range = 80;

	// 체력
	_currentHP = _maxHP = 120;

	// 공격력
	_damage = 50;

	// 생성 딜레이
	_addDelay = 3;

	_gold = _cost = 120;

	return S_OK;
}

void melee_chopper::attack()
{
	unit::attack();

	if (_index.indexNum != 3) return; // 공격 시점
	if (_attack.running) return; // 이미 공격을 했는지.

								 // 공격해야하는 상황.
	for (int i = 0; i < _vShotUnit.size(); i++)
	{
		if (_attack.splash) break; // 스플 ㄴㄴ해요
		_vShotUnit[i]->hitDamage(_damage);
		_attack.splash = true;
	}

	_attack.running = true;
}


void melee_chopper::setState(int st)
{
	unit::setState(st, "chopper");
}
