#include "Door2.h" 

void Door2::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void Door2::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = true;

	l = x;
	t = y;
	r = x + DOOR2_BOX_WIDTH;
	b = y + DOOR2_BOX_HEIGHT;
}


void Door2::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = DOOR2_BOX_WIDTH;
	height = DOOR2_BOX_HEIGHT;
}