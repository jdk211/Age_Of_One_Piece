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
	
	//�̹��� �߰� �Լ�
	addImage();

	//�� �߰�
	SCENEMANAGER->addScene("playerScene", new playScene);
	SCENEMANAGER->addScene("title", new titleScene);
	
	//���� ��
	SCENEMANAGER->changeScene("title");

	//������ ���
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
	//����ۿ��� �ѷ���
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
	//����ۿ� �ִ� �׸��� HDC�� �׸���
	this->getBackBuffer()->render( getHDC(), 0, 0 );
}

