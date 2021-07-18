#include "Help.h"

void Help::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}

void Help::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + HELP_BOX_WIDTH;
	b = y + HELP_BOX_HEIGHT;
}



void Help::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = HELP_BOX_WIDTH;
	height = HELP_BOX_HEIGHT;
}