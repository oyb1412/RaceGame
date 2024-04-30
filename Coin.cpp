#include <d3dx9.h>
#include "Coin.h"
#include "texture.h"
#include "mydirect3d.h"
#include "Plane.h"
#include <time.h>
#include "Light.h"
void tag_coin::Init(SCENE Type)
{
	Tex[0] = Texture.SetLoadFile("Accet/Texture/Coin.png", 1, 1);
	Tex[1] = Texture.SetLoadFile("Accet/Texture/11.png", 1, 1);

	m_pd3dDevice = Device.Get();
	D3DXCreateBox(m_pd3dDevice, 1.0f, 1.0f, 1.0f, &m_pBox, NULL);
	VECTOR3* pVertices;
	m_pBox->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVertices);
	D3DXComputeBoundingBox(pVertices, m_pBox->GetNumVertices(), m_pBox->GetNumBytesPerVertex(), &m_Min, &m_Max);
	m_pBox->UnlockVertexBuffer();
	srand((unsigned int)time(NULL));

	if (Type == SCENE_S1)
	{
		for (int i = 0; i < COIN_MAX_S1; i++)
		{
			Coin[i].Life = true;
			Coin[i].Speed = 0;
			Coin[i].Scale = VECTOR3(4.0f, 4.0f, 4.0f);
			Coin[i].Trans = VECTOR3(4.0f, 50.0f, 4.0f);
		}

		Coin[0].Trans = VECTOR3(-6.0f, 1.5f,25.0f);

		Coin[1].Trans = VECTOR3(6.0f, 1.5f, 25.0f);

		Coin[2].Trans = VECTOR3(-6.0f, 1.5f, 55.0f);

		Coin[3].Trans = VECTOR3(6.0f, 1.5f, 55.0f);

		Coin[4].Trans = VECTOR3(-6.0f, 1.5f, 150.0f);

		Coin[5].Trans = VECTOR3(6.0f, 1.5f, 150.0f);

		Coin[6].Trans = VECTOR3(-6.0f, 1.5f, 190.0f);

		Coin[7].Trans = VECTOR3(6.0f, 1.5f, 190.0f);

		Coin[8].Trans = VECTOR3(0.0f, 1.5f, 80.0f);

		Coin[9].Trans = VECTOR3(0.0f, 1.5f, 155.0f);

		Coin[10].Trans = VECTOR3(0.0f, 1.5f, 160.0f);

		Coin[11].Trans = VECTOR3(0.0f, 1.5f, 165.0f);

		Coin[12].Trans = VECTOR3(-6.0f, 1.5f, 250.0f);

		Coin[13].Trans = VECTOR3(6.0f, 1.5f, 250.0f);

		Coin[14].Trans = VECTOR3(0.0f, 1.5f, 300.0f);

		Coin[15].Trans = VECTOR3(0.0f, 1.5f, 310.0f);

		Coin[16].Trans = VECTOR3(0.0f, 1.5f, 320.0f);

		Coin[17].Trans = VECTOR3(0.0f, 1.5f, 330.0f);

		Coin[18].Trans = VECTOR3(0.0f, 1.5f, 340.0f);

		Coin[19].Trans = VECTOR3(0.0f, 1.5f, 450.0f);

		Coin[20].Trans = VECTOR3(0.0f, 1.5f, 460.0f);

		Coin[21].Trans = VECTOR3(0.0f, 1.5f, 470.0f);

		Coin[22].Trans = VECTOR3(0.0f, 1.5f, 480.0f);

		Coin[23].Trans = VECTOR3(0.0f, 1.5f, 490.0f);

		Coin[24].Trans = VECTOR3(-3.0f, 1.5f, 600.0f);

		Coin[25].Trans = VECTOR3(3.0f, 1.5f, 600.0f);

		Coin[26].Trans = VECTOR3(-3.0f, 1.5f, 630.0f);

		Coin[27].Trans = VECTOR3(3.0f, 1.5f, 630.0f);

		Coin[28].Trans = VECTOR3(-3.0f, 1.5f, 660.0f);

		Coin[29].Trans = VECTOR3(3.0f, 1.5f, 660.0f);

		Coin[30].Trans = VECTOR3(-11.0f, 1.5f,760.0f);

		Coin[31].Trans = VECTOR3(11.0f, 1.5f, 760.0f);

		Coin[32].Trans = VECTOR3(-16.0f, 1.5f, 835.0f);

		Coin[33].Trans = VECTOR3(16.0f, 1.5f, 835.0f);

		Coin[34].Trans = VECTOR3(-2.0f, 1.5f, 930.0f);

		Coin[35].Trans = VECTOR3(2.0f, 1.5f, 950.0f);

		Coin[36].Trans = VECTOR3(-2.0f, 1.5f, 970.0f);

		Coin[37].Trans = VECTOR3(2.0f, 1.5f, 990.0f);

		Coin[38].Trans = VECTOR3(-2.0f, 1.5f, 1010.0f);

		Coin[39].Trans = VECTOR3(2.0f, 1.5f, 1030.0f);

		Coin[40].Trans = VECTOR3(-2.0f, 1.5f, 1050.0f);
	}
	if (Type == SCENE_S2)
	{
		for (int i = 0; i < COIN_MAX_S2; i++)
		{
			Coin[i].Life = true;
			Coin[i].Speed = 0;
			Coin[i].Scale = VECTOR3(4.0f, 4.0f, 4.0f);
			Coin[i].Trans = VECTOR3(4.0f, 50.0f, 4.0f);
		}
		Coin[0].Trans = VECTOR3(0.0f, 2.0f, 70.0f);
		Coin[1].Trans = VECTOR3(0.0f, 2.0f, 150.0f);
		Coin[2].Trans = VECTOR3(0.0f, 2.0f, 230.0f);
		Coin[3].Trans = VECTOR3(-4.0f, 2.0f, 300.0f);
		Coin[4].Trans = VECTOR3(4.0f, 2.0f, 300.0f);
		Coin[5].Trans = VECTOR3(-4.0f, 2.0f, 380.0f);
		Coin[6].Trans = VECTOR3(4.0f, 2.0f, 380.0f);
		Coin[7].Trans = VECTOR3(-4.0f, 2.0f, 460.0f);
		Coin[8].Trans = VECTOR3(4.0f, 2.0f, 460.0f);
		Coin[9].Trans = VECTOR3(-4.0f, 2.0f, 540.0f);
		Coin[10].Trans = VECTOR3(4.0f, 2.0f, 540.0f);
		Coin[11].Trans = VECTOR3(-4.0f, 2.0f, 620.0f);
		Coin[12].Trans = VECTOR3(4.0f, 2.0f, 620.0f);
		Coin[13].Trans = VECTOR3(-4.0f, 2.0f,700.0f);
		Coin[14].Trans = VECTOR3(4.0f, 2.0f, 700.0f);
		Coin[15].Trans = VECTOR3(-4.0f, 2.0f, 780.0f);
		Coin[16].Trans = VECTOR3(4.0f, 2.0f, 780.0f);
		Coin[17].Trans = VECTOR3(0.0f, 2.0f, 920.0f);
		Coin[18].Trans = VECTOR3(0.0f, 2.0f, 930.0f);
		Coin[19].Trans = VECTOR3(0.0f, 2.0f, 940.0f);

		Coin[20].Trans = VECTOR3(0.0f, 2.0f, 1050.0f);

		Coin[21].Trans = VECTOR3(-4.0f, 2.0f, 1180.0f);
		Coin[22].Trans = VECTOR3(4.0f, 2.0f, 1180.0f);
		Coin[23].Trans = VECTOR3(-4.0f, 2.0f, 1230.0f);
		Coin[24].Trans = VECTOR3(4.0f, 2.0f, 1230.0f);
		Coin[25].Trans = VECTOR3(-4.0f, 2.0f, 1280.0f);
		Coin[26].Trans = VECTOR3(4.0f, 2.0f, 1280.0f);
		Coin[27].Trans = VECTOR3(-4.0f, 2.0f, 1330.0f);
		Coin[28].Trans = VECTOR3(4.0f, 2.0f, 1330.0f);
		Coin[29].Trans = VECTOR3(-4.0f, 2.0f, 1380.0f);
		Coin[30].Trans = VECTOR3(4.0f, 2.0f, 1380.0f);
	}
	if (Type == SCENE_S3)
	{
		for (int i = 0; i < COIN_MAX_S3; i++)
		{
			Coin[i].Life = true;
			Coin[i].Speed = 0;
			Coin[i].Scale = VECTOR3(4.0f, 4.0f, 4.0f);
			Coin[i].Trans = VECTOR3(4.0f, 50.0f, 4.0f);
		}
		Coin[0].Trans = VECTOR3(0.0f, 1.5f, 30.0f);
		Coin[1].Trans = VECTOR3(0.0f, 1.5f, 70.0f);
		Coin[2].Trans = VECTOR3(4.5f, 1.5f, 150.0f);
		Coin[3].Trans = VECTOR3(-4.5f, 1.5f,150.0f);
		Coin[4].Trans = VECTOR3(4.5f, 1.5f, 250.0f);
		Coin[5].Trans = VECTOR3(-4.5f, 1.5f, 250.0f);
		Coin[6].Trans = VECTOR3(4.5f, 1.5f, 350.0f);
		Coin[7].Trans = VECTOR3(-4.5f, 1.5f, 350.0f);
		Coin[8].Trans = VECTOR3(4.5f, 1.5f, 450.0f);
		Coin[9].Trans = VECTOR3(-4.5f, 1.5f, 500.0f);
		Coin[10].Trans = VECTOR3(4.5f, 1.5f, 550.0f);
		Coin[11].Trans = VECTOR3(-4.5f, 1.5f, 600.0f);
		Coin[12].Trans = VECTOR3(4.5f, 1.5f, 650.0f);
		Coin[13].Trans = VECTOR3(-4.5f, 1.5f, 700.0f);
		Coin[14].Trans = VECTOR3(4.5f, 1.5f, 750.0f);
		Coin[15].Trans = VECTOR3(-4.5f, 1.5f, 800.0f);

		Coin[16].Trans = VECTOR3(0.5f, 1.5f, 1140.0f);
		Coin[17].Trans = VECTOR3(13.0f, 1.5f, 1140.0f);

		Coin[18].Trans = VECTOR3(-23.0f, 1.5f, 1250.0f);
		Coin[19].Trans = VECTOR3(-23.0f, 1.5f, 1350.0f);

		Coin[20].Trans = VECTOR3(-26.0f, 1.5f, 1430.0f);
		Coin[21].Trans = VECTOR3(-20.0f, 1.5f, 1430.0f);

		Coin[22].Trans = VECTOR3(-26.0f, 1.5f, 1480.0f);
		Coin[23].Trans = VECTOR3(-20.0f, 1.5f, 1480.0f);


		Coin[24].Trans = VECTOR3(.0f, 1.5f, 1720.0f);
		Coin[25].Trans = VECTOR3(0.0f, 1.5f, 1740.0f);

		Coin[26].Trans = VECTOR3(0.0f, 1.5f, 1750.0f);
		Coin[27].Trans = VECTOR3(0.0f, 1.5f, 1760.0f);

		Coin[28].Trans = VECTOR3(-5.0f, 1.5f, 1940.0f);
		Coin[29].Trans = VECTOR3(5.0f, 1.5f, 1940.0f);
		Coin[30].Trans = VECTOR3(-5.0f, 1.5f, 1960.0f);
		Coin[31].Trans = VECTOR3(5.0f, 1.5f, 1960.0f);
		Coin[32].Trans = VECTOR3(-5.0f, 1.5f, 1980.0f);
		Coin[33].Trans = VECTOR3(5.0f, 1.5f, 1980.0f);
	}
}


