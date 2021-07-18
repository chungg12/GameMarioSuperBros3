#pragma once
#pragma once

#include "GameObject.h"
#include "Container.h"
#define CONTAINER_PINK_BIG13_BOX_WIDTH  89
#define CONTAINER_PINK_BIG13_BOX_HEIGHT 41
class ContainerPinkBig13 : public CContainer
{

public:
	ContainerPinkBig13(int objectId) : CContainer(objectId, CONTAINER_PINK_BIG13_BOX_WIDTH)
	{

	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

