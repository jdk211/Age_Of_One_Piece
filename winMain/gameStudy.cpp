#include "stdafx.h"
#include "gameStudy.h"
#include "titleScene.h"
#include "playScene.h"

gameStudy::gameStudy()
{
}


gameStudy::~gameStudy()
{
}

HRESULT gameStudy::init()
{
	gameNode::init(true);
	
	//이미지 추가 함수
	addImage();

	//씬 추가
	SCENEMANAGER->addScene("playerScene", new playScene);
	SCENEMANAGER->addScene("title", new titleScene);
	
	//시작 씬
	SCENEMANAGER->changeScene("title");

	//프레임 출력
	_showFrame = false;

	return S_OK;
}

void gameStudy::release()
{

	gameNode::release();
}

void gameStudy::update()
{
	SCENEMANAGER->update();

	if (KEYMANAGER->isOnceKeyDown('F'))
	{
		_showFrame = !_showFrame;
	}

	gameNode::update();
}

void gameStudy::render( )
{
	//백버퍼에서 뿌려줌
	/*HDC backDC = this->getBackBuffer()->getMemDC();*/
	PatBlt( getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS );
	SetBkMode(getMemDC(), TRANSPARENT);
	//============================================================
	SCENEMANAGER->render();

	if (_showFrame)
	{
		TIMEMANAGER->render(getMemDC());
	}	
	//============================================================
	//백버퍼에 있는 그림을 HDC에 그리자
	this->getBackBuffer()->render( getHDC(), 0, 0 );
}

