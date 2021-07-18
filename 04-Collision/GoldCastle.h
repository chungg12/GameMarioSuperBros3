#pragma once
#include "GameObject.h"

#define GOLD_CASTLE_BOX_WIDTH  17
#define GOLD_CASTLE_BOX_HEIGHT 19
class GoldCastle : public CGameObject
{

public:
	GoldCastle(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

