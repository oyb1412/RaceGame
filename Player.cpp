#include "common.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "input.h"
#include "C_Ground.h"
#include "texture.h"
#include "sound.h"
#include "mydirect3d.h"
#include "Player.h"
#include "Scene.h"
#include "Collison.h"
#include "Effect.h"
#include "Mesh.h"
#include "Shadow.h"
#include "Scene.h"
#include "TwoD.h"
#include "Collison.h"
#include "pluseffect.h"

#define SPEED 0.015
void tag_Player::Init()
{
	Velocity = 0.0f;
	Boost_Count = 0;
	Player_Struct.Boost_Gage = 0;
	Move_Speed = 0.0f;
	Grabity_Speed = 0.0f;
	Boost = false;
	if (Scene.Stage_Type(SCENE_S1))
	{
		Grabity_Velocity = 0.013f;
	}
	else
	{
		Grabity_Velocity = 0.01f;
	}
	g_vecFront =VECTOR3(0.0f, 0.0f, 0.1f);
	g_vecRight = VECTOR3(0.02f, 0.0f, 0.0f);
	Jump = true;
	Jump_Velocity = 0.01f;
	Jump_Type = 1;
	Player_Struct.Move_Velocity = 0.0f;
	vecDir = VECTOR3(0.0f, 0.0f, 0.0f);
	vecUp = VECTOR3(0.0f, 1.0f, 0.0f);
	Speed = 0.0f;
	Jump_up = 0.0f;
	Player_Struct.Start_Count = 0;
	Player_Struct.Time_Count = 0;
	Jump_Sound = false;
	Start_Sound = false;
	Jump_Speed = 0.0f;
	Start_Bgm = false;
	Plus_MaxSpeed = 0.0f;
	//Player.Trans = VECTOR3(0.0f, 1.6f, 2100.0f); 
	Player_Struct.Trans = VECTOR3(0.0f, 1.6f, 1.0f);

	Player_Struct.Scale = VECTOR3(0.5f, 0.5f, 0.5f);
	Player_Struct.Life = true;
	
		m_pd3dDevice = Device.Get();
		D3DXCreateBox(m_pd3dDevice, 1.0f, 1.0f, 1.0f, &m_pBox, NULL);

		VECTOR3 *pVertices;
		m_pBox->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVertices);
		D3DXComputeBoundingBox(pVertices, m_pBox->GetNumVertices(), m_pBox->GetNumBytesPerVertex(), &m_Min, &m_Max);
		m_pBox->UnlockVertexBuffer();

		Mesh.Set("Accet/Mesh/space ship .blend.x", 1);
	
}

