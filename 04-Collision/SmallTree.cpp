#include "SmallTree.h" 

void SmallTree::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void SmallTree::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = true;

	l = x;
	t = y;
	r = x + SMALL_TREES_BOX_WIDTH;
	b = y + SMALL_TREES_BOX_HEIGHT;
}


void SmallTree::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = SMALL_TREES_BOX_WIDTH;
	height = SMALL_TREES_BOX_HEIGHT;
}