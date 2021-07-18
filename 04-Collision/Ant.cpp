#include "Ant.h"

void Ant::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	left = x;
	top = y;
	right = x + ANT_BBOX_WIDTH;

	
		bottom = y + ANT_BBOX_HEIGHT;
}

void Ant::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
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

void Ant::Render()
{
	int ani = ANT_ANI_WALKING_LEFT;

	 if (vx > 0) ani = ANT_ANI_WALKING_RIGHT;
	else if (vx <= 0) ani = ANT_ANI_WALKING_LEFT;

	animations[ani]->Render(x, y);
}

void Ant::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	
	case ANT_STATE_WALKING:
		vx = ANT_WALKING_SPEED;

	
	}
}

void Ant::SetPosition(float x, float y) {
	this->x = x;
	this->y = y;
	if (min_x == -1 && max_x == -1)// not init zone walking
	{
		min_x = x - ANT_DEFAULT_ZONE_WALKING;
		max_x = x + ANT_DEFAULT_ZONE_WALKING;
	}
}