void tag_coin::Update()
{
	if (Scene.Stage_Type(SCENE_S1))
	{
		for (int i = 0; i < COIN_MAX_S1; i++)
		{
			if (Coin[i].Life)
			{
				Coin[i].Speed++;
			}
		}
	}
	if (Scene.Stage_Type(SCENE_S2))
	{
		for (int i = 0; i < COIN_MAX_S2; i++)
		{
			if (Coin[i].Life)
			{
				Coin[i].Speed++;
			}
		}
	}
	if (Scene.Stage_Type(SCENE_S3))
	{
		for (int i = 0; i < COIN_MAX_S3; i++)
		{
			if (Coin[i].Life)
			{
				Coin[i].Speed++;
			}
		}
	}
	
}

void tag_coin::Draw()
{
	if (Scene.Stage_Type(SCENE_S1))
	{
		for (int i = COIN_MAX_S1; i > -1; i--)
		{
			if (Coin[i].Life)
			{
				Sprite_Coin(i);
				Effectdraw(0, Coin[i].Trans.x, Coin[i].Trans.y, Coin[i].Trans.z, 2, Coin[i].Speed, 3, 4, 4);
			}
		}
	}

	if(Scene.Stage_Type(SCENE_S2))
	{
		for (int i = COIN_MAX_S2; i > -1; i--)
		{
			if (Coin[i].Life)
			{
				Sprite_Coin(i);
				Effectdraw(0, Coin[i].Trans.x, Coin[i].Trans.y, Coin[i].Trans.z, 2, Coin[i].Speed, 3, 4, 4);
			}
		}
	}

	if (Scene.Stage_Type(SCENE_S3))
	{
		for (int i = COIN_MAX_S3; i > -1; i--)
		{
			if (Coin[i].Life)
			{
				Sprite_Coin(i);
				Effectdraw(0, Coin[i].Trans.x, Coin[i].Trans.y, Coin[i].Trans.z, 2, Coin[i].Speed, 3, 4, 4);

			}
		}
	}
}

