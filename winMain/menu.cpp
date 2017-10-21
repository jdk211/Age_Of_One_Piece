#include "stdafx.h"
#include "menu.h"
#include "unitManager.h"
#include "town.h"

menu::menu()
{
}


menu::~menu()
{
}

HRESULT menu::init()
{
	_level = 1;
	_levelChange = false;

	_unitName[SPECIAL_UNIT] = "luffy";

	_unitName[MELEE_UNIT] = "zoro";
	_unitName[ARCHER_UNIT] = "nami";
	_cost[MELEE_UNIT] = 60;
	_cost[ARCHER_UNIT] = 90;
	_cost[SPECIAL_UNIT] = 380;
	_delay[MELEE_UNIT] = 2.f;
	_delay[ARCHER_UNIT] = 3.5f;
	_delay[SPECIAL_UNIT] = 5.f;

	for (int i = 0; i < END_INDEX; i++)
	{
		_unitBtn[i] = new button;
		_unitBtn[i]->init(_unitName[i], (700 + (i * 90)), 75, pointMake(0, 0), pointMake(0, 2), pointMake(0, 1));
		_btnRc[i] = RectMake(_unitBtn[i]->getRc().left, _unitBtn[i]->getRc().top,
			_unitBtn[i]->getRc().right - _unitBtn[i]->getRc().left, _unitBtn[i]->getRc().bottom - _unitBtn[i]->getRc().top);
	}

	//라인 다이아 애니메이션
	_lineAni = new animation;
	_lineAni->init(200, 80, 50, 80);
	_lineAni->setDefPlayFrame(false, true);
	_lineAni->setFPS(4);
	_lineAni->start();

	//대기열 렉트
	for (int i = 0; i < MAXWAIT; i++)
	{

		_wait[i].x = 293 + (i * 64);
		_wait[i].y = 15;
		_wait[i].rc = RectMake(_wait[i].x, _wait[i].y, 32, 24);

	}

	//대기열 프로그레스바
	_waitBar = new progressBar;
	_waitBar->init(295, 52, 206, 6);
	_waitBar->setGauge(0, 0);

	_count = 0;

	_eTime = 0;

	return S_OK;
}

void menu::release()
{
	for (int i = 0; i < END_INDEX; i++)
	{
		_unitBtn[i]->release();
		SAFE_DELETE(_unitBtn[i]);
	}
}

void menu::update()
{
	for (int i = 0; i < END_INDEX; i++)
	{
		_unitBtn[i]->update();
	}

	lineChageNum();							//유닛 생성 라인 변경
	unitSelect();							//유닛 선택시
	buttonChange(_playerTown->getLevel());	//유닛 생성 버튼 이미지를 레벨에 맞게 변경
	
	if (_vWait.size() != 0)
	{
		_waitBar->setGauge(_eTime, _delay[_vWait[0].index]);
	}
	_waitBar->update();
	produceUnit();

	_lineAni->frameUpdate(TIMEMANAGER->getElapsedTime());
}

