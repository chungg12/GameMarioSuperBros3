#include "Mushroom.h" 

void MushRoom::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void MushRoom::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = true;

	l = x;
	t = y;
	r = x + MUSH_BOX_WIDTH;
	b = y + MUSH_BOX_HEIGHT;
}


void MushRoom::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = MUSH_BOX_WIDTH;
	height = MUSH_BOX_HEIGHT;
}