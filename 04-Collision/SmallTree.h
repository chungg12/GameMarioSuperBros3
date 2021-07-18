#pragma once
#pragma once
#include "GameObject.h"

#define SMALL_TREES_BOX_WIDTH  16
#define SMALL_TREES_BOX_HEIGHT 16
class SmallTree : public CGameObject
{

public:
	SmallTree(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

