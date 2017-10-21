#pragma once

#include "gameNode.h"

class unitManager;
class unit;



class newUnits : public gameNode
{
public:
	enum eUNITJOP
	{
		MELEE_UNIT,
		ARCHER_UNIT,
		SPECIAL_UNIT,
		END_INDEX
	};

	struct stWAITLINE
	{
		RECT rc;
		image* img;
		string unitName;
		eUNITJOP index;
		int line;
		int x, y;
	};
private:
	//레벨
	int _level;
	bool _levelChange;

	//유닛
	char* _unitName[END_INDEX];
	int _cost[END_INDEX];

	//유닛 매니저
	unitManager* _um;

	//타운
	unit* _enemyTown;

	int _count, _enemyCount;
	float _delay[END_INDEX];
	float _eTime;

	int _line;

	vector<stWAITLINE> _vWait;
	vector<stWAITLINE>::iterator _viWait;
public:
	newUnits();
	~newUnits();

	HRESULT init();
	void release();
	void update();
	void render();

	void unitSelect();
	void LevelChange();
	void produceUnit();

	void setUnitManagerMemoryLink(unitManager* um) { _um = um; }
	void setEnemyTownMemoryLink(unit* town) { _enemyTown = town; }
};

