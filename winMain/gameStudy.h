#pragma once

#include "gameNode.h"

class gameStudy : public gameNode
{
private:
	bool _showFrame;

public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void addImage();
};

