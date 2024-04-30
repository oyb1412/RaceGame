#include <d3d9.h>
#include <d3dx9.h>
#include "mydirect3d.h"
#include "common.h"
#include "texture.h"
#include "Light.h"
#include "input.h"
#include "Camera.h"
#include "Plane.h"



void tag_Plane::Init(Plane_Tag Type)
{
	if (Type == WALL)
	{
		D3DXMatrixIdentity(&BilBoard);
		Wall_Info.Tex[0] = Texture.SetLoadFile("Accet/Texture/Mase.png", 1, 1);
		Wall_Info.Tex[1] = Texture.SetLoadFile("Accet/Texture/space.jpg", 1, 1);
		Wall_Info.Tex[2] = Texture.SetLoadFile("Accet/Texture/yajirusi_jump.png", 1, 1);


		int height = 1;
		int width = 1;
		int height_length = 1;
		int width_length = 1;
		Wall_Info.Vertex_Number = (height + 1) * (width + 1);
		int Porigon_Plus = (height - 1) * 4;
		int Index_Plus = (height - 1) * 2;
		Wall_Info.Porigon_Number = height * width * 2 + Porigon_Plus;
		int Index_Number = (width * 2 + 2) * height + Index_Plus;
		int Number = 0;
		float UVH = 1 / (float)height;
		float UVW = 1 / (float)width;
		VECTOR3 Start(-1 * width * width_length * 0.5f, height * height_length * 0.5f, 0.0f);
		m_pd3dDevice = Device.Get();
		m_pd3dDevice->CreateVertexBuffer(sizeof(field) * Wall_Info.Vertex_Number, 0, FVF_PLCT, D3DPOOL_DEFAULT, &Wall_Info.m_pVB, NULL);
		field* p_field;
		Wall_Info.m_pVB->Lock(0, 0, (void**)&p_field, NULL);
		for (int i = 0; i < height + 1; i++)
		{
			for (int g = 0; g < width + 1; g++)
			{
				p_field[Number].Position.x = Start.x + (width_length * g);
				p_field[Number].Position.y = Start.y + -1.0f * (height_length * i);
				p_field[Number].Position.z = 0.0f;
				p_field[Number].Normal = VECTOR3(0.0f, 0.0f, 1.0f);
				p_field[Number].Color = D3DCOLOR_RGBA(255, 255, 255, 255);
				p_field[Number].uv = VECTOR2((float)g, (float)i);
				Number++;
			}
		}
		Wall_Info.m_pVB->Unlock();
		int Index_Half = Index_Number / 2;
		int q = 0;
		int w = 1;
		int t = 0;
		int a = 0;
		m_pd3dDevice->CreateIndexBuffer(sizeof(WORD) * Index_Number, 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &Wall_Info.m_pIB, NULL);
		WORD* p_index;
		Wall_Info.m_pIB->Lock(0, 0, (void**)&p_index, 0);
		for (int i = 0; i < Index_Half; i++)
		{

			if (i == (width + 1) + t)
			{
				p_index[(width + 1) * 2 + t * 2] = WORD(width + ((width + 1) * a));
				p_index[(width + 1) * 2 + t * 2 + 1] = WORD(width + (width + 2) + ((width + 1) * a));
				w--;
				q--;
				t += (width + 2);
				a++;
			}
			else
			{
				p_index[i * 2] = WORD(i + (width + w));
				p_index[i * 2 + 1] = WORD(i + q);
			}
		}
		Wall_Info.m_pIB->Unlock();
	}
	else if (Type == GROUND)
	{
		Ground_Info.Tex[1] = Texture.SetLoadFile("Accet/Texture/Goal_Line.jpg", 1, 1);
		Ground_Info.Tex[2] = Texture.SetLoadFile("Accet/Texture/yajirusi_gyaku.png", 1, 1);
		Ground_Info.Tex[3] = Texture.SetLoadFile("Accet/Texture/yajirusi_fast.png", 1, 1);
		Ground_Info.Tex[4] = Texture.SetLoadFile("Accet/Texture/yajirusi_slow.png", 1, 1);


		int height = 1;
		int width = 1;
		int height_length = 1;
		int width_length = 1;
		Ground_Info.Vertex_Number= (height + 1) * (width + 1);
		int Porigon_Plus = (height - 1) * 4;
		int Index_Plus = (height - 1) * 2;
		Ground_Info.Porigon_Number = height * width * 2 + Porigon_Plus;
		int Index_Number = (width * 2 + 2) * height + Index_Plus;
		int Number = 0;
		int Number1 = 0;
		float UVH = 1 / (float)height;
		float UVW = 1 / (float)width;
		VECTOR3 Start(-1 * (float)width * (float)width_length * 0.5f, 0.0, (float)height * (float)height_length * 0.5f);
		m_pd3dDevice = Device.Get();
		m_pd3dDevice->CreateVertexBuffer(sizeof(field) * Ground_Info.Vertex_Number, 0, FVF_PLCT, D3DPOOL_DEFAULT, &Ground_Info.m_pVB, NULL);
		field* p_field;
		Ground_Info.m_pVB->Lock(0, 0, (void**)&p_field, NULL);
		for (int i = 0; i < height + 1; i++)
		{
			for (int g = 0; g < width + 1; g++)
			{
				p_field[Number].Position.x = Start.x + (width_length * g);
				p_field[Number].Position.y = 0.0f;
				p_field[Number].Position.z = Start.z + -1.0f * (height_length * i);
				p_field[Number].Normal = VECTOR3(0.0f, 1.0f, 0.0f);
				p_field[Number].Color = D3DCOLOR_RGBA(255, 255, 255, 255);
				p_field[Number].uv = VECTOR2((float)g, (float)i);
				Number++;
			}
		}
		Ground_Info.m_pVB->Unlock();

		int Index_Half = Index_Number / 2;
		int q = 0;
		int w = 1;
		int t = 0;
		int a = 0;

		m_pd3dDevice->CreateIndexBuffer(sizeof(WORD) * Index_Number, 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &Ground_Info.m_pIB, NULL);
		WORD* p_index;
		Ground_Info.m_pIB->Lock(0, 0, (void**)&p_index, 0);
		for (int i = 0; i < Index_Half; i++)
		{

			if (i == (width + 1) + t)
			{
				p_index[(width + 1) * 2 + t * 2] = WORD(width + ((width + 1) * a));
				p_index[(width + 1) * 2 + t * 2 + 1] = WORD(width + (width + 2) + ((width + 1) * a));
				w--;
				q--;
				t += (width + 2);
				a++;
			}
			else
			{
				p_index[i * 2] = WORD(i + (width + w));
				p_index[i * 2 + 1] = WORD(i + q);
			}
		}
		Ground_Info.m_pIB->Unlock();
	}
}
void tag_Plane::Update()
{
		BilBoard = Camera.Camera_Info().mtxView;
		D3DXMatrixInverse(&mtxViewInv, NULL, &BilBoard);
		mtxViewInv._41 = 0.0f;
		mtxViewInv._42 = 0.0f;
		mtxViewInv._43 = 0.0f;
}
void tag_Plane::Draw(Plane_Tag Type,int texid,float Trans_x, float Trans_y, float Trans_z,float Scale_x, float Scale_y, float Scale_z)
{
	if (Type == WALL)
	{
		m_pd3dDevice = Device.Get();
		Light_SetUp_Cube();
		MATRIX matWorld, matTrans, matScaling;
		D3DXMatrixIdentity(&matWorld);
		MatScaling(&matScaling, Scale_x, Scale_y, Scale_z);
		MatTrans(&matTrans, Trans_x, Trans_y, Trans_z);
		matWorld = mtxViewInv * matScaling * matTrans;
		m_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
		m_pd3dDevice->SetFVF(FVF_PLCT);
		m_pd3dDevice->SetTexture(0, Texture.Get(Wall_Info.Tex[texid]));
		m_pd3dDevice->SetStreamSource(0, Wall_Info.m_pVB, 0, sizeof(field));
		m_pd3dDevice->SetIndices(Wall_Info.m_pIB);
		m_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLESTRIP, 0, 0, Wall_Info.Vertex_Number, 0, Wall_Info.Porigon_Number);
	}
	else if (Type == GROUND)
	{
		m_pd3dDevice = Device.Get();
		Light_SetUp_Cube();
		MATRIX matWorld, matTrans, matScaling;
		D3DXMatrixIdentity(&matWorld);
		MatScaling(&matScaling, Scale_x, Scale_y, Scale_z);
		MatTrans(&matTrans, Trans_x, Trans_y, Trans_z);
		matWorld = matScaling * matTrans;
		m_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
		m_pd3dDevice->SetFVF(FVF_PLCT);
		m_pd3dDevice->SetTexture(0, Texture.Get(Ground_Info.Tex[texid]));
		m_pd3dDevice->SetStreamSource(0, Ground_Info.m_pVB, 0, sizeof(field));
		m_pd3dDevice->SetIndices(Ground_Info.m_pIB);
		m_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLESTRIP, 0, 0,Ground_Info.Vertex_Number, 0, Ground_Info.Porigon_Number);
	}
}

