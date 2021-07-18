#include "BrickQuest.h"
#include "CoinUp.h"

void CBrickQuest::Render()
{
	animations[0]->Render(x, y);
	RenderBoundingBox();
}

void CBrickQuest::DownUpCoin() // MINI_BRICK2_ANI_UP_COIN
{
	if (this->numberCoin == 0) return;// over coin
	if (this->numberCoin > 0)//still coin -> animation coin up
	{
		this->objCoinUp->SetState(COIN_UP_STATE_MOVING);
	}
	this->numberCoin--;

	if (this->numberCoin == 0) //và số lượng xu == 0->MINI_BRICK2_ANI_NO_QUEST
	{
		this->SetState(MINI_BRICK2_ANI_NO_QUEST);
	}
}
void CBrickQuest::SetCoinUp(CCoinUp* _objCoinUp)
{
	objCoinUp = _objCoinUp;
}
