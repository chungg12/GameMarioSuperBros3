
#pragma once
#include "GameObject.h"
#include "Container.h"
#define CONTAINER_PINK13_BOX_WIDTH  73
#define CONTAINER_PINK13_BOX_HEIGHT 33
class Container13Pink : public CContainer
{

public:
	Container13Pink(int objectId) : CContainer(objectId, CONTAINER_PINK13_BOX_WIDTH)
	{

	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

