#include "Bridge.h" 

void Bridge::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void Bridge::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + BRIDGE_BOX_WIDTH;
	b = y + BRIDGE_BOX_HEIGHT;
}


void Bridge::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = BRIDGE_BOX_WIDTH;
	height = BRIDGE_BOX_HEIGHT;
}