void tag_coin::Effectdraw(int tex, float x, float y, float z, float scaling, int speed, int RenderSpeed, int Widht, int Length)
{
	float cutU = (float)1 / (float)Widht;
	float cutV = (float)1 / (float)Length;
	int X = (speed / RenderSpeed) % Widht;
	int Y = (speed / (RenderSpeed * Widht)) % Length;
	Sprite_Draw(tex, x, y, z, scaling, cutU * X, cutV * Y, cutU, cutV);
}

void tag_coin::Sprite_Draw(int textureID, float x, float y, float z, float size, float cut_x, float cut_y, float cut_w, float cut_h)
{

	m_pd3dDevice = Device.Get();
	float u0 = cut_x;
	float v0 = cut_y;
	float u1 = (cut_x + cut_w);
	float v1 = (cut_y + cut_h);

	CUBEVERTEX Cube[] = {
		{ VECTOR3(-0.5f, 0.5f, 0.0f), D3DCOLOR_RGBA(255, 255, 255, 255), VECTOR2(u0,v0)},
		{ VECTOR3(0.5f,0.5f,0.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(u1,v0) },
		{ VECTOR3(-0.5f,-0.5f,0.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(u0,v1) },
		{ VECTOR3(0.5f,-0.5f,0.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(u1,v1) }
	};


	m_pd3dDevice->SetFVF(FVF_PCT);
	m_pd3dDevice->SetTexture(0, Texture.Get(Tex[textureID]));
	MATRIX matTrans, matWorld, matScal;
	MatTrans(&matTrans, x, y, z);
	MatScaling(&matScal, size, size, size);
	matWorld = Plane.Bilboard() * matScal * matTrans;
	m_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
	m_pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Cube, sizeof(CUBEVERTEX));
}

void tag_coin::Uninit()
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
VECTOR3 tag_coin::Coin_Min(int index)
{
	return Coin[index].Min;
}
VECTOR3 tag_coin::Coin_Max(int index)
{
	return Coin[index].Max;
}
bool tag_coin::Dis_Coin(int index)
{
	return Coin[index].Life = false;
}
void tag_coin::Sprite_Coin(int index)
{

	m_pd3dDevice->SetTexture(0, Texture.Get(Tex[1]));
	m_pd3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	MATRIX World, Trans, Scale;
	D3DXMatrixTranslation(&Trans,Coin[index].Trans.x, Coin[index].Trans.y, Coin[index].Trans.z);
	D3DXMatrixScaling(&Scale, Coin[index].Scale.x*0.5, Coin[index].Scale.y * 0.5, Coin[index].Scale.z * 0.5);
	World = Scale * Trans;
	D3DXVec3TransformCoord(&Coin[index].Min, &m_Min, &World);
	D3DXVec3TransformCoord(&Coin[index].Max, &m_Max, &World);
	m_pd3dDevice->SetTransform(D3DTS_WORLD, &World);
	//m_pBox->DrawSubset(0);
	
	m_pd3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);

}