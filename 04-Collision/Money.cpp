#include "Money.h" 

void Money::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void Money::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = false;

	l = x;
	t = y;
	r = x + MONEY_BOX_WIDTH;
	b = y + MONEY_BOX_HEIGHT;
}


void Money::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = MONEY_BOX_WIDTH;
	height = MONEY_BOX_HEIGHT;
}