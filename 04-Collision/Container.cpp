#include "Container.h" 

void CContainer::Render()
{
	animations[0]->Render(x, y);
	//RenderBoundingBox();
}



void CContainer::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + this->width;
	b = y + this->height;
}


void CContainer::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{

}