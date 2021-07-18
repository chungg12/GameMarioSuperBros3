#pragma once

#include "GameObject.h"

class CContainer : public CGameObject
{

public:
	CContainer(int objectId, int w) : CGameObject(objectId)
	{
		this->width = w;
		this->height = 1;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

