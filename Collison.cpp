#include "common.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "Player.h"
#include "C_Ground.h"
#include "Tutorial.h"
#include "Effect.h"
#include "sound.h"
#include "Collison.h"
#include "Scene.h"
#include "Coin.h" 
#include "input.h"
#include "Fade.h"

void tag_Colision::Init()
{
	
	Collision.Hit = false;
	Collision.Boost_Count = 0;
	Collision.Boost = false;
	Collision.Slow_Count = 0;
	Collision.Slow = false;
	Collision.Jump_Count = 0;
	Collision.Jump = false;
	Collision.Chaos_Count = 0;
	Collision.Chaos = false;
	Collision.GameOver = false;
	Collision.Distory = false;
	Collision.Goal = false;
	Collision.Goal_Count = 0;
	turm = 0;
	Collision.Time_Save[3] = {0};
}


void tag_Colision::Update()
{
	turm--;

	{//tutorial
		if (Scene.Stage_Type(SCENE_TUTORIAL))
		{
			if (Ground_T(0, 1))
			{
				Player.Gravity(0.1f);
				Collision.Distory = false;
			}
			if (!Ground_T(0, 1))
			{
				Collision.Distory = true;
			}


			if (Ground_T(1, 2) && !Collision.Boost && Player.Info().Trans.z != 1)
			{
				Sound.Play(SOUND_LABEL_SE_SPEED);
				Collision.Boost = true;
			}
			if (Collision.Boost)
			{
				Collision.Boost_Count++;
			}
			if (Collision.Boost_Count <= 30 && Collision.Boost)
			{
				Effect.Create(SPEED_UP, Player.Info().Trans.x, Player.Info().Trans.y, Player.Info().Trans.z);
				Player.Position_Z(0.1f);
			}
			if (Collision.Boost_Count > 30 && Collision.Boost)
			{
				Collision.Boost = false;
				Collision.Boost_Count = 0;
			}


			if (Ground_T(2, 3) && !Collision.Slow && Player.Info().Trans.z != 1 )
			{
				Sound.Play(SOUND_LABEL_SE_SLOW);

				Collision.Slow = true;
			}
			if (Collision.Slow)
			{
				Collision.Slow_Count++;
			}
			if (Collision.Slow_Count <= 30 && Collision.Slow)
			{
				Effect.Create(SPEED_SLOW, Player.Info().Trans.x, Player.Info().Trans.y, Player.Info().Trans.z);

				if (Player.Info().Move_Velocity > 0.2)
				{
					Player.F_Velocity(-0.015f);
				}
			}
			if (Collision.Slow_Count > 30 && Collision.Slow)
			{
				Collision.Slow = false;
				Collision.Slow_Count = 0;
			}


			if (Ground_T(3, 4) && !Collision.Chaos && Player.Info().Trans.z != 1)
			{
				Effect.Create(CHAOS, Player.Info().Trans.x, Player.Info().Trans.y, Player.Info().Trans.z);
				Sound.Play(SOUND_LABEL_SE_CHAOS);

				Collision.Chaos = true;
			}
			if (Collision.Chaos)
			{
				Collision.Chaos_Count++;
			}

			if (Collision.Chaos_Count >200 && Collision.Chaos)
			{
				Collision.Chaos = false;
				Collision.Chaos_Count = 0;
			}


			if (Player.Info().Trans.z != 1 && Ground_T(4, 5) && !Collision.Jump)
			{
				Effect.Create(JUMP, Player.Info().Trans.x, Player.Info().Trans.y, Player.Info().Trans.z);
				Sound.Play(SOUND_LABEL_SE_SUPERJUMP);

				Collision.Jump = true;
			}
			if (Collision.Jump)
			{
				Collision.Jump_Count++;
			}
			if (Collision.Jump_Count > 270 && Collision.Jump)
			{
				Collision.Jump = false;
				Collision.Jump_Count = 0;
			}
		}
	}
	{//Stage1
		if (Scene.Stage_Type(SCENE_S1))
		{
			if (Hit_Coin(0, COIN_MAX_S1) && Player.Info().Trans.z != 1 && turm < 0)
			{
				turm = 10;
				Sound.Play(SOUND_LABEL_SE_COIN);
				Player.Plus_Boost(100);
			}
			if (!Ground_S1(0, 28) || Ground_S1(70, 87))
			{
				Collision.Distory = true;
			}
			if (Ground_S1(0, 28)|| Ground_S1(70, 87))
			{
				Player.Gravity(0.1f);
				Collision.Distory = false;
			}
			if (Ground_S1(91, 95) && !Collision.Boost && Player.Info().Trans.x != 0
				|| Ground_S1(28, 36) && !Collision.Boost && Player.Info().Trans.x != 0)
			{
				if (!Player.Type_Boost())
				{
					Sound.Play(SOUND_LABEL_SE_SPEED);
					Collision.Boost = true;
				}
			}
			if (Collision.Boost)
			{
				Collision.Boost_Count++;
			}
			if (Collision.Boost_Count <= 30 && Collision.Boost)
			{
				Effect.Create(SPEED_UP, Player.Info().Trans.x, Player.Info().Trans.y, Player.Info().Trans.z);

				Player.Position_Z(0.1f);
			}
			if (Collision.Boost_Count > 30 && Collision.Boost)
			{
				Collision.Boost = false;
				Collision.Boost_Count = 0;
			}

			if (Ground_S1(36, 45) && !Collision.Slow && Player.Info().Trans.z != 1)
			{
				Sound.Play(SOUND_LABEL_SE_SLOW);

				Collision.Slow = true;
			}
			if (Collision.Slow)
			{
				Collision.Slow_Count++;
			}
			if (Collision.Slow_Count <= 30 && Collision.Slow)
			{
				Effect.Create(SPEED_SLOW, Player.Info().Trans.x, Player.Info().Trans.y, Player.Info().Trans.z);
				if (Player.Info().Move_Velocity > 0.2)
				{
					Player.F_Velocity(-0.015f);
				}
			}
			if (Collision.Slow_Count > 30 && Collision.Slow)
			{
				Collision.Slow = false;
				Collision.Slow_Count = 0;
			}
			if (Ground_S1(45, 50) && !Collision.Chaos && Player.Info().Trans.z != 1)
			{
				Effect.Create(CHAOS, Player.Info().Trans.x, Player.Info().Trans.y, Player.Info().Trans.z);
				Sound.Play(SOUND_LABEL_SE_CHAOS);

				Collision.Chaos = true;
			}
			if (Collision.Chaos)
			{
				Collision.Chaos_Count++;
			}

			if (Collision.Chaos_Count > 200 && Collision.Chaos)
			{
				Collision.Chaos = false;
				Collision.Chaos_Count = 0;
			}
			if (Ground_S1(50, 58) && Player.Info().Trans.z != 1 && !Collision.GameOver
				|| Ground_S1(66, 70) && Player.Info().Trans.z != 1 && !Collision.GameOver
				|| Ground_S1(87, 91) && Player.Info().Trans.z != 1 && !Collision.GameOver
				|| Player.Info().Time_Count/60 >=40 && !Collision.GameOver)
			{
				Sound.Stop();
				Sound.Play(SOUND_LABEL_SE_DETAH);
				Effect.Create(DISTROY, Player.Info().Trans.x, Player.Info().Trans.y, Player.Info().Trans.z);
				Collision.GameOver = true;
				Player.Distroy();
			}
			if (Player.Info().Trans.z != 1 && Ground_S1(58, 65) && !Collision.Jump)
			{
				Effect.Create(JUMP, Player.Info().Trans.x, Player.Info().Trans.y, Player.Info().Trans.z);
				Sound.Play(SOUND_LABEL_SE_SUPERJUMP);

				Collision.Jump = true;
			}
			if (Collision.Jump)
			{
				Collision.Jump_Count++;
			}
			if (Collision.Jump_Count > 270 && Collision.Jump)
			{
				Collision.Jump = false;
				Collision.Jump_Count = 0;
			}
			if (Ground_S1(65, 66) && Player.Info().Trans.z != 1 && !Collision.Goal)
			{
				Sound.Stop();
				Sound.Play(SOUND_LABEL_SE_GOAL);
				Collision.Time_Save[0] = Player.Info().Time_Count/60;
				Collision.Goal = true;
			}
			if (Collision.Goal)
			{
				Collision.Goal_Count++;
			}
			if (Keyboard.IsPress(DIK_SPACE) && Collision.Goal && Collision.Goal_Count >= 300)
			{
				Sound.Stop();
				Fade_Trigger = true;
			}
			if (Fade_Trigger)
			{
				Fade.Fade_Funtion(true);
				Fade.Fade_Funtion(true);

				if (Fade.Fade_Funtion(true, true) >= 255)
				{
					Fade_Trigger = false;
					Scene.SetNextScene(SCENE_S2);
				}
			}


		}
	}


	{//Stage2
		if (Scene.Stage_Type(SCENE_S2))
		{
			if (Hit_Coin(0, COIN_MAX_S2) && Player.Info().Trans.z != 1 && turm < 0)
			{
				turm = 10;
				Sound.Play(SOUND_LABEL_SE_COIN);
				Player.Plus_Boost(100);
			}
			if(Ground_S2(0, 17))
			{
				Player.Gravity(0.1f);
				Collision.Distory = false;
			}
			if (!Ground_S2(0, 17))
			{
				Collision.Distory = true;
			}
			if (Ground_S2(17, 18) && Player.Info().Trans.z != 1 && !Collision.Goal)
			{
				Sound.Stop();
				Sound.Play(SOUND_LABEL_SE_GOAL);
				Collision.Time_Save[1] = Player.Info().Time_Count/60;
				Collision.Goal = true;
			}
			if (Collision.Goal)
			{
				Collision.Goal_Count++;
			}
			if (Keyboard.IsPress(DIK_SPACE) && Collision.Goal && Collision.Goal_Count >= 300)
			{
				Sound.Stop();
				Fade_Trigger = true;
			}
			if (Fade_Trigger)
			{
				Fade.Fade_Funtion(true);
				Fade.Fade_Funtion(true);

				if (Fade.Fade_Funtion(true, true) >= 255)
				{
					Fade_Trigger = false;
					Scene.SetNextScene(SCENE_S3);
				}
			}
			if (Ground_S2(18, 50) && Player.Info().Trans.z != 1
				|| Player.Info().Time_Count / 60 >=90 && !Collision.GameOver)
			{
				Sound.Stop();
				Effect.Create(DISTROY, Player.Info().Trans.x, Player.Info().Trans.y, Player.Info().Trans.z);
				Sound.Play(SOUND_LABEL_SE_DETAH);
				Collision.GameOver = true;
				Player.Distroy();
			}
			if (Ground_S2(50, 63) && !Collision.Boost && Player.Info().Trans.z != 1)
			{
				if (!Player.Type_Boost())
				{
					Sound.Play(SOUND_LABEL_SE_SPEED);
					Collision.Boost = true;
				}
			}
			if (Collision.Boost)
			{
				Collision.Boost_Count++;
			}
			if (Collision.Boost_Count <= 30 && Collision.Boost)
			{
				Effect.Create(SPEED_UP, Player.Info().Trans.x, Player.Info().Trans.y, Player.Info().Trans.z);

				Player.Position_Z(0.1f);
			}
			if (Collision.Boost_Count > 30 && Collision.Boost)
			{
				Collision.Boost = false;
				Collision.Boost_Count = 0;
			}
			if (Player.Info().Trans.z != 1 && Ground_S2(63, 69) && !Collision.Jump)
			{
				Effect.Create(JUMP, Player.Info().Trans.x, Player.Info().Trans.y, Player.Info().Trans.z);
				Sound.Play(SOUND_LABEL_SE_SUPERJUMP);
				Collision.Jump = true;
			}
			if (Collision.Jump)
			{
				Collision.Jump_Count++;
			}
			if (Collision.Jump_Count > 270 && Collision.Jump)
			{
				Collision.Jump = false;
				Collision.Jump_Count = 0;
			}
			if (Ground_S2(69, 72) && !Collision.Slow && Player.Info().Trans.z != 1)
			{
				Sound.Play(SOUND_LABEL_SE_SLOW);

				Collision.Slow = true;
			}
			if (Collision.Slow)
			{
				Collision.Slow_Count++;
			}
			if (Collision.Slow_Count <= 30 && Collision.Slow)
			{
				Effect.Create(SPEED_SLOW, Player.Info().Trans.x, Player.Info().Trans.y, Player.Info().Trans.z);
				if (Player.Info().Move_Velocity > 0.2)
				{
					Player.F_Velocity(-0.015f);
				}
			}
			if (Collision.Slow_Count > 30 && Collision.Slow)
			{
				Collision.Slow = false;
				Collision.Slow_Count = 0;
			}

			if (Ground_S2(72, 75) && !Collision.Chaos && Player.Info().Trans.z != 1)
			{
				Effect.Create(CHAOS, Player.Info().Trans.x, Player.Info().Trans.y, Player.Info().Trans.z);
				Sound.Play(SOUND_LABEL_SE_CHAOS);

				Collision.Chaos = true;
			}
			if (Collision.Chaos)
			{
				Collision.Chaos_Count++;
			}

			if (Collision.Chaos_Count > 200 && Collision.Chaos)
			{
				Collision.Chaos = false;
				Collision.Chaos_Count = 0;
			}
		}
	}


	{//stage3
		if (Scene.Stage_Type(SCENE_S3))
		{
			if (Hit_Coin(0, COIN_MAX_S3) && Player.Info().Trans.z != 1 && turm < 0)
			{
				turm = 10;
				Sound.Play(SOUND_LABEL_SE_COIN);
				Player.Plus_Boost(100);
			}
			if (Ground_S3(0, 32))
			{
				Player.Gravity(0.1f);
				Collision.Distory = false;
			}
			if (!Ground_S3(0, 32))
			{
				Collision.Distory = true;
			}
			if (Ground_S3(33, 62) && Player.Info().Trans.z != 1
				|| Player.Info().Time_Count / 60 >= 90 && !Collision.GameOver)
			{
				Sound.Stop();
				Effect.Create(DISTROY, Player.Info().Trans.x, Player.Info().Trans.y, Player.Info().Trans.z);
				Sound.Play(SOUND_LABEL_SE_DETAH);
				Collision.GameOver = true;
				Player.Distroy();
			}
			if (Ground_S3(62, 80) && !Collision.Boost && Player.Info().Trans.z != 1)
			{
				if (!Player.Type_Boost())
				{
					Sound.Play(SOUND_LABEL_SE_SPEED);
					Collision.Boost = true;
				}
			}
			if (Collision.Boost)
			{
				Collision.Boost_Count++;
			}
			if (Collision.Boost_Count <= 30 && Collision.Boost)
			{
				Effect.Create(SPEED_UP, Player.Info().Trans.x, Player.Info().Trans.y, Player.Info().Trans.z);

				Player.Position_Z(0.1f);
			}
			if (Collision.Boost_Count > 30 && Collision.Boost)
			{
				Collision.Boost = false;
				Collision.Boost_Count = 0;
			}
			if (Ground_S3(80, 84) && !Collision.Slow && Player.Info().Trans.z != 1)
			{
				Sound.Play(SOUND_LABEL_SE_SLOW);

				Collision.Slow = true;
			}
			if (Collision.Slow)
			{
				Collision.Slow_Count++;
			}
			if (Collision.Slow_Count <= 30 * 2 && Collision.Slow)
			{
				Effect.Create(SPEED_SLOW, Player.Info().Trans.x, Player.Info().Trans.y, Player.Info().Trans.z);
				if (Player.Info().Move_Velocity > 0.2)
				{
					Player.F_Velocity(-0.015f);
				}
			}
			if (Collision.Slow_Count > 30 * 2 && Collision.Slow)
			{
				Collision.Slow = false;
				Collision.Slow_Count = 0;
			}
			if (Ground_S3(84, 85) && !Collision.Chaos && Player.Info().Trans.z != 1)
			{
				Effect.Create(CHAOS, Player.Info().Trans.x, Player.Info().Trans.y, Player.Info().Trans.z);
				Sound.Play(SOUND_LABEL_SE_CHAOS);

				Collision.Chaos = true;
			}
			if (Collision.Chaos)
			{
				Collision.Chaos_Count++;
			}

			if (Collision.Chaos_Count > 300 && Collision.Chaos)
			{
				Collision.Chaos = false;
				Collision.Chaos_Count = 0;
			}

			if (Ground_S3(32, 33) && Player.Info().Trans.z != 1 && !Collision.Goal)
			{
				Sound.Stop();
				Sound.Play(SOUND_LABEL_SE_GOAL);
				Collision.Time_Save[2] = Player.Info().Time_Count / 60;
				Collision.Goal = true;
			}
			if (Collision.Goal)
			{
				Collision.Goal_Count++;
			}
			if (Keyboard.IsPress(DIK_SPACE) && Collision.Goal && Collision.Goal_Count >= 300)
			{
				Sound.Stop();
				Fade_Trigger = true;
			}
			if (Fade_Trigger)
			{
				Fade.Fade_Funtion(true);
				Fade.Fade_Funtion(true);

				if (Fade.Fade_Funtion(true, true) >= 255)
				{
					Fade_Trigger = false;
					Scene.SetNextScene(SCENE_NAME);
				}
			}
		}
    }
}
bool tag_Colision::Hit_Coin(int index_start, int index_end)
{
	bool x = false;
	int a = 0;
	for (int i = index_start; i < index_end; i++)
	{
		D3DXVECTOR3 playerMin = Player.Min();
		D3DXVECTOR3 playerMax = Player.Max();
		D3DXVECTOR3 coinMin = COIN.Coin_Min(i);
		D3DXVECTOR3 coinMax = COIN.Coin_Max(i);
		Collision.Hit = CheckCubelntersection(&playerMin, &playerMax, &coinMin, &coinMax);
		x = Collision.Hit;
		if (x && Player.Info().Trans.z != 1)
		{
			COIN.Dis_Coin(i);
			break;
		}
	}
	return x;
}

