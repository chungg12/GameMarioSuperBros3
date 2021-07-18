#include "MediumTree.h" 

void MediumTree::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void MediumTree::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = true;

	l = x;
	t = y;
	r = x + MEDIUM_TREE_BOX_WIDTH;
	b = y + MEDIUM_TREE_BOX_HEIGHT;
}


void MediumTree::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = MEDIUM_TREE_BOX_WIDTH;
	height = MEDIUM_TREE_BOX_HEIGHT;
}