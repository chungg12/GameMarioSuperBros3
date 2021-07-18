#include "ContainerGreen1_3.h" 

void ContainerGreen13::Render()
{
	animations[0]->Render(x, y);
	//RenderBoundingBox();
}



void ContainerGreen13::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + this->width;
	b = y + this->height;
}


void ContainerGreen13::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
}