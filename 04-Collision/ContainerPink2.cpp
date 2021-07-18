#include "ContainerPink2.h" 

void ContainerPink2::Render()
{
	animations[0]->Render(x, y);
	//RenderBoundingBox();
}



void ContainerPink2::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + this->width;
	b = y + this->height;
}


void ContainerPink2::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
}