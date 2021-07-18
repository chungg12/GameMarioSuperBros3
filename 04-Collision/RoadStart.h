#pragma once
#pragma once
#pragma once
#pragma once
#include "GameObject.h"

#define ROAD_START_BOX_WIDTH  25
#define ROAD_START_BOX_HEIGHT 6
class RoadStart : public CGameObject
{

public:
	RoadStart(int objectId) : CGameObject(objectId)
	{
		this->isBackground = false;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

