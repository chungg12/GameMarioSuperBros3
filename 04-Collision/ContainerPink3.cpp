#include "ContainerPink3.h" 

void ContainerPink3::Render()
{
	animations[0]->Render(x, y);
	//RenderBoundingBox();
}



void ContainerPink3::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + this->width;
	b = y + this->height;
}


void ContainerPink3::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
}