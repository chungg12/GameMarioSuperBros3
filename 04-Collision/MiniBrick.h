#pragma once
#pragma once
#pragma once
#include "GameObject.h"

#define MINI_BRICK_BOX_WIDTH  16
#define MINI_BRICK_BOX_HEIGHT 16
class MiniBrick : public CGameObject
{

public:
	MiniBrick(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

