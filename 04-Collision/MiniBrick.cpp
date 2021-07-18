#include "MiniBrick.h" 

void MiniBrick::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void MiniBrick::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = false;

	l = x;
	t = y;
	r = x + MINI_BRICK_BOX_WIDTH;
	b = y + MINI_BRICK_BOX_HEIGHT;
}


void MiniBrick::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = MINI_BRICK_BOX_WIDTH;
	height = MINI_BRICK_BOX_HEIGHT;
}