void menu::render()
{
	IMAGEMANAGER->findImage("board")->render(getMemDC(), 620, 10);
	//버튼 이미지
	for (int i = 0; i < END_INDEX; i++)
	{
		_unitBtn[i]->render();

		char strName[100];
		sprintf_s(strName, "%s ", _unitName[i]);
		MY_UTIL::TextOutplus(getMemDC(), _unitBtn[i]->getRc().left + 12, _unitBtn[i]->getRc().top, strName, 25, RGB(0, 0, 0), 500, "BlackChancery");
		
		char strBeri[100];
		sprintf_s(strBeri, "%d ", _cost[i]);
		MY_UTIL::TextOutplus(getMemDC(), _unitBtn[i]->getRc().left + 30, _unitBtn[i]->getRc().bottom - 35, strBeri, 20, RGB(0, 0, 0), 500, "BlackChancery");

	}

	//대기열 렉트
	for (int i = 0; i < MAXWAIT; i++)
	{
		SelectObject(getMemDC(), GetStockObject(NULL_BRUSH));
		Rectangle(getMemDC(), _wait[i].rc.left, _wait[i].rc.top, _wait[i].rc.right, _wait[i].rc.bottom);
	}

	for (int i = 0; i < _vWait.size(); i++)
	{
		if (_vWait[i].img != NULL)
		{
			_vWait[i].img->render(getMemDC(), _wait[i].rc.left, _wait[i].rc.top);
		}
	}

	//대기열 딜레이 렉트 보여주기용
	if (_vWait.size() != 0)
	{
		_waitBar->render();
	}
	Rectangle(getMemDC(), 294, 53, 500, 63);

	//바닥 선택 이미지
	if (_ptMouse.y > 296 && _ptMouse.y < 375)
	{
		IMAGEMANAGER->findImage("lineSelect")->render(getMemDC(), VIEWMANAGER->getPtx((32 * 7) - 6), 296);
	}
	else if (_ptMouse.y > 490 && _ptMouse.y < 568)
	{
		IMAGEMANAGER->findImage("lineSelect")->render(getMemDC(), VIEWMANAGER->getPtx((32 * 7) - 6), 488);
	}

	IMAGEMANAGER->findImage("selectObject")->aniRender(getMemDC(), VIEWMANAGER->getPtx(32 * 6), 32 * 8, _lineAni);
	IMAGEMANAGER->findImage("selectObject")->aniRender(getMemDC(), VIEWMANAGER->getPtx(32 * 6), 32 * 14, _lineAni);

	IMAGEMANAGER->findImage("coin_board")->render(getMemDC(), 70, 10);
	IMAGEMANAGER->findImage("beri")->render(getMemDC(), 90, 55);

	//레벨
	char str1[100];
	sprintf_s(str1, "%d", _playerTown->getLevel());
	MY_UTIL::TextOutplus(getMemDC(), 120, 15, "LEVEL", 20, RGB(0, 0, 0), 500, "BlackChancery"); // BlackChancery, Dynalight
	MY_UTIL::TextOutplus(getMemDC(), 195, 5, str1, 40, RGB(0, 0, 0), 500, "BlackChancery");

	//코인
	char str2[100];
	sprintf_s(str2, "%d ", _playerTown->getGold());
	MY_UTIL::TextOutplus(getMemDC(), 150, 50, str2, 30, RGB(0, 0, 0), 500, "BlackChancery");

	//경험치
	char str3[32];
	sprintf_s(str3, "%d", _playerTown->getExp());
	MY_UTIL::TextOutplus(getMemDC(), 80, 95, "EXP", 20, RGB(0, 0, 0), 500, "BlackChancery"); // BlackChancery, Dynalight
	MY_UTIL::TextOutplus(getMemDC(), 150, 87, str3, 30, RGB(0, 0, 0), 500, "BlackChancery");
}

