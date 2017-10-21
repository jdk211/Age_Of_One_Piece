#pragma once
#include "unit_archer.h"
#include <vector>

class bullet_smoker : public gameNode { // Projectiles
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
	HRESULT init(string imagename, float x, float y, float speed) {
		_image = IMAGEMANAGER->findImage(imagename);
		_x = x - _image->getFrameWidth() / 2 - 15;
		_y = y - 15;
		_speed = speed;
		_index.time = TIMEMANAGER->getWorldTime();
		_index.delay = 0.25;
		_index.indexNum = 0;
		return S_OK;
	}
	void release() {}
	void update() {
		if (TIMEMANAGER->getWorldTime() - _index.time > _index.delay) {
			_index.time = TIMEMANAGER->getWorldTime();
			_index.indexNum++;
		}
		move();
	}
	void move() {
		_x += -_speed*TIMEMANAGER->getElapsedTime();
	}
	void render(float ptY) {
		_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

		_image->frameRender(getMemDC(), VIEWMANAGER->getPtx(_rc.left), ptY + _y, _index.indexNum, 0);
	}
	float getX() { return _x; }
	float getY() { return _y; }

	float getDistanceX(float destX, float x) {
		if (destX - x > 0)
			return destX - x;
		else
			return x - destX;
	}
	bool isRelease()
	{
		if (_index.indexNum >= _image->getMaxFrameX())
			return true;
		return false;
	}

	bool coll(float x) {
		if (getDistanceX(getX(), x) < 20)
			return true;
		else
			return false;
	}
};

class archer_smoker : public unit_archer
{
private:
	vector<bullet_smoker> _bullet;
public:
	/*
	모든 유닛이 이동은 동일.

	따로 해줘야 할것
	init();		초기화

	attack();	어택
	*/
	archer_smoker();
	~archer_smoker();

	virtual HRESULT init(string imageName, int line, int id);
	virtual void plusUpdate();
	virtual void plusRender();

	virtual void attack();

	virtual void setState(int st);

	vector<bullet_smoker> getBullet() { return _bullet; }
	bullet_smoker getBulletNum(int i) { return _bullet[i]; }
};

