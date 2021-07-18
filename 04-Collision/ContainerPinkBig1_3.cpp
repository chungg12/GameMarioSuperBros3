#include "ContainerPinkBig1_3.h" 

void ContainerPinkBig13::Render()
{
	animations[0]->Render(x, y);
	//RenderBoundingBox();
}



void ContainerPinkBig13::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + this->width;
	b = y + this->height;
}


void ContainerPinkBig13::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
}