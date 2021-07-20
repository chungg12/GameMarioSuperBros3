#pragma once
#pragma once
#include "GameObject.h"

#define CHIM_NEY_BOX_WIDTH  31
#define CHIM_NEY_BOX_HEIGHT 48
class Chimney : public CGameObject
{

public:
	Chimney(int objectId) : CGameObject(objectId)
	{
		this->isBackground = false;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

