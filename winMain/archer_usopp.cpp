#include "stdafx.h"
#include "archer_usopp.h"


archer_usopp::archer_usopp()
{
}


archer_usopp::~archer_usopp()
{
}

HRESULT archer_usopp::init( string imageName, int line, int id )
{
	unit::init( imageName, line, id );

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

	_gold = _cost = 150;

	return S_OK;
}

void archer_usopp::plusUpdate()
{
	for( int i = 0; i < _bullet.size(); i++ )
	{
		_bullet[i].update();
		for( int j = 0; j < _vShotUnit.size(); j++ )
		{
			if( getDistanceX( _bullet[i].getX(), _vShotUnit[j]->getX() ) < 20 )
			{
				_vShotUnit[j]->hitDamage( _damage );
				_bullet.erase( _bullet.begin() + i );
				i -= 1;
				break;
			}
		}
	}
}

void archer_usopp::plusRender()
{
	int ptY = 0;
	switch( _line )
	{
	case 1:
		ptY = 340;
		break;
	case 2:
		ptY = 530;
		break;
	}
	for( int i = 0; i < _bullet.size(); i++ ) {
		_bullet[i].render( ptY );
	}
}

void archer_usopp::attack()
{
	unit::attack();

	if( _index.indexNum != 5 ) return; // ���� ����
	if( _attack.running ) return; // �̹� ������ �ߴ���.

								  // �����ؾ��ϴ� ��Ȳ.
	bullet_usopp _blt;
	_blt.init( "usopp_bullet", _x, _y - 15 - _image->getFrameHeight() / 2, 250 );

	_bullet.push_back( _blt );


	_attack.running = true;
}

void archer_usopp::setState( int st )
{
	unit::setState( st, "usopp" );
}

