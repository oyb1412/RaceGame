#include "common.h"
#include "Cube.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "texture.h"
#include "Light.h"
#include "Mesh.h"
#include "mydirect3d.h"



void tag_Cube::Init()
{
	WORD Index[36] = {
			0,1,2,
			2,1,3,
			4,5,6,
			6,5,7,
			8,9,10,
			10,9,11,
			12,13,14,
			14,13,15,
			16,17,18,
			18,17,19,
			20,21,22,
			22,21,23
		};
	m_pd3dDevice = Device.Get();

	CUBEVERTEX Cube[] = {
{VECTOR3(-0.5f,-0.5f,-0.5f),VECTOR3(0.0f,0.0f,-1.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(0.0f,0.25f)},
{VECTOR3(-0.5f,0.5f,-0.5f),VECTOR3(0.0f,0.0f,-1.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(0.0f,0.0f)},
{VECTOR3(0.5f,-0.5f,-0.5f),VECTOR3(0.0f,0.0f,-1.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(0.25f,0.25f)},
{VECTOR3(0.5f,0.5f,-0.5f),VECTOR3(0.0f,0.0f,-1.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(0.25f,0.0f)},
//後ろ
{VECTOR3(0.5f,-0.5f,0.5f),VECTOR3(0.0f,0.0f,1.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(0.25f,0.25f)},
{VECTOR3(0.5f,0.5f,0.5f),VECTOR3(0.0f,0.0f,1.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(0.25f,0.0f)},
{VECTOR3(-0.5f,-0.5f,0.5f),VECTOR3(0.0f,0.0f,1.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(0.5f,0.25f)},
{VECTOR3(-0.5f,0.5f,0.5f),VECTOR3(0.0f,0.0f,1.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(0.5f,0.0f)},
//右
{VECTOR3(0.5f,-0.5f,-0.5f),VECTOR3(1.0f,0.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(0.5f,0.25f)},
{VECTOR3(0.5f,0.5f,-0.5f),VECTOR3(1.0f,0.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(0.5f,0.0f)},
{VECTOR3(0.5f,-0.5f,0.5f),VECTOR3(1.0f,0.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(0.75f,0.25f)},
{VECTOR3(0.5f,0.5f,0.5f),VECTOR3(1.0f,0.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(0.75f,0.0f)},
//左
{VECTOR3(-0.5f,-0.5f,0.5f),VECTOR3(-1.0f,0.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(0.75f,0.25f)},
{VECTOR3(-0.5f,0.5f,0.5f),VECTOR3(-1.0f,0.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(0.75f,0.0f)},
{VECTOR3(-0.5f,-0.5f,-0.5f),VECTOR3(-1.0f,0.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(1.0f,0.25f)},
{VECTOR3(-0.5f,0.5f,-0.5f),VECTOR3(-1.0f,0.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(1.0f,0.0f)},
//下
{VECTOR3(0.5f,-0.5f,-0.5f),VECTOR3(0.0f,-1.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(0.25f,0.5f)},
{VECTOR3(0.5f,-0.5f,0.5f),VECTOR3(0.0f,-1.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(0.25f,0.25f)},
{VECTOR3(-0.5f,-0.5f,-0.5f),VECTOR3(0.0f,-1.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(0.5f,0.5f)},
{VECTOR3(-0.5f,-0.5f,0.5f),VECTOR3(0.0f,-1.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(0.5f,0.25f)},
//上
{VECTOR3(-0.5f,0.5f,-0.5f),VECTOR3(0.0f,1.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(0.0f,3.0f)},
{VECTOR3(-0.5f,0.5f,0.5f),VECTOR3(0.0f,1.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(0.0f,0.0f)},
{VECTOR3(0.5f,0.5f,-0.5f),VECTOR3(0.0f,1.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(1.0f,3.0f)},
{VECTOR3(0.5f,0.5f,0.5f),VECTOR3(0.0f,1.0f,0.0f),D3DCOLOR_RGBA(255,255,255,255),VECTOR2(1.0f,0.0f)}
};



	
	m_pd3dDevice->CreateVertexBuffer(sizeof(Cube), 0, FVF_PLCT, D3DPOOL_DEFAULT, &m_pVB, NULL);
	void *pVertex;
	m_pVB->Lock(0, sizeof(pVertex), &pVertex, 0);
	memcpy(pVertex, Cube, sizeof(Cube));
	m_pVB->Unlock();

	m_pd3dDevice->CreateIndexBuffer(sizeof(Index), 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &m_pIB, NULL);
	void *pIndex;
	m_pIB->Lock(0,sizeof(Index), &pIndex, 0);
	memcpy(pIndex, Index, sizeof(Index));
	m_pIB->Unlock();
	Tex[1] = Texture.SetLoadFile("Accet/Texture/Brown.jpg", 1, 1);
	Tex[2] = Texture.SetLoadFile("Accet/Texture/gray.png", 1, 1);
	Tex[9] = Texture.SetLoadFile("Accet/Texture/Mase.png", 1, 1);
	Tex[7] = Texture.SetLoadFile("Accet/Texture/blue.jpg", 1, 1);
	Tex[8] = Texture.SetLoadFile("Accet/Texture/blue1.jpg", 1, 1);
	Tex[9] = Texture.SetLoadFile("Accet/Texture/Brown1.jpg", 1, 1);
	Tex[10] = Texture.SetLoadFile("Accet/Texture/Yellow.jpg", 1, 1);
	Tex[11] = Texture.SetLoadFile("Accet/Texture/BW.jpg", 1, 1);
	Tex[12] = Texture.SetLoadFile("Accet/Texture/Brown2.jpg", 1, 1);
	Tex[13] = Texture.SetLoadFile("Accet/Texture/gray2.jpg", 1, 1);

	Tex[14] = Texture.SetLoadFile("Accet/Texture/asiba.jpg", 1, 1);

	Tex[15] = Texture.SetLoadFile("Accet/Texture/suna.jpg", 1, 1);//移動速度減少

	Tex[16] = Texture.SetLoadFile("Accet/Texture/1111.png", 1, 1);//移動速度増加

	Tex[17] = Texture.SetLoadFile("Accet/Texture/yougan.jpg", 1, 1);//滑っちゃう

	Tex[18] = Texture.SetLoadFile("Accet/Texture/kusa.jpg", 1, 1);//足場利用制限

	Tex[19] = Texture.SetLoadFile("Accet/Texture/sora.jpg", 1, 1);//ジャンプ力増加

	Tex[20] = Texture.SetLoadFile("Accet/Texture/gravity.jpg", 1, 1);//ジャンプ力増加

	
	


	

	
}
void tag_Cube::Update()
{
	
	

}
void tag_Cube::Draw(int texid,float size_x, float size_y, float size_z,float trans_x, float trans_y, float trans_z )
{
	m_pd3dDevice = Device.Get();
	Light_SetUp_Cube();


	MATRIX matWorld, matTranslation, matScal;

	m_pd3dDevice->SetFVF(FVF_PLCT);
	m_pd3dDevice->SetTexture(0, Texture.Get(Tex[texid]));
	m_pd3dDevice->SetStreamSource(0, m_pVB, 0, sizeof(CUBEVERTEX));
	m_pd3dDevice->SetIndices(m_pIB);
	MatScaling(&matScal, size_x, size_y, size_z);
	MatTrans(&matTranslation, trans_x, trans_y, trans_z);
	matWorld = matScal * matTranslation;
	m_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
	m_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 36, 0,12);

	
}
void tag_Cube::Uninit()
{
	if (m_pd3dDevice)
	{
		m_pd3dDevice->Release();
	}
	if (m_pIB)
	{
		m_pIB->Release();
	}
	if (m_pVB)
	{
		m_pVB->Release();
	}
}
