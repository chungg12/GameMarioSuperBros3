#pragma once
#pragma once
#pragma once
#pragma once
#include "GameObject.h"

#define GREENPARA_WALKING_SPEED 0.03f;

#define GREENPARA_BBOX_WIDTH 16
#define GREENPARA_BBOX_HEIGHT 28
#define GREENPARA_BBOX_HEIGHT_DIE 9

#define GREENPARA_STATE_WALKING 100
#define GREENPARA_STATE_DIE 200
#define GREENPARA_STATE_WAS_DIE 300

#define GREENPARA_ANI_WALKING_LEFT 0
#define GREENPARA_ANI_DIE 1
#define GREENPARA_ANI_REVIVAL 3

#define GREENPARA_DEFAULT_ZONE_WALKING 42

class GreenPara : public CGameObject
{

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();


public:
	int dieTime = 100;// 100/16 times frame
	int min_x = -1; //move min x
	int max_x = -1;//move max x default
	GreenPara(int objectId) : CGameObject(objectId)
	{
		this->SetState(GREENPARA_STATE_WALKING);
		this->isBackground = false;
	}
	virtual void SetState(int state);
	virtual void SetPosition(float x, float y);
};