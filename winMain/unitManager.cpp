#include "stdafx.h"
#include "unitManager.h"
#include "unit.h"

#include "town.h"

#include "special_luffy.h"
#include "melee_zoro.h"
#include "melee_chopper.h"
#include "melee_brook.h"
#include "melee_sanji.h"
#include "melee_franky.h"
#include "archer_nami.h"
#include "archer_kuma.h"
#include "archer_robin.h"
#include "archer_usopp.h"
#include "archer_hancock.h"

#include "special_blackbeard.h"
#include "melee_hody.h"
#include "melee_coby.h"
#include "melee_akainu.h"
#include "melee_lucci.h"
#include "melee_shiki.h"
#include "archer_wapol.h"
#include "archer_doflamingo.h"
#include "archer_kizaru.h"
#include "archer_smoker.h"
#include "archer_enel.h"

unitManager::unitManager()
{
}

unitManager::~unitManager()
{	
}

HRESULT unitManager::init()
{

	return S_OK;
}

void unitManager::release()
{
}

void unitManager::update()
{
	//�÷��̾� ������Ʈ
	for (_viPlayerUnit = _vPlayerUnit.begin(); _viPlayerUnit != _vPlayerUnit.end(); ++_viPlayerUnit) {
		(*_viPlayerUnit)->update(1);
	}

	//���ʹ� ������Ʈ
	for (_viEnemyUnit = _vEnemyUnit.begin(); _viEnemyUnit != _vEnemyUnit.end(); ++_viEnemyUnit) {
		(*_viEnemyUnit)->update(-1);
	}

	stateUnit();
}

void unitManager::render()
{
	vUnit _vPt;
	// �÷��̾� �ֱ�
	for (int i = 0; i < _vPlayerUnit.size(); i++)
		_vPt.push_back(_vPlayerUnit[i]);
	// ���� �ֱ�
	for (int i = 0; i < _vEnemyUnit.size(); i++)
		_vPt.push_back(_vEnemyUnit[i]);

	// ����
	int size = _vPt.size();
	for (int i = 0; i < size -1; i++)
	{
		for (int j = 1; j < size -i; j++)
		{
			if (_vPt[j-1]->getY() > _vPt[j]->getY())	
				swap(_vPt[j-1],_vPt[j]);
		}
	}

	for (int i = 0; i < _vPt.size(); i++)
		_vPt[i]->render();
}

void unitManager::addTown(bool team, unit* town)
{
	if (team)
	{
		_vPlayerUnit.push_back(town);
	}
	else
	{
		_vEnemyUnit.push_back(town);
	}
}

void unitManager::addPlayerUnit(string unitName, int line)
{
	if (unitName == "zoro")
	{
		addPlayerZoro(line);
	}
	else if (unitName == "chopper")
	{
		addPlayerChopper(line);
	}
	else if (unitName == "nami")
	{
		addPlayerNami(line);
	}
	else if (unitName == "brook")
	{
		addPlayerBrook(line);
	}
	else if (unitName == "robin")
	{
		addPlayerRobin(line);
	}
	else if (unitName == "kuma")
	{
		addPlayerKuma(line);
	}
	else if (unitName == "hancock")
	{
		addPlayerHancock(line);
	}
	else if (unitName == "franky")
	{
		addPlayerFranky(line);
	}
	else if (unitName == "sanji")
	{
		addPlayerSanji(line);
	}
	else if (unitName == "usopp")
	{
		addPlayerUsopp(line);
	}
}

void unitManager::addPlayerUnit(string unitName, int line, int level)
{
	if (unitName == "luffy")
	{
		addPlayerLuffy(line, level);
	}
}

