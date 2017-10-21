#include "stdafx.h"
#include "special_blackbeard.h"


special_blackbeard::special_blackbeard()
{
}


special_blackbeard::~special_blackbeard()
{
}

HRESULT special_blackbeard::init( string imageName, int line, int level, int id )
{
	unit::init( imageName, line, level, id );

	// �̵��ӵ�
	_speed = 150;

	// �̵���Ÿ�
	_sight = 40;

	// x��ǥ
	_x = 1488;

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


	return S_OK;
}

void special_blackbeard::attack()
{
	unit::attack();
	if( _attack.running ) return; // �̹� ������ �ߴ���.

								  // �����ؾ��ϴ� ��Ȳ.
	int ptY = 0;
	switch( _line )
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

	if( _level == 4 ) EFFECTMANAGER->play( "blackbeard_effect4", _x - 60, _y + ptY - 55 );
	else if( _level == 5 && _index.indexNum == 1 ) EFFECTMANAGER->play( "blackbeard_effect5_1", _x, _y + ptY );

	switch( _level )
	{
	case 1:
		if( _index.indexNum != 3 ) return; // ���� ����

		break;
	case 2:
		if( _index.indexNum != 3 ) return;

		break;
	case 3:
		if( _index.indexNum != 5 ) return;

		break;
	case 4:
		if( _index.indexNum != 2 ) return;

		break;
	case 5:
		if( _index.indexNum != 8 ) return;

		break;
	}


	for( int i = 0; i < _vShotUnit.size(); i++ )
	{
		//if (!_attack.splash) ; // ���� �����ؿ�

		if( _level == 5 ) EFFECTMANAGER->play( "blackbeard_effect5_2", _x - 50, _y + ptY - 40 );

		_vShotUnit[i]->hitDamage( _damage );
		_attack.splash = true;
	}

	_attack.running = true;


}

void special_blackbeard::setState( int st )
{
	unit::setState( st, "blackbeard", _level );
}
