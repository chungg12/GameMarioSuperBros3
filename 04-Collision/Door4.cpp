#include "Door4.h" 

void Door4::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void Door4::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = true;

	l = x;
	t = y;
	r = x + DOOR4_BOX_WIDTH;
	b = y + DOOR4_BOX_HEIGHT;
}


void Door4::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = DOOR4_BOX_WIDTH;
	height = DOOR4_BOX_HEIGHT;
}