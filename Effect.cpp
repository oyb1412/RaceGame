#include <d3d9.h>
#include <tchar.h>
#include <d3dx9.h>
#include "texture.h"
#include "sound.h"
#include "common.h"
#include "mydirect3d.h"
#include "Player.h"
#include "Effect.h"
#include "Plane.h"
#include "Title.h"
#include "Scene.h"

void tag_Effect::Init(void)
{
		Tex[1] = Texture.SetLoadFile("Accet/Texture/Speed_Up.png", 1, 1);
		Tex[2] = Texture.SetLoadFile("Accet/Texture/Speed_Slow.png", 1, 1);
		Tex[3] = Texture.SetLoadFile("Accet/Texture/Gyaku.png", 1, 1);
		Tex[4] = Texture.SetLoadFile("Accet/Texture/Jump.png", 1, 1);
		Tex[5] = Texture.SetLoadFile("Accet/Texture/Distroy.png", 1, 1);
		Tex[6] = Texture.SetLoadFile("Accet/Texture/Boost_Effect.png", 1, 1);
	Speed_Up.Visible = false;
	Speed_Up.Speed = 0;
	Speed_Up.Position = VECTOR3(0.0f, 0.0f, 0.0f);
	Speed_Slow.Visible = false;
	Speed_Slow.Speed = 0;
	Speed_Slow.Position = VECTOR3(0.0f, 0.0f, 0.0f);
	Chaos.Visible = false;
	Chaos.Speed = 0;
	Chaos.Position = VECTOR3(0.0f, 0.0f, 0.0f);
	Jump.Visible = false;
	Jump.Speed = 0;
	Jump.Position = VECTOR3(0.0f, 0.0f, 0.0f);
	Distroy.Visible = false;
	Distroy.Speed = 0;
	Distroy.Position = VECTOR3(0.0f, 0.0f, 0.0f);
	Boost.Visible = false;
	Boost.Speed = 0;
	Boost.Position = VECTOR3(0.0f, 0.0f, 0.0f);

}
void tag_Effect::Update(void)
{
	
	if (Speed_Up.Visible)
	{
		Speed_Up.Speed += 1;
	}
	if (Speed_Up.Speed >= 40)
	{
		Speed_Up.Visible = false;
	}
	if (Speed_Slow.Visible)
	{
		Speed_Slow.Speed += 1;
	}
	if (Scene.Stage_Type(SCENE_S3))
	{
		if (Speed_Slow.Speed >= 20)
		{
			Speed_Slow.Visible = false;
		}
	}
	else
	{
		if (Speed_Slow.Speed >= 40)
		{
			Speed_Slow.Visible = false;
		}
	}
	if (Chaos.Visible)
	{
		Chaos.Speed += 1;
	}	

	if (Chaos.Speed >= 40)
	{
		Chaos.Visible = false;
	}
	if (Jump.Visible)
	{
		Jump.Speed += 1;
	}
	if (Jump.Speed >= 40)
	{
		Jump.Visible = false;
	}
	

	if (Distroy.Visible)
	{
		Distroy.Speed += 1;
	}
	if (Distroy.Speed >= 40)
	{
		Distroy.Visible = false;
	}

	if (Boost.Visible)
	{
		Boost.Speed += 1;
	}
	if (Boost.Speed >= 40)
	{
		Boost.Visible = false;
	}
}

void tag_Effect::Create(effect_tag Type, float x, float y, float z)
{
	if (Type == SPEED_UP)
	{
		if (!Speed_Up.Visible)
		{
			Speed_Up.Position.x = x;
			Speed_Up.Position.y = y;
			Speed_Up.Position.z = z;
			Speed_Up.Visible = true;
			Speed_Up.Speed = 0;
		}
	}
	if (Type == BOOST)
	{
		if (!Boost.Visible)
		{
			Boost.Position.x = x;
			Boost.Position.y = y;
			Boost.Position.z = z;
			Boost.Visible = true;
			Boost.Speed = 0;
		}
	}
	if (Type ==SPEED_SLOW)
	{
		if (!Speed_Slow.Visible)
		{
			Speed_Slow.Position.x = x;
			Speed_Slow.Position.y = y;
			Speed_Slow.Position.z = z;
			Speed_Slow.Visible = true;
			Speed_Slow.Speed = 0;

		}
	}
	if (Type == CHAOS)
	{
		if (!Chaos.Visible)
		{
			Chaos.Position.x = x;
			Chaos.Position.y = y;
			Chaos.Position.z = z;
			Chaos.Visible = true;
			Chaos.Speed = 0;
		}
	}

	if (Type == JUMP)
	{
		if (!Jump.Visible)
		{
			Jump.Position.x = x;
			Jump.Position.y = y;
			Jump.Position.z = z;
			Jump.Visible = true;
			Jump.Speed = 0;
		}
	}

	if (Type == DISTROY)
	{
		if (!Distroy.Visible)
		{
			Distroy.Position.x = x;
			Distroy.Position.y = y;
			Distroy.Position.z = z;
			Distroy.Visible = true;
			Distroy.Speed = 0;
		}
	}
}





