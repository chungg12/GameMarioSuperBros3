#pragma once
#pragma once
#include "GameObject.h"

#define GOLD_ROCK_BOX_WIDTH  17
#define GOLD_ROCK_BOX_HEIGHT 15
class GoldRock : public CGameObject
{

public:
	GoldRock(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

