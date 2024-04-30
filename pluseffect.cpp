#include "common.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "mydirect3d.h"
#include "texture.h"
#include "PlusEffect.h"
#include "sound.h"
#include "Player.h"
#include "Plane.h"
static int g_PlusEffectFrameCount = 0;
static float Size = 1.0f;
static 	D3DCOLOR g_color = D3DCOLOR_RGBA(0, 0, 0, 255);
#define FVF_VERTEX3D (D3DFVF_XYZ | D3DFVF_DIFFUSE|D3DFVF_TEX1)
static DEVICE m_pd3dDevice;
static void Sprite_SetColor(D3DCOLOR color);
static void Sprite_Draw_Change(int textureID, float x, float y, float z, float size);
struct pluseffect
{
	int Texture;
	D3DXVECTOR3 Position;
	bool Visivle;
	int LifeFrame;			
	int SpawnFrame;			
	D3DCOLOR Color;
	float Showsize;
};
pluseffect PlusEffect[PLUSEFFECT_MAX] = {};
struct CUBEVERTEX
{
	VECTOR3 Position;
	DWORD color;
	VECTOR2 uv;
};
void PlusEffect_Init(void)
{
	g_PlusEffectFrameCount = 0;
	for (int i = 0; i < PLUSEFFECT_MAX; i++)
	{
		PlusEffect[i].Position = VECTOR3(0.0f, 0.0f, 0.0f);

		PlusEffect[i].Texture = Texture.SetLoadFile("Accet/Texture/Missile.jpg", 1, 1);
		PlusEffect[i].Visivle = false;
		PlusEffect[i].LifeFrame = 0;
		PlusEffect[i].SpawnFrame = -1;
		PlusEffect[i].Showsize = 1;
	}
}

void PlusEffect_Update(void)
{
	for (int i = 0; i < PLUSEFFECT_MAX; i++)
	{
		if (PlusEffect[i].Visivle)
		{

			int elapsedFrame = g_PlusEffectFrameCount - PlusEffect[i].SpawnFrame;

			float e = elapsedFrame / (float)PlusEffect[i].LifeFrame;

			if (e > 1.0f)
			{
				e = 1.0f;
				PlusEffect[i].LifeFrame = 0;
				PlusEffect[i].SpawnFrame = -1;
				PlusEffect[i].Visivle = false;
			}

			D3DXCOLOR color = PlusEffect[i].Color;
			color.a = 1.0f - e;
			PlusEffect[i].Color = color;
			PlusEffect[i].Showsize = 1 - e / 2;
		}
	}
	g_PlusEffectFrameCount++;
}

void PlusEffect_Draw(void)
{
	m_pd3dDevice = Device.Get();

	m_pd3dDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);		
	m_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);	
	m_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);		
	for (int i = 0; i < PLUSEFFECT_MAX; i++)
	{
		if (PlusEffect[i].Visivle)
		{
			Sprite_SetColor(PlusEffect[i].Color);
			Sprite_Draw_Change(PlusEffect[i].Texture, PlusEffect[i].Position.x, PlusEffect[i].Position.y, PlusEffect[i].Position.z, PlusEffect[i].Showsize*Size);

		}
	}
	m_pd3dDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);		
	m_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);	
	m_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
}

void PlusEffect_Uninit(void)
{

}

void PlusEffect_Creat(float x, float y, float z, D3DCOLOR color, int lifeframe, int size)
{
	for (int i = 0; i < PLUSEFFECT_MAX; i++)
	{
		if (!PlusEffect[i].Visivle)
		{
			PlusEffect[i].Position.x = x;
			PlusEffect[i].Position.y = y;
			PlusEffect[i].Position.z = z;
			PlusEffect[i].Color = color;
			PlusEffect[i].LifeFrame = lifeframe;
			PlusEffect[i].SpawnFrame = g_PlusEffectFrameCount;
			PlusEffect[i].Visivle = true;

			break;
		}
	}
}
void Sprite_SetColor(D3DCOLOR color)
{
	g_color = color;
}
void Sprite_Draw_Change(int textureID, float x, float y, float z, float size)
{

	D3DXMATRIX  mtxT, mtxS, mtxW, mtxR;
	D3DXMatrixTranslation(&mtxT, x, y, z);
	D3DXMatrixScaling(&mtxS, size, size, size);
	
	D3DXMatrixRotationY(&mtxR, RADIAN(90));
	mtxW = Plane.Bilboard() *mtxS *mtxT;

	CUBEVERTEX Cube[] = {
		{ VECTOR3(-0.5f,-0.5f,0.1f),g_color,VECTOR2(0.0f,1.0f) },
		{ VECTOR3(-0.5f, 0.5f, 0.1f), g_color, VECTOR2(0.0f,0.0f) },
		{ VECTOR3(0.5f,-0.5f,0.1f),g_color,VECTOR2(1.0f,1.0f) },
		{ VECTOR3(0.5f,0.5f,0.1f),g_color,VECTOR2(1.0f,0.0f) }
	};

	m_pd3dDevice = Device.Get();
	m_pd3dDevice->SetFVF(FVF_VERTEX3D);
	m_pd3dDevice->SetTexture(0, Texture.Get(textureID));
	m_pd3dDevice->SetTransform(D3DTS_WORLD, &mtxW);

	m_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Cube, sizeof(CUBEVERTEX));

}