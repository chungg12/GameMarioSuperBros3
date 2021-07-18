#pragma once
#pragma once
#pragma once
#pragma once
#include "GameObject.h"
#include "Container.h"
#define CONTAINER_BIG_BLUE_BOX_WIDTH  123
#define CONTAINER_BIG_BLUE_BOX_HEIGHT 95
class ContainerBigBlue : public CContainer
{

public:
	ContainerBigBlue(int objectId) : CContainer(objectId, CONTAINER_BIG_BLUE_BOX_WIDTH)
	{

	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

