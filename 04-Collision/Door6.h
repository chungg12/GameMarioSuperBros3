#pragma once
#pragma once
#pragma once
#pragma once
#pragma once
#pragma once
#include "GameObject.h"

#define DOOR6_BOX_WIDTH  17
#define DOOR6_BOX_HEIGHT 17
class Door6 : public CGameObject
{

public:
	Door6(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

