#include "WaterStart.h" 

void WaterStart::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void WaterStart::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = false;

	l = x;
	t = y;
	r = x + WATERSTART_BOX_WIDTH;
	b = y + WATERSTART_BOX_HEIGHT;
}


void WaterStart::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = WATERSTART_BOX_WIDTH;
	height = WATERSTART_BOX_HEIGHT;
}