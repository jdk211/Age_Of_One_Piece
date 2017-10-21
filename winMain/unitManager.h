#pragma once
#include "gameNode.h"
#include <vector>

class unit;

class unitManager : public gameNode
{
private:
	typedef vector<unit*> vUnit;
	typedef vector<unit*>::iterator viUnit;

	unit* _playerTownLink;
	unit* _enemyTownLink;

	vUnit _vPlayerUnit, _vEnemyUnit;
	viUnit _viPlayerUnit, _viEnemyUnit;
public:
	unitManager();
	~unitManager();

	HRESULT init();
	void release();
	void update();
	void render();

	//���� ���� �Լ�
	void addTown(bool team, unit* town);

	void addPlayerUnit(string unitName, int line);
	void addPlayerUnit(string unitName, int line, int level);
	void addEnemyUnit(string unitName, int line);
	void addEnemyUnit(string unitName, int line, int level);

	void addPlayerZoro(int line);
	void addPlayerChopper(int line);
	void addPlayerNami(int line);
	void addPlayerBrook(int line);
	void addPlayerKuma(int line);
	void addPlayerRobin(int line);
	void addPlayerLuffy(int line, int level);
	void addPlayerSanji(int line);
	void addPlayerUsopp(int line);
	void addPlayerHancock(int line);
	void addPlayerFranky(int line);

	void addEnemyHody(int line);
	void addEnemyWapol(int line);
	void addEnemyCoby(int line);
	void addEnemyAkainu(int line);
	void addEnemyKizaru(int line);
	void addEnemyDoflamingo(int line);
	void addEnemyLucci(int line);
	void addEnemySmoker(int line);
	void addEnemyShiki(int line);
	void addEnemyEnel(int line);
	void addEnemyBlackbeard(int line, int level);


	//���� ���� �Լ�
	void deletePlayerUnit(int arrayNum);
	void deleteEnemyUnit(int arrayNum);

	//�ൿ ���� ����
	void stateUnit();

	//�޸� ��ũ
	void setPlayerTownMemoryLink(unit* town) { _playerTownLink = town; }
	void setEnemyTownMemoryLink(unit* town) { _enemyTownLink = town; }

	//Ÿ�� ��ü �Ѱ��ֱ�
	unit* getPlayerTown() { return _playerTownLink; }
	unit* getEnemyTown() { return _enemyTownLink; }

	float getDistanceX(float destX, float x) {
		if (destX - x > 0)
			return destX - x;
		else
			return x - destX;
	}
};

