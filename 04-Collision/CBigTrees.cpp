#include "CBigTrees.h" 

void CBigTrees::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void CBigTrees::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + BIG_TREES_BOX_WIDTH;
	b = y + BIG_TREES_BOX_HEIGHT;
}


void CBigTrees::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = BIG_TREES_BOX_WIDTH;
	height = BIG_TREES_BOX_HEIGHT;
}