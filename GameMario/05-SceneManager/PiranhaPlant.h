

#pragma once
#include "GameObject.h"
#include "Mario.h"

#define VENUS_WALKING_SPEED 0.06f;

#define VENUS_BBOX_WIDTH 18
#define VENUS_BBOX_HEIGHT 28

#define GREEN_BBOX_HEIGHT 27*3
//#define VENUS_BBOX_HEIGHT 27*3

#define VENUS_STATE_GOING_UP			 100
#define VENUS_STATE_GOING_DOWN			 200
#define VENUS_STATE_SHOOTING_UP			 300
#define VENUS_STATE_SHOOTING_DOWN		 400
#define VENUS_STATE_SEEING				 500
#define VENUS_STATE_STANDING_STILL		 600
#define VENUS_STATE_SLEEPING	700
#define	ID_ANI_PIRANHA_PLANT 75000




class PiranhaPlant : public CGameObject
{
protected:


	float l_safe;
	float t_safe;
	float r_safe;
	float b_safe;

	float min_y = y;
	float max_y = y;


	ULONGLONG time_interval;

	float ax;
	float ay;
	LPGAMEOBJECT player;
	ULONGLONG die_start;


	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();

	virtual int IsCollidable() { return 1; };
	virtual int IsBlocking() { return 0; } 
	//virtual void OnNoCollision(DWORD dt);

	//virtual void OnCollisionWith(LPCOLLISIONEVENT e);

public:
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	PiranhaPlant(float x, float y);
	virtual void SetState(int state);


};