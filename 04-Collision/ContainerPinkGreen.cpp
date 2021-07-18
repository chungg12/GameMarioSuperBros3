#include "ContainerPinkGreen.h" 

void ContainerPinkGreen::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void ContainerPinkGreen::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = true;

	l = x;
	t = y;
	r = x + CONTAINER_PINK_GREEN_BOX_WIDTH;
	b = y + CONTAINER_PINK_GREEN_BOX_HEIGHT;
}


void ContainerPinkGreen::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = CONTAINER_PINK_GREEN_BOX_WIDTH;
	height = CONTAINER_PINK_GREEN_BOX_HEIGHT;
}