#include "ContainerBigBlue.h" 

void ContainerBigBlue::Render()
{
	animations[0]->Render(x, y);
	//RenderBoundingBox();
}



void ContainerBigBlue::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + this->width;
	b = y + this->height;
}


void ContainerBigBlue::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
}