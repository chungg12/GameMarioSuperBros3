#include "Card.h" 

void Card::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void Card::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + CARD_BOX_WIDTH;
	b = y + CARD_BOX_HEIGHT;
}


void Card::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = CARD_BOX_WIDTH;
	height = CARD_BOX_HEIGHT;
}