#pragma once

#include "common.h"
#include <d3dx9.h>
enum Plane_Tag
{
	GROUND,
	WALL
};
struct plane_tag
{
	VERTEXBUFFER m_pVB;
	INDEXBUFFER m_pIB;
	int Porigon_Number;
	int Vertex_Number;
	int Tex[5];
};
static Plane_Tag Plane_Type;
static plane_tag Ground_Info;
static plane_tag Wall_Info;
class tag_Plane
{
private:
	DEVICE m_pd3dDevice;
	MATRIX BilBoard;
	MATRIX mtxViewInv;
	struct field
	{
		VECTOR3 Position;
		VECTOR3 Normal;
		DWORD Color;
		VECTOR2 uv;
	};


public:
	void Init(Plane_Tag Type);
	void Update();
	void Draw(Plane_Tag Type,int texid, float Trans_x, float Trans_y, float Trans_z, float Scale_x, float Scale_y, float Scale_z);
	void Uninit();
	MATRIX Bilboard();


	/*void Field_Init();
	void Field_Draw(int Texid, float Trans_x, float Trans_y, float Trans_z, float Scale_x, float Scale_y, float Scale_z);
	void Field_Uninit();*/
};
extern tag_Plane Plane;
