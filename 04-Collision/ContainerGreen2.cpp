#include "ContainerGreen2.h" 

void ContainerGreen2::Render()
{
	animations[0]->Render(x, y);
	//RenderBoundingBox();
}



void ContainerGreen2::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + this->width;
	b = y + this->height;
}


void ContainerGreen2::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
}