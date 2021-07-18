#pragma once
#pragma once
#pragma once
#pragma once
#pragma once
#pragma once
#include "GameObject.h"

#define DOOR3_BOX_WIDTH  17
#define DOOR3_BOX_HEIGHT 17
class Door3 : public CGameObject
{

public:
	Door3(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

