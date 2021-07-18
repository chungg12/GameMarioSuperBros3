#pragma once
#pragma once
#pragma once
#include "GameObject.h"

#define WATERSTART_BOX_WIDTH  34
#define WATERSTART_BOX_HEIGHT 20
class WaterStart : public CGameObject
{

public:
	WaterStart(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

