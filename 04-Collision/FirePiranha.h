#pragma once
#pragma once
#include "GameObject.h"

#define FIREPIRANHA_BOX_WIDTH  18
#define FIREPIRANHA_BOX_HEIGHT 28

#define FIREPIRANHA_DEFAULT_ZONE_UP 5
#define  FIREPIRANHA_SPEED 0.010f

#define  FIREPIRANHA_STATE_HIDE 0
#define  FIREPIRANHA_STATE_MOVING 1



class FirePiranha : public CGameObject
{

public:
	FirePiranha(int objectId) : CGameObject(objectId)
	{
		this->isBackground = false;
		this->SetState(FIREPIRANHA_STATE_MOVING);
		this->width = FIREPIRANHA_BOX_WIDTH;
		this->height = FIREPIRANHA_BOX_HEIGHT;
	}
	int min_y = -1; //move min y
	int max_y = -1;//move max y default
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void SetPosition(float x, float y);
	virtual void SetState(int state);

};

