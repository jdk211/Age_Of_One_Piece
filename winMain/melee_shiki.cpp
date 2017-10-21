#include "stdafx.h"
#include "melee_shiki.h"


melee_shiki::melee_shiki()
{
}


melee_shiki::~melee_shiki()
{
}
HRESULT melee_shiki::init(string imageName, int line, int id)
{
	unit::init(imageName, line, id);

	// �̵��ӵ�
	_speed = 150;

	// �̵���Ÿ�
	_sight = 40;

	// x��ǥ
	_x = 1488;

	// ���÷���
	_attack.splash = false;

	// ���ݵ�����
	_attack.delay = 3;

	// ���� ����
	_attack.range = 80;

	// ü��
	_currentHP = _maxHP = 250;

	// ���ݷ�
	_damage = 50;

	_gold = _cost = 180;

	return S_OK;
}

void melee_shiki::attack()
{
	unit::attack();

	if (_index.indexNum != 3) return; // ���� ����
	if (_attack.running) return; // �̹� ������ �ߴ���.

	// �����ؾ��ϴ� ��Ȳ.
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


void melee_shiki::setState(int st)
{
	unit::setState(st, "shiki");
}