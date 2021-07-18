#include "ContainerGreen1.h" 

void ContainerGreen1::Render()
{
	animations[0]->Render(x, y);
	//RenderBoundingBox();
}



void ContainerGreen1::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + this->width;
	b = y + this->height;
}


void ContainerGreen1::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
}