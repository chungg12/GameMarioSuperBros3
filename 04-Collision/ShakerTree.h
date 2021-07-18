#pragma once
#pragma once
#pragma once
#include "GameObject.h"

#define SHAKER_TREE_BOX_WIDTH  16
#define SHAKER_TREE_BOX_HEIGHT 16
class ShakerTree : public CGameObject
{

public:
	ShakerTree(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

