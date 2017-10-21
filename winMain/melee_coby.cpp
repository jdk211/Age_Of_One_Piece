#include "stdafx.h"
#include "melee_coby.h"


melee_coby::melee_coby()
{
}


melee_coby::~melee_coby()
{
}
HRESULT melee_coby::init(string imageName, int line, int id)
{
	unit::init(imageName, line, id);

	// 이동속도
	_speed = 150;

	// 이동사거리
	_sight = 40;

	// x좌표
	_x = 1488;

	// 스플레시
	_attack.splash = false;

	// 공격딜레이
	_attack.delay = 3;

	// 공격 범위
	_attack.range = 80;

	// 체력
	_currentHP = _maxHP = 100;

	// 공격력
	_gold = _damage = 60;

	return S_OK;
}

void melee_coby::attack()
{
	unit::attack();

	if (_index.indexNum != 3) return; // 공격 시점
	if (_attack.running) return; // 이미 공격을 했는지.

	float little_distance = 100000;
	float little_index = 0;

	for (int i = 0; i < _vShotUnit.size(); i++)
	{
		if (getDistanceX(_x, _vShotUnit[i]->getX()) > little_distance) {
			little_distance = getDistanceX(_x, _vShotUnit[i]->getX());
			little_index = i;
		}
	}

	if (_attack.splash) return; // 스플 ㄴㄴ해요
	_vShotUnit[little_index]->hitDamage(_damage);
	_attack.splash = true;

	_attack.running = true;
}


void melee_coby::setState(int st)
{
	unit::setState(st, "coby");
}