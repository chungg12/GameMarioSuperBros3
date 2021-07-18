#include "Container1_3Pink.h" 

void Container13Pink::Render()
{
	animations[0]->Render(x, y);
	//RenderBoundingBox();
}



void Container13Pink::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + this->width;
	b = y + this->height;
}


void Container13Pink::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
}