#include "stdafx.h"
#include "archer_kizaru.h"


archer_kizaru::archer_kizaru()
{
}


archer_kizaru::~archer_kizaru()
{
}

HRESULT archer_kizaru::init(string imageName, int line, int id)
{
	unit::init(imageName, line, id);

	// 이동속도
	_speed = 110;

	// 이동사거리
	_sight = 250;

	// x좌표
	_x = 1488;

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

	_gold = _cost = 510;

	return S_OK;
}

float archer_kizaru::getDistanceX(float destX, float x)
{
	if (destX - x > 0)
		return destX - x;
	else
		return x - destX;
}

void archer_kizaru::plusUpdate()
{
	for (int i = 0; i < _bullet_kizaru.size(); i++)
	{
		_bullet_kizaru[i].update();
		for (int j = 0; j < _vShotUnit.size(); j++)
		{
			if (getDistanceX(_bullet_kizaru[i].getX(), _vShotUnit[j]->getX()) < 20)
			{
				_vShotUnit[j]->hitDamage(_damage);
				_bullet_kizaru.erase(_bullet_kizaru.begin() + i);
				i -= 1;
				break;
			}
		}
	}
}

void archer_kizaru::plusRender()
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
	for (int i = 0; i < _bullet_kizaru.size(); i++) {
		_bullet_kizaru[i].render(ptY);
	}
}

void archer_kizaru::attack()
{
	unit::attack();

	if (_index.indexNum != 3) return; // 공격 시점
	if (_attack.running) return; // 이미 공격을 했는지.

	// 공격해야하는 상황.
	bullet_kizaru _blt;
	_blt.init("kizaru_bullet", _x - 80, _y - 15 - _image->getFrameHeight() / 2 - 10, 250);

	_bullet_kizaru.push_back(_blt);


	_attack.running = true;
}

void archer_kizaru::setState(int st)
{
	unit::setState(st, "kizaru");
}