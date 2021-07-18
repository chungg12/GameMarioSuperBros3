#include "Container1_3Blue.h" 

void Container13Blue::Render()
{
	animations[0]->Render(x, y);
	//RenderBoundingBox();
}



void Container13Blue::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + this->width;
	b = y + this->height;
}


void Container13Blue::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
}