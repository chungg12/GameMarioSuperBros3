#include "CoinUp.h" 

void CCoinUp::Render()
{
	if (this->GetState() == COIN_UP_STATE_HIDE) {
		return;
	}
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void CCoinUp::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = false;

	l = x;
	t = y;
	r = x + COIN_UP_BOX_WIDTH;
	b = y + COIN_UP_BOX_HEIGHT;
}


void CCoinUp::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	//hide not update 
	if (this->GetState() == COIN_UP_STATE_HIDE) {
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
		this->SetState(COIN_UP_STATE_HIDE);
	}


}
void CCoinUp::SetPosition(float x, float y) {
	this->x = x;
	this->y = y;
	if (min_y == -1 && max_y == -1)// not init zone walking
	{
		min_y = y - COIN_UP_DEFAULT_ZONE_UP - this->height;
		max_y = y;
	}
	this->y = this->y - 1;// move up 1 point -> check [condition hidden coin]
}

void CCoinUp::SetState(int state)
{
	CGameObject::SetState(state);
	vx = 0;
	switch (state)
	{
	case COIN_UP_STATE_MOVING:
		vy = -COIN_UP_SPEED;//bottom -> top
		break;
	case COIN_UP_STATE_HIDE:
		vy = 0;
		break;
	}
}

