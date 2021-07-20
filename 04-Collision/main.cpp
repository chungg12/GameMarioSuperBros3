/* =============================================================
	INTRODUCTION TO GAME PROGRAMMING SE102

	SAMPLE 04 - COLLISION

	This sample illustrates how to:

		1/ Implement SweptAABB algorithm between moving objects
		2/ Implement a simple (yet effective) collision frame work

	Key functions:
		CGame::SweptAABB
		CGameObject::SweptAABBEx
		CGameObject::CalcPotentialCollisions
		CGameObject::FilterCollision

		CGameObject::GetBoundingBox

================================================================ */

#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#include "debug.h"
#include "Game.h"
#include "Textures.h"

#include <fstream>
#include <iostream>
#include <string>
#include "main.h"



#include "GameObject.h"
#include "Mario.h"
#include "Brick.h"
#include "BigBrick.h"
#include "LongBrick.h"
#include "Goomba.h"
#include "Chimney.h"
#include "MiniBrick.h"
#include "MiniBrick2.h"
#include "MiniChimney.h"
#include "BrickMini3.h"
#include "CoinUp.h"
#include "RoadStart.h"
#include "CirlceStart.h"
#include "RoadStart2.h"
#include "CastleAni.h"
#include "Ant.h"
#include "RedKoopa.h"
#include "RedGoomba.h"
#include "GreenKoopa.h"
#include "GreenPara.h"
#include "Piranha.h"
#include "BrownGoomba.h"
#include "BackgroundObject.h"
#include "ObjectContainer.h"
using namespace std;

#define WINDOW_CLASS_NAME L"SampleWindow"
#define MAIN_WINDOW_TITLE L"04 - Collision"

#define BACKGROUND_COLOR D3DCOLOR_XRGB(181, 224, 241)
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#define MAX_FRAME_RATE 120

#define ID_TEX_MARIO 0
#define ID_TEX_ENEMY 10
#define ID_TEX_MISC 20
#define IS_RENDER_BOUNDING_BOX false


#define OBJECT_ID_COINT_UP 18
#define ANI_OBJECT_ID_COINT_UP 19

#define ID_OBJECT_BACKGROUND 1
#define ID_OBJECT_BACKGROUND_CONTAINER 2

CGame* game;
CMario* mario;
vector<LPGAMEOBJECT> objects;

CTextures* textures;
CSprites* sprites;
CAnimations* animations;


