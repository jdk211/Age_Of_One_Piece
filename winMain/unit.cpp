#include "stdafx.h"
#include "unit.h"

unit::unit()
{
}


unit::~unit()
{
}
HRESULT unit::init(int team) {
	return S_OK;
}

HRESULT unit::init(string imageName, int line, int id)
{
	_id = id;

	_image = IMAGEMANAGER->findImage(imageName);

	_index.time = TIMEMANAGER->getWorldTime();
	_index.dealy = 0.18;
	_index.indexMax = 8;
	_index.indexNum = 0;

	_attack.time = TIMEMANAGER->getWorldTime();

	_line = line;

	_y = RND->getFromFloatTo(-15, 15);

	life = true;

	_exp = 1000;
	/*
	스피드,x좌표
	*/
	return S_OK;
}

HRESULT unit::init(string imageName, int line, int level, int id)
{
	_id = id;

	_image = IMAGEMANAGER->findImage(imageName);

	_index.time = TIMEMANAGER->getWorldTime();
	_index.dealy = 0.18;
	_index.indexMax = 8;
	_index.indexNum = 0;

	_attack.time = TIMEMANAGER->getWorldTime();

	_line = line;

	_y = RND->getFromFloatTo(-15, 15);

	life = true;

	_exp = 100;
	/*
	스피드,x좌표
	*/
	return S_OK;
}

void unit::release()
{
}

void unit::update(int dx)
{
	switch (_state)
	{
	case ESTAND: // 정지
		if (TIMEMANAGER->getWorldTime() - _index.time > _index.dealy) {
			_index.time = TIMEMANAGER->getWorldTime();

			if (_index.indexNum >= _image->getMaxFrameX()) {
				_index.indexNum = 0;
			}
			else
			{
				_index.indexNum++;
			}
		}
		break;
	case EMOVE:
		move(dx);
		break;
	case EATTACK:

		attack();
		break;
	case EDIE:

		die();
		break;
	}

	plusUpdate();
}

void unit::plusUpdate()
{
}

void unit::render()
{
	_rc = RectMakeCenter(_x, _y - _image->getFrameHeight() / 2, _image->getFrameWidth(), _image->getFrameHeight());

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
	/*Rectangle(getMemDC(), VIEWMANAGER->getPtx(_x) - _sight, ptY - 15,
		VIEWMANAGER->getPtx(_x) + _sight, ptY + 15);

	Rectangle(getMemDC(),	VIEWMANAGER->getPtx(_x) - _attack.range, ptY - 5,
							VIEWMANAGER->getPtx(_x) + _attack.range, ptY + 5);*/
	_image->frameRender(getMemDC(), VIEWMANAGER->getPtx(_rc.left), ptY + _rc.top, _index.indexNum, 0);

	plusRender();

	if (_currentHP < 0) return;
	//char str[100];
	//sprintf_s(str, "%d [%d]", _state, _vShotUnit.size());
	//MY_UTIL::TextOutplus(getMemDC(), VIEWMANAGER->getPtx((_rc.left + _rc.right) / 2 - 50), ptY + _rc.bottom + 5,
	//	str, 25, RGB(255, 20, 255), 1000, "Dynalight"); // BlackChancery

	//sprintf_s(str, "[%0.2f/%0.2f]", _currentHP, _maxHP);
	//MY_UTIL::TextOutplus(getMemDC(), VIEWMANAGER->getPtx((_rc.left + _rc.right) / 2 - 50), ptY + _rc.top - 25,
	//	str, 20, RGB(255, 20, 255), 500, "Dynalight"); // BlackChancery

	/*for (int i = 0; i < _vShotUnit.size(); i++)
	{
		//LineMake(getMemDC(), _x, _y, _vShotUnit[i]->getX(), _vShotUnit[i]->getY());
		sprintf_s(str, "%0.2f %0.2f", _vShotUnit[i]->getX(), _vShotUnit[i]->getY());
		MY_UTIL::TextOutplus(getMemDC(), VIEWMANAGER->getPtx(_rc.left), ptY + _rc.bottom + 5 + (i+1)*25,
			str, 20, RGB(255, 20, 255), 1000, "Dynalight"); // BlackChancery
	}*/
}

