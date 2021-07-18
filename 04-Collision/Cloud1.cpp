#include "Cloud1.h" 

void Cloud1::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void Cloud1::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = true;

	l = x;
	t = y;
	r = x + CLOUD1_BOX_WIDTH;
	b = y + CLOUD1_BOX_HEIGHT;
}


void Cloud1::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = CLOUD1_BOX_WIDTH;
	height = CLOUD1_BOX_HEIGHT;
}