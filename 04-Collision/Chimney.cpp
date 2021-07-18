#include "Chimney.h" 

void Chimney::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void Chimney::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = false;

	l = x;
	t = y;
	r = x + CHIM_NEY_BOX_WIDTH;
	b = y + CHIM_NEY_BOX_HEIGHT;
}


void Chimney::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = CHIM_NEY_BOX_WIDTH;
	height = CHIM_NEY_BOX_HEIGHT;
}