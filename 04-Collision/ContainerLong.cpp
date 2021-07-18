#include "ContainerLong.h" 

void ContainerLong::Render()
{
	animations[0]->Render(x, y);
	//RenderBoundingBox();
}



void ContainerLong::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + this->width;
	b = y + this->height;
}


void ContainerLong::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
}