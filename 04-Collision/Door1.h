#pragma once
#pragma once
#pragma once
#pragma once
#include "GameObject.h"

#define DOOR1_BOX_WIDTH  17
#define DOOR1_BOX_HEIGHT 17
class Door1 : public CGameObject
{

public:
	Door1(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

