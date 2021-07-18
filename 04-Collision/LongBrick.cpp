#include "LongBrick.h"

void CLongBrick::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
} 

void CLongBrick::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + LONG_BRICK_BBOX_WIDTH;
	b = y + LONG_BRICK_BBOX_HEIGHT;
}

 