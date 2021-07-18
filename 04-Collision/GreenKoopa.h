#pragma once
#pragma once
#pragma once
#include "GameObject.h"

#define GREENKOOPA_WALKING_SPEED 0.03f;

#define GREENKOOPA_BBOX_WIDTH 16
#define GREENKOOPA_BBOX_HEIGHT 28
#define GREENKOOPA_BBOX_HEIGHT_DIE 9

#define GREENKOOPA_STATE_WALKING 100
#define GREENKOOPA_STATE_DIE 200
#define GREENKOOPA_STATE_WAS_DIE 300

#define GREENKOOPA_ANI_WALKING_LEFT 0
#define GREENKOOPA_ANI_WALKING_RIGHT 1
#define GREENKOOPA_ANI_DIE 2
#define GREENKOOPA_ANI_REVIVAL 3

#define GREENKOOPA_DEFAULT_ZONE_WALKING 42

class GreenKoopa : public CGameObject
{

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();


public:
	int dieTime = 100;// 100/16 times frame
	int min_x = -1; //move min x
	int max_x = -1;//move max x default
	GreenKoopa(int objectId) : CGameObject(objectId)
	{
		this->SetState(GREENKOOPA_STATE_WALKING);
		this->isBackground = false;
	}
	virtual void SetState(int state);
	virtual void SetPosition(float x, float y);
};