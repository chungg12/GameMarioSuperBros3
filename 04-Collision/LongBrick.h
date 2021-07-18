#pragma once
#include "GameObject.h"

#define LONG_BRICK_BBOX_WIDTH  47
#define LONG_BRICK_BBOX_HEIGHT 15

class CLongBrick : public CGameObject
{
public:
	CLongBrick(int objectId) : CGameObject(objectId)
	{
		width = LONG_BRICK_BBOX_WIDTH;
		height = LONG_BRICK_BBOX_HEIGHT;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);

};