#include "stdafx.h"
#include "melee_akainu.h"


melee_akainu::melee_akainu()
{
}


melee_akainu::~melee_akainu()
{
}


HRESULT melee_akainu::init(string imageName, int line, int id)
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
	_attack.time -= _attack.delay = 0.5;

	// 공격 범위
	_attack.range = 80;

	// 체력
	_currentHP = _maxHP = 250;

	// 공격력
	_damage = 50;

	_gold = _cost = 270;

	return S_OK;
}

void melee_akainu::attack()
{
	unit::attack();

	if (_index.indexNum != 15) return; // 공격 시점
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


void melee_akainu::setState(int st)
{
	unit::setState(st, "akainu");
}