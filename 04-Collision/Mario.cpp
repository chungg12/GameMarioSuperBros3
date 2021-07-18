#include <algorithm>
#include "debug.h"

#include "Mario.h"
#include "Game.h"

#include "Goomba.h"
#include "Container.h"
#include "BrickQuest.h"
#include "RedKoopa.h"
#include "RedGoomba.h"
#include "GreenKoopa.h"
#include "GreenPara.h"
#include "BrownGoomba.h"




void CMario::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	// Calculate dx, dy 
	CGameObject::Update(dt);

	vy += MARIO_GRAVITY*dt;//mario rơi từ trên xuống.

	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;
	coEvents.clear();


	// turn off collision when die 
	if (state != MARIO_STATE_DIE)
	{
		CalcPotentialCollisions(coObjects, coEvents);//  tính toán va chạm
	}

	// reset untouchable timer if untouchable time has passed
	if ( GetTickCount() - untouchable_start > MARIO_UNTOUCHABLE_TIME) 
	{
		untouchable_start = 0;
		untouchable = 0;
	}

	// No collision occured, proceed normally
	if (coEvents.size()==0)
	{
		x += width; 
		y += height;
	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;

		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		// block 
		x += min_tx*width + nx*0.4f;		// nx*0.4f : need to push out a bit to avoid overlapping next frame
		y += min_ty*height + ny*0.4f;
		
		if (nx!=0) vx = 0;
		if (ny!=0) vy = 0;

		// Collision logic 
		for (UINT i = 0; i < coEventsResult.size(); i++)
		{
			LPCOLLISIONEVENT e = coEventsResult[i];

			if (dynamic_cast<CGoomba *>(e->obj)) // if e->obj is Goomba  
			{
				CGoomba *goomba = dynamic_cast<CGoomba *>(e->obj);

				// jump on top >> kill Goomba and deflect a bit 
				if (e->ny < 0)
				{
					if (goomba->GetState()!= GOOMBA_STATE_DIE)
					{
						goomba->SetState(GOOMBA_STATE_DIE);
						vy = -MARIO_JUMP_DEFLECT_SPEED;
					}
				}
				else if (e->nx != 0)
				{
					if (untouchable==0)
					{
						if (goomba->GetState()!=GOOMBA_STATE_DIE)
						{
							if (level > MARIO_LEVEL_SMALL)
							{
								level = MARIO_LEVEL_SMALL;
								StartUntouchable();
							}
							else 
								SetState(MARIO_STATE_DIE);
						}
					}
				}
			}
			 
			else if (dynamic_cast<CBrickQuest*>(e->obj)) // if e->obj is BrickQuest  
			{
				CBrickQuest* objBrickQuest = dynamic_cast<CBrickQuest*>(e->obj);
				DebugOut(L"[CBrickQuest] nx=%f vx=%f  vy=%f x=%f  y=%f \n", nx, vx, vy, x, y  );
				if (e->ny > 0 )// nhay len đội cục gạch có dấu hỏi 
				{
					objBrickQuest->DownUpCoin();
				}
			}
			else if (dynamic_cast<RedKoopa*>(e->obj)) // if e->obj is Goomba  
			{
				RedKoopa* redKoopa = dynamic_cast<RedKoopa*>(e->obj);

				// jump on top >> kill Goomba and deflect a bit 
				if (e->ny < 0)
				{
					if (redKoopa->GetState() != REDKOOPA_STATE_DIE)
					{
						redKoopa->SetState(REDKOOPA_STATE_DIE);
						vy = -MARIO_JUMP_DEFLECT_SPEED;
					}
				}
				else if (e->nx != 0)
				{
					if (untouchable == 0)
					{
						if (redKoopa->GetState() != REDKOOPA_STATE_DIE)
						{
							if (level > MARIO_LEVEL_SMALL)
							{
								level = MARIO_LEVEL_SMALL;
								StartUntouchable();
							}
							else
								SetState(MARIO_STATE_DIE);
						}
					}
				}
			}
			else if (dynamic_cast<BrownGoomba*>(e->obj)) // if e->obj is Goomba  
			{
				BrownGoomba* brownGoomba = dynamic_cast<BrownGoomba*>(e->obj);

				// jump on top >> kill Goomba and deflect a bit 
				if (e->ny < 0)
				{
					if (brownGoomba->GetState() != BROWNGOOMBA_STATE_DIE)
					{
						brownGoomba->SetState(BROWNGOOMBA_STATE_DIE);
						vy = -MARIO_JUMP_DEFLECT_SPEED;
					}
				}
				else if (e->nx != 0)
				{
					if (untouchable == 0)
					{
						if (brownGoomba->GetState() != BROWNGOOMBA_STATE_DIE)
						{
							if (level > MARIO_LEVEL_SMALL)
							{
								level = MARIO_LEVEL_SMALL;
								StartUntouchable();
							}
							else
								SetState(MARIO_STATE_DIE);
						}
					}
				}
			}
			else if (dynamic_cast<RedGoomba*>(e->obj)) // if e->obj is Goomba  
			{
				RedGoomba* redGoomba = dynamic_cast<RedGoomba*>(e->obj);

				// jump on top >> kill Goomba and deflect a bit 
				if (e->ny < 0)
				{
					if (redGoomba->GetState() != REDGOOMBA_STATE_DIE)
					{
						redGoomba->SetState(REDGOOMBA_STATE_DIE);
						vy = -MARIO_JUMP_DEFLECT_SPEED;
					}
				}
				else if (e->nx != 0)
				{
					if (untouchable == 0)
					{
						if (redGoomba->GetState() != REDGOOMBA_STATE_DIE)
						{
							if (level > MARIO_LEVEL_SMALL)
							{
								level = MARIO_LEVEL_SMALL;
								StartUntouchable();
							}
							else
								SetState(MARIO_STATE_DIE);
						}
					}
				}
			}
			else if (dynamic_cast<GreenPara*>(e->obj)) // if e->obj is Goomba  
			{
				GreenPara* greenPara = dynamic_cast<GreenPara*>(e->obj);

				// jump on top >> kill Goomba and deflect a bit 
				if (e->ny < 0)
				{
					if (greenPara->GetState() != GREENPARA_STATE_DIE)
					{
						greenPara->SetState(GREENPARA_STATE_DIE);
						vy = -MARIO_JUMP_DEFLECT_SPEED;
					}
				}
				else if (e->nx != 0)
				{
					if (untouchable == 0)
					{
						if (greenPara->GetState() != GREENPARA_STATE_DIE)
						{
							if (level > MARIO_LEVEL_SMALL)
							{
								level = MARIO_LEVEL_SMALL;
								StartUntouchable();
							}
							else
								SetState(MARIO_STATE_DIE);
						}
					}
				}
			else if (dynamic_cast<GreenKoopa*>(e->obj)) // if e->obj is Goomba  
			{
			GreenKoopa* greenKoopa = dynamic_cast<GreenKoopa*>(e->obj);

				// jump on top >> kill Goomba and deflect a bit 
				if (e->ny < 0)
				{
					if (greenKoopa->GetState() != GREENKOOPA_STATE_DIE)
					{
						greenKoopa->SetState(GREENKOOPA_STATE_DIE);
						vy = -MARIO_JUMP_DEFLECT_SPEED;
					}
				}
				else if (e->nx != 0)
				{
					if (untouchable == 0)
					{
						if (greenKoopa->GetState() != GREENKOOPA_STATE_DIE)
						{
							if (level > MARIO_LEVEL_SMALL)
							{
								level = MARIO_LEVEL_SMALL;
								StartUntouchable();
							}
							else
								SetState(MARIO_STATE_DIE);
						}
					}
				}
			}
			
			}
		}
	}

	// clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}

