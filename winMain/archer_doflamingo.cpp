#include "stdafx.h"
#include "archer_doflamingo.h"


archer_doflamingo::archer_doflamingo()
{
}


archer_doflamingo::~archer_doflamingo()
{
}

HRESULT archer_doflamingo::init(string imageName, int line, int id)
{
	unit::init(imageName, line, id);

	// �̵��ӵ�
	_speed = 110;

	// �̵���Ÿ�
	_sight = 250;

	// x��ǥ
	_x = 1488;

	// ���÷���
	_attack.splash = false;

	// ���ݵ�����
	_attack.time -= _attack.delay = 7;

	// ���� ����
	_attack.range = 480;

	// ü��
	_currentHP = _maxHP = 150;

	// ���ݷ�
	_damage = 78;

	_gold = _cost = 225;

	return S_OK;
}


void archer_doflamingo::attack()
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
	EFFECTMANAGER->play("doflamingo_effect", _vShotUnit[little_index]->getX(), _vShotUnit[little_index]->getY() + ptY - 35);

	_attack.splash = true;
	_attack.running = true;
}

void archer_doflamingo::setState(int st)
{
	unit::setState(st, "doflamingo");
}