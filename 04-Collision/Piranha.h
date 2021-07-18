#pragma once
#pragma once
#pragma once
#pragma once
#include "GameObject.h"

#define PIRANHA_WALKING_SPEED 0.03f;

#define PIRANHA_BBOX_WIDTH 16
#define PIRANHA_BBOX_HEIGHT 28
#define PIRANHA_BBOX_HEIGHT_DIE 9

#define PIRANHA_STATE_WALKING 100
#define PIRANHA_STATE_DIE 200
#define PIRANHA_STATE_WAS_DIE 300

#define PIRANHA_ANI_WALKING 0
#define PIRANHA_ANI_DIE 1

#define PIRANHA_DEFAULT_ZONE_WALKING 10

class Piranha : public CGameObject
{

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();


public:
	int dieTime = 100;// 100/16 times frame
	int min_y = -1; //move min x
	int max_y = -1;//move max x default
	Piranha(int objectId) : CGameObject(objectId)
	{
		this->SetState(PIRANHA_STATE_WALKING);
		this->isBackground = false;
	}
	virtual void SetState(int state);
	virtual void SetPosition(float x, float y);
};