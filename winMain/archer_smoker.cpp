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

	// �̵��ӵ�
	_speed = 110;

	// �̵���Ÿ�
	_sight = 400;

	// x��ǥ
	_x = 1488;

	// ���÷���
	_attack.splash = false;

	// ���ݵ�����
	_attack.time -= _attack.delay = 5.2;

	// ���� ����
	_attack.range = 500;

	// ü��
	_currentHP = _maxHP = 40;

	// ���ݷ�
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
			{// �Ѿ˰� �� �浹����
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

	if (_index.indexNum != 4) return; // ���� ����
	if (_attack.running) return; // �̹� ������ �ߴ���.

								 // �����ؾ��ϴ� ��Ȳ.
	bullet_smoker _blt;
	_blt.init("smoker_bullet", _x, _y - 15 - _image->getFrameHeight() / 2, 400);

	_bullet.push_back(_blt);


	_attack.running = true;
}

void archer_smoker::setState(int st)
{
	unit::setState(st, "smoker");
}

