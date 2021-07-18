#pragma once
#pragma once

#include "GameObject.h"

#define MONEY_BOX_WIDTH  18
#define MONEY_BOX_HEIGHT 18
class Money : public CGameObject
{

public:
	Money(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

