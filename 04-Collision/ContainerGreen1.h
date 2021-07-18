#pragma once
#include "GameObject.h"
#include "Container.h"

#define CONTAINER_GREEN1_BOX_WIDTH  79
#define CONTAINER_GREEN1_BOX_HEIGHT 45
class ContainerGreen1 : public CContainer
{

public:
	ContainerGreen1(int objectId) : CContainer(objectId, CONTAINER_GREEN1_BOX_WIDTH)
	{
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

