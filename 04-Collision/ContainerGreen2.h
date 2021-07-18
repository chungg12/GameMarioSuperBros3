#pragma once

#include "GameObject.h"
#include "Container.h"

#define CONTAINER_GREEN2_BOX_WIDTH  94
#define CONTAINER_GREEN2_BOX_HEIGHT 29
class ContainerGreen2 : public CContainer
{

public:
	ContainerGreen2(int objectId) : CContainer(objectId, CONTAINER_GREEN2_BOX_WIDTH)
	{
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

