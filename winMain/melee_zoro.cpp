#include "stdafx.h"
#include "melee_zoro.h"

melee_zoro::melee_zoro()
{
}

melee_zoro::~melee_zoro()
{
}

HRESULT melee_zoro::init(string imageName, int line,int id)
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
	_currentHP = _maxHP = 100;

	// ���ݷ�
	_damage = 40;

	_cost = 200;

	_exp = 100;

	return S_OK;
}

void melee_zoro::attack()
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


void melee_zoro::setState(int st)
{
	unit::setState(st, "zoro");
}
