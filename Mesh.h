#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "common.h"
#include "Scene.h"

class tag_Mesh
{
private:
	struct model:public tag_Scene
	{
		MESH g_pMesh;
		DWORD g_MaterialCount;
		BUFFER g_pMaterials;
		int *g_pTextureids;
		int *Mesh;
		MATERIAL *pMat;
	};
	model Model[10];
	DEVICE m_pd3dDevice;
public:
	int *Load(const char* pFilename, int Number);
	void Create(int Number, float Trans_x, float Trans_y, float Trans_z, float Angle_y, float Scale_x, float Scale_y, float Scale_z);
	void Set(const char* pFilename, int Number);

	
	virtual void Uninit(void);
};
extern tag_Mesh Mesh;