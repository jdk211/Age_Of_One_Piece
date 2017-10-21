#include "stdafx.h"
#include "archer_wapol.h"


archer_wapol::archer_wapol()
{
}


archer_wapol::~archer_wapol()
{
}

HRESULT archer_wapol::init( string imageName, int line, int id )
{
	unit::init( imageName, line, id );

	// 이동속도
	_speed = 110;

	// 이동사거리
	_sight = 250;

	// x좌표
	_x = 1488;

	// 스플레시
	_attack.splash = false;

	// 공격딜레이
	_attack.time -= _attack.delay = 7;

	// 공격 범위
	_attack.range = 480;

	// 체력
	_currentHP = _maxHP = 150;

	// 공격력
	_damage = 78;

	_gold = _cost = 150;

	return S_OK;
}

void archer_wapol::plusUpdate()
{
	for( int i = 0; i < _bullet.size(); i++ )
	{
		_bullet[i].update();
		for( int j = 0; j < _vShotUnit.size(); j++ )
		{
			if( getDistanceX( _bullet[i].getX(), _vShotUnit[j]->getX() ) < 20 )
			{
				_vShotUnit[j]->hitDamage( _damage );
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
				EFFECTMANAGER->play( "wapol_effect2", _bullet[i].getX(), ptY - 40 );
				_bullet.erase( _bullet.begin() + i );
				i -= 1;
				break;
			}
		}
	}
}

void archer_wapol::plusRender()
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

void archer_wapol::attack()
{
	unit::attack();

	if( _index.indexNum != 3 ) return; // 공격 시점
	if( _attack.running ) return; // 이미 공격을 했는지.

								  // 공격해야하는 상황.
	bullet_wapol _blt;
	_blt.init( "wapol_bullet", _x, _y - 15 - _image->getFrameHeight() / 2, 250 );
	_bullet.push_back( _blt );
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

	EFFECTMANAGER->play( "wapol_effect", _x, _y + ptY - 40 );
	_attack.running = true;
}

void archer_wapol::setState( int st )
{
	unit::setState( st, "wapol" );
}

