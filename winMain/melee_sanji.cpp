#include "stdafx.h"
#include "melee_sanji.h"


melee_sanji::melee_sanji()
{
}

melee_sanji::~melee_sanji()
{
}

HRESULT melee_sanji::init( string imageName, int line, int id )
{
	unit::init( imageName, line, id );

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
	_gold = _damage = 85;

	_cost = 200;

	return S_OK;
}

void melee_sanji::attack()
{
	unit::attack();

	if( _index.indexNum != 3 ) return; // ���� ����
	if( _attack.running ) return; // �̹� ������ �ߴ���.

								  // �����ؾ��ϴ� ��Ȳ.
	for( int i = 0; i < _vShotUnit.size(); i++ )
	{
		if( _attack.splash ) break; // ���� �����ؿ�
		_vShotUnit[i]->hitDamage( _damage );
		_attack.splash = true;
	}

	_attack.running = true;
}


void melee_sanji::setState( int st )
{
	unit::setState( st, "sanji" );
}
