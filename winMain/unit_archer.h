#pragma once
#include "unit.h"

class bullet : public gameNode { // Projectiles
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
	virtual HRESULT init(string imagename, float x, float y, float speed) {
		_image = IMAGEMANAGER->findImage(imagename);
		_x = x - _image->getFrameWidth() / 2;
		_y = y;
		_speed = speed;
		_index.time = TIMEMANAGER->getWorldTime();
		_index.delay = 0.25;
		_index.indexNum = 0;
		return S_OK;
	}
	virtual void release() {}
	virtual void update() {
		if (TIMEMANAGER->getWorldTime() - _index.time > _index.delay) {
			_index.time = TIMEMANAGER->getWorldTime();
			_index.indexNum++;
			if (_index.indexNum >= _image->getMaxFrameX()) {
				_index.indexNum = 0;
			}
		}
		move();
	}
	virtual void move() {
		//_x += _speed*TIMEMANAGER->getElapsedTime();
	}
	virtual void render(float ptY) {
		_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

		_image->frameRender(getMemDC(), VIEWMANAGER->getPtx(_x), ptY + _y, _index.indexNum, 0);
	}
	virtual float getX() { return _x; }
	virtual float getY() { return _y; }

	virtual float getDistanceX(float destX, float x) {
		if (destX - x > 0)
			return destX - x;
		else
			return x - destX;
	}

	virtual bool coll(float x) {
		int backX = 0;
		switch (_index.indexNum) {
		case 0:
			backX = _image->getFrameWidth() / 10 * 3.5;
			break;
		case 1:
			backX = _image->getFrameWidth() / 10 * 1.2;
			break;
		case 2:
			backX = -_image->getFrameWidth() / 10 * 1.5;
			break;
		case 3:case 4:case 5:case 6:
			backX = -_image->getFrameWidth() / 10 * 4.1;
			break;
		case 7:
			backX = -_image->getFrameWidth() / 10 * 1.9;
			break;
		case 8:
			backX = _image->getFrameWidth() / 10 * 0.5;
			break;
		case 9:
			backX = _image->getFrameWidth() / 10 * 2.6;
			break;
		}

		if (getDistanceX(getX() + backX, x) < 20)
			return true;
		else
			return false;
	}
};

class unit_archer : public unit
{
public:
	/*class bullet {
	private:
		image _image;
		float _x, _y;
		float _speed;
		float _radius;
		int _dir;
	public:
		HRESULT init();
		virtual void release();
		virtual void update();
		virtual void render();
	};*/
private:

public:
	unit_archer();
	~unit_archer();
};

