#pragma once
#include "GameObject.h"
#include "CoinUp.h"


#define MINI_BRICK2_ANI_HAS_QUEST 0
#define MINI_BRICK2_ANI_NO_QUEST 1
#define MINI_BRICK2_ANI_UP_COIN 2
class CBrickQuest : public CGameObject
{

public:
	CCoinUp* objCoinUp;
	int numberCoin = 1;//default 1 coin
	CBrickQuest(int objectId) : CGameObject(objectId)
	{
		
	}
	virtual void Render();
	void DownUpCoin();
	void SetCoinUp(CCoinUp* _objCoinUp);
};