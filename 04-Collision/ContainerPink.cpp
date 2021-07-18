#include "ContainerPink.h" 

void ContainerPink::Render()
{
	animations[0]->Render(x, y);
	//RenderBoundingBox();
}



void ContainerPink::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + this->width;
	b = y + this->height;
}


void ContainerPink::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
}