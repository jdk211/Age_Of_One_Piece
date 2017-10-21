#pragma once
#include "gameNode.h"
#include "button.h"
#include "progressBar.h"
#include <vector>

class unitManager;
class unit;
//melee, archer, special
#define MAXWAIT 5

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

class menu : public gameNode
{
private:
	//레벨
	int _level;
	bool _levelChange;

	//유닛
	char* _unitName[END_INDEX];
	int _cost[END_INDEX];

	//버튼
	button* _unitBtn[END_INDEX];
	RECT _btnRc[END_INDEX];
	
	//애니메이션
	animation* _lineAni;

	//유닛 매니저
	unitManager* _um;

	//타운
	unit* _playerTown;

	//대기열
	stWAITLINE _wait[MAXWAIT];	//대기열 렉트
	progressBar* _waitBar;		//대기열 프로그레스 바
	int _count, _enemyCount;
	float _delay[END_INDEX];
	float _eTime;

	vector<stWAITLINE> _vWait;
	vector<stWAITLINE>::iterator _viWait;

public:
	menu();
	~menu();

	HRESULT init();
	void release();
	void update();
	void render();

	//본진의 레벨이 올라갈수록 바꿔주는 함수
	void unitSelect();
	void buttonChange(int level);
	void lineChageNum();
	void produceUnit();

	void setUnitManagerMemoryLink(unitManager* um) { _um = um; }
	void setTownMemoryLink(unit* town) { _playerTown = town; }
};
