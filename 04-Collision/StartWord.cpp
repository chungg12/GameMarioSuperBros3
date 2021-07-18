#include "StartWord.h" 

void StartWord::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}



void StartWord::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	isBackground = false;

	l = x;
	t = y;
	r = x + STARTWORD_BOX_WIDTH;
	b = y + STARTWORD_BOX_HEIGHT;
}


void StartWord::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	width = STARTWORD_BOX_WIDTH;
	height = STARTWORD_BOX_HEIGHT;
}