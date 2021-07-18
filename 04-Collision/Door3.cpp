#include "Door3.h" 

void Door3::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void Door3::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = true;

	l = x;
	t = y;
	r = x + DOOR3_BOX_WIDTH;
	b = y + DOOR3_BOX_HEIGHT;
}


void Door3::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = DOOR3_BOX_WIDTH;
	height = DOOR3_BOX_HEIGHT;
}