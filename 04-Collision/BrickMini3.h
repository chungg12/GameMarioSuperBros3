#pragma once
#pragma once

#include "GameObject.h"
// la cai cuc gach mini co hinh cong ben canh dam may 1 cuc
#define MINI_BRICK3_BOX_WIDTH  19
#define MINI_BRICK3_BOX_HEIGHT 19
class MiniBrick3 : public CGameObject
{

public:
	MiniBrick3(int objectId) : CGameObject(objectId)
	{
		this->isBackground = false;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

