#pragma once
#pragma once
#pragma once
#pragma once
#pragma once
#include "GameObject.h"

#define DOORSTART_BOX_WIDTH  17
#define DOORSTART_BOX_HEIGHT 18
class DoorStart : public CGameObject
{

public:
	DoorStart(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