void tag_Player::Update()
{
	//if (MouseInput.PushLeft())
	//{
	//	Player_Struct.Trans.x += 0.2f;
	//}
	if (Player_Struct.Trans.y >= 0.0f)
	{
		Shadow.Creat(Player_Struct.Trans.x, 0.01f, Player_Struct.Trans.z, D3DCOLOR_RGBA(255, 255, 255, 255), 1, 0.0f);
	}

	if (!Start_Sound && !Scene.Stage_Type(SCENE_TUTORIAL))
	{
		Sound.Play(SOUND_LABEL_SE_START);
		Start_Sound = true;
	}
	if (Player_Struct.Start_Count < 310)
	{
		Player_Struct.Start_Count++;
	}
	if (!Player_Struct.Life)
	{
		//StopSound();
	}
	if (Player_Struct.Start_Count >= 180)
	{
		if (!Start_Bgm)
		{
			if (Scene.Stage_Type(SCENE_S1))
			{
				Sound.Play(SOUND_LABEL_GAMEBGM);
			}
			else if (Scene.Stage_Type(SCENE_S2))
			{
				Sound.Play(SOUND_LABEL_S2BGM);
			}
			else if (Scene.Stage_Type(SCENE_S3))
			{
				Sound.Play(SOUND_LABEL_S3BGM);
			}
			else if (Scene.Stage_Type(SCENE_TUTORIAL))
			{
				Sound.Play(SOUND_LABEL_TBGM);
			}
			Start_Bgm = true;
		}
		if (Colision.Collsion_Info().Jump)
		{
			if (Scene.Stage_Type(SCENE_S1))
			{
				Jump_up = 0.07f;
			}
			else
			{
				Jump_up = 0.07f;
			}
		}
		if(Jump_up > 0.0)
		{
			Jump_up -= 0.001f;
		}
		if (Colision.Collsion_Info().GameOver)
		{
			Player_Struct.Life = false;
		}
		if (Player_Struct.Trans.y <= -10 && Player_Struct.Life)
		{
			Sound.Stop();
			Sound.Play(SOUND_LABEL_SE_DETAH);
			Effect.Create(DISTROY, Player_Struct.Trans.x, Player_Struct.Trans.y, Player_Struct.Trans.z);
			Player_Struct.Life = false;
		}
		if (!Player_Struct.Life)
		{

		}
		if (Player_Struct.Life)
		{
			{
				Player_Struct.Trans.y -= 0.1f;
			}
			if (Player_Struct.Move_Velocity > 0.0f)
			{
				Player_Struct.Move_Velocity -= 0.001f;
			}
			if (Player_Struct.Move_Velocity <= 0)
			{
				Player_Struct.Move_Velocity = 0;
			}
			Normal3(&vecDir, &vecDir);
			if (!Colision.Collsion_Info().Goal)
			{
				if (Speed >= 1.8f)
				{
					Speed = 1.8f;
				}
					Player_Struct.Trans.z+= vecDir.z * (Player_Struct.Move_Velocity + Speed);
					//Player_Struct.Trans.x+= vecDir.x*0.8;
					if (Scene.Stage_Type(SCENE_S2))
					{
						Player_Struct.Time_Count+=2;
					}
					else
					{
						Player_Struct.Time_Count++;
					}
		

				if (Keyboard.IsPress(DIK_DOWN)&& Player_Struct.Move_Velocity > 0)
				{
					Player_Struct.Move_Velocity -= 0.003f;
				}

				if (Keyboard.IsPress(DIK_SPACE) && Player_Struct.Boost_Gage >= 600 && !Boost && !Colision.Collsion_Info().Boost)
				{
					Sound.Play(SOUND_LABEL_SE_SPEED);
					Boost = true;
					Player_Struct.Boost_Gage = 0;
				}
				if (Boost)
				{
					Boost_Count++;
				}
				if (Boost_Count <= 40 && Boost)
				{
					Effect.Create(BOOST, Player_Struct.Trans.x, Player_Struct.Trans.y, Player_Struct.Trans.z);
					Position_Z(0.1f);
				}
				if (Boost_Count > 40 && Boost)
				{
					Boost = false;
					Boost_Count = 0;
				}
				if (Player_Struct.Boost_Gage >= 600)
				{
					Player_Struct.Boost_Gage = 600;
				}
				if (Scene.Stage_Type(SCENE_TUTORIAL))
				{
					if (Keyboard.IsPress(DIK_UP) && TwoD.Count() > 400 && Player_Struct.Boost_Gage <= 600)
					{
						Player_Struct.Move_Velocity += 0.003f;
						vecDir = g_vecFront;
						if (!Boost && Player_Struct.Start_Count >= 180)
						{
							Player_Struct.Boost_Gage++;
						}
					}
					if (Keyboard.IsPress(DIK_RIGHT) && Keyboard.IsPress(DIK_UP) && !Colision.Collsion_Info().Chaos && Player_Struct.Trans.x <= 2.5)
					{
						Player_Struct.Trans.x += 0.2f;
					}
					if (Keyboard.IsPress(DIK_LEFT) && Keyboard.IsPress(DIK_UP) && !Colision.Collsion_Info().Chaos && Player_Struct.Trans.x >= -2.5)
					{
						Player_Struct.Trans.x -= 0.2f;
					}
					if (Keyboard.IsPress(DIK_RIGHT) && Keyboard.IsPress(DIK_UP) && Colision.Collsion_Info().Chaos && Player_Struct.Trans.x >= -2.5)
					{
						Player_Struct.Trans.x -= 0.2f;
					}
					if (Keyboard.IsPress(DIK_LEFT) && Keyboard.IsPress(DIK_UP) && Colision.Collsion_Info().Chaos && Player_Struct.Trans.x <= 2.5)
					{
						Player_Struct.Trans.x += 0.2f;
					}

				}
				else if (Scene.Stage_Type(SCENE_S1) || Scene.Stage_Type(SCENE_S2) || Scene.Stage_Type(SCENE_S3))
				{
					if (Keyboard.IsPress(DIK_UP) && Player_Struct.Boost_Gage <= 600)
					{
						Player_Struct.Move_Velocity += 0.003f;
						vecDir = g_vecFront;
						if (!Boost && Player_Struct.Start_Count >= 180)
						{
							Player_Struct.Boost_Gage++;
						}
					}
					if (Keyboard.IsPress(DIK_RIGHT) /*&& Keyboard.IsPress(DIK_UP)*/ && !Colision.Collsion_Info().Chaos)
					{
						Player_Struct.Trans.x += 0.2f;
					}
					if (Keyboard.IsPress(DIK_LEFT)/* && Keyboard.IsPress(DIK_UP)*/ && !Colision.Collsion_Info().Chaos)
					{
						Player_Struct.Trans.x -= 0.2f;
					}
					if (Keyboard.IsPress(DIK_RIGHT) && Keyboard.IsPress(DIK_UP) && Colision.Collsion_Info().Chaos)
					{
						Player_Struct.Trans.x -= 0.2f;

					}
					if (Keyboard.IsPress(DIK_LEFT) && Keyboard.IsPress(DIK_UP) && Colision.Collsion_Info().Chaos)
					{
						Player_Struct.Trans.x += 0.2f;
					}
				}
			}
			if (Colision.Collsion_Info().Goal)
			{
				Player_Struct.Move_Velocity = 1.0f;
				Speed = 0.0f;
				Jump_up = 0.0f;
			
			}
			if (Speed > 0)
			{
				Speed -= 0.05f;
			}
		

			if (Player_Struct.Move_Velocity > 0.8f)
			{
				Player_Struct.Move_Velocity = 0.8f;
			}

			if (Jump && Jump_Type == 1 && !Colision.Collsion_Info().Goal)
			{
				Player_Struct.Trans.y += Jump_Speed + 0.1f + Jump_up;
				if (Player_Struct.Trans.y > 0 && !Colision.Collsion_Info().Goal)
				{
					Jump_Speed -= Grabity_Velocity;
					Jump_Sound = false;
				}
				if (Player_Struct.Trans.y <= 0 &&!Colision.Collsion_Info().Goal)
				{
					Jump_Speed = (0 - Jump_Speed);
					if (!Jump_Sound)
					{
						Sound.Play(SOUND_LABEL_SE_JUMP);
						Jump_Sound = true;
					}
				}
				if (Player_Struct.Trans.y <= 0 && Colision.Collsion_Info().Distory)
				{
					Jump_Speed = -0.2f;
				}
				if (Colision.Collsion_Info().Goal&&Player_Struct.Trans.y > 0.1f)
				{
					Player_Struct.Trans.y -= 0.1f;
					if (Player_Struct.Trans.y <= 0.1f)
					{
						Player_Struct.Trans.y = 0.1f;
					}
				}
			}
		}
	}
	if(!Colision.Collsion_Info().Goal && Player_Struct.Life && Player_Struct.Start_Count >=180 && !Boost && !Colision.Collsion_Info().Boost && !Colision.Collsion_Info().Slow)
	PlusEffect_Creat(Player_Struct.Trans.x, Player_Struct.Trans.y, Player_Struct.Trans.z, D3DCOLOR_XRGB(240, 255, 255), 20, 60);
	
	if(Boost)
	PlusEffect_Creat(Player_Struct.Trans.x, Player_Struct.Trans.y, Player_Struct.Trans.z, D3DCOLOR_XRGB(255, 0, 0), 70, 100);

	if (Colision.Collsion_Info().Boost)
	PlusEffect_Creat(Player_Struct.Trans.x, Player_Struct.Trans.y, Player_Struct.Trans.z, D3DCOLOR_XRGB(0, 0, 255), 70, 100);

}

