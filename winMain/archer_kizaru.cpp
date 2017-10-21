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

	if (_index.indexNum != 3) return; // ���� ����
	if (_attack.running) return; // �̹� ������ �ߴ���.

	// �����ؾ��ϴ� ��Ȳ.
	bullet_kizaru _blt;
	_blt.init("kizaru_bullet", _x - 80, _y - 15 - _image->getFrameHeight() / 2 - 10, 250);

	_bullet_kizaru.push_back(_blt);


	_attack.running = true;
}

void archer_kizaru::setState(int st)
{
	unit::setState(st, "kizaru");
}