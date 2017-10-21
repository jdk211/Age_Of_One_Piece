#include "stdafx.h"
#include "archer_nami.h"


archer_nami::archer_nami()
{
}


archer_nami::~archer_nami()
{
}

HRESULT archer_nami::init(string imageName, int line, int id)
{
	unit::init(imageName, line, id);

	// �̵��ӵ�
	_speed = 110;

	// �̵���Ÿ�
	_sight = 250;

	// x��ǥ
	_x = 112;

	// ���÷���
	_attack.splash = false;

	// ���ݵ�����
	_attack.time -=  _attack.delay = 7;

	// ���� ����
	_attack.range = 480;

	// ü��
	_currentHP = _maxHP = 40;

	// ���ݷ�
	_damage = 87.5f;

	_cost = 200;

	return S_OK;
}

void archer_nami::plusUpdate()
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

void archer_nami::plusRender()
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

void archer_nami::attack()
{
	unit::attack();

	if (_index.indexNum != 10) return; // ���� ����
	if (_attack.running) return; // �̹� ������ �ߴ���.

	// �����ؾ��ϴ� ��Ȳ.
	bullet_nami _blt;
	_blt.init("nami_bullet", _x, _y - 15 - _image->getFrameHeight()/2, 250);

	_bullet.push_back(_blt);
	
	_attack.running = true;
}

float archer_nami::getDistanceX(float destX, float x)
{

	if (destX - x > 0)
		return destX - x;
	else
		return x - destX;
}

void archer_nami::setState(int st)
{
	unit::setState(st, "nami");
}