void unitManager::addEnemyUnit(string unitName, int line)
{
	if (unitName == "coby")
	{
		addEnemyCoby(line);
	}
	else if (unitName == "smoker")
	{
		addEnemySmoker(line);
	}// �Ʒ��� ����
	else if (unitName == "hody")
	{
		addEnemyHody(line);
	}
	else if (unitName == "wapol")
	{
		addEnemyWapol(line);
	}
	else if (unitName == "doflamingo")
	{
		addEnemyDoflamingo(line);
	}
	else if (unitName == "enel")
	{
		addEnemyEnel(line);
	}
	else if (unitName == "kizaru")
	{
		addEnemyKizaru(line);
	}
	else if (unitName == "akainu")
	{
		addEnemyAkainu(line);
	}
	else if (unitName == "lucci")
	{
		addEnemyLucci(line);
	}
	else if (unitName == "shiki")
	{
		addEnemyShiki(line);
	}
}

void unitManager::addEnemyUnit(string unitName, int line, int level)
{
	if (unitName == "blackbeard")
	{
		addEnemyBlackbeard(line, level);
	}
}
//---------------------------------------------------------------------------------------------//
void unitManager::addPlayerLuffy(int line, int level)
{
	unit* _unit;
	_unit = new special_luffy;
	_unit->init("luffy_stand", line, level, (_unitID++) % 1000);
	_vPlayerUnit.push_back(_unit);
}

void unitManager::addPlayerSanji(int line)
{
	unit* _unit;
	_unit = new melee_sanji;
	_unit->init("sanji_stand", line, (_unitID++) % 1000);
	_vPlayerUnit.push_back(_unit);
}

void unitManager::addPlayerUsopp(int line)
{
	unit* _unit;
	_unit = new archer_usopp;
	_unit->init("usopp_stand", line, (_unitID++) % 1000);
	_vPlayerUnit.push_back(_unit);
}

void unitManager::addPlayerHancock(int line)
{
	unit* _unit;
	_unit = new archer_hancock;
	_unit->init("hancock_stand", line, (_unitID++) % 1000);
	_vPlayerUnit.push_back(_unit);
}

void unitManager::addPlayerFranky(int line)
{
	unit* _unit;
	_unit = new melee_franky;
	_unit->init("franky_stand", line, (_unitID++) % 1000);
	_vPlayerUnit.push_back(_unit);
}

void unitManager::addEnemyHody(int line)
{
	unit* _unit;
	_unit = new melee_hody;
	_unit->init("hody_stand", line, (_unitID++) % 1000);
	_vEnemyUnit.push_back(_unit);
}

void unitManager::addEnemyWapol(int line)
{
	unit* _unit;
	_unit = new archer_wapol;
	_unit->init("wapol_stand", line, (_unitID++) % 1000);
	_vEnemyUnit.push_back(_unit);
}

void unitManager::addPlayerZoro(int line)
{
	unit* _unit;
	_unit = new melee_zoro;
	_unit->init("zoro_stand", line, (_unitID++) % 1000);
	_vPlayerUnit.push_back(_unit);
}

void unitManager::addPlayerChopper(int line)
{
	unit* _unit;
	_unit = new melee_chopper;
	_unit->init("chopper_stand", line, (_unitID++) % 1000);
	_vPlayerUnit.push_back(_unit);
}

void unitManager::addPlayerNami(int line)
{
	unit* _unit;
	_unit = new archer_nami;
	_unit->init("nami_stand", line, (_unitID++) % 1000);
	_vPlayerUnit.push_back(_unit);
}

void unitManager::addPlayerBrook(int line)
{
	unit* _unit;
	_unit = new melee_brook;
	_unit->init("brook_stand", line, (_unitID++) % 1000);
	_vPlayerUnit.push_back(_unit);
}

void unitManager::addPlayerKuma(int line)
{
	unit* _unit;
	_unit = new archer_kuma;
	_unit->init("kuma_stand", line, (_unitID++) % 1000);
	_vPlayerUnit.push_back(_unit);
}
void unitManager::addPlayerRobin(int line)
{
	unit* _unit;
	_unit = new archer_robin;
	_unit->init("robin_stand", line, (_unitID++) % 1000);
	_vPlayerUnit.push_back(_unit);
}
//-------------------------------------------------------------------------------------------------//
void unitManager::addEnemyCoby(int line)
{
	unit* _unit;
	_unit = new melee_coby;
	_unit->init("coby_stand", line, (_unitID++) % 1000);
	_vEnemyUnit.push_back(_unit);
}

