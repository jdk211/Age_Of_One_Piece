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

	// �̵��ӵ�
	_speed = 150;

	// �̵���Ÿ�
	_sight = 40;

	// x��ǥ
	_x = 112;

	// ���÷���
	_attack.splash = false;

	// ���ݵ�����
	_attack.delay = 1.5;

	// ���� ����
	_attack.range = 80;

	// ü��
	_currentHP = _maxHP = 120;

	// ���ݷ�
	_damage = 50;

	// ���� ������
	_addDelay = 3;

	_gold = _cost = 120;

	return S_OK;
}

void melee_chopper::attack()
{
	unit::attack();

	if (_index.indexNum != 3) return; // ���� ����
	if (_attack.running) return; // �̹� ������ �ߴ���.

								 // �����ؾ��ϴ� ��Ȳ.
	for (int i = 0; i < _vShotUnit.size(); i++)
	{
		if (_attack.splash) break; // ���� �����ؿ�
		_vShotUnit[i]->hitDamage(_damage);
		_attack.splash = true;
	}

	_attack.running = true;
}


void melee_chopper::setState(int st)
{
	unit::setState(st, "chopper");
}
