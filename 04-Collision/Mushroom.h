#pragma once
#pragma once
#pragma once
#pragma once
#pragma once
#include "GameObject.h"

#define MUSH_BOX_WIDTH  17
#define MUSH_BOX_HEIGHT 18
class MushRoom : public CGameObject
{

public:
	MushRoom(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

