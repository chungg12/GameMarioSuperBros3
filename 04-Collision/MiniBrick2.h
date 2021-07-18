#pragma once

#include "GameObject.h"
#include "BrickQuest.h"

#define MINI_BRICK2_BOX_WIDTH  19
#define MINI_BRICK2_BOX_HEIGHT 19



class MiniBrick2 : public CBrickQuest
{

public:
	MiniBrick2(int objectId) : CBrickQuest(objectId)
	{
		SetState(MINI_BRICK2_ANI_HAS_QUEST);
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);

};

