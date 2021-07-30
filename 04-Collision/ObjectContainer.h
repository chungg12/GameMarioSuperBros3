#pragma once
#pragma once

#pragma once
#include "GameObject.h"
#include "Container.h"
class ObjectContainer : public CContainer
{


public:
	ObjectContainer(int objectId,int w,int h) : CContainer(objectId, w)
	{
		
		
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

