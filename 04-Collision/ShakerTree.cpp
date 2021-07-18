#include "ShakerTree.h" 

void ShakerTree::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void ShakerTree::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = true;

	l = x;
	t = y;
	r = x + SHAKER_TREE_BOX_WIDTH;
	b = y + SHAKER_TREE_BOX_HEIGHT;
}


void ShakerTree::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = SHAKER_TREE_BOX_WIDTH;
	height = SHAKER_TREE_BOX_HEIGHT;
}