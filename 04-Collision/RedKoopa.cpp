#include "RedKoopa.h"
#include <iostream>

void RedKoopa::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	isBackground = false;
	left = x;
	top = y;
	right = x + REDKOOPA_BBOX_WIDTH;

	if (state == REDKOOPA_STATE_DIE)
		bottom = y + REDKOOPA_BBOX_HEIGHT_DIE;
	else
		bottom = y + REDKOOPA_BBOX_HEIGHT;
}

void RedKoopa::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
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

void RedKoopa::Render()
{
	int ani = REDKOOPA_ANI_WALKING_LEFT;
	if (state == REDKOOPA_STATE_DIE) {
		ani = REDKOOPA_ANI_DIE;
	}
	else if (vx > 0) ani = REDKOOPA_ANI_WALKING_RIGHT;
	else if (vx <= 0) ani = REDKOOPA_ANI_WALKING_LEFT;

	animations[ani]->Render(x, y);

	//RenderBoundingBox();
}

void RedKoopa::SetState(int state)
{
	CGameObject::SetState(state);

	switch (state)
	{
	case REDKOOPA_STATE_DIE:
		y += REDKOOPA_BBOX_HEIGHT - REDKOOPA_BBOX_HEIGHT_DIE + 1;
		vx = 0;
		vy = 0;
		break;
	case REDKOOPA_STATE_WALKING:
		vx = REDKOOPA_WALKING_SPEED;
	
	}
}

void RedKoopa::SetPosition(float x, float y) {
	this->x = x;
	this->y = y;
	if (min_x == -1 && max_x == -1)// not init zone walking
	{
		min_x = x - REDKOOPA_DEFAULT_ZONE_WALKING;
		max_x = x + REDKOOPA_DEFAULT_ZONE_WALKING;
	}
}