bool tag_Colision::Ground_T(int index_start, int index_end)
{
	bool x;
	int a = 0;
	for (int i = index_start; i < index_end; i++)
	{
		D3DXVECTOR3 playerMin = Player.Min();
		D3DXVECTOR3 playerMax = Player.Max();
		D3DXVECTOR3 tutorialMin = TUTORIAL.Min(i);
		D3DXVECTOR3 tutorialMax = TUTORIAL.Max(i);
		Collision.Hit = CheckCubelntersection(&playerMin, &playerMax, &tutorialMin, &tutorialMax);
		x = Collision.Hit;
		if (x)
		{
			break;
		}
	}
	return x;
}

bool tag_Colision::Ground_S1(int index_start,int index_end)
{
	bool x;
//	int a = 0;
	for (int i = index_start; i < index_end; i++)
	{
		D3DXVECTOR3 playerMin = Player.Min();
		D3DXVECTOR3 playerMax = Player.Max();
		D3DXVECTOR3 groundMin = C_Ground.Min(0, i);
		D3DXVECTOR3 groundMax = C_Ground.Max(0, i);
		Collision.Hit = CheckCubelntersection(&playerMin, &playerMax, &groundMin, &groundMax);
		x = Collision.Hit;
		if (x)
		{
			break;
		}
	}
	return x;
}
bool tag_Colision::Ground_S2(int index_start, int index_end)
{
	bool x;
	int a = 0;
	for (int i = index_start; i < index_end; i++)
	{
		D3DXVECTOR3 playerMin = Player.Min();
		D3DXVECTOR3 playerMax = Player.Max();
		D3DXVECTOR3 groundMin = C_Ground.Min(1, i);
		D3DXVECTOR3 groundMax = C_Ground.Max(1, i);
		Collision.Hit = CheckCubelntersection(&playerMin, &playerMax, &groundMin, &groundMax);
		x = Collision.Hit;
		if (x)
		{
			break;
		}
	}
	return x;
}
bool tag_Colision::Ground_S3(int index_start, int index_end)
{
	bool x;
	int a = 0;
	for (int i = index_start; i < index_end; i++)
	{
		D3DXVECTOR3 playerMin = Player.Min();
		D3DXVECTOR3 playerMax = Player.Max();
		D3DXVECTOR3 groundMin = C_Ground.Min(2, i);
		D3DXVECTOR3 groundMax = C_Ground.Max(2, i);
		Collision.Hit = CheckCubelntersection(&playerMin, &playerMax, &groundMin, &groundMax);
		x = Collision.Hit;
		if (x)
		{
			break;
		}
	}
	return x;
}