class AnimationSet {
public:
	int id;
	vector<int> anis;

};
class CSampleKeyHander : public CKeyEventHandler
{
	virtual void KeyState(BYTE* states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
};

CSampleKeyHander* keyHandler;
string currentContext = "";
std::vector<AnimationSet> tmp_animation_set;


void CSampleKeyHander::OnKeyUp(int KeyCode)
{
}

void CSampleKeyHander::KeyState(BYTE* states)
{
	// disable control key when Mario die 
	if (mario->GetState() == MARIO_STATE_DIE) return;
	if (game->IsKeyDown(DIK_RIGHT))
		mario->SetState(MARIO_STATE_WALKING_RIGHT);
	else if (game->IsKeyDown(DIK_LEFT))
		mario->SetState(MARIO_STATE_WALKING_LEFT);
	else
		mario->SetState(MARIO_STATE_IDLE);
}

LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

int stringToInt(string str)
{
	return atoi(str.c_str());
}
float stringToFloat(string str)
{
	return std::stod(str);
}
bool IsNumberic(string str)
{
	try
	{
		int a = atoi(str.c_str());
		return true;
	}
	catch (const std::exception&)
	{
		return false;

	}
}

AnimationSet GetAnimationSetByType(int idAni)
{
	for (int i = 0; i < tmp_animation_set.size(); i++) {
		if (tmp_animation_set[i].id == idAni) return tmp_animation_set[i];
	}
	AnimationSet ani;
	return ani;
}
CGameObject* GetGameObject(int objectId, vector<string> strData)
{
	//0 = Mario , 1 = Brick, 2 = Goomba , 3 = Long Brick
	if (strData.size() == 7)
	{
		if (stringToInt(strData[4]) == ID_OBJECT_BACKGROUND)
		{
			CGameObject* obj = 	new BackgroundObject(objectId, stringToInt(strData[5]),stringToInt(strData[6]));
			return obj;
		}
		else if (stringToInt(strData[4]) == ID_OBJECT_BACKGROUND_CONTAINER)
		{
			CGameObject* obj = new ObjectContainer(objectId, stringToInt(strData[5]), stringToInt(strData[6]));
			return obj;
		}
	}
	switch (objectId)
	{
	case 0: {
		mario = new CMario(objectId);
		return mario;
	}
	case 2: {
		CGoomba* goomba = new CGoomba(objectId);
		if (strData.size() > 5)
		{
			goomba->min_x = stringToInt(strData[4]);
			goomba->max_x = stringToInt(strData[5]);
		}
		return goomba;
	}
	case 1: return	new CBrick(objectId);
	case 3: return	new CLongBrick(objectId);
	case 8: return	new BigBrick(objectId);
	case 9: return	new Chimney(objectId);
	case 11: return	new MiniBrick(objectId);
	case 14: return	new MiniBrick2(objectId);
	case OBJECT_ID_COINT_UP: return	new CCoinUp(objectId);
	case 19: return	new MiniBrick3(objectId);
	case 20: return	new MiniChimney(objectId);
	case 33: return new RoadStart(objectId);
	case 34: return new CircleStart(objectId);
	case 36: return new RoadStart2(objectId);
	case 50: return new CastleAni(objectId);
	
	case 52: {
		Ant* ant = new Ant(objectId);
		return ant;
	}
	case 53: return new RedKoopa(objectId);
	case 54: return new RedGoomba(objectId);
	case 55: return new GreenKoopa(objectId);
	case 56: return new GreenPara(objectId);
	case 57: return new Piranha(objectId);
	case 58: return new BrownGoomba(objectId);
	default:
		return NULL;
	}
}

std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}


void ProcessLineData(string str)
{
	// Process str
	std::string delimiter = " ";
	size_t pos = 0;
	std::string data;
	vector<string> strData;//backup long setting
	while ((pos = str.find(delimiter)) != std::string::npos) {
		data = str.substr(0, pos);
		strData.push_back(data);		str.erase(0, pos + delimiter.length());
	}
	strData.push_back(str);
	if (strData[0] == "" || strData[0] == "#") return;
	if (currentContext == "[ANIMATIONS]")
	{
		for (int i = 0; i < strData.size(); i++)
		{
			if (strData[i] == "" || strData[i] == "#") break;

			LPANIMATION ani = NULL;
			for (int j = 1; j < strData.size(); j += 2)
			{

				if (ani == NULL)
				{
					ani = new CAnimation(stringToInt(strData[j + 1]));
				}
				ani->Add(stringToInt(strData[j]));
			}
			animations->Add(stringToInt(strData[0]), ani);
		}
	}
	else  if (currentContext == "[TEXTURES]")
	{
		int id = stringToInt(strData[0]);
		string filePath = strData[1];
		textures->Add(id, s2ws(filePath).c_str(), D3DCOLOR_XRGB(stringToInt(strData[2]), stringToInt(strData[3]), stringToInt(strData[4])));
	}
	else if (currentContext == "[SPRITES]")
	{
		LPDIRECT3DTEXTURE9 texPic = textures->Get(stringToInt(strData[5]));
		sprites->Add(stringToInt(strData[0]), stringToInt(strData[1]), stringToInt(strData[2]), stringToInt(strData[3]), stringToInt(strData[4]), texPic);

	}
	else if (currentContext == "[ANIMATION_SETS]")
	{
		//add temp list animation set
		AnimationSet ani_i;
		ani_i.id = stringToInt(strData[0]);
		for (int i = 1; i < strData.size(); i++)
		{
			ani_i.anis.push_back(stringToInt(strData[i]));
		}
		tmp_animation_set.push_back(ani_i);
	}
	else if (currentContext == "[OBJECTS]")
	{
		int idAni = stringToInt(strData[3]);
		AnimationSet ani_type = GetAnimationSetByType(idAni);
		int objectId = stringToInt(strData[0]);

		int x = stringToInt(strData[1]);
		int y = stringToInt(strData[2]);

		CGameObject* gameObject = GetGameObject(objectId, strData);

		if (gameObject != NULL)
		{
			for (int iAni = 0; iAni < ani_type.anis.size(); iAni++)
			{
				gameObject->AddAnimation(ani_type.anis[iAni]);
			}
			gameObject->SetPosition(x, y);
			objects.push_back(gameObject);

			//when MiniBrick2 -> auto create coin up object
			if (dynamic_cast<MiniBrick2*>(gameObject)) // if e->obj is Container  
			{
				MiniBrick2* objMiniBrick2 = dynamic_cast<MiniBrick2*>(gameObject);


				CCoinUp* objCoinUp = new CCoinUp(OBJECT_ID_COINT_UP);
				AnimationSet ani_type_CoinUp = GetAnimationSetByType(ANI_OBJECT_ID_COINT_UP);
				objCoinUp->AddAnimation(ani_type_CoinUp.anis[0]);
				objCoinUp->SetPosition(x, y - objCoinUp->height);
				objMiniBrick2->SetCoinUp(objCoinUp);
				objects.push_back(objCoinUp);
			}
		}
	}
}

