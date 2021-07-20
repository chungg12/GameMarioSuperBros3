#include "ObjectContainer.h" 

void ObjectContainer::Render()
{
	animations[0]->Render(x, y);
	//RenderBoundingBox();
}



void ObjectContainer::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + this->widthObject;
	b = y + this->widthObject;
}


void ObjectContainer::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	
}