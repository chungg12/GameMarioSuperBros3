#include "MiniCloud.h" 

void MiniCloud::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void MiniCloud::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = true;

	l = x;
	t = y;
	r = x + MINI_CLOUD_BOX_WIDTH;
	b = y + MINI_CLOUD_BOX_HEIGHT;
}


void MiniCloud::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = MINI_CLOUD_BOX_WIDTH;
	height = MINI_CLOUD_BOX_HEIGHT;
}