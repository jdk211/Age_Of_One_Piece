#include "stdafx.h"
#include "archer_enel.h"


archer_enel::archer_enel()
{
}


archer_enel::~archer_enel()
{
}

HRESULT archer_enel::init(string imageName, int line, int id)
{
	unit::init(imageName, line, id);

	// 이동속도
	_speed = 110;

	// 이동사거리
	_sight = 400;

	// x좌표
	_x = 1488;

	// 스플레시
	_attack.splash = false;

	// 공격딜레이
	_attack.time -= _attack.delay = 5.2;

	// 공격 범위
	_attack.range = 500;

	// 체력
	_currentHP = _maxHP = 150;

	// 공격력
	_damage = 78;

	_gold = _cost = 340;

	return S_OK;
}

void archer_enel::attack()
{
	unit::attack();

	if (_index.indexNum != 4) return; // 공격 시점
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

	int ptY = 0;
	switch (_vShotUnit[little_index]->getLine())
	{
	case 0:
		ptY = 50;
		break;
	case 1:
		ptY = 340;
		break;
	case 2:
		ptY = 530;
		break;
	}
	EFFECTMANAGER->play("enel_effect", _vShotUnit[little_index]->getX(), _vShotUnit[little_index]->getY() + ptY - 35);

	_attack.splash = true;
	_attack.running = true;
}

void archer_enel::setState(int st)
{
	unit::setState(st, "enel");
}

