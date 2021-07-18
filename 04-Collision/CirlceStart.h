#pragma once
#pragma once
#pragma once
#include "GameObject.h"

#define CIRCLE_START_BOX_WIDTH  9
#define CIRCLE_START_BOX_HEIGHT 7
class CircleStart : public CGameObject
{

public:
	CircleStart(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

