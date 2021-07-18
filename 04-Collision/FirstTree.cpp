#include "FirstTree.h" 

void FirstTree::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void FirstTree::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = true;

	l = x;
	t = y;
	r = x + FIRST_TREES_BOX_WIDTH;
	b = y + FIRST_TREES_BOX_HEIGHT;
}


void FirstTree::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = FIRST_TREES_BOX_WIDTH;
	height = FIRST_TREES_BOX_HEIGHT;
}