#pragma once
#pragma once
#pragma once
#pragma once
#pragma once
#include "GameObject.h"
#include "Container.h"
#define CONTAINER_BIG_BLUE_BOX_WIDTH  58
#define CONTAINER_BIG_BLUE_BOX_HEIGHT 145
class ContainerLong : public CContainer
{

public:
	ContainerLong(int objectId) : CContainer(objectId, CONTAINER_BIG_BLUE_BOX_WIDTH)
	{

	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

