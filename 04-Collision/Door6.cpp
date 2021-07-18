#include "Door6.h" 

void Door6::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void Door6::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = true;

	l = x;
	t = y;
	r = x + DOOR6_BOX_WIDTH;
	b = y + DOOR6_BOX_HEIGHT;
}


void Door6::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = DOOR6_BOX_WIDTH;
	height = DOOR6_BOX_HEIGHT;
}