#pragma once
#include "unit_archer.h"
#include <vector>

class bullet_wapol: public gameNode { // Projectiles
public:
	struct index {
		float time;
		float delay;
		int indexNum;
	};
protected:
	image *_image;
	float _x, _y;
	float _speed;
	index _index;
	RECT _rc;

public:
	HRESULT init( string imagename, float x, float y, float speed ) {
		_image = IMAGEMANAGER->findImage( imagename );
		_x = x;
		_y = y;
		_speed = speed;
		_index.time = TIMEMANAGER->getWorldTime();
		_index.delay = 0.25;
		return S_OK;
	}
	void release() {}
	void update() {
		if( TIMEMANAGER->getWorldTime() - _index.time > _index.delay ) {
			_index.time = TIMEMANAGER->getWorldTime();
			_index.indexNum++;
			if( _index.indexNum >= _image->getMaxFrameX() ) {
				_index.indexNum = 0;
			}
		}
		move();
	}
	void move() {
		_x -= _speed*TIMEMANAGER->getElapsedTime();
	}
	void render( float ptY ) {
		_rc = RectMakeCenter( _x, _y, _image->getFrameWidth(), _image->getFrameHeight() );

		_image->frameRender( getMemDC(), VIEWMANAGER->getPtx( _x ), ptY + _y, _index.indexNum, 0 );
	}
	float getX() { return _x; }
	float getY() { return _y; }
};

class archer_wapol: public unit_archer
{
public:

private:
	vector<bullet_wapol> _bullet;

public:
	/*
	모든 유닛이 이동은 동일.

	따로 해줘야 할것
	init();		초기화

	attack();	어택
	*/
	archer_wapol();
	~archer_wapol();

	virtual HRESULT init( string imageName, int line, int id );
	virtual void plusUpdate();
	virtual void plusRender();

	virtual void attack();

	virtual void setState( int st );

	float getDistanceX( float destX, float x ) {
		if( destX - x > 0 )
			return destX - x;
		else
			return x - destX;
	}

	vector<bullet_wapol> getBullet() { return _bullet; }
	bullet_wapol getBulletNum( int i ) { return _bullet[i]; }
};

