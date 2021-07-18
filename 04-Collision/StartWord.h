#pragma once
#pragma once
#include "GameObject.h"

#define STARTWORD_BOX_WIDTH  18
#define STARTWORD_BOX_HEIGHT 18
class StartWord : public CGameObject
{

public:
	StartWord(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

