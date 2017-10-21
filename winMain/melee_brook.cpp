#include "stdafx.h"
#include "melee_brook.h"


melee_brook::melee_brook()
{
}


melee_brook::~melee_brook()
{
}

HRESULT melee_brook::init(string imageName, int line, int id)
{
	unit::init(imageName, line, id);

	// �̵��ӵ�
	_speed = 150;

	// �̵���Ÿ�
	_sight = 40;

	// x��ǥ
	_x = 112;

	// ���÷���
	_attack.splash = false;

	// ���ݵ�����
	_attack.time -= _attack.delay = 0.5;

	// ���� ����
	_attack.range = 80;

	// ü��
	_currentHP = _maxHP = 120;

	// ���ݷ�
	_damage = 50;

	_gold = _cost = 270;

	return S_OK;
}

void melee_brook::attack()
{
	unit::attack();

	if (_index.indexNum != 3) return; // ���� ����
	if (_attack.running) return; // �̹� ������ �ߴ���.

	float little_distance = 100000;
	float little_index = 0;

	for (int i = 0; i < _vShotUnit.size(); i++)
	{
		if (getDistanceX(_x, _vShotUnit[i]->getX()) > little_distance) {
			little_distance = getDistanceX(_x, _vShotUnit[i]->getX());
			little_index = i;
		}
	}

	if (_attack.splash) return; // ���� �����ؿ�
	_vShotUnit[little_index]->hitDamage(_damage);
	_attack.splash = true;

	_attack.running = true;
}


void melee_brook::setState(int st)
{
	unit::setState(st, "brook");
}