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
	//플레이어 업데이트
	for (_viPlayerUnit = _vPlayerUnit.begin(); _viPlayerUnit != _vPlayerUnit.end(); ++_viPlayerUnit) {
		(*_viPlayerUnit)->update(1);
	}

	//에너미 업데이트
	for (_viEnemyUnit = _vEnemyUnit.begin(); _viEnemyUnit != _vEnemyUnit.end(); ++_viEnemyUnit) {
		(*_viEnemyUnit)->update(-1);
	}

	stateUnit();
}

void unitManager::render()
{
	vUnit _vPt;
	// 플레이어 넣기
	for (int i = 0; i < _vPlayerUnit.size(); i++)
		_vPt.push_back(_vPlayerUnit[i]);
	// 몬스터 넣기
	for (int i = 0; i < _vEnemyUnit.size(); i++)
		_vPt.push_back(_vEnemyUnit[i]);

	// 정렬
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
	}// 아래는 수정
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
	//동적할당 된 쫄따구 날리고
	SAFE_DELETE(_vPlayerUnit[arrayNum]);
	//날라간 쫄다구 있는 방도 날리자
	_vPlayerUnit.erase(_vPlayerUnit.begin() + arrayNum);
	//erase 안에는 실제 주소값이 들어간다. 상수나 변수가 들어가면 error...
}

void unitManager::deleteEnemyUnit(int arrayNum)
{
	//적이 죽을때 플레이어한테 돈과 경험치를 올려줌
	_playerTownLink->setGold(RND->getFromFloatTo(1.5f, 2.f) * _vEnemyUnit[arrayNum]->getGold());
	_playerTownLink->setExp(_vEnemyUnit[arrayNum]->getExp());
	//동적할당 된 쫄따구 날리고
	SAFE_DELETE(_vEnemyUnit[arrayNum]);
	//날라간 쫄다구 있는 방도 날리자
	_vEnemyUnit.erase(_vEnemyUnit.begin() + arrayNum);
	//erase 안에는 실제 주소값이 들어간다. 상수나 변수가 들어가면 error...
}

