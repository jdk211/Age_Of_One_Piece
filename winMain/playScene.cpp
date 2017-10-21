#include "stdafx.h"
#include "playScene.h"
#include "unit.h"
#include "town.h"
#include "unitManager.h"


playScene::playScene()
{
}


playScene::~playScene()
{
}

HRESULT playScene::init()
{
	//유닛 매니저
	_um = new unitManager;
	_um->init();

	//타운 클래스 
	_pTown = new town;
	_pTown->init(0);
	_um->addTown(true, _pTown);
	_um->setPlayerTownMemoryLink(_pTown);
	_eTown = new town;
	_eTown->init(1);
	_um->addTown(false, _eTown);
	_um->setEnemyTownMemoryLink(_eTown);

	//메뉴 클래스
	_menu = new menu;
	_menu->init();
	_menu->setUnitManagerMemoryLink(_um);
	_menu->setTownMemoryLink(_pTown);
	
	// 유닛추가
	_newUnits = new newUnits;
	_newUnits->init();
	_newUnits->setUnitManagerMemoryLink(_um);
	_newUnits->setEnemyTownMemoryLink(_eTown);

	//카메라 매니저
	VIEWMANAGER->init(750, 720 / 2, _mapSizeX, _mapSizeY);

	//바다 움직이는 애니메이션
	_bgAni = new animation;
	_bgAni->init(6400, 768, 1600, 768);
	_bgAni->setDefPlayFrame(false, true);
	_bgAni->setFPS(4);
	_bgAni->start();

	NewTime = TIMEMANAGER->getWorldTime();
	NetDelay = 14.0;
	NewRND = RND->getFromFloatTo(-NetDelay / 2, NetDelay / 2);

	_gameEnd = false;

	return S_OK;
}

void playScene::release()
{
	_um->release();
	SAFE_DELETE(_um);
	_menu->release();
	SAFE_DELETE(_menu);
	//_pTown->release();
	//SAFE_DELETE(_pTown);
}

void playScene::update()
{
	if (_gameEnd) return;
	
	float vx, vy;
	vx = VIEWMANAGER->getPtx(VIEWMANAGER->getPlaceX());
	vy = VIEWMANAGER->getPty(VIEWMANAGER->getPlaceY());

	if (_ptMouse.x < 50) { // 왼쪽
		if (VIEWMANAGER->getendX() > CENTERX) {
			VIEWMANAGER->MoveTo(VIEWMANAGER->getendX() - 7, vy);
		}
	}
	else if (_ptMouse.x > WINSIZEX - 50) { // 오른쪽
		if (VIEWMANAGER->getendX() < _mapSizeX - CENTERX) {
			VIEWMANAGER->MoveTo(VIEWMANAGER->getendX() + 7, vy);
		}
	}

	_um->update();
	_newUnits->update();
	_menu->update();
	EFFECTMANAGER->update();
	VIEWMANAGER->updateX();

	_bgAni->frameUpdate(TIMEMANAGER->getElapsedTime());

	if (_pTown->getCurrentHP() < 0 || _eTown->getCurrentHP() < 0) _gameEnd = true;
}

void playScene::render()
{
	//배경
	IMAGEMANAGER->render("map", getMemDC(), -VIEWMANAGER->getPlaceX() + CENTERX, 0);
	IMAGEMANAGER->findImage("seaFrame")->aniRender(getMemDC(), -VIEWMANAGER->getPlaceX() + CENTERX, 0, _bgAni);

	_menu->render();
	_newUnits->render();
	_um->render();
	EFFECTMANAGER->render();

	//char str[100];
	//sprintf_s(str, "%d %d", _ptMouse.x, _ptMouse.y);
	//MY_UTIL::TextOutplus(getMemDC(), 70, 150, str, 20, RGB(0, 0, 0), 500, "Dynalight"); // BlackChancery, Dynalight
	
	if(_gameEnd) finish();
}

void playScene::finish()
{
	if (_pTown->getCurrentHP() < 0)
	{
		MY_UTIL::TextOutplus(getMemDC(), 40, WINSIZEY / 4, "LOSE", 350, RGB(0, 0, 0), 1000, "BlackChancery"); // BlackChancery, Dynalight
	}
	else if (_eTown->getCurrentHP() < 0)
	{
		MY_UTIL::TextOutplus(getMemDC(), 20, WINSIZEY / 4, "WIN", 400, RGB(0, 0, 0), 1000, "BlackChancery"); // BlackChancery, Dynalight
	}
}
