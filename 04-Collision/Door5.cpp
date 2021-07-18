#include "Door5.h" 

void Door5::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void Door5::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = true;

	l = x;
	t = y;
	r = x + DOOR5_BOX_WIDTH;
	b = y + DOOR5_BOX_HEIGHT;
}


void Door5::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = DOOR5_BOX_WIDTH;
	height = DOOR5_BOX_HEIGHT;
}