void unitManager::stateUnit()
{
	int clear = 0;
	for (int i = 0; i < _vPlayerUnit.size(); i++)
	{
		// move가 되는 조건 : 무브사거리안에 적이 없다.
		// attack가 되는 조건 : 공격 사거리 안에 적이 있다. || 공격 쿨타임이 끝남.
		// non(stand)가 되는 조건 : 공격 사거리 안에 적이 있다. && 공격 쿨타임이 안끝남.


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
			// 다른 라인일때 넘겨라.
			if (_vEnemyUnit[j]->getLine() != 0) { // -> 유닛이다.
				if (_vPlayerUnit[i]->getLine() != _vEnemyUnit[j]->getLine()) continue;
			}
			if (_vEnemyUnit[j]->getCurrentHP() < 0) // EDIE상태일때는 공격안당함.
			{
				_vPlayerUnit[i]->pop_unit(_vEnemyUnit[j]->getID());
				continue;
			}

			if (getDistanceX(_vPlayerUnit[i]->getX(), _vEnemyUnit[j]->getX()) < _vPlayerUnit[i]->getAttackRange())
			{// 적이 공격 사거리 범위 안에 있다.
				_vPlayerUnit[i]->push_unit(_vEnemyUnit[j]);
			}
			else
			{ // 사거리 밖일때
				_vPlayerUnit[i]->pop_unit(_vEnemyUnit[j]->getID());
			}
		}

		if (_vPlayerUnit[i]->getvShotUnit_size() != 0)
		{ // 공격 범위내에 적이 존재.
			if (_vPlayerUnit[i]->isAttackTime())
			{ // 공격 쿨이 돌았다.
				_vPlayerUnit[i]->setState(EATTACK);
			}
			else
			{ // 공격 쿨이 덜 돌았다.
				bool moveblock = false;
				for (int j = 0; j < _vEnemyUnit.size(); j++)
				{
					// 다른 라인일때 넘겨라.
					if (_vEnemyUnit[j]->getLine() != 0) { // -> 유닛이다.
						if (_vPlayerUnit[i]->getLine() != _vEnemyUnit[j]->getLine()) continue;
					}

					if (getDistanceX(_vPlayerUnit[i]->getX(), _vEnemyUnit[j]->getX())< _vPlayerUnit[i]->getSight())
					{ // 이동범위 안에 들어옴.
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
		{ // 공격 범위 내에 적이 없다.
			_vPlayerUnit[i]->setState(EMOVE);
			/*
			// 공격 쿨이 돌았고, 공격사거리 내에 거점이 있을때 공격
			if( _vPlayerUnit[i]->isAttackTime() && 32 * ( 50 - 8 )  < _vPlayerUnit[i]->getX() + _vPlayerUnit[i]->getAttackRange() )
			_vPlayerUnit[i]->setState( EATTACK );
			// 공격 쿨이 덜 돌았고, 공격 사거리 내에 거점이 없을때 이동
			else if( _vPlayerUnit[i]->getX() <= 32 * ( 50 - 8 ) )
			_vPlayerUnit[i]->setState( EMOVE );
			// 공격 쿨이 덜 돌았고, 공격 사거리 내에 거점이 있을때 멈춤
			else
			_vPlayerUnit[i]->setState( ESTAND );
			*/
		}
	}

	for (int i = 0; i < _vEnemyUnit.size(); i++)
	{
		// move가 되는 조건 : 무브사거리안에 적이 없다.
		// attack가 되는 조건 : 공격 사거리 안에 적이 있다. || 공격 쿨타임이 끝남.
		// non(stand)가 되는 조건 : 공격 사거리 안에 적이 있다. && 공격 쿨타임이 안끝남.


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
			if (_vPlayerUnit[j]->getLine() != 0) { // -> 유닛이다.
				if (_vEnemyUnit[i]->getLine() != _vPlayerUnit[j]->getLine()) continue;
			}
			if (_vPlayerUnit[j]->getCurrentHP() < 0)
			{
				_vEnemyUnit[i]->pop_unit(_vPlayerUnit[j]->getID());
				continue;
			}
			if (getDistanceX(_vEnemyUnit[i]->getX(), _vPlayerUnit[j]->getX()) < _vEnemyUnit[i]->getAttackRange())
			{// 적이 공격 사거리 범위 안에 있다.
				_vEnemyUnit[i]->push_unit(_vPlayerUnit[j]);

			}
			else
			{ // 사거리 밖일때
				_vEnemyUnit[i]->pop_unit(_vPlayerUnit[j]->getID());
			}
		}

		if (_vEnemyUnit[i]->getvShotUnit_size() != 0)
		{ // 공격 범위내에 적이 존재.
			if (_vEnemyUnit[i]->isAttackTime())
			{ // 공격 쿨이 돌았다.
				_vEnemyUnit[i]->setState(EATTACK);
			}
			else
			{ // 공격 쿨이 덜 돌았다.
				bool moveblock = false;
				for (int j = 0; j < _vPlayerUnit.size(); j++)
				{
					if (_vPlayerUnit[j]->getLine() != 0) { // -> 유닛이다.
						if (_vEnemyUnit[i]->getLine() != _vPlayerUnit[j]->getLine()) continue;
					}

					if (getDistanceX(_vEnemyUnit[i]->getX(), _vPlayerUnit[j]->getX())< _vEnemyUnit[i]->getSight())
					{ // 이동범위 안에 들어옴.
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
		{ // 공격 범위 내에 적이 없다.
			_vEnemyUnit[i]->setState(EMOVE);
			/*
			// 공격 쿨이 돌았고, 공격사거리 내에 거점이 있을때 공격
			if( _vEnemyUnit[i]->isAttackTime() &&  32 * 8  > _vEnemyUnit[i]->getX() - _vEnemyUnit[i]->getAttackRange() )
			_vEnemyUnit[i]->setState( EATTACK );
			// 공격 쿨이 덜 돌았고, 공격 사거리 내에 거점이 없을때 이동
			else if(_vEnemyUnit[i]->getX() >= 32 * 8  )
			_vEnemyUnit[i]->setState(EMOVE);
			// 공격 쿨이 덜 돌았고, 공격 사거리 내에 거점이 있을때 멈춤
			else
			_vEnemyUnit[i]->setState( ESTAND );
			*/
		}
	}

}

