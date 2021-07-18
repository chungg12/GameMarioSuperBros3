#pragma once
#pragma once
#pragma once
#include "GameObject.h"

#define CLOUD1_BOX_WIDTH  32
#define CLOUD1_BOX_HEIGHT 22
class Cloud1 : public CGameObject
{

public:
	Cloud1(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

