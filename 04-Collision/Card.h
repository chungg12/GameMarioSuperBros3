#pragma once
#pragma once
#include "GameObject.h"

#define CARD_BOX_WIDTH  18
#define CARD_BOX_HEIGHT 19
class Card : public CGameObject
{

public:
	Card(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

