#include "BigBrick.h" 

void BigBrick::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void BigBrick::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = false;

	l = x;
	t = y;
	r = x + BIG_BRICK_BOX_WIDTH;
	b = y + BIG_BRICK_BOX_HEIGHT;
}


void BigBrick::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = BIG_BRICK_BOX_WIDTH;
	height = BIG_BRICK_BOX_HEIGHT;
}