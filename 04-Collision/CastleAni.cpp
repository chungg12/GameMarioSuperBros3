#include "CastleAni.h" 

void CastleAni::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void CastleAni::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + CASTLEANI_BOX_WIDTH;
	b = y + CASTLEANI_BOX_HEIGHT;
}


void CastleAni::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = CASTLEANI_BOX_WIDTH;
	height = CASTLEANI_BOX_HEIGHT;
}