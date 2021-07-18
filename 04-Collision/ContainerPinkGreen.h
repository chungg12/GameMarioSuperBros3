#pragma once
#pragma once
#include "GameObject.h"

#define CONTAINER_PINK_GREEN_BOX_WIDTH  87
#define CONTAINER_PINK_GREEN_BOX_HEIGHT 80
class ContainerPinkGreen : public CGameObject
{

public:
	ContainerPinkGreen(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

