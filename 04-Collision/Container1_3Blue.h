#pragma once

#pragma once
#include "GameObject.h"
#include "Container.h"
#define CONTAINER_BLUE13_BOX_WIDTH  73
#define CONTAINER_BLUE13_BOX_HEIGHT 40
class Container13Blue : public CContainer
{

public:
	Container13Blue(int objectId) : CContainer(objectId, CONTAINER_BLUE13_BOX_WIDTH)
	{

	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

