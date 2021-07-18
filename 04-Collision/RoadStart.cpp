#include "RoadStart.h" 

void RoadStart::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void RoadStart::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground =false;

	l = x;
	t = y;
	r = x + ROAD_START_BOX_WIDTH;
	b = y + ROAD_START_BOX_HEIGHT;
}


void RoadStart::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = ROAD_START_BOX_WIDTH;
	height = ROAD_START_BOX_HEIGHT;
}