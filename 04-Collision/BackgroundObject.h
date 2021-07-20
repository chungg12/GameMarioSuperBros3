#pragma once
#pragma once
#include "GameObject.h"

class BackgroundObject : public CGameObject
{
public:
	int widthObject;
	int heightObject;

public:
	BackgroundObject(int objectId, int w, int h) : CGameObject(objectId)
	{
		this->isBackground = true;
		this->widthObject = w;
		this->heightObject = h;
	} 
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