void CMario::Render()
{
	int ani;
	if (state == MARIO_STATE_DIE)
		ani = MARIO_ANI_DIE;
	else
	if (level == MARIO_LEVEL_BIG)
	{
		if (vx == 0)
		{
			if (nx>0) ani = MARIO_ANI_BIG_IDLE_RIGHT;
			else ani = MARIO_ANI_BIG_IDLE_LEFT;
		}
		else if (vx > 0) 
			ani = MARIO_ANI_BIG_WALKING_RIGHT; 
		else ani = MARIO_ANI_BIG_WALKING_LEFT;
	}
	else if (level == MARIO_LEVEL_SMALL)
	{
		if (vx == 0)
		{
			if (nx>0) ani = MARIO_ANI_SMALL_IDLE_RIGHT;
			else ani = MARIO_ANI_SMALL_IDLE_LEFT;
		}
		else if (vx > 0)
			ani = MARIO_ANI_SMALL_WALKING_RIGHT;
		else ani = MARIO_ANI_SMALL_WALKING_LEFT;
	}

	int alpha = 255;
	if (untouchable) alpha = 128;
	if (x < 0) x = 0; // khong cho mario di lui ve ben trai man hinh < 0
	animations[ani]->Render(x, y, alpha);

//	RenderBoundingBox();
}

void CMario::SetState(int state)
{
	CGameObject::SetState(state);

	switch (state)
	{
	case MARIO_STATE_WALKING_RIGHT:
		vx = MARIO_WALKING_SPEED;
		nx = 1;
		break;
	case MARIO_STATE_WALKING_LEFT: 
		vx = -MARIO_WALKING_SPEED;
		nx = -1;
		break;
	case MARIO_STATE_JUMP: 
		vy = -MARIO_JUMP_SPEED_Y;
	case MARIO_STATE_IDLE: 
		vx = 0;
		break;
	case MARIO_STATE_DIE:
		vy = -MARIO_DIE_DEFLECT_SPEED;
		break;
	}
}

void CMario::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	left = x;
	top = y; 

	if (level==MARIO_LEVEL_BIG)
	{
		right = x + MARIO_BIG_BBOX_WIDTH;
		bottom = y + MARIO_BIG_BBOX_HEIGHT;
	}
	else
	{
		right = x + MARIO_SMALL_BBOX_WIDTH;
		bottom = y + MARIO_SMALL_BBOX_HEIGHT;
	}
}