void Update(DWORD dt)
{
	// We know that Mario is the first object in the list hence we won't add him into the colliable object list
	// TO-DO: This is a "dirty" way, need a more organized way 

	vector<LPGAMEOBJECT> coObjects;
	for (int i = 0; i < objects.size(); i++)
	{
		CGameObject* gameObject = objects[i];
		CGoomba* goomba = (CGoomba*)gameObject;
		if (goomba != NULL && goomba->state == GOOMBA_STATE_WAS_DIE)
		{
			continue;
		}
		
		coObjects.push_back(gameObject);
	}

	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Update(dt, &coObjects);
	}


	// Update camera to follow mario
	float cx, cy;
	mario->GetPosition(cx, cy);

	cx -= SCREEN_WIDTH / 2;
	if (cx < 0)
	{
		cx = 0; // khong di chuyen camrera lui ->so am
	}
	cy -= SCREEN_HEIGHT / 2;
	if (true || cy > SCREEN_HEIGHT + SCREEN_HEIGHT / 4)
	{
		cy = 0;
	}
	//CGame::GetInstance()->SetCamPos(cx, 0.0f /*cy*/);
	CGame::GetInstance()->SetCamPos(cx, cy); // chay theo mario theo chieu y
}

/*
	Render a frame
*/
void Render()
{
	LPDIRECT3DDEVICE9 d3ddv = game->GetDirect3DDevice();
	LPDIRECT3DSURFACE9 bb = game->GetBackBuffer();
	LPD3DXSPRITE spriteHandler = game->GetSpriteHandler();

	if (d3ddv->BeginScene())
	{
		// Clear back buffer with a color
		d3ddv->ColorFill(bb, NULL, BACKGROUND_COLOR);

		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		for (int i = 0; i < objects.size(); i++)
			objects[i]->Render();

		spriteHandler->End();
		d3ddv->EndScene();
	}

	// Display back buffer content to the screen
	d3ddv->Present(NULL, NULL, NULL, NULL);
}

HWND CreateGameWindow(HINSTANCE hInstance, int nCmdShow, int ScreenWidth, int ScreenHeight)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;

	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WINDOW_CLASS_NAME;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	HWND hWnd =
		CreateWindow(
			WINDOW_CLASS_NAME,
			MAIN_WINDOW_TITLE,
			WS_OVERLAPPEDWINDOW, // WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			ScreenWidth,
			ScreenHeight,
			NULL,
			NULL,
			hInstance,
			NULL);

	if (!hWnd)
	{
		OutputDebugString(L"[ERROR] CreateWindow failed");
		DWORD ErrCode = GetLastError();
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return hWnd;
}

