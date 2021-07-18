#include "ContainerBlue.h" 

void ContainerBlue::Render()
{
	animations[0]->Render(x, y);
	//RenderBoundingBox();
}



void ContainerBlue::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + this->width;
	b = y + this->height;
}


void ContainerBlue::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
}