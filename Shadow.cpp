#include "common.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "mydirect3d.h"
#include "texture.h"
#include "Shadow.h"
#include "sound.h"
#include "Player.h"

void tag_Shadow::Init(void)
{
	g_ShadowFrameCount = 0;
	for (int i = 0; i < PLUSEFFECT_MAX; i++)
	{
		Shadow[i].Position = VECTOR3(0.0f, 0.0f, 0.0f);

		Shadow[i].Texture = Texture.SetLoadFile("Accet/Texture/Missile.jpg", 1, 1);
		Shadow[i].Visivle = false;
		Shadow[i].LifeFrame = 0;
		Shadow[i].SpawnFrame = -1;
		Shadow[i].Showsize = 1;
	}
}

void tag_Shadow::Update(void)
{
	for (int i = 0; i < PLUSEFFECT_MAX; i++)
	{
		if (Shadow[i].Visivle)
		{
	

			int elapsedFrame = g_ShadowFrameCount - Shadow[i].SpawnFrame;

			float e = elapsedFrame / (float)Shadow[i].LifeFrame;

			if (e > 1.0f)
			{
				e = 1.0f;
				Shadow[i].LifeFrame = 0;
				Shadow[i].SpawnFrame = -1;
				Shadow[i].Visivle = false;
			}

			D3DXCOLOR color = Shadow[i].Color;
			color.a = 1.0f - e;
			Shadow[i].Color = color;
		}
	}
	g_ShadowFrameCount++;
}

void tag_Shadow::Draw(void)
{
	m_pd3dDevice = Device.Get();

	//m_pd3dDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);		
	//m_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);	
	//m_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);		
	//m_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
	//m_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	m_pd3dDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_REVSUBTRACT);
	m_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
	m_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	for (int i = 0; i < PLUSEFFECT_MAX; i++)
	{
		if (Shadow[i].Visivle&&Player.Info().Trans.y >= 0.0f)
		{
			Sprite_SetColor(Shadow[i].Color);
			Sprite_Draw_Change(Shadow[i].Texture, Shadow[i].Position.x, Shadow[i].Position.y, Shadow[i].Position.z, 1-Player.Info().Trans.y);
		}
	}
	//Sprite_SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
	m_pd3dDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);		
	m_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);	
	m_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);	
	//m_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
	//m_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	//m_pd3dDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_REVSUBTRACT);
	//m_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
	//m_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
}

void tag_Shadow::Uninit(void)
{
	if (m_pd3dDevice != NULL)
	{
		m_pd3dDevice->Release();
	}
}

void tag_Shadow::Creat(float x, float y,float z,D3DCOLOR color,int lifeframe,float size)
{
	for (int i = 0; i < PLUSEFFECT_MAX; i++)
	{
		if (!Shadow[i].Visivle)
		{
			Shadow[i].Position.x = x + size * (float)cos(g_ShadowFrameCount);
			Shadow[i].Position.y = y;
			Shadow[i].Position.z = z + size * (float)sin(g_ShadowFrameCount);

			Shadow[i].Color = color;
			Shadow[i].LifeFrame = lifeframe;
			Shadow[i].SpawnFrame = g_ShadowFrameCount;
			Shadow[i].Visivle = true;

			break;
		}
	}
}
void tag_Shadow::Sprite_SetColor(D3DCOLOR color)
{
	g_color = color;
}
void tag_Shadow::Sprite_Draw_Change(int textureID, float x, float y, float z,float size)
{
	
	D3DXMATRIX  mtxT,  mtxS, mtxW,mtxR;
	D3DXMatrixTranslation(&mtxT, x, y, z);
	D3DXMatrixScaling(&mtxS, size, size, size);
	D3DXMatrixRotationX(&mtxR, RADIAN(90));
	mtxW = mtxS* mtxR* mtxT ;

	CUBEVERTEX Cube[] = {
		{ VECTOR3(-0.5f,-0.5f,0.0f),g_color,VECTOR2(0.0f,1.0f) },
		{ VECTOR3(-0.5f, 0.5f, 0.0f), g_color, VECTOR2(0.0f,0.0f) },
		{ VECTOR3(0.5f,-0.5f,0.0f),g_color,VECTOR2(1.0f,1.0f) },
		{ VECTOR3(0.5f,0.5f,0.0f),g_color,VECTOR2(1.0f,0.0f) }
	};

	m_pd3dDevice = Device.Get();
	m_pd3dDevice->SetFVF(FVF_PCT);
	m_pd3dDevice->SetTexture(0, Texture.Get(textureID));
	m_pd3dDevice->SetTransform(D3DTS_WORLD, &mtxW);

	m_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Cube, sizeof(CUBEVERTEX));

}