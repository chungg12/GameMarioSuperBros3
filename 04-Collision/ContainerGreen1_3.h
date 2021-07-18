#pragma once
#include "GameObject.h"
#include "Container.h"

#define CONTAINER_GREEN13_BOX_WIDTH  73
#define CONTAINER_GREEN13_BOX_HEIGHT 40
class ContainerGreen13 : public CContainer
{

public:
	ContainerGreen13(int objectId) : CContainer(objectId, CONTAINER_GREEN13_BOX_WIDTH)
	{
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

