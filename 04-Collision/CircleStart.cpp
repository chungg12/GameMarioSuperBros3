#include "CirlceStart.h" 

void CircleStart::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void CircleStart::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = false;

	l = x;
	t = y;
	r = x + CIRCLE_START_BOX_WIDTH;
	b = y + CIRCLE_START_BOX_HEIGHT;
}


void CircleStart::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = CIRCLE_START_BOX_WIDTH;
	height = CIRCLE_START_BOX_HEIGHT;
}