void tag_Player::Uninit()
{
	if (m_pd3dDevice != NULL)
	{
		m_pd3dDevice->Release();
	}
	if (m_pSpeher != NULL)
	{
		m_pSpeher->Release();
	}
	if (m_pBox != NULL)
	{
		m_pBox->Release();
	}
}



void tag_Player::Draw()
{
	m_pd3dDevice = Device.Get();
	//m_pd3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);

	MATRIX matWorld, matTrans, matScale, matRotation;
	D3DXMatrixTranslation(&matTrans, Player_Struct.Trans.x, Player_Struct.Trans.y, Player_Struct.Trans.z);
	D3DXMatrixScaling(&matScale, Player_Struct.Scale.x, Player_Struct.Scale.y, Player_Struct.Scale.z);
	matWorld = matScale * matTrans;
	D3DXVec3TransformCoord(&Player_Struct.Min, &m_Min, &matWorld);
	D3DXVec3TransformCoord(&Player_Struct.Max, &m_Max, &matWorld);
	//m_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
	if (Player_Struct.Life)
	{
		//m_pBox->DrawSubset(0);
		Mesh.Create(1, Player_Struct.Trans.x, Player_Struct.Trans.y, Player_Struct.Trans.z, 0.0f, 0.07f, 0.07f, 0.07f);
	}
	m_pd3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);

}

float tag_Player::PlusSpeed(float index)
{
	return Plus_MaxSpeed+=index;
}
VECTOR3 tag_Player::Min()
{
	return  Player_Struct.Min;
}
VECTOR3 tag_Player::Max()
{
	return Player_Struct.Max;
}
float tag_Player::Gravity(float index)
{
	return Player_Struct.Trans.y += index;
}
bool tag_Player::Distroy()
{
	return Player_Struct.Life = false;
}

player tag_Player::Info()
{
	return Player_Struct;
}
float tag_Player::Position_Z(float index)
{
	return Speed += index;
}
float tag_Player::F_Velocity(float index)
{
	return Player_Struct.Move_Velocity+=index;
}
int tag_Player::Plus_Boost(int index)
{
	return Player_Struct.Boost_Gage += index;
}
bool tag_Player::Type_Boost()
{
	return Boost;
}
float tag_Player::hyouji_speed()
{
	return Speed;
}