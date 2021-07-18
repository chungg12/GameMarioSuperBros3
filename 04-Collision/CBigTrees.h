#pragma once
#include "GameObject.h"

#define BIG_TREES_BOX_WIDTH  145
#define BIG_TREES_BOX_HEIGHT 128
class CBigTrees : public CGameObject
{

public:
	CBigTrees(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

