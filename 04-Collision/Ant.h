#pragma once
#pragma once
#include "GameObject.h"

#define ANT_WALKING_SPEED 0.004f;

#define ANT_BBOX_WIDTH 18
#define ANT_BBOX_HEIGHT 18

#define ANT_STATE_WALKING 100
#define ANT_ANI_WALKING_LEFT 0
#define ANT_ANI_WALKING_RIGHT 1
#define ANT_DEFAULT_ZONE_WALKING 30
class Ant : public CGameObject
{

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();


public:
	int dieTime = 100;// 100/16 times frame
	int min_x = -1; //move min x
	int max_x = -1;//move max x default
	Ant(int objectId) : CGameObject(objectId)
	{
		this->SetState(ANT_STATE_WALKING);
		this->isBackground = false;
	}
	virtual void SetState(int state);
	virtual void SetPosition(float x, float y);
};