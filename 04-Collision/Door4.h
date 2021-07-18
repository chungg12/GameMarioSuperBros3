#pragma once
#pragma once
#pragma once
#pragma once
#pragma once
#pragma once
#include "GameObject.h"

#define DOOR4_BOX_WIDTH  17
#define DOOR4_BOX_HEIGHT 17
class Door4 : public CGameObject
{

public:
	Door4(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

