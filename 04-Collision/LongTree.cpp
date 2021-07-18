#include "LongTree.h"

void LongTree::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}

void LongTree::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = true;
	l = x;
	t = y;
	r = x + LONG_TREES_BOX_WIDTH;
	b = y + LONG_TREES_BOX_HEIGHT;
}


void LongTree::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = LONG_TREES_BOX_WIDTH;
	height = LONG_TREES_BOX_HEIGHT;
}