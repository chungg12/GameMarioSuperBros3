#include "RedGoomba.h"

void RedGoomba::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + REDGOOMBA_BBOX_WIDTH;

	if (state == REDGOOMBA_STATE_DIE)
		bottom = y + REDGOOMBA_BBOX_HEIGHT_DIE;
	else
		bottom = y + REDGOOMBA_BBOX_HEIGHT;
}

void RedGoomba::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);

	//
	// TO-DO: make sure Goomba can interact with the world and to each of them too!
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

void RedGoomba::Render()
{
	int ani = REDGOOMBA_ANI_WALKING;
	if (state == REDGOOMBA_STATE_DIE) {
		ani = REDGOOMBA_ANI_NOT_FLY;
	}
	if (dieTime > 0) // paint die stay only time
	{
		animations[ani]->Render(x, y);
	}

	if (state == REDGOOMBA_STATE_DIE && dieTime > 0) {
	
	}
	//RenderBoundingBox();
}

void RedGoomba::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case REDGOOMBA_STATE_DIE:
		y += REDGOOMBA_BBOX_HEIGHT - REDGOOMBA_BBOX_HEIGHT_DIE + 1;
		vx = 0;
		vy = 0;
		break;
	case REDGOOMBA_STATE_WALKING:
		vx = -REDGOOMBA_WALKING_SPEED;
	}
}

void RedGoomba::SetPosition(float x, float y) {
	this->x = x;
	this->y = y;
	if (min_x == -1 && max_x == -1)// not init zone walking
	{
		min_x = x - REDGOOMBA_DEFAULT_ZONE_WALKING;
		max_x = x + REDGOOMBA_DEFAULT_ZONE_WALKING;
	}
}
