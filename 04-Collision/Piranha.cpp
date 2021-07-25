#include "Piranha.h" 

void Piranha::Render()
{
	if (this->GetState() == PIRANHA_STATE_HIDE) {
		return;
	}
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void Piranha::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = false;

	l = x;
	t = y;
	r = x + PIRANHA_BOX_WIDTH;
	b = y + PIRANHA_BOX_HEIGHT;
}


void Piranha::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	//hide not update 
	if (this->GetState() == PIRANHA_STATE_HIDE) {
		return;
	}

	CGameObject::Update(dt, coObjects);

	x += width;
	y += height;

	//Navigator top to bottom
	if (vy < 0 && y < this->min_y) {
		y = min_y;
		vy = -vy;
	}
	//[condition hidden coin]
	if (y >= max_y)
	{
		this->SetState(PIRANHA_STATE_MOVING);
	}


}
void Piranha::SetPosition(float x, float y) {
	this->x = x;
	this->y = y;
	if (min_y == -1 && max_y == -1)// not init zone walking
	{
		min_y = y - PIRANHA_DEFAULT_ZONE_UP - this->height;
		max_y = y;
	}
	this->y = this->y - 1;// move up 1 point -> check [condition hidden coin]
}

void Piranha::SetState(int state)
{
	CGameObject::SetState(state);
	vx = 0;
	switch (state)
	{
	case PIRANHA_STATE_MOVING:
		vy = -PIRANHA_SPEED;//bottom -> top
		break;
	case PIRANHA_STATE_HIDE:
		vy = 0;
		break;
	}
}

