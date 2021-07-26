#pragma once
#include "GameObject.h"

#define PIRANHA_BOX_WIDTH  18
#define PIRANHA_BOX_HEIGHT 28

#define PIRANHA_DEFAULT_ZONE_UP 5
#define  PIRANHA_SPEED 0.05f

#define  PIRANHA_STATE_HIDE 0
#define  PIRANHA_STATE_MOVING 1



class Piranha : public CGameObject
{

public:
	Piranha(int objectId) : CGameObject(objectId)
	{
		this->isBackground = false;
		this->SetState(PIRANHA_STATE_MOVING);
		this->width = PIRANHA_BOX_WIDTH;
		this->height = PIRANHA_BOX_HEIGHT;
	}
	int min_y = -1; //move min y
	int max_y = -1;//move max y default
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void SetPosition(float x, float y);
	virtual void SetState(int state);

};

