#include "stdafx.h"
#include "archer_kuma.h"


archer_kuma::archer_kuma()
{
}


archer_kuma::~archer_kuma()
{
}

HRESULT archer_kuma::init(string imageName, int line, int id)
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
	_attack.time -= _attack.delay = 7;

	// ���� ����
	_attack.range = 480;

	// ü��
	_currentHP = _maxHP = 150;

	// ���ݷ�
	_damage = 78;

	_gold = _cost = 510;

	_exp = 100;

	return S_OK;
}

float getDistanceX(float destX, float x) 
{
	if (destX - x > 0)
		return destX - x;
	else
		return x - destX;
}

void archer_kuma::plusUpdate()
{
	for (int i = 0; i < _bullet_kuma.size(); i++)
	{
		_bullet_kuma[i].update();
		for (int j = 0; j < _vShotUnit.size(); j++)
		{
			if (getDistanceX(_bullet_kuma[i].getX(), _vShotUnit[j]->getX()) < 20)
			{
				_vShotUnit[j]->hitDamage(_damage);
				_bullet_kuma.erase(_bullet_kuma.begin() + i);
				i -= 1;
				break;
			}
		}
	}
}

void archer_kuma::plusRender()
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
	for (int i = 0; i < _bullet_kuma.size(); i++) {
		_bullet_kuma[i].render(ptY);
	}
}

float archer_kuma::getDistanceX(float destX, float x) {
	if (destX - x > 0)
		return destX - x;
	else
		return x - destX;
}

void archer_kuma::attack()
{
	unit::attack();

	if (_index.indexNum != 12) return; // ���� ����
	if (_attack.running) return; // �̹� ������ �ߴ���.

	// �����ؾ��ϴ� ��Ȳ.
	bullet_kuma _blt;
	_blt.init("kuma_bullet", _x, _y - 15 - _image->getFrameHeight() / 2 + 52, 250);

	_bullet_kuma.push_back(_blt);


	_attack.running = true;
}

void archer_kuma::setState(int st)
{
	unit::setState(st, "kuma");
}
