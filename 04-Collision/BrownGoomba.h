#pragma once
#pragma once
#pragma once
#include "GameObject.h"

#define BROWNGOOMBA_WALKING_SPEED 0.03f;

#define BROWNGOOMBA_BBOX_WIDTH 16
#define BROWNGOOMBA_BBOX_HEIGHT 15
#define BROWNGOOMBA_BBOX_HEIGHT_DIE 9

#define BROWNGOOMBA_STATE_WALKING 100
#define BROWNGOOMBA_STATE_NOT_FLY 200
#define BROWNGOOMBA_STATE_DIE 300
#define BROWNGOOMBA_STATE_WAS_DIE 400

#define BROWNGOOMBA_ANI_WALKING 0
#define BROWNGOOMBA_ANI_NOT_FLY 1
#define BROWNGOOMBA_ANI_DIE 2

#define BROWNGOOMBA_DEFAULT_ZONE_WALKING 100

class BrownGoomba : public CGameObject
{

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();


public:
	int dieTime = 100;// 100/16 times frame
	int min_x = -1; //move min x
	int max_x = -1;//move max x default
	BrownGoomba(int objectId) : CGameObject(objectId)
	{
		this->SetState(BROWNGOOMBA_STATE_WALKING);
		this->isBackground = false;
	}
	virtual void SetState(int state);
	virtual void SetPosition(float x, float y);
};