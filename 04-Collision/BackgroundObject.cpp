#include "BackgroundObject.h" 

void BackgroundObject::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void BackgroundObject::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + this->widthObject;
	b = y + this->heightObject;
}


void BackgroundObject::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = this->widthObject;
	height = this->heightObject;
}