#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "common.h"
#include "Scene.h"



class tag_Cube : public tag_Scene
{
	private:
	
		struct CUBEVERTEX
		{
			VECTOR3 Position;
			VECTOR3 Normal;
			DWORD color;
			VECTOR2 uv;
		};
		VERTEXBUFFER m_pVB;
		INDEXBUFFER m_pIB;
		DEVICE m_pd3dDevice;
		int Tex[25];
		HWND hWnd;
		WORD Index[36] = {};
	public:
	

		virtual void Init(void);
		virtual void Update(void);
		virtual void Draw(int texid, float size_x, float size_y, float size_z, float trans_x, float trans_y, float trans_z);
		virtual void Uninit(void);
};

extern tag_Cube Cube;