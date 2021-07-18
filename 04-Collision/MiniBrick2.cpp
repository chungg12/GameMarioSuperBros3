#include "MiniBrick2.h" 
#include "CoinUp.h" 

void MiniBrick2::Render()
{
	animations[state]->Render(x, y);
	RenderBoundingBox();
}



void MiniBrick2::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + MINI_BRICK2_BOX_WIDTH;
	b = y + MINI_BRICK2_BOX_HEIGHT;
}


void MiniBrick2::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = MINI_BRICK2_BOX_WIDTH;
	height = MINI_BRICK2_BOX_HEIGHT;
}



