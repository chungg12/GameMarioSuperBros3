#pragma once
	
#pragma once
#pragma once
#pragma once
#pragma once
#include "GameObject.h"

#define HELP_BOX_WIDTH  18
#define HELP_BOX_HEIGHT 17
class Help : public CGameObject
{

public:
	Help(int objectId) : CGameObject(objectId)
	{
		this->isBackground = true;
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

