#pragma once
#pragma once
#include "GameObject.h"

#define FIRST_TREES_BOX_WIDTH  128
#define FIRST_TREES_BOX_HEIGHT 64
class FirstTree : public CGameObject
{

public:
	FirstTree(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

