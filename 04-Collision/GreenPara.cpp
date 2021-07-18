#include "GreenPara.h"
#include <iostream>

void GreenPara::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	isBackground = false;
	left = x;
	top = y;
	right = x + GREENPARA_BBOX_WIDTH;

	if (state == GREENPARA_STATE_DIE)
		bottom = y + GREENPARA_BBOX_HEIGHT_DIE;
	else
		bottom = y + GREENPARA_BBOX_HEIGHT;
}

void GreenPara::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);

	//
	// TO-DO: make sure can interact with the world and to each of them too!
	// 

	x += width;
	y += height;

	if (vx < 0 && x < this->min_x) {//dao chieu
		x = min_x;
		vx = -vx;
	}

	if (vx > 0 && x > this->max_x) {
		x = max_x;
		vx = -vx;
	}
}

void GreenPara::Render()
{
	int ani = GREENPARA_ANI_WALKING_LEFT;
	if (state == GREENPARA_STATE_DIE) {
		ani = GREENPARA_ANI_DIE;
	}
	else if (vx> 0) 
	{
		dieTime -= dt;
		if (dieTime <= 0) // paint die stay only time
		{
			state = GREENPARA_STATE_WAS_DIE;//not render next frame
		}
	}
	else if (vx<= 0) {
		ani = GREENPARA_ANI_WALKING_LEFT;

		animations[ani]->Render(x, y);
	}
		

	//RenderBoundingBox();
}

void GreenPara::SetState(int state)
{
	CGameObject::SetState(state);

	switch (state)
	{
	case GREENPARA_STATE_DIE:
		y += GREENPARA_BBOX_HEIGHT - GREENPARA_BBOX_HEIGHT_DIE + 1;
		vx = 0;
		vy = 0;
		break;
	case GREENPARA_STATE_WALKING:
		vx = GREENPARA_WALKING_SPEED;

	}
}

void GreenPara::SetPosition(float x, float y) {
	this->x = x;
	this->y = y;
	if (min_x == -1 && max_x == -1)// not init zone walking
	{
		min_x = x - GREENPARA_DEFAULT_ZONE_WALKING;
		max_x = x + GREENPARA_DEFAULT_ZONE_WALKING;
	}
}
