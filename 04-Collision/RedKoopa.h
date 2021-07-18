#pragma once
#pragma once
#include "GameObject.h"

#define REDKOOPA_WALKING_SPEED 0.03f;

#define REDKOOPA_BBOX_WIDTH 16
#define REDKOOPA_BBOX_HEIGHT 27
#define REDKOOPA_BBOX_HEIGHT_DIE 9

#define REDKOOPA_STATE_WALKING 100
#define REDKOOPA_STATE_DIE 200
#define REDKOOPA_STATE_WAS_DIE 300

#define REDKOOPA_ANI_WALKING_LEFT 0
#define REDKOOPA_ANI_WALKING_RIGHT 1
#define REDKOOPA_ANI_DIE 2
#define REDKOOPA_ANI_REVIVAL 3
//#define REDKOOPA_ANI_DIE 1
//#define REDKOOPA_ANI_REVIVAL 2

#define REDKOOPA_DEFAULT_ZONE_WALKING 42

class RedKoopa : public CGameObject
{

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();


public:
	int dieTime = 100;// 100/16 times frame
	int min_x = -1; //move min x
	int max_x = -1;//move max x default
	RedKoopa(int objectId) : CGameObject(objectId)
	{
		this->SetState(REDKOOPA_STATE_WALKING);
		this->isBackground = false;
	}
	virtual void SetState(int state);
	virtual void SetPosition(float x, float y);
};