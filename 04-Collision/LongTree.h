#pragma once
#pragma once
#pragma once
#include "GameObject.h"

#define LONG_TREES_BOX_WIDTH  94
#define LONG_TREES_BOX_HEIGHT 129
class LongTree : public CGameObject
{

public:
	LongTree(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

