#pragma once
#pragma once
#pragma once
#pragma once
#include "GameObject.h"

#define CASTLEANI_BOX_WIDTH  18
#define CASTLEANI_BOX_HEIGHT 25
class CastleAni : public CGameObject
{

public:
	CastleAni(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

