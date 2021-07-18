#include "GoldRock.h"

void GoldRock::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}

void GoldRock::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + GOLD_ROCK_BOX_WIDTH;
	b = y + GOLD_ROCK_BOX_HEIGHT;
}



void GoldRock::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = GOLD_ROCK_BOX_WIDTH;
	height = GOLD_ROCK_BOX_HEIGHT;
}