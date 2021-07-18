#pragma once
#pragma once
#pragma once
#include "GameObject.h"
#include "Container.h"
#define CONTAINER_PINK_BOX_WIDTH  57
#define CONTAINER_PINK_BOX_HEIGHT 47
class ContainerPink : public CContainer
{

public:
	ContainerPink(int objectId) : CContainer(objectId, CONTAINER_PINK_BOX_WIDTH)
	{
	
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

