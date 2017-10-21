#include "stdafx.h"
#include "archer_smoker.h"


archer_smoker::archer_smoker()
{
}


archer_smoker::~archer_smoker()
{
}

HRESULT archer_smoker::init(string imageName, int line, int id)
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
	_currentHP = _maxHP = 40;

	// 공격력
	_damage = 87.5f;
	
	_gold = _cost = 90;

	return S_OK;
}

void archer_smoker::plusUpdate()
{
	for (int i = 0; i < _bullet.size(); i++)
	{
		_bullet[i].update();
		for (int j = 0; j < _vShotUnit.size(); j++)
		{
			if (_bullet[i].isRelease()) 
			{
				_vShotUnit[j]->hitDamage(_damage);
				_bullet.erase(_bullet.begin() + i);
				i -= 1;
				break;
			}
			if (_bullet[i].coll(_vShotUnit[j]->getX()))
			{// 총알과 적 충돌판정
				_vShotUnit[j]->hitDamage(_damage);
				_bullet.erase(_bullet.begin() + i);
				i -= 1;
				break;
			}
		}
	}
}

void archer_smoker::plusRender()
{
	int ptY = 0;
	switch (_line)
	{
	case 1:
		ptY = 340;
		break;
	case 2:
		ptY = 530;
		break;
	}
	for (int i = 0; i < _bullet.size(); i++) {
		_bullet[i].render(ptY);
	}
}

void archer_smoker::attack()
{
	unit::attack();

	if (_index.indexNum != 4) return; // 공격 시점
	if (_attack.running) return; // 이미 공격을 했는지.

								 // 공격해야하는 상황.
	bullet_smoker _blt;
	_blt.init("smoker_bullet", _x, _y - 15 - _image->getFrameHeight() / 2, 400);

	_bullet.push_back(_blt);


	_attack.running = true;
}

void archer_smoker::setState(int st)
{
	unit::setState(st, "smoker");
}

