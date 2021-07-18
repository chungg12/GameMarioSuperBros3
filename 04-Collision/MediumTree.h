#pragma once
#pragma once
#pragma once
#include "GameObject.h"

#define MEDIUM_TREE_BOX_WIDTH  64
#define MEDIUM_TREE_BOX_HEIGHT 54
class MediumTree : public CGameObject
{

public:
	MediumTree(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

