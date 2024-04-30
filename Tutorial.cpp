#include "common.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "mydirect3d.h"
#include "C_Ground.h"
#include "Player.h"
#include <stdlib.h>
#include <time.h>
#include "Effect.h"
#include "Cube.h"
#include "Plane.h"
#include "Camera.h"
#include "Fade.h"
#include "Scene.h"
#include "TwoD.h"
#include "Number.h"
#include "texture.h"
#include "sound.h"
#include "Tutorial.h"
#include "Collison.h"
#include "sprite.h"
#include "Shadow.h"
//#define FVF_TUTORIAL (D3DFVF_XYZ | D3DFVF_NORMAL| D3DFVF_DIFFUSE |D3DFVF_TEX1)

void tag_Tutorial::Init()
{
	Counter = 0;
	Cube.Init();
	Trans_difference = 0;
	Plane.Init(GROUND);
	Plane.Init(WALL);
	Player.Init();
	Camera.Init();
	Colision.Init();	
	Effect.Init();
	TwoD.Init();
	Shadow.Init();
	m_pd3dDevice = Device.Get();
	D3DXCreateBox(m_pd3dDevice, 1.0f, 1.0f, 1.0f, &m_pBox, NULL);
	VECTOR3 *pVertices;
	m_pBox->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVertices);
	D3DXComputeBoundingBox(pVertices, m_pBox->GetNumVertices(), m_pBox->GetNumBytesPerVertex(), &m_Min, &m_Max);
	m_pBox->UnlockVertexBuffer();
	Fade_Counter = false;
	Ground_T[0].Trans = VECTOR3(0.0f, 0.0f, 700.0f);
	Ground_T[0].Scale = VECTOR3(5.0f, 0.1f, 1400.0f);

	Ground_T[1].Trans = VECTOR3(0.0f, 0.0f, 100.0f);//fast
	Ground_T[1].Scale = VECTOR3(5.0f, 0.1f, 35.0f);

	Ground_T[2].Trans = VECTOR3(0.0f, 0.0f, 300.0f);//slow
	Ground_T[2].Scale = VECTOR3(5.0f, 0.1f, 35.0f);

	Ground_T[3].Trans = VECTOR3(0.0f, 0.0f, 500.0f);//chaos
	Ground_T[3].Scale = VECTOR3(5.0f, 0.1f, 35.0f);

	Ground_T[4].Trans = VECTOR3(0.0f, 2.0f, 700.0f);//jump
	Ground_T[4].Scale = VECTOR3(5.0f, 5.0f, 1.0f);

	Ground_T[5].Trans = VECTOR3(-5.0f, 2.5f, 800.0f);
	Ground_T[5].Scale = VECTOR3(5.0f, 5.0f, 0.1f);

	Ground_T[6].Trans = VECTOR3(-5.0f, 2.5f, 900.0f);
	Ground_T[6].Scale = VECTOR3(5.0f, 5.0f, 0.1f);

	Ground_T[7].Trans = VECTOR3(5.0f, 2.5f, 800.0f);
	Ground_T[7].Scale = VECTOR3(5.0f, 5.0f, 0.1f);

	Ground_T[8].Trans = VECTOR3(5.0f, 2.5f, 900.0f);
	Ground_T[8].Scale = VECTOR3(5.0f, 5.0f, 0.1f);
	Texture.Load(hWnd);

}
void tag_Tutorial::Update()
{
	TwoD.Update();
	Camera.Update();
	Plane.Update();
	Player.Update();
	Shadow.Update();
	Effect.Update();
	Colision.Update();
	Trans_difference = 1000 - Player.Info().Trans.z;

	if (!Fade_Counter)
	{
		Fade.Fade_Funtion(false);
	}

	if (Player.Info().Trans.z >= 1350)
	{
		Fade_Counter = true;
	}
	if (Fade_Counter)
	{
		
		Fade.Fade_Funtion(true);
		if (Fade.Fade_Funtion(false,true) >= 255)
		{
			Sound.Stop();
			Scene.SetNextScene(SCENE_TITLE);
		}
	}
}
void tag_Tutorial::Draw()
{	
	TwoD.Draw();

	for (int i = 0; i < 9; i++)
	{
		Sprite_Ground(i);
	}
	Cube.Draw(7, Ground_T[0].Scale.x, Ground_T[0].Scale.y, Ground_T[0].Scale.z, Ground_T[0].Trans.x, Ground_T[0].Trans.y, Ground_T[0].Trans.z);
	Plane.Draw(GROUND, 3, Ground_T[1].Trans.x, Ground_T[1].Trans.y, Ground_T[1].Trans.z, Ground_T[1].Scale.x, Ground_T[1].Scale.y, Ground_T[1].Scale.z);
	Plane.Draw(GROUND, 4, Ground_T[2].Trans.x, Ground_T[2].Trans.y, Ground_T[2].Trans.z, Ground_T[2].Scale.x, Ground_T[2].Scale.y, Ground_T[2].Scale.z);
	Plane.Draw(GROUND, 2, Ground_T[3].Trans.x, Ground_T[3].Trans.y, Ground_T[3].Trans.z, Ground_T[3].Scale.x, Ground_T[3].Scale.y, Ground_T[3].Scale.z);
	Plane.Draw(WALL, 2, Ground_T[4].Trans.x, Ground_T[4].Trans.y, Ground_T[4].Trans.z, Ground_T[4].Scale.x, Ground_T[4].Scale.y, Ground_T[4].Scale.z);
	for (int i = 5; i < 9; i++)
	{
		Plane.Draw(WALL, 0, Ground_T[i].Trans.x, Ground_T[i].Trans.y, Ground_T[i].Trans.z, Ground_T[i].Scale.x, Ground_T[i].Scale.y, Ground_T[i].Scale.z);

	}
	Effect.Draw();
	Player.Draw();
	Shadow.Draw();
	TwoD.T_Draw();
	//Number.Draw(Player.Info().Time_Count / 90, 30, 30, 600,2);
	TwoD.Tex_Draw();
}

void tag_Tutorial::Uninit()
{
	if (m_pd3dDevice != NULL)
	{
		m_pd3dDevice->Release();
	}
	if (m_pBox != NULL)
	{
		m_pBox->Release();
	}
}

void tag_Tutorial::Sprite_Ground(int index)
{
	m_pd3dDevice = Device.Get();
	m_pd3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	MATRIX World, Trans, Scale;
	D3DXMatrixTranslation(&Trans, Ground_T[index].Trans.x, Ground_T[index].Trans.y, Ground_T[index].Trans.z);
	D3DXMatrixScaling(&Scale, Ground_T[index].Scale.x, Ground_T[index].Scale.y, Ground_T[index].Scale.z);
	World = Scale * Trans;
	D3DXVec3TransformCoord(&Ground_T[index].Min, &m_Min, &World);
	D3DXVec3TransformCoord(&Ground_T[index].Max, &m_Max, &World);
	m_pd3dDevice->SetTransform(D3DTS_WORLD, &World);
	//m_pBox->DrawSubset(0);
	m_pd3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
}

tag_Tutorial::ground tag_Tutorial::Ground_T_Info(int index)
{
	return Ground_T[index];
}



VECTOR3 tag_Tutorial::Min(int index)
{
	return Ground_T[index].Min;
}
VECTOR3 tag_Tutorial::Max(int index)
{
	return Ground_T[index].Max;
}

float tag_Tutorial::difference()
{
	return Trans_difference;
}