int Run()
{
	MSG msg;
	int done = 0;
	DWORD frameStart = GetTickCount();
	DWORD tickPerFrame = 1000 / MAX_FRAME_RATE;

	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) done = 1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		DWORD now = GetTickCount();

		// dt: the time between (beginning of last frame) and now
		// this frame: the frame we are about to render
		DWORD dt = now - frameStart;

		if (dt >= tickPerFrame)
		{
			frameStart = now;

			game->ProcessKeyboard();
			Update(dt);
			Render();
		}
		else
			Sleep(tickPerFrame - dt);
	}

	return 1;
}

//void LoadResources2()
//{
//	objects.clear();
//
//
//	textures = CTextures::GetInstance();
//	sprites = CSprites::GetInstance();
//	animations = CAnimations::GetInstance();
//
//	string fileName = "mario.txt";
//	std::ifstream file(fileName);
//	std::string str;
//	while (std::getline(file, str))
//	{
//		if (str[0] == '[') //style context
//		{
//			currentContext = str;
//			continue;
//		}
//		else if (str[0] == '#' || str.length() == 0)//comment or empty line
//		{
//			continue;
//		}
//		else if (IsNumberic(string(1, str[0]))) // is data strart with number
//		{
//			ProcessLineData(str);
//		}
//	}
//}

//doc file mario map 1-3
//void LoadResources3()
//{
//	objects.clear();
//
//
//	textures = CTextures::GetInstance();
//	sprites = CSprites::GetInstance();
//	animations = CAnimations::GetInstance();
//
//	string fileName = "mario1-3.txt";
//	std::ifstream file(fileName);
//	std::string str;
//	while (std::getline(file, str))
//	{
//		if (str[0] == '[') //style context
//		{
//			currentContext = str;
//			continue;
//		}
//		else if (str[0] == '#' || str.length() == 0)//comment or empty line
//		{
//			continue;
//		}
//		else if (IsNumberic(string(1, str[0]))) // is data strart with number
//		{
//			ProcessLineData(str);
//		}
//	}
//}

//doc file start game

void LoadResources4(string fileName)
{
	objects.clear();


	textures = CTextures::GetInstance();
	sprites = CSprites::GetInstance();
	animations = CAnimations::GetInstance();


	std::ifstream file(fileName);
	std::string str;
	while (std::getline(file, str))
	{
		if (str[0] == '[') //style context
		{
			currentContext = str;
			continue;
		}
		else if (str[0] == '#' || str.length() == 0)//comment or empty line
		{
			continue;
		}
		else if (IsNumberic(string(1, str[0]))) // is data strart with number
		{
			ProcessLineData(str);
		}
	}
}




void CSampleKeyHander::OnKeyDown(int KeyCode)
{
	switch (KeyCode)
	{
	case DIK_SPACE:
	case DIK_Z:
		mario->SetState(MARIO_STATE_JUMP);
		break;
	case DIK_F4:
		LoadResources4("start_mario.txt");
		break;
	case DIK_F5:
		LoadResources4("mario.txt");
		break;
	case DIK_F6:
		LoadResources4("mario1-3.txt");
		break;
	case DIK_A: // reset
	mario->SetState(MARIO_STATE_IDLE);
		mario->SetLevel(MARIO_LEVEL_BIG);
	mario->SetSpeed(0, 0);
		break;
	}
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd = CreateGameWindow(hInstance, nCmdShow, SCREEN_WIDTH, SCREEN_HEIGHT);

	game = CGame::GetInstance();
	game->Init(hWnd);

	keyHandler = new CSampleKeyHander();
	game->InitKeyboard(keyHandler);

	//LoadResources2();
	//LoadResources3();
	LoadResources4("mario.txt");

	SetWindowPos(hWnd, 0, 0, 0, SCREEN_WIDTH * 2, SCREEN_HEIGHT * 2, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);

	Run();

	return 0;
}