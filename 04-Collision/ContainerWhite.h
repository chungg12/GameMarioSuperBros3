#pragma once
#pragma once
#pragma once
#pragma once
#include "GameObject.h"
#include "Container.h"
#define CONTAINER_WHITE_BOX_WIDTH  74
#define CONTAINER_WHITE_BOX_HEIGHT 112
class ContainerWhite : public CContainer
{

public:
	ContainerWhite(int objectId) : CContainer(objectId, CONTAINER_WHITE_BOX_WIDTH)
	{

	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