void unit::plusRender(int x, int y)
{
}

void unit::plusRender()
{
}


void unit::move(int dx)
{
	if (TIMEMANAGER->getWorldTime() - _index.time > _index.dealy) {
		_index.time = TIMEMANAGER->getWorldTime();

		if (_index.indexNum >= _image->getMaxFrameX()) {
			_index.indexNum = 0;
		}
		else
		{
			_index.indexNum++;
		}
	}
	_x += dx*_speed*TIMEMANAGER->getElapsedTime();
}

void unit::attack()
{
	if (TIMEMANAGER->getWorldTime() - _index.time > _index.dealy) {
		_index.time = TIMEMANAGER->getWorldTime();

		_index.indexNum++;
	}
}

void unit::die()
{
	if (TIMEMANAGER->getWorldTime() - _index.time > _index.dealy) {
		_index.time = TIMEMANAGER->getWorldTime();

		_index.indexNum++;
	}
}

void unit::setState(int st, string name, int level)
{
	switch (st) {
	case ESTAND:
		_image = IMAGEMANAGER->findImage(name + "_stand");
		_state = ESTAND;
		break;
	case EMOVE:
		_image = IMAGEMANAGER->findImage(name + "_move");
		_state = EMOVE;
		break;
	case EATTACK:
		_image = IMAGEMANAGER->findImage(name + "_attack");
		_state = EATTACK;
		_attack.splash = _attack.running = false;
		_index.indexNum = 0;

		if (level == 1)
		{
			_image = IMAGEMANAGER->findImage(name + "_attack1");
			_state = EATTACK;
			_attack.splash = _attack.running = false;
			_index.indexNum = 0;
		}
		else if (level == 2)
		{
			_image = IMAGEMANAGER->findImage(name + "_attack2");
			_state = EATTACK;
			_attack.splash = _attack.running = false;
			_index.indexNum = 0;
		}
		else if (level == 3)
		{
			_image = IMAGEMANAGER->findImage(name + "_attack3");
			_state = EATTACK;
			_attack.splash = _attack.running = false;
			_index.indexNum = 0;
		}
		else if (level == 4)
		{
			_image = IMAGEMANAGER->findImage(name + "_attack4");
			_state = EATTACK;
			_attack.splash = _attack.running = false;
			_index.indexNum = 0;
		}
		else if (level == 5)
		{
			_image = IMAGEMANAGER->findImage(name + "_attack5");
			_state = EATTACK;
			_attack.splash = _attack.running = false;
			_index.indexNum = 0;
		}

		break;
	case EDIE:
		if (!life) break;
		_image = IMAGEMANAGER->findImage(name + "_die");
		_state = EDIE;
		life = false;
		_index.indexNum = 0;
		break;
	}
}

void unit::push_unit(unit* _unit)
{
	for (int i = 0; i < _vShotUnit.size(); i++)
	{
		if (_vShotUnit[i]->getID() == _unit->getID())
			return;
	}

	_vShotUnit.push_back(_unit);
}

void unit::pop_unit(int id)
{
	for (_viShotUnit = _vShotUnit.begin(); _viShotUnit != _vShotUnit.end(); ++_viShotUnit)
	{
		if ((*_viShotUnit)->getID() == id)
		{
			_vShotUnit.erase(_viShotUnit);
			return;
		}
	}
}

bool unit::isAttackTime()
{
	if (TIMEMANAGER->getWorldTime() - _attack.time > _attack.delay) {
		_attack.time = TIMEMANAGER->getWorldTime();
		return true;
	}
	return false;
}

bool unit::isDieEnd()
{
	if (_state == EDIE && _index.indexNum >= _image->getMaxFrameX() + 3)
		return true;
	else
		return false;
}

bool unit::isAttackEnd()
{
	if (_state != EATTACK)
	{
		return true;
	}
	else if (_state == EATTACK && _index.indexNum >= _image->getMaxFrameX())
	{
		_attack.time = TIMEMANAGER->getWorldTime();
		return true;
	}
	else
		return false;
}
