#include "BrownGoomba.h"

void BrownGoomba::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + BROWNGOOMBA_BBOX_WIDTH;

	if (state == BROWNGOOMBA_STATE_DIE)
		bottom = y + BROWNGOOMBA_BBOX_HEIGHT_DIE;
	else
		bottom = y + BROWNGOOMBA_BBOX_HEIGHT;
}

void BrownGoomba::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
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

void BrownGoomba::Render()
{
	int ani = BROWNGOOMBA_ANI_WALKING;
	if (state == BROWNGOOMBA_STATE_DIE) {
		ani = BROWNGOOMBA_ANI_NOT_FLY;
	}
	if (dieTime > 0) // paint die stay only time
	{
		animations[ani]->Render(x, y);
	}

	if (state == BROWNGOOMBA_STATE_DIE && dieTime > 0) {

	}
	//RenderBoundingBox();
}

void BrownGoomba::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case BROWNGOOMBA_STATE_DIE:
		y += BROWNGOOMBA_BBOX_HEIGHT - BROWNGOOMBA_BBOX_HEIGHT_DIE + 1;
		vx = 0;
		vy = 0;
		break;
	case BROWNGOOMBA_STATE_WALKING:
		vx = -BROWNGOOMBA_WALKING_SPEED;
	}
}

void BrownGoomba::SetPosition(float x, float y) {
	this->x = x;
	this->y = y;
	if (min_x == -1 && max_x == -1)// not init zone walking
	{
		min_x = x - BROWNGOOMBA_DEFAULT_ZONE_WALKING;
		max_x = x + BROWNGOOMBA_DEFAULT_ZONE_WALKING;
	}
}