void tag_Plane::Uninit()
{
	if (m_pd3dDevice)
	{
		m_pd3dDevice->Release();
	}

		if (Ground_Info.m_pVB)
		{
			Ground_Info.m_pVB->Release();
		}
		if (Ground_Info.m_pIB)
		{
			Ground_Info.m_pIB->Release();
		}
		if (Wall_Info.m_pVB)
		{
			Wall_Info.m_pVB->Release();
		}
		if (Wall_Info.m_pIB)
		{
			Wall_Info.m_pIB->Release();
		}
}
MATRIX tag_Plane::Bilboard()
{
	return mtxViewInv;
}

//void tag_Plane::Field_Init()
//{
//	tex[1] = Texture.SetLoadFile("Accet/Texture/Goal_Line.jpg", 1, 1);
//	tex[2] = Texture.SetLoadFile("Accet/Texture/yajirusi_gyaku.png", 1, 1);
//	tex[3] = Texture.SetLoadFile("Accet/Texture/yajirusi_fast.png", 1, 1);
//	tex[4] = Texture.SetLoadFile("Accet/Texture/yajirusi_slow.png", 1, 1);
//	int height = 1;
//	int width = 1;
//	int height_length = 1;
//	int width_length = 1;
//	Vertex_Number = (height + 1) * (width + 1);
//	int Porigon_Plus = (height - 1) * 4;
//	int Index_Plus = (height - 1) * 2;
//	Porigon_Number = height * width * 2 + Porigon_Plus;
//	int Index_Number = (width * 2 + 2)*height + Index_Plus;
//	int Number = 0;
//	int Number1 = 0;
//	float UVH = 1 / (float)height;
//	float UVW = 1 / (float)width;
//	VECTOR3 Start(-1 * (float)width * (float)width_length * 0.5f, 0.0, (float)height * (float)height_length * 0.5f);
//	m_pd3dDevice = Device.Get();
//	m_pd3dDevice->CreateVertexBuffer(sizeof(field) * Vertex_Number, 0, FVF_PLCT, D3DPOOL_DEFAULT, &m_pVB, NULL);
//	field * p_field;
//	m_pVB->Lock(0, 0, (void**)&p_field, NULL);
//	for (int i = 0; i < height + 1; i++)
//	{
//		for (int g = 0; g < width + 1; g++)
//		{
//			p_field[Number].Position.x = Start.x + (width_length * g);
//			p_field[Number].Position.y = 0.0f;
//			p_field[Number].Position.z = Start.z + -1.0f*(height_length * i);
//			p_field[Number].Normal = VECTOR3(0.0f, 1.0f, 0.0f);
//			p_field[Number].Color = D3DCOLOR_RGBA(255, 255, 255, 255);
//			p_field[Number].uv = VECTOR2((float)g, (float)i);
//			Number++;
//		}
//	}
//	m_pVB->Unlock();
//
//	int Index_Half = Index_Number / 2;
//	int q = 0;
//	int w = 1;
//	int t = 0;
//	int a = 0;
//
//	m_pd3dDevice->CreateIndexBuffer(sizeof(WORD) *Index_Number, 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &m_pIB, NULL);
//	WORD *p_index;
//	m_pIB->Lock(0, 0, (void**)&p_index, 0);
//	for (int i = 0; i < Index_Half; i++)
//	{
//
//		if (i == (width + 1) + t)
//		{
//			p_index[(width + 1) * 2 + t * 2] = WORD(width + ((width + 1)*a));
//			p_index[(width + 1) * 2 + t * 2 + 1] = WORD(width + (width + 2) + ((width + 1)*a));
//			w--;
//			q--;
//			t += (width + 2);
//			a++;
//		}
//		else
//		{
//			p_index[i * 2] = WORD(i + (width + w));
//			p_index[i * 2 + 1] = WORD(i + q);
//		}
//	}
//	m_pIB->Unlock();
//}
//
//
//
//void tag_Plane::Field_Draw(int Texid, float Trans_x, float Trans_y, float Trans_z, float Scale_x, float Scale_y, float Scale_z)
//{
//
//	m_pd3dDevice = Device.Get();
//	Light_SetUp_Cube();
//	MATRIX matWorld, matTrans, matScaling;
//	D3DXMatrixIdentity(&matWorld);
//	MatScaling(&matScaling, Scale_x, Scale_y, Scale_z);
//	MatTrans(&matTrans, Trans_x, Trans_y, Trans_z);
//	matWorld = matScaling * matTrans;
//	m_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
//	Light_SetUp_Cube();
//	m_pd3dDevice->SetFVF(FVF_PLCT);
//
//
//	m_pd3dDevice->SetTexture(0, Texture.Get(tex[Texid]));
//	m_pd3dDevice->SetStreamSource(0, m_pVB, 0, sizeof(field));
//	m_pd3dDevice->SetIndices(m_pIB);
//	m_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLESTRIP, 0, 0, Vertex_Number, 0, Porigon_Number);
//}
//void tag_Plane::Field_Uninit()
//{
//	if (m_pd3dDevice)
//	{
//		m_pd3dDevice->Release();
//	}
//	if (m_pIB)
//	{
//		m_pIB->Release();
//	}
//	if (m_pVB)
//	{
//		m_pVB->Release();
//	}
//}