#include "RoadStart2.h" 

void RoadStart2::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void RoadStart2::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = false;

	l = x;
	t = y;
	r = x + ROAD_START2_BOX_WIDTH;
	b = y + ROAD_START2_BOX_HEIGHT;
}


void RoadStart2::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = ROAD_START2_BOX_WIDTH;
	height = ROAD_START2_BOX_HEIGHT;
}