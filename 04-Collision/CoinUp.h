#pragma once
#include "GameObject.h"

#define COIN_UP_BOX_WIDTH  18
#define COIN_UP_BOX_HEIGHT 18

#define COIN_UP_DEFAULT_ZONE_UP 50
#define  COIN_UP_SPEED 0.005f

#define  COIN_UP_STATE_HIDE 0
#define  COIN_UP_STATE_MOVING 1



class CCoinUp : public CGameObject
{

public:
	CCoinUp(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
		this->SetState(COIN_UP_STATE_HIDE);
		this->width = COIN_UP_BOX_WIDTH;
		this->height = COIN_UP_BOX_HEIGHT;
	}
	int min_y = -1; //move min y
	int max_y = -1;//move max y default
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void SetPosition(float x, float y);
	virtual void SetState(int state);

};

