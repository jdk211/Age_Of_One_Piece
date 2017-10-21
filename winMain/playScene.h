#pragma once
#include "gameNode.h"
#include "animation.h"
#include "menu.h"
#include "newUnits.h"

class unitManager;
class unit;

class playScene : public gameNode
{
private:
	float NetDelay, NewTime, NewRND;

	unitManager *_um;

	unit* _pTown;
	unit* _eTown;

	menu* _menu;

	animation* _bgAni;

	newUnits *_newUnits;

	bool _newUnit;

	bool _gameEnd;
public:
	playScene();
	~playScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void finish();
};

