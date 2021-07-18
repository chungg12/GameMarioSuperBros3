#pragma once
#include "GameObject.h"


class CBrick : public CGameObject
{
#define BRICK_BBOX_WIDTH  16
#define BRICK_BBOX_HEIGHT 16

public:
	CBrick(int objectId ) : CGameObject(objectId)
	{
		width = BRICK_BBOX_WIDTH;
		height = BRICK_BBOX_HEIGHT;
	}
	virtual void Render();
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
};