BOOL tag_Colision::CheckCubelntersection(VECTOR3 *vMin1, VECTOR3 *vMax1, VECTOR3 *vMin2, VECTOR3 *vMax2)
{
	if (vMin1->x <= vMax2->x && vMax1->x >= vMin2->x &&
		vMin1->y <= vMax2->y && vMax1->y >= vMin2->y &&
		vMin1->z <= vMax2->z && vMax1->z >= vMin2->z)
		return TRUE;
	return FALSE;
}
BOOL tag_Colision::CheckSphereIntersect(VECTOR3 vCenter1, float fRadius1, VECTOR3 vCenter2, float fRadius2)
{
	float fDistance;
	VECTOR3 vDiff;
	vDiff = vCenter2 - vCenter1;
	fDistance = D3DXVec3Length(&vDiff);

	if (fDistance <= (fRadius1 + fRadius2))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
//bool tag_Colision::Key_Chaos()
//{
//	return Collision.Chaos;
//}
//bool tag_Colision::Player_Dis()
//{
//	return Collision.Distory;
//}
//bool tag_Colision::Game_Over()
//{
//	return Collision.GameOver;
//}
//bool tag_Colision::Time_Over()
//{
//	return Collision.GameOver = true;
//}
//bool tag_Colision::Jump_UP()
//{
//	return Collision.Jump;
//}
//bool tag_Colision::S1_Goal()
//{
//	return Collision.Goal;
//}
//int tag_Colision::SaveTime(int i)
//{
//	return Collision.Time_Save[i];
//}
//int tag_Colision::gcount()
//{
//	return Collision.Goal_Count;
//}
tag_Colision::collison tag_Colision::Collsion_Info()
{
	return Collision;
}