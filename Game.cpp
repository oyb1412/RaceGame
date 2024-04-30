#include "Camera.h"
#include "Game.h"
#include "C_Ground.h"
#include "Ground.h"
#include "texture.h"
#include "Player.h"
#include "Collison.h"
#include "Number.h"
#include "Plane.h"
#include "sprite.h"
#include "Scene.h"
#include "Fade.h"
#include "Effect.h"
#include "TwoD.h"
#include "Shadow.h"
#include "Coin.h"
#include "pluseffect.h"



void tag_Game::Init(SCENE Type)
{
	Texture.Init();
	if (Type == SCENE_S1)
	{
		C_Ground.Init(SCENE_S1);
		COIN.Init(SCENE_S1);

	}
	if (Type == SCENE_S2)
	{
		C_Ground.Init(SCENE_S2);
		COIN.Init(SCENE_S2);

	}
	if (Type == SCENE_S3)
	{
		C_Ground.Init(SCENE_S3);
		COIN.Init(SCENE_S3);

	}
	Ground.Init();
	Player.Init();
	Colision.Init();
	PlusEffect_Init();
	TwoD.Init();
	Camera.Init();
	Effect.Init();
	Shadow.Init();
	Fade_Counter = false;
	Texture.Load(hWnd);

}
void tag_Game::Update(SCENE Type)
{
	if (Type == SCENE_S1)
	{
		C_Ground.Update(SCENE_S1);
		if (Colision.Collsion_Info().GameOver || !Player.Info().Life)
		{
			Fade_Counter = true;
		}
		if (Fade_Counter)
		{
			Fade.Fade_Funtion(true);
			if (Fade.Fade_Funtion(false, true) >= 255)
			{
				Scene.SetNextScene(SCENE_S1_WAIT);
			}
		}
	}
	if (Type == SCENE_S2)
	{
		C_Ground.Update(SCENE_S2);
		if (Colision.Collsion_Info().GameOver || !Player.Info().Life)
		{
			Fade_Counter = true;
		}
		if (Fade_Counter)
		{
			Fade.Fade_Funtion(true);
			if (Fade.Fade_Funtion(false, true) >= 255)
			{
				Scene.SetNextScene(SCENE_S2_WAIT);
			}
		}
	}
	if (Type == SCENE_S3)
	{
		C_Ground.Update(SCENE_S3);
		if (Colision.Collsion_Info().GameOver || !Player.Info().Life)
		{
			Fade_Counter = true;
		}
		if (Fade_Counter)
		{
			Fade.Fade_Funtion(true);
			if (Fade.Fade_Funtion(false, true) >= 255)
			{
				Scene.SetNextScene(SCENE_S3_WAIT);
			}
		}
	}

	COIN.Update();
	if (!Fade_Counter)
	{
		Fade.Fade_Funtion(false);
	}
	Player.Update();
	PlusEffect_Update();
	Camera.Update();

	Shadow.Update();
	Effect.Update();
	TwoD.Update();
	Plane.Update();
	Colision.Update();

}
void tag_Game::Draw(SCENE Type)
{
	TwoD.Draw();

	if (Type == SCENE_S1)
	{
		C_Ground.Draw(SCENE_S1);
		Ground.Draw(SCENE_S1);

	}
	if (Type == SCENE_S2)
	{
		C_Ground.Draw(SCENE_S2);
		Ground.Draw(SCENE_S2);

	}
	if (Type == SCENE_S3)
	{
		C_Ground.Draw(SCENE_S3);
		Ground.Draw(SCENE_S3);

	}
	COIN.Draw();

	Effect.Draw();
	Player.Draw();
	Shadow.Draw();
	PlusEffect_Draw();
	Number.Draw(Player.Info().Time_Count / 60, 90, 30, 430,2);
	TwoD.Tex_Draw();
}
void tag_Game::Uninit()
{ 
	C_Ground.Uninit();
	Ground.Uninit();
	//Player.Uninit();
}
