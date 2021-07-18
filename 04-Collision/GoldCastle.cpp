#include "GoldCastle.h" 

void GoldCastle::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void GoldCastle::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = true;

	l = x;
	t = y;
	r = x + GOLD_CASTLE_BOX_WIDTH;
	b = y + GOLD_CASTLE_BOX_HEIGHT;
}


void GoldCastle::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = GOLD_CASTLE_BOX_WIDTH;
	height = GOLD_CASTLE_BOX_HEIGHT;
}