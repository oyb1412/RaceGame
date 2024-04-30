#pragma once
#include "common.h"
#include <d3dx9.h>
#include "Scene.h"

struct effect
{
	BOOL Visible;
	VECTOR3 Position;
	VECTOR3 Scale;
	short Speed;
};

enum effect_tag
{
	SPEED_UP,
	SPEED_SLOW,
	CHAOS,
	JUMP,
	DISTROY,
	BOOST
};
static effect_tag Effect_Tag;

static effect Speed_Up;
static effect Speed_Slow;
static effect Chaos;
static effect Jump;
static effect Distroy;
static effect Boost;

#define EFFECT_MAX 10
class tag_Effect : public tag_Scene
{
private:

	short Tex[TEX_MAX];
	VERTEXBUFFER m_pVB;
	INDEXBUFFER m_pIB;
	DEVICE m_pd3dDevice;



	struct CUBEVERTEX
	{
		VECTOR3 Position;
		DWORD color;
		VECTOR2 uv;
	};
public:
	void Create(effect_tag Type, float x, float y, float z);
	void Effectdraw(int tex, float x, float y, float z, float scaling, int speed, int RenderSpeed, int Widht,int Length );
	void Sprite_Draw(int textureID, float x, float y, float z, float size, float cut_x, float cut_y, float cut_w, float cut_h);

	virtual void Init(void);
	virtual void Update(void);
	virtual void Draw(void);
	virtual void Uninit(void);
};

extern tag_Effect Effect;