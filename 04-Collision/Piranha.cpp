#include "Piranha.h"

void Piranha::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + PIRANHA_BBOX_WIDTH;

	if (state == PIRANHA_STATE_DIE)
		bottom = y + PIRANHA_BBOX_HEIGHT_DIE;
	else
		bottom = y + PIRANHA_BBOX_HEIGHT;
}

void Piranha::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt, coObjects);

	//
	// TO-DO: make sure Goomba can interact with the world and to each of them too!
	// 

	x += width;
	y += height;

	if (vy < 0 && x < this->min_y) {//dao chieu
		y = min_y;
		vy = -vy;
	}

	if (vy > 0 && y > this->max_y) {
		y = max_y;
		vy = -vy;
	}
}

void Piranha::Render()
{
	
	int ani = PIRANHA_ANI_WALKING;
	if (state == PIRANHA_STATE_DIE) {
		ani = PIRANHA_ANI_DIE;
	}
	if (dieTime > 0) // paint die stay only time
	{
		//animations[ani]->Render(x, y);
	}

	if (state == PIRANHA_STATE_DIE && dieTime > 0) {

	}
	//RenderBoundingBox();
}

void Piranha::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case PIRANHA_STATE_DIE:
		y += PIRANHA_BBOX_HEIGHT - PIRANHA_BBOX_HEIGHT_DIE + 1;
		vx = 0;
		vy = 0;
		break;
	case PIRANHA_STATE_WALKING:
		vy = -PIRANHA_WALKING_SPEED;
	}
}

void Piranha::SetPosition(float x, float y) {
	this->x = x;
	this->y = y;
	if (min_y == -1 && max_y == -1)// not init zone walking
	{
		min_y = y - PIRANHA_DEFAULT_ZONE_WALKING;
		max_y = y + PIRANHA_DEFAULT_ZONE_WALKING;
	}
}
