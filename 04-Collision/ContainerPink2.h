#pragma once
#pragma once
#pragma once
#pragma once
#include "GameObject.h"
#include "Container.h"
#define CONTAINER_PINK2_BOX_WIDTH  64
#define CONTAINER_PINK2_BOX_HEIGHT 81
class ContainerPink2 : public CContainer
{

public:
	ContainerPink2(int objectId) : CContainer(objectId, CONTAINER_PINK2_BOX_WIDTH)
	{

	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

