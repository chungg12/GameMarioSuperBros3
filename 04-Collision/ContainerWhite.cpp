#include "ContainerWhite.h" 

void ContainerWhite::Render()
{
	animations[0]->Render(x, y);
	//RenderBoundingBox();
}



void ContainerWhite::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + this->width;
	b = y + this->height;
}


void ContainerWhite::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
}