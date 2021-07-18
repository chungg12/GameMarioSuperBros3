#pragma once
#pragma once
#pragma once
#include "GameObject.h"

#define BRIDGE_BOX_WIDTH  21
#define BRIDGE_BOX_HEIGHT 21
class Bridge : public CGameObject
{

public:
	Bridge(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

