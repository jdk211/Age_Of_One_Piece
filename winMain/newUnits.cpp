#include "stdafx.h"
#include "newUnits.h"
#include "town.h"

newUnits::newUnits()
{
}


newUnits::~newUnits()
{
}

HRESULT newUnits::init()
{
	_level = 0;
	_levelChange = false;

	_unitName[SPECIAL_UNIT] = "blackbeard";

	_unitName[MELEE_UNIT] = "coby";
	_unitName[ARCHER_UNIT] = "smoker";

	_count = 0;

	_delay[MELEE_UNIT] = 2.f;
	_delay[ARCHER_UNIT] = 3.5f;
	_delay[SPECIAL_UNIT] = 5.f;
	_cost[MELEE_UNIT] = 60;
	_cost[ARCHER_UNIT] = 90;
	_cost[SPECIAL_UNIT] = 380;

	_eTime = 0;

	_line = 1;

	return S_OK;
}

void newUnits::release()
{
}

void newUnits::update()
{
	unitSelect();
	LevelChange();
	produceUnit();
}

void newUnits::render()
{
	
}
void newUnits::unitSelect()
{
	int indexUnit = RND->getFromIntTo(0,2);
	_line = RND->getInt(2) + 1;
	switch (indexUnit)
	{
	case 0:
		if (_count < 5)
		{
			if (_enemyTown->getGold() < _cost[MELEE_UNIT]) return;
			_enemyTown->setGold(-_cost[MELEE_UNIT]);

			stWAITLINE wait;

			wait.unitName = _unitName[MELEE_UNIT];
			wait.img = IMAGEMANAGER->findImage(wait.unitName + "_stand");
			wait.index = MELEE_UNIT;
			wait.line = _line;
			_vWait.push_back(wait);

			_count++;
			if (_count > 5)
			{
				_count = 4;
			}
		}
		break;
	case 1:
		if (_count < 5)
		{
			if (_enemyTown->getGold() < _cost[ARCHER_UNIT]) return;
			_enemyTown->setGold(-_cost[ARCHER_UNIT]);

			stWAITLINE wait;

			wait.unitName = _unitName[ARCHER_UNIT];
			wait.img = IMAGEMANAGER->findImage(wait.unitName + "_stand");
			wait.index = ARCHER_UNIT;
			wait.line = _line;
			_vWait.push_back(wait);

			_count++;
			if (_count > 5)
			{
				_count = 4;
			}
		}
		break;
	case 2:
		if (_count < 5)
		{
			if (_enemyTown->getGold() < _cost[SPECIAL_UNIT]) return;
			_enemyTown->setGold(-_cost[SPECIAL_UNIT]);

			stWAITLINE wait;

			wait.unitName = _unitName[SPECIAL_UNIT];
			wait.img = IMAGEMANAGER->findImage(wait.unitName + "_stand");
			wait.index = SPECIAL_UNIT;
			wait.line = _line;
			_vWait.push_back(wait);

			_count++;
			if (_count > 5)
			{
				_count = 4;
			}
		}
		break;
	}
}

void newUnits::LevelChange()
{
	int level = _enemyTown->getLevel();
	switch (_enemyTown->getLevel())
	{
	case 1:
		if (_level < level)
		{
			_levelChange = false;
			_level = level;
		}
		else if (level == _level && !_levelChange)
		{
			_unitName[MELEE_UNIT] = "coby";
			_unitName[ARCHER_UNIT] = "smoker";

			_levelChange = true;
		}
		break;
	case 2: // 1·¦ºÎÅÍ ¼öÁ¤
		if (_level < level)
		{
			_levelChange = false;
			_level = level;
		}
		else if (level == _level && !_levelChange)
		{
			_unitName[MELEE_UNIT] = "hody";
			_unitName[ARCHER_UNIT] = "wapol";
			_delay[MELEE_UNIT] = 2.5f;
			_delay[ARCHER_UNIT] = 4.2f;
			_delay[SPECIAL_UNIT] = 6.5f;
			_cost[MELEE_UNIT] = 85;
			_cost[ARCHER_UNIT] = 150;
			_cost[SPECIAL_UNIT] = 570;

			_levelChange = true;
		}
		break;
	case 3:
		if (_level < level)
		{
			_levelChange = false;
			_level = level;
		}
		else if (level == _level && !_levelChange)
		{
			_unitName[MELEE_UNIT] = "lucci";
			_unitName[ARCHER_UNIT] = "doflamingo";
			_delay[MELEE_UNIT] = 3.f;
			_delay[ARCHER_UNIT] = 4.9f;
			_delay[SPECIAL_UNIT] = 8.f;
			_cost[MELEE_UNIT] = 120;
			_cost[ARCHER_UNIT] = 225;
			_cost[SPECIAL_UNIT] = 855;

			_levelChange = true;
		}
		break;
	case 4:
		if (_level < level)
		{
			_levelChange = false;
			_level = level;
		}
		else if (level == _level && !_levelChange)
		{
			_unitName[MELEE_UNIT] = "shiki";
			_unitName[ARCHER_UNIT] = "enel";
			_delay[MELEE_UNIT] = 3.5f;
			_delay[ARCHER_UNIT] = 5.6f;
			_delay[SPECIAL_UNIT] = 9.5f;
			_cost[MELEE_UNIT] = 180;
			_cost[ARCHER_UNIT] = 340;
			_cost[SPECIAL_UNIT] = 1280;

			_levelChange = true;
		}
		break;
	case 5:
		if (_level < level)
		{
			_levelChange = false;
			_level = level;
		}
		else if (level == _level && !_levelChange)
		{
			_unitName[MELEE_UNIT] = "akainu";
			_unitName[ARCHER_UNIT] = "kizaru";
			_delay[MELEE_UNIT] = 4.f;
			_delay[ARCHER_UNIT] = 6.3f;
			_delay[SPECIAL_UNIT] = 11.f;
			_cost[MELEE_UNIT] = 270;
			_cost[ARCHER_UNIT] = 510;
			_cost[SPECIAL_UNIT] = 1920;

			_levelChange = true;
		}
		break;
	}
}

void newUnits::produceUnit()
{
	if (_vWait.size() == 0) return;

	if (_vWait[0].img != NULL)
	{
		_eTime += TIMEMANAGER->getElapsedTime();
		if (_eTime > _delay[_vWait[0].index])
		{
			if (_vWait[0].index == SPECIAL_UNIT)
			{
				_um->addEnemyUnit(_vWait[0].unitName, _vWait[0].line, _level);
			}
			else
			{
				_um->addEnemyUnit(_vWait[0].unitName, _vWait[0].line);
			}

			_count--;
			_eTime = 0;
			_vWait.erase(_vWait.begin());
		}
	}
	else
	{
		return;
	}

}
