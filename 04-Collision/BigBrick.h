#pragma once
#pragma once
#include "GameObject.h"

#define BIG_BRICK_BOX_WIDTH  152
#define BIG_BRICK_BOX_HEIGHT 31
class BigBrick : public CGameObject
{

public:
	BigBrick(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

