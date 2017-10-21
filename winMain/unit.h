#pragma once
#include "gameNode.h"
#include "unitManager.h"

#include <map>

class unit : public gameNode
{
public:
	struct index {
		float time;
		float dealy;
		int indexNum, indexMax;
	};
	struct attack {
		float time;		// 
		float delay;	// 
		bool splash;	// ������ ���� ����?
		bool running;	// ������?
		float range;	// ���� ����
	};
protected:
	int _id;

	image *_image;
	index _index;
	attack _attack;

	float _currentHP, _maxHP;	// ü��
	float _damage;	//������

	float _x, _y;	// ��ǥ
	RECT _rc;
	float _speed; // �̵� �ӵ�
	float _sight; // �̵� ��Ÿ�

	int _addDelay; // ���� ������
	int _line; /* 1 or 2*/
	int _state;

	int _cost;
	int _gold;
	int _exp;

	bool life;

	vector<unit*> _vShotUnit;
	vector<unit*>::iterator _viShotUnit;
public:

public:
	unit();
	~unit();

	virtual HRESULT init(int team);
	virtual HRESULT init(string imageName, int line, int id);
	virtual HRESULT init(string imageName, int line, int level, int id);
	virtual void release();
	virtual void update(int dx);
	virtual void plusUpdate();
	virtual void render();
	virtual void plusRender(int x, int y);
	virtual void plusRender();

	virtual void move(int dx);
	virtual void attack();
	virtual void die();

	void setState(int st, string name, int level = 0);
	virtual void setState(int st) {}
	void push_unit(unit* _unit);
	void pop_unit(int id);

	float getX() { return _x; }
	float getY() { return _y; }

	float getSight() { return _sight; }
	float getAttackRange() { return _attack.range; }

	float getCurrentHP() { return _currentHP; }
	float getMaxHP() { return _maxHP; }

	int getLine() { return _line; }

	int getID() { return _id; }

	void setCost(int cost) { _cost += cost; }
	void setGold(int gold) { _gold += gold; }
	void setExp(int exp) { _exp += exp; }

	int getCost() { return _cost; }
	int getGold() { return _gold; }
	int getExp() { return _exp; }

	virtual int getLevel() { return 0; }

	int getvShotUnit_size() { return _vShotUnit.size(); }

	bool isAttackTime();
	bool isAttackEnd();
	bool isDieEnd();

	float getDistanceX(float destX, float x) {
		if (destX - x > 0)
			return destX - x;
		else
			return x - destX;
	}

	void hitDamage(float a) { _currentHP -= a; }

};