void unitManager::addEnemyAkainu(int line)
{
	unit* _unit;
	_unit = new melee_akainu;
	_unit->init("akainu_stand", line, (_unitID++) % 1000);
	_vEnemyUnit.push_back(_unit);
}

void unitManager::addEnemyKizaru(int line)
{
	unit* _unit;
	_unit = new archer_kizaru;
	_unit->init("kizaru_stand", line, (_unitID++) % 1000);
	_vEnemyUnit.push_back(_unit);
}

void unitManager::addEnemyDoflamingo(int line)
{
	unit* _unit;
	_unit = new archer_doflamingo;
	_unit->init("doflamingo_stand", line, (_unitID++) % 1000);
	_vEnemyUnit.push_back(_unit);
}

void unitManager::addEnemyLucci(int line)
{
	unit* _unit;
	_unit = new melee_lucci;
	_unit->init("lucci_stand", line, (_unitID++) % 1000);
	_vEnemyUnit.push_back(_unit);
}

void unitManager::addEnemySmoker(int line)
{
	unit* _unit;
	_unit = new archer_smoker;
	_unit->init("smoker_stand", line, (_unitID++) % 1000);
	_vEnemyUnit.push_back(_unit);
}

void unitManager::addEnemyShiki(int line)
{
	unit* _unit;
	_unit = new melee_shiki;
	_unit->init("shiki_stand", line, (_unitID++) % 1000);
	_vEnemyUnit.push_back(_unit);
}

void unitManager::addEnemyEnel(int line)
{
	unit* _unit;
	_unit = new archer_enel;
	_unit->init("enel_stand", line, (_unitID++) % 1000);
	_vEnemyUnit.push_back(_unit);
}

void unitManager::addEnemyBlackbeard(int line, int level)
{
	unit* _unit;
	_unit = new special_blackbeard;
	_unit->init("blackbeard_stand", line, level, (_unitID++) % 1000);
	_vEnemyUnit.push_back(_unit);
}

//--------------------------------------------------------------------------------------------------------------------//

void unitManager::deletePlayerUnit(int arrayNum)
{
	_enemyTownLink->setGold(RND->getFromFloatTo(1.5f, 2.f) * _vPlayerUnit[arrayNum]->getGold());
	_enemyTownLink->setExp(_vPlayerUnit[arrayNum]->getExp());
	//�����Ҵ� �� �̵��� ������
	SAFE_DELETE(_vPlayerUnit[arrayNum]);
	//���� �̴ٱ� �ִ� �浵 ������
	_vPlayerUnit.erase(_vPlayerUnit.begin() + arrayNum);
	//erase �ȿ��� ���� �ּҰ��� ����. ����� ������ ���� error...
}

void unitManager::deleteEnemyUnit(int arrayNum)
{
	//���� ������ �÷��̾����� ���� ����ġ�� �÷���
	_playerTownLink->setGold(RND->getFromFloatTo(1.5f, 2.f) * _vEnemyUnit[arrayNum]->getGold());
	_playerTownLink->setExp(_vEnemyUnit[arrayNum]->getExp());
	//�����Ҵ� �� �̵��� ������
	SAFE_DELETE(_vEnemyUnit[arrayNum]);
	//���� �̴ٱ� �ִ� �浵 ������
	_vEnemyUnit.erase(_vEnemyUnit.begin() + arrayNum);
	//erase �ȿ��� ���� �ּҰ��� ����. ����� ������ ���� error...
}