void tag_Effect::Effectdraw(int tex, float x, float y, float z, float scaling, int speed, int RenderSpeed, int Widht, int Length)
{
	float cutU = (float)1 / (float)Widht ;
	float cutV = (float)1 / (float)Length;
	int X = (speed / RenderSpeed) % Widht;
	int Y = (speed / (RenderSpeed * Widht)) % Length;
	Sprite_Draw(tex, x, y, z, scaling, cutU * X, cutV * Y, cutU, cutV);
}
void tag_Effect::Draw(void)
{
	if (Scene.Stage_Type(SCENE_S1) || Scene.Stage_Type(SCENE_S2) || Scene.Stage_Type(SCENE_S3) || Scene.Stage_Type(SCENE_TUTORIAL))
	{
		if (Speed_Up.Visible)
		{
			Effectdraw(1, Player.Info().Trans.x, Player.Info().Trans.y, Player.Info().Trans.z, 4.0f, Speed_Up.Speed, 2, 5, 4);
		}
	}
	if (Speed_Slow.Visible)
	{
		Effectdraw(2, Player.Info().Trans.x, Player.Info().Trans.y, Player.Info().Trans.z, 5.0f, Speed_Slow.Speed, 2, 5, 4);

	}
	if (Chaos.Visible)
	{
		Effectdraw(3, Player.Info().Trans.x, Player.Info().Trans.y, Player.Info().Trans.z, 5.0f, Chaos.Speed, 3, 5, 3);

	}
	if (Jump.Visible)
	{
		Effectdraw(4, Player.Info().Trans.x, Player.Info().Trans.y, Player.Info().Trans.z, 5.0f, Jump.Speed, 2, 5, 4);

	}

	if (Distroy.Visible)
	{
		Effectdraw(5, Player.Info().Trans.x, Player.Info().Trans.y, Player.Info().Trans.z, 4.0f, Distroy.Speed, 5, 2, 4);

	}

	if (Boost.Visible)
	{
		Effectdraw(6, Player.Info().Trans.x, Player.Info().Trans.y, Player.Info().Trans.z, 5.0f, Boost.Speed, 2, 5, 4);

	}
}


void tag_Effect::Sprite_Draw(int textureID, float x, float y,float z,float size, float cut_x, float cut_y, float cut_w, float cut_h)
{

	m_pd3dDevice = Device.Get();
	float u0 = cut_x ;
	float v0 = cut_y ;
	float u1 = (cut_x + cut_w) ;
	float v1 = (cut_y + cut_h) ;

	CUBEVERTEX Cube[] = {
		{ VECTOR3(-0.5f, 0.5f, 0.0f), D3DCOLOR_RGBA(255, 255, 255, 255), VECTOR2(u0,v0)},
		{ VECTOR3(0.5f,0.5f,0.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(u1,v0) },
		{ VECTOR3(-0.5f,-0.5f,0.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(u0,v1) },
		{ VECTOR3(0.5f,-0.5f,0.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(u1,v1) }
	};


	m_pd3dDevice->SetFVF(FVF_PCT);
	m_pd3dDevice->SetTexture(0, Texture.Get(Tex[textureID]));
	MATRIX matTrans, matWorld, matScal;
	MatTrans(&matTrans,x, y, z);
	MatScaling(&matScal, size, size, size);
	matWorld = Plane.Bilboard() * matScal*matTrans;
	m_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
	m_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Cube, sizeof(CUBEVERTEX));
}

void tag_Effect::Uninit()
{
	if (m_pd3dDevice != NULL)
	{
		m_pd3dDevice->Release();
	}
	if (m_pIB != NULL)
	{
		m_pIB->Release();
	}
	if (m_pVB != NULL)
	{
		m_pVB->Release();
	}
}