void menu::unitSelect()
{
	if (PtInRect(&_btnRc[0], _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			if (_count < 5)
			{
				if (_playerTown->getGold() < _cost[MELEE_UNIT]) return;
				_playerTown->setGold(-_cost[MELEE_UNIT]);

				stWAITLINE wait;

				wait.unitName = _unitName[MELEE_UNIT];
				wait.img = IMAGEMANAGER->findImage(wait.unitName + "_wait");
				wait.index = MELEE_UNIT;
				wait.line = _lineNum;
				_vWait.push_back(wait);


				_count++;
				if (_count > 5)
				{
					_count = 4;
				}
			}
		}
	}
	if (PtInRect(&_btnRc[1], _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			if (_count < 5)
			{
				if (_playerTown->getGold() < _cost[ARCHER_UNIT]) return;
				_playerTown->setGold(-_cost[ARCHER_UNIT]);

				stWAITLINE wait;

				wait.unitName = _unitName[ARCHER_UNIT];
				wait.img = IMAGEMANAGER->findImage(wait.unitName + "_wait");
				wait.index = ARCHER_UNIT;
				wait.line = _lineNum;
				_vWait.push_back(wait);

				_count++;
				if (_count > 5)
				{
					_count = 4;
				}
			}
		}
	}
	if (PtInRect(&_btnRc[2], _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{

			if (_count < 5)
			{
				if (_playerTown->getGold() < _cost[SPECIAL_UNIT]) return;
				_playerTown->setGold(-_cost[SPECIAL_UNIT]);

				stWAITLINE wait;

				wait.unitName = _unitName[SPECIAL_UNIT];
				wait.img = IMAGEMANAGER->findImage(wait.unitName + "_wait");
				wait.index = SPECIAL_UNIT;
				wait.line = _lineNum;
				_vWait.push_back(wait);
				_count++;
				if (_count > 5)
				{
					_count = 4;
				}
			}
		}
	}
}

void menu::buttonChange(int level)
{
	switch (level)
	{
	case 1:
		_unitName[MELEE_UNIT] = "zoro";
		_unitName[ARCHER_UNIT] = "nami";
		break;
	case 2:
		if (level == _level && !_levelChange)
		{
			_unitName[MELEE_UNIT] = "sanji";
			_unitName[ARCHER_UNIT] = "usopp";
			_delay[MELEE_UNIT] = 2.5f;
			_delay[ARCHER_UNIT] = 4.2f;
			_delay[SPECIAL_UNIT] = 6.5f;
			_cost[MELEE_UNIT] = 85;
			_cost[ARCHER_UNIT] = 150;
			_cost[SPECIAL_UNIT] = 570;
			for (int i = 0; i < END_INDEX; i++)
			{
				_unitBtn[i]->init(_unitName[i], (700 + (i * 90)), 75, pointMake(0, 0), pointMake(0, 2), pointMake(0, 1));
			}

			_levelChange = true;
		}
		else if (level != _level)
		{
			_level = level;
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
			_unitName[MELEE_UNIT] = "chopper";
			_unitName[ARCHER_UNIT] = "robin";
			_delay[MELEE_UNIT] = 3.f;
			_delay[ARCHER_UNIT] = 4.9f;
			_delay[SPECIAL_UNIT] = 8.f;
			_cost[MELEE_UNIT] = 120;
			_cost[ARCHER_UNIT] = 225;
			_cost[SPECIAL_UNIT] = 855;
			for (int i = 0; i < END_INDEX; i++)
			{
				_unitBtn[i]->init(_unitName[i], (700 + (i * 90)), 75, pointMake(0, 0), pointMake(0, 2), pointMake(0, 1));
			}

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
			_unitName[MELEE_UNIT] = "franky";
			_unitName[ARCHER_UNIT] = "hancock";
			_delay[MELEE_UNIT] = 3.5f;
			_delay[ARCHER_UNIT] = 5.6f;
			_delay[SPECIAL_UNIT] = 9.5f;
			_cost[MELEE_UNIT] = 180;
			_cost[ARCHER_UNIT] = 340;
			_cost[SPECIAL_UNIT] = 1280;
			for (int i = 0; i < END_INDEX; i++)
			{
				_unitBtn[i]->init(_unitName[i], (700 + (i * 90)), 75, pointMake(0, 0), pointMake(0, 2), pointMake(0, 1));
			}

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
			_unitName[MELEE_UNIT] = "brook";
			_unitName[ARCHER_UNIT] = "kuma";
			_delay[MELEE_UNIT] = 4.f;
			_delay[ARCHER_UNIT] = 6.3f;
			_delay[SPECIAL_UNIT] = 11.f;
			_cost[MELEE_UNIT] = 270;
			_cost[ARCHER_UNIT] = 510;
			_cost[SPECIAL_UNIT] = 1920;
			for (int i = 0; i < END_INDEX; i++)
			{
				_unitBtn[i]->init(_unitName[i], (700 + (i * 90)), 75, pointMake(0, 0), pointMake(0, 2), pointMake(0, 1));
			}

			_levelChange = true;
		}
		break;
	}
}

void menu::lineChageNum()
{
	if (_ptMouse.y > 296 && _ptMouse.y < 375)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_lineNum = 1;
		}
	}
	else if (_ptMouse.y > 490 && _ptMouse.y < 568)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_lineNum = 2;
		}
	}
}

void menu::produceUnit()
{
	if (_vWait.size() == 0) return;

	if (_vWait[0].img != NULL)
	{
		_eTime += TIMEMANAGER->getElapsedTime();
		if (_eTime > _delay[_vWait[0].index])
		{
			if(_vWait[0].index == SPECIAL_UNIT)
			{
				_um->addPlayerUnit(_vWait[0].unitName, _vWait[0].line, _level);
			}
			else 
			{
				_um->addPlayerUnit(_vWait[0].unitName, _vWait[0].line);
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
