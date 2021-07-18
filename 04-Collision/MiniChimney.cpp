#include "MiniChimney.h" 

void MiniChimney::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void MiniChimney::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = false;

	l = x;
	t = y;
	r = x + MINI_CHIMNEY_BOX_WIDTH;
	b = y + MINI_CHIMNEY_BOX_HEIGHT;
}


void MiniChimney::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = MINI_CHIMNEY_BOX_WIDTH;
	height = MINI_CHIMNEY_BOX_HEIGHT;
}