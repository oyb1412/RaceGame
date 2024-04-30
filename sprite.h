#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "common.h"
#include "Scene.h"
class tag_Sprite
{
private:
	struct Sprite
	{
		D3DXVECTOR4 position;
		D3DCOLOR color;
		D3DXVECTOR2 uv;
	};

	D3DCOLOR g_color = D3DCOLOR_RGBA(255, 255, 255, 255);
	LPDIRECT3DVERTEXBUFFER9 g_VertexBuffer = NULL;
	LPDIRECT3DINDEXBUFFER9 g_pIndexBuffer = NULL;
public:
	void Draw_MiddleStandard(int TextureID, float dx, float dy,float size = 1, int fade = 255);
	void Draw_Number(int textureID, float dx, float dy, float cut_x, float cut_y, float cut_w, float cut_h,int fade = 255);
	void Draw_Tex_x_y(int textureID, float dx, float dy, float size_x, float size_y, float size_z);
	void Draw_Tex_x_y_Fade(int textureID, float dx, float dy, int fade);
	void SetColor(D3DCOLOR color);
};
extern tag_Sprite Sprite;