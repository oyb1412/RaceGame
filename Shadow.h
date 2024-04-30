#pragma once
#include "common.h"
#define PLUSEFFECT_MAX (1024)


class tag_Shadow
{
private:
	int g_ShadowFrameCount = 0;
	float Size = 0;
	D3DCOLOR g_color = D3DCOLOR_RGBA(0, 0, 0, 255);
	DEVICE m_pd3dDevice;

	struct shadow
	{
		int Texture;
		D3DXVECTOR3 Position;
		bool Visivle;
		int LifeFrame;			
		int SpawnFrame;			
		D3DCOLOR Color;
		float Showsize;
	};
	shadow Shadow[PLUSEFFECT_MAX] = {};
	struct CUBEVERTEX
	{
		VECTOR3 Position;
		DWORD color;
		VECTOR2 uv;
	};
public:
	virtual void Init(void);
	virtual void Update(void);
	virtual void Draw(void);
	virtual void Uninit(void);

	void Creat(float x, float y, float z, D3DCOLOR color, int lifeframe, float size);
	void Sprite_Draw_Change(int textureID, float x, float y, float z, float size);
	void Sprite_SetColor(D3DCOLOR color);
};
extern tag_Shadow Shadow;