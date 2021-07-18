#include "Door1.h" 

void Door1::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void Door1::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = true;

	l = x;
	t = y;
	r = x + DOOR1_BOX_WIDTH;
	b = y + DOOR1_BOX_HEIGHT;
}


void Door1::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = DOOR1_BOX_WIDTH;
	height = DOOR1_BOX_HEIGHT;
}