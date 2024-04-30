#include "Mesh.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "texture.h"
#include "Light.h"
#include "common.h"
#include "mydirect3d.h"
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#define MODEL_FILE_PATH "Accet/Mesh/"


void tag_Mesh::Uninit()
{
	for (int i = 0; i < 10; i++)
	{
		delete[]Model[i].g_pTextureids;
	}
	if (m_pd3dDevice != NULL)
	{
		m_pd3dDevice->Release();
	}
}
int *tag_Mesh::Load(const char* pFilename, int Number)
{
	m_pd3dDevice = Device.Get();
	HRESULT hr = D3DXLoadMeshFromX(pFilename, D3DXMESH_MANAGED, m_pd3dDevice, NULL, &Model[Number].g_pMaterials, NULL, &Model[Number].g_MaterialCount, &Model[Number].g_pMesh);//xŠg’£Žqƒt?ƒCƒ‹‚Ì“Ç‚Ýž‚Ý
	if (FAILED(hr))
	{
		MessageBox(NULL, "???? ???? ??", "??", MB_OKCANCEL | MB_DEFBUTTON2);
	}
	Model[Number].pMat = (MATERIAL*)Model[Number].g_pMaterials->GetBufferPointer();
	Model[Number].g_pTextureids = new int[Model[Number].g_MaterialCount];
	for (DWORD i = 0; i < Model[Number].g_MaterialCount; i++)
	{
		Model[Number].pMat[i].MatD3D.Diffuse.r = 1.0f;
		Model[Number].pMat[i].MatD3D.Diffuse.g = 1.0f;
		Model[Number].pMat[i].MatD3D.Diffuse.b = 1.0f;
		Model[Number].pMat[i].MatD3D.Diffuse.b = 1.0f;
		Model[Number].g_pTextureids[i] = NULL;
		if (Model[Number].pMat[i].pTextureFilename == NULL)
		{
			Model[Number].g_pTextureids[i] = -1;
		}
		else
		{
			char buf[256];
			strcpy(buf, MODEL_FILE_PATH);
			strcat(buf, Model[Number].pMat[i].pTextureFilename);
			Model[Number].g_pTextureids[i] = Texture.SetLoadFile(buf, 0, 0);
		}
	}
	Model[Number].g_pMaterials->Release();
	Light_SetUp_Model();
	return Model[Number].g_pTextureids;
}
void tag_Mesh::Create(int Number,float Trans_x, float Trans_y, float Trans_z,float Angle_y,float Scale_x,float Scale_y,float Scale_z)//
{
	Light_SetUp_Model();
	D3DMATERIAL9 Mat = {};
	Mat.Diffuse.r = 0.8f;
	Mat.Diffuse.g = 0.8f;
	Mat.Diffuse.b = 0.8f;
	Mat.Diffuse.a = 1.0f;
	Mat.Ambient.r = 0.3f;
	Mat.Ambient.g = 0.3f;
	Mat.Ambient.b = 0.3f;
	Mat.Ambient.a = 1.0f;
	m_pd3dDevice->SetMaterial(&Mat);
	for (DWORD i = 0; i < Model[Number].g_MaterialCount; i++)
	{
		if(Model[Number].g_pTextureids[i] < 0 )
		{ 
			Light_SetUp_Model();
			m_pd3dDevice->SetTexture(0, NULL);
			MATRIX matWorld, matTrans, matScale, matRotation;
			MatTrans(&matTrans, Trans_x, Trans_y, Trans_z);
			MatScaling(&matScale, Scale_x, Scale_y, Scale_z);
			MatRotatY(&matRotation, (RADIAN(Angle_y)));
			matWorld = matScale * matRotation * matTrans;
			m_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
			Model[Number].g_pMesh->DrawSubset(i);
		}
		else
		{
			Light_SetUp_Model();
			m_pd3dDevice->SetTexture(0, Texture.Get(Model[Number].Mesh[i]));
			MATRIX matWorld, matTrans, matScale,matRotation;
			MatTrans(&matTrans, Trans_x, Trans_y, Trans_z);
			MatScaling(&matScale, Scale_x, Scale_y, Scale_z);
			MatRotatY(&matRotation, (RADIAN(Angle_y)));
			matWorld = matScale * matRotation* matTrans;
			m_pd3dDevice->SetTransform(D3DTS_WORLD, &matWorld);
			Model[Number].g_pMesh->DrawSubset(i);
		}
	}
}
void tag_Mesh::Set(const char* pFilename, int Number)
{
	Model[Number].Mesh = Load(pFilename, Number);
}