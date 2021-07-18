#pragma once

#include "GameObject.h"

#define MINI_CHIMNEY_BOX_WIDTH  52
#define MINI_CHIMNEY_BOX_HEIGHT 54
class MiniChimney : public CGameObject
{

public:
	MiniChimney(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