void unitManager::stateUnit()
{
	int clear = 0;
	for (int i = 0; i < _vPlayerUnit.size(); i++)
	{
		// move�� �Ǵ� ���� : �����Ÿ��ȿ� ���� ����.
		// attack�� �Ǵ� ���� : ���� ��Ÿ� �ȿ� ���� �ִ�. || ���� ��Ÿ���� ����.
		// non(stand)�� �Ǵ� ���� : ���� ��Ÿ� �ȿ� ���� �ִ�. && ���� ��Ÿ���� �ȳ���.


		if (_vPlayerUnit[i]->isDieEnd()) {
			deletePlayerUnit(i);
			i -= 1;
			continue;
		}

		if (_vPlayerUnit[i]->getCurrentHP() < 0)
		{
			_vPlayerUnit[i]->setState(EDIE);
			continue;
		}

		if (!_vPlayerUnit[i]->isAttackEnd()) continue;

		for (int j = 0; j < _vEnemyUnit.size(); j++)
		{
			// �ٸ� �����϶� �Ѱܶ�.
			if (_vEnemyUnit[j]->getLine() != 0) { // -> �����̴�.
				if (_vPlayerUnit[i]->getLine() != _vEnemyUnit[j]->getLine()) continue;
			}
			if (_vEnemyUnit[j]->getCurrentHP() < 0) // EDIE�����϶��� ���ݾȴ���.
			{
				_vPlayerUnit[i]->pop_unit(_vEnemyUnit[j]->getID());
				continue;
			}

			if (getDistanceX(_vPlayerUnit[i]->getX(), _vEnemyUnit[j]->getX()) < _vPlayerUnit[i]->getAttackRange())
			{// ���� ���� ��Ÿ� ���� �ȿ� �ִ�.
				_vPlayerUnit[i]->push_unit(_vEnemyUnit[j]);
			}
			else
			{ // ��Ÿ� ���϶�
				_vPlayerUnit[i]->pop_unit(_vEnemyUnit[j]->getID());
			}
		}

		if (_vPlayerUnit[i]->getvShotUnit_size() != 0)
		{ // ���� �������� ���� ����.
			if (_vPlayerUnit[i]->isAttackTime())
			{ // ���� ���� ���Ҵ�.
				_vPlayerUnit[i]->setState(EATTACK);
			}
			else
			{ // ���� ���� �� ���Ҵ�.
				bool moveblock = false;
				for (int j = 0; j < _vEnemyUnit.size(); j++)
				{
					// �ٸ� �����϶� �Ѱܶ�.
					if (_vEnemyUnit[j]->getLine() != 0) { // -> �����̴�.
						if (_vPlayerUnit[i]->getLine() != _vEnemyUnit[j]->getLine()) continue;
					}

					if (getDistanceX(_vPlayerUnit[i]->getX(), _vEnemyUnit[j]->getX())< _vPlayerUnit[i]->getSight())
					{ // �̵����� �ȿ� ����.
						moveblock = true;
					}
				}

				if (moveblock)
					_vPlayerUnit[i]->setState(ESTAND);
				else
					_vPlayerUnit[i]->setState(EMOVE);
			}
		}
		else
		{ // ���� ���� ���� ���� ����.
			_vPlayerUnit[i]->setState(EMOVE);
			/*
			// ���� ���� ���Ұ�, ���ݻ�Ÿ� ���� ������ ������ ����
			if( _vPlayerUnit[i]->isAttackTime() && 32 * ( 50 - 8 )  < _vPlayerUnit[i]->getX() + _vPlayerUnit[i]->getAttackRange() )
			_vPlayerUnit[i]->setState( EATTACK );
			// ���� ���� �� ���Ұ�, ���� ��Ÿ� ���� ������ ������ �̵�
			else if( _vPlayerUnit[i]->getX() <= 32 * ( 50 - 8 ) )
			_vPlayerUnit[i]->setState( EMOVE );
			// ���� ���� �� ���Ұ�, ���� ��Ÿ� ���� ������ ������ ����
			else
			_vPlayerUnit[i]->setState( ESTAND );
			*/
		}
	}

	for (int i = 0; i < _vEnemyUnit.size(); i++)
	{
		// move�� �Ǵ� ���� : �����Ÿ��ȿ� ���� ����.
		// attack�� �Ǵ� ���� : ���� ��Ÿ� �ȿ� ���� �ִ�. || ���� ��Ÿ���� ����.
		// non(stand)�� �Ǵ� ���� : ���� ��Ÿ� �ȿ� ���� �ִ�. && ���� ��Ÿ���� �ȳ���.


		if (_vEnemyUnit[i]->isDieEnd())
		{
			deleteEnemyUnit(i);
			i -= 1;
			continue;
		}

		if (_vEnemyUnit[i]->getCurrentHP() < 0)
		{
			_vEnemyUnit[i]->setState(EDIE);
			continue;
		}

		if (!_vEnemyUnit[i]->isAttackEnd()) continue;

		for (int j = 0; j < _vPlayerUnit.size(); j++)
		{
			if (_vPlayerUnit[j]->getLine() != 0) { // -> �����̴�.
				if (_vEnemyUnit[i]->getLine() != _vPlayerUnit[j]->getLine()) continue;
			}
			if (_vPlayerUnit[j]->getCurrentHP() < 0)
			{
				_vEnemyUnit[i]->pop_unit(_vPlayerUnit[j]->getID());
				continue;
			}
			if (getDistanceX(_vEnemyUnit[i]->getX(), _vPlayerUnit[j]->getX()) < _vEnemyUnit[i]->getAttackRange())
			{// ���� ���� ��Ÿ� ���� �ȿ� �ִ�.
				_vEnemyUnit[i]->push_unit(_vPlayerUnit[j]);

			}
			else
			{ // ��Ÿ� ���϶�
				_vEnemyUnit[i]->pop_unit(_vPlayerUnit[j]->getID());
			}
		}

		if (_vEnemyUnit[i]->getvShotUnit_size() != 0)
		{ // ���� �������� ���� ����.
			if (_vEnemyUnit[i]->isAttackTime())
			{ // ���� ���� ���Ҵ�.
				_vEnemyUnit[i]->setState(EATTACK);
			}
			else
			{ // ���� ���� �� ���Ҵ�.
				bool moveblock = false;
				for (int j = 0; j < _vPlayerUnit.size(); j++)
				{
					if (_vPlayerUnit[j]->getLine() != 0) { // -> �����̴�.
						if (_vEnemyUnit[i]->getLine() != _vPlayerUnit[j]->getLine()) continue;
					}

					if (getDistanceX(_vEnemyUnit[i]->getX(), _vPlayerUnit[j]->getX())< _vEnemyUnit[i]->getSight())
					{ // �̵����� �ȿ� ����.
						moveblock = true;
					}
				}

				if (moveblock)
					_vEnemyUnit[i]->setState(ESTAND);
				else
					_vEnemyUnit[i]->setState(EMOVE);
			}
		}
		else
		{ // ���� ���� ���� ���� ����.
			_vEnemyUnit[i]->setState(EMOVE);
			/*
			// ���� ���� ���Ұ�, ���ݻ�Ÿ� ���� ������ ������ ����
			if( _vEnemyUnit[i]->isAttackTime() &&  32 * 8  > _vEnemyUnit[i]->getX() - _vEnemyUnit[i]->getAttackRange() )
			_vEnemyUnit[i]->setState( EATTACK );
			// ���� ���� �� ���Ұ�, ���� ��Ÿ� ���� ������ ������ �̵�
			else if(_vEnemyUnit[i]->getX() >= 32 * 8  )
			_vEnemyUnit[i]->setState(EMOVE);
			// ���� ���� �� ���Ұ�, ���� ��Ÿ� ���� ������ ������ ����
			else
			_vEnemyUnit[i]->setState( ESTAND );
			*/
		}
	}

}

