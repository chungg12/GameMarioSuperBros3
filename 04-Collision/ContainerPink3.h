#pragma once

#include "GameObject.h"
#include "Container.h"
#define CONTAINER_PINK3_BOX_WIDTH  121
#define CONTAINER_PINK3_BOX_HEIGHT 64
class ContainerPink3 : public CContainer
{

public:
	ContainerPink3(int objectId) : CContainer(objectId, CONTAINER_PINK3_BOX_WIDTH)
	{

	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

