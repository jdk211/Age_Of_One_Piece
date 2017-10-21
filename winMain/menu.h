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
	//����
	int _level;
	bool _levelChange;

	//����
	char* _unitName[END_INDEX];
	int _cost[END_INDEX];

	//��ư
	button* _unitBtn[END_INDEX];
	RECT _btnRc[END_INDEX];
	
	//�ִϸ��̼�
	animation* _lineAni;

	//���� �Ŵ���
	unitManager* _um;

	//Ÿ��
	unit* _playerTown;

	//��⿭
	stWAITLINE _wait[MAXWAIT];	//��⿭ ��Ʈ
	progressBar* _waitBar;		//��⿭ ���α׷��� ��
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

	//������ ������ �ö󰥼��� �ٲ��ִ� �Լ�
	void unitSelect();
	void buttonChange(int level);
	void lineChageNum();
	void produceUnit();

	void setUnitManagerMemoryLink(unitManager* um) { _um = um; }
	void setTownMemoryLink(unit* town) { _playerTown = town; }
};
