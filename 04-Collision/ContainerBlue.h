#pragma once
#pragma once
#include "GameObject.h"
#include "Container.h"

#define CONTAINER_BLUE1_BOX_WIDTH  57
#define CONTAINER_BLUE1_BOX_HEIGHT 80
//cuc xanh blue ben canh cuc mau hong hinh vuong o vi tri dau tien
class ContainerBlue : public CContainer
{

public:
	ContainerBlue(int objectId) : CContainer(objectId, CONTAINER_BLUE1_BOX_WIDTH)
	{
	}
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
};

