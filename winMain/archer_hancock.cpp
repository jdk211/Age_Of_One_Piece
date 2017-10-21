#include "stdafx.h"
#include "archer_hancock.h"


archer_hancock::archer_hancock()
{
}


archer_hancock::~archer_hancock()
{
}

HRESULT archer_hancock::init(string imageName, int line, int id)
{
	unit::init(imageName, line, id);

	// 이동속도
	_speed = 110;

	// 이동사거리
	_sight = 250;

	// x좌표
	_x = 112;

	// 스플레시
	_attack.splash = false;

	// 공격딜레이
	_attack.time -= _attack.delay = 7;

	// 공격 범위
	_attack.range = 480;

	// 체력
	_currentHP = _maxHP = 150;

	// 공격력
	_damage = 78;

	_gold = _cost = 340;

	_exp = 100;

	return S_OK;
}

void archer_hancock::plusUpdate()
{
	for (int i = 0; i < _bullet.size(); i++)
	{
		_bullet[i].update();
		for (int j = 0; j < _vShotUnit.size(); j++)
		{
			if (getDistanceX(_bullet[i].getX(), _vShotUnit[j]->getX()) < 20)
			{
				_vShotUnit[j]->hitDamage(_damage);
				_bullet.erase(_bullet.begin() + i);
				i -= 1;
				break;
			}
		}
	}
}

void archer_hancock::plusRender()
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

void archer_hancock::attack()
{
	unit::attack();

	if (_index.indexNum != 5) return; // 공격 시점
	if (_attack.running) return; // 이미 공격을 했는지.

								 // 공격해야하는 상황.
	bullet_hancock _blt;
	_blt.init("hancock_bullet", _x, _y - 15 - _image->getFrameHeight() / 2, 250);

	_bullet.push_back(_blt);


	_attack.running = true;
}

void archer_hancock::setState(int st)
{
	unit::setState(st, "hancock");
}

