#pragma once
#pragma once
#pragma once
#pragma once
#pragma once
#include "GameObject.h"

#define ROAD_START2_BOX_WIDTH  7
#define ROAD_START2_BOX_HEIGHT 24
class RoadStart2 : public CGameObject
{

public:
	RoadStart2(int objectId) : CGameObject(objectId)
	{
		this->isBackground = false;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

