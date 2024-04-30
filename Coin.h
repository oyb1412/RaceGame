#pragma once
#include "Effect.h"
#include "common.h"
#include <d3dx9.h>
#include "C_Ground.h"
#define COIN_MAX_S1 41
#define COIN_MAX_S2 31
#define COIN_MAX_S3 34


class tag_coin : public tag_Effect
{
private:

	short Tex[TEX_MAX];
	VERTEXBUFFER m_pVB;
	INDEXBUFFER m_pIB;
	DEVICE m_pd3dDevice;
	MESH m_pBox;
	VECTOR3 m_Min, m_Max;



	
public:
	void Effectdraw(int tex, float x, float y, float z, float scaling, int speed, int RenderSpeed, int Widht, int Length);
	void Sprite_Draw(int textureID, float x, float y, float z, float size, float cut_x, float cut_y, float cut_w, float cut_h);
	void Sprite_Coin(int index);
	VECTOR3 Coin_Min(int index);
	VECTOR3 Coin_Max(int index);
	bool Dis_Coin(int index);
	virtual void Init(SCENE Type);
	virtual void Update();
	virtual void Draw();
	virtual void Uninit(void);
	struct CUBEVERTEX
	{
		VECTOR3 Position;
		DWORD color;
		VECTOR2 uv;
	};
	struct coin
	{
		VECTOR3 Trans;
		VECTOR3 Scale;
		VECTOR3 Min, Max;
		int Speed;
		bool Life;
	};
	coin Coin[50];

};

extern tag_coin COIN;