#include "DoorStart.h" 

void DoorStart::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void DoorStart::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = true;

	l = x;
	t = y;
	r = x + DOORSTART_BOX_WIDTH;
	b = y + DOORSTART_BOX_HEIGHT;
}


void DoorStart::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = DOORSTART_BOX_WIDTH;
	height = DOORSTART_BOX_HEIGHT;
}