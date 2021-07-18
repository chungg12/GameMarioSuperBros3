#include "BrickMini3.h" 

void MiniBrick3::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void MiniBrick3::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	
	l = x;
	t = y;
	r = x + MINI_BRICK3_BOX_WIDTH;
	b = y + MINI_BRICK3_BOX_HEIGHT;
}


void MiniBrick3::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = MINI_BRICK3_BOX_WIDTH;
	height = MINI_BRICK3_BOX_HEIGHT;
}