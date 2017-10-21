#include "stdafx.h"
#include "special_luffy.h"


special_luffy::special_luffy()
{
}


special_luffy::~special_luffy()
{
}

HRESULT special_luffy::init(string imageName, int line, int level, int id)
{
	unit::init(imageName, line, level, id);

	// �̵��ӵ�
	_speed = 150;

	// �̵���Ÿ�
	_sight = 40;

	// x��ǥ
	_x = 112;

	// ���÷���
	_attack.splash = true;

	// ���ݵ�����
	_attack.delay = 1.5;

	// ���� ����
	_attack.range = 80;

	// ü��
	_currentHP = _maxHP = 420;

	// ���ݷ�
	_damage = 30;

	//����
	_level = level;

	if (level == 1)
	{
		_gold = _cost = 380;
	}
	else if (level == 2)
	{
		_gold = _cost = 570;
	}
	else if (level == 2)
	{
		_gold = _cost = 855;
	}
	else if (level == 2)
	{
		_gold = _cost = 1280;
	}
	else if (level == 2)
	{
		_gold = _cost = 1920;
	}

	_exp = 100;

	return S_OK;
}

void special_luffy::attack()
{
	unit::attack();

	if (_attack.running) return; // �̹� ������ �ߴ���.

	switch (_level)
	{
	case 1:
		if (_index.indexNum != 3) return; // ���� ����

		break;
	case 2:
		if (_index.indexNum != 7) return;

		break;
	case 3:
		if (_index.indexNum != 7) return;

		break;
	case 4:
		if (_index.indexNum != 12) return;

		break;
	case 5:
		if (_index.indexNum != 15) return;

		break;
	}

	// �����ؾ��ϴ� ��Ȳ.
	for (int i = 0; i < _vShotUnit.size(); i++)
	{
		//if (!_attack.splash) ; // ���� �����ؿ�
		_vShotUnit[i]->hitDamage(_damage);
		_attack.splash = true;
	}

	_attack.running = true;
}

void special_luffy::setState(int st)
{
	unit::setState(st, "luffy", _level);
}
