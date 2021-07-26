#include "FirePiranha.h" 

void FirePiranha::Render()
{
	if (this->GetState() == FIREPIRANHA_STATE_HIDE) {
		return;
	}
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void FirePiranha::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = false;

	l = x;
	t = y;
	r = x + FIREPIRANHA_BOX_WIDTH;
	b = y + FIREPIRANHA_BOX_HEIGHT;
}


void FirePiranha::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	//hide not update 
	if (this->GetState() == FIREPIRANHA_STATE_HIDE) {
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
		this->SetState(FIREPIRANHA_STATE_MOVING);
	}


}
void FirePiranha::SetPosition(float x, float y) {
	this->x = x;
	this->y = y;
	if (min_y == -1 && max_y == -1)// not init zone walking
	{
		min_y = y - FIREPIRANHA_DEFAULT_ZONE_UP - this->height;
		max_y = y;
	}
	this->y = this->y - 1;// move up 1 point -> check [condition hidden coin]
}

void FirePiranha::SetState(int state)
{
	CGameObject::SetState(state);
	vx = 0;
	switch (state)
	{
	case FIREPIRANHA_STATE_MOVING:
		vy = -FIREPIRANHA_SPEED;//bottom -> top
		break;
	case FIREPIRANHA_STATE_HIDE:
		vy = 0;
		break;
	}
}

