#include "GreenKoopa.h"
#include <iostream>

void GreenKoopa::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	isBackground = false;
	left = x;
	top = y;
	right = x + GREENKOOPA_BBOX_WIDTH;

	if (state == GREENKOOPA_STATE_DIE)
		bottom = y + GREENKOOPA_BBOX_HEIGHT_DIE;
	else
		bottom = y + GREENKOOPA_BBOX_HEIGHT;
}

void GreenKoopa::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
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

void GreenKoopa::Render()
{
	int ani = GREENKOOPA_ANI_WALKING_LEFT;
	if (state == GREENKOOPA_STATE_DIE) {
		ani = GREENKOOPA_ANI_DIE;
	}
	else if (vx > 0) ani = GREENKOOPA_ANI_WALKING_RIGHT;
	else if (vx <= 0) ani = GREENKOOPA_ANI_WALKING_LEFT;

	animations[ani]->Render(x, y);

	//RenderBoundingBox();
}

void GreenKoopa::SetState(int state)
{
	CGameObject::SetState(state);

	switch (state)
	{
	case GREENKOOPA_STATE_DIE:
		y += GREENKOOPA_BBOX_HEIGHT - GREENKOOPA_BBOX_HEIGHT_DIE + 1;
		vx = 0;
		vy = 0;
		break;
	case GREENKOOPA_STATE_WALKING:
		vx = GREENKOOPA_WALKING_SPEED;

	}
}

void GreenKoopa::SetPosition(float x, float y) {
	this->x = x;
	this->y = y;
	if (min_x == -1 && max_x == -1)// not init zone walking
	{
		min_x = x - GREENKOOPA_DEFAULT_ZONE_WALKING;
		max_x = x + GREENKOOPA_DEFAULT_ZONE_WALKING;
	}
}
