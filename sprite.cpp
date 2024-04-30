#include <d3d9.h>
#include <d3dx9.h>
#include "mydirect3d.h"
#include "texture.h"
#include "sprite.h"
#include "common.h"






void tag_Sprite::SetColor(D3DCOLOR color)
{
	g_color = color;
}
void tag_Sprite::Draw_MiddleStandard(int TextureID, float dx, float dy, float size,int fade)
{
	int w = Texture.GetWidth(TextureID);
	int h = Texture.GetHeight(TextureID);

	D3DXMATRIX  mtxScaling,mtxTransration, mtxITransration, mtxWorld;

	D3DXMatrixTranslation(&mtxITransration, -dx, -dy, 0.0f);
	D3DXMatrixTranslation(&mtxTransration, dx, dy, 0.0f);
	D3DXMatrixScaling(&mtxScaling, size, size, 0.0f);
	mtxWorld =  mtxITransration * mtxScaling * mtxTransration;

	Sprite v[] = {
	{ D3DXVECTOR4(dx  - 0.5f * w,dy - 0.5f * h,0.0f,1.0f) ,D3DCOLOR_RGBA(255, 255, 255,  fade), D3DXVECTOR2(0.0f, 0.0f) },
	{ D3DXVECTOR4(dx  + 0.5f * w,dy  - 0.5f * h,0.0f,1.0f) ,D3DCOLOR_RGBA(255, 255, 255, fade), D3DXVECTOR2(1.0f, 0.0f) },
	{ D3DXVECTOR4(dx  - 0.5f * w,dy  + 0.5f * h,0.0f,1.0f) ,D3DCOLOR_RGBA(255, 255, 255, fade), D3DXVECTOR2(0.0f, 1.0f) },
	{ D3DXVECTOR4(dx  + 0.5f * w,dy  + 0.5f * h,0.0f,1.0f) ,D3DCOLOR_RGBA(255, 255, 255, fade), D3DXVECTOR2(1.0f, 1.0f) },
	};

	for (int i = 0; i < 4; i++)
	{
		D3DXVec4Transform(&v[i].position, &v[i].position, &mtxWorld);
	}
	LPDIRECT3DDEVICE9 g_pDevice = Device.Get();
	g_pDevice->SetFVF(FVF_VERTEXSPRITE);
	g_pDevice->SetTexture(0, Texture.Get(TextureID));
	g_pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, v, sizeof(Sprite));
}

void tag_Sprite::Draw_Tex_x_y(int textureID, float dx, float dy,float size_x,float size_y,float size_z)
{
	int w = Texture.GetWidth(textureID);
	int h = Texture.GetHeight(textureID);
	D3DXMATRIX mtxW, mtxT, mtxIT, mtxS;

	D3DXMatrixTranslation(&mtxT, -dx, -dy, 0.0f);
	D3DXMatrixTranslation(&mtxIT, dx, dy, 0.0f);
	D3DXMatrixScaling(&mtxS, size_x, size_y, size_z);
	mtxW = mtxT * mtxS * mtxIT;

	Sprite v[] = {
		{ D3DXVECTOR4(dx - 0.5f - 0.3f * w,dy - 0.4f - 0.3f * h,1.0f,1.0f) , g_color, D3DXVECTOR2(0.0f, 0.0f) },
		{ D3DXVECTOR4(dx - 0.5f + 0.01f * w,dy - 0.4f - 0.3f * h,1.0f,1.0f) , g_color, D3DXVECTOR2(1.0f, 0.0f) },
		{ D3DXVECTOR4(dx - 0.5f - 0.3f * w,dy - 0.4f + 0.01f * h,1.0f,1.0f) , g_color, D3DXVECTOR2(0.0f, 1.0f) },
		{ D3DXVECTOR4(dx - 0.5f + 0.01f * w,dy - 0.4f + 0.01f * h,1.0f,1.0f) , g_color, D3DXVECTOR2(1.0f, 1.0f) },

	};

	D3DXVec4Transform(&v[0].position, &v[0].position, &mtxW);
	D3DXVec4Transform(&v[1].position, &v[1].position, &mtxW);
	D3DXVec4Transform(&v[2].position, &v[2].position, &mtxW);
	D3DXVec4Transform(&v[3].position, &v[3].position, &mtxW);

	LPDIRECT3DDEVICE9 g_pDevice = Device.Get();
	g_pDevice->SetFVF(FVF_VERTEXSPRITE);
	g_pDevice->SetTexture(0, Texture.Get(textureID));
	g_pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, v, sizeof(Sprite));
}
void tag_Sprite::Draw_Tex_x_y_Fade(int textureID, float dx, float dy,int fade)
{
	int w = Texture.GetWidth(textureID);
	int h = Texture.GetHeight(textureID);

	Sprite v[] = {
		{ D3DXVECTOR4(dx - 0.5f - 0.3f * w,dy - 0.4f - 0.3f * h,0.0f,1.0f) , D3DCOLOR_RGBA(255, 255, 255,  fade), D3DXVECTOR2(0.0f, 0.0f) },
		{ D3DXVECTOR4(dx - 0.5f + 0.01f * w,dy - 0.4f - 0.3f * h,0.0f,1.0f) , D3DCOLOR_RGBA(255, 255, 255, fade), D3DXVECTOR2(1.0f, 0.0f) },
		{ D3DXVECTOR4(dx - 0.5f - 0.3f * w,dy - 0.4f + 0.01f * h,0.0f,1.0f) , D3DCOLOR_RGBA(255, 255, 255, fade), D3DXVECTOR2(0.0f, 1.0f) },
		{ D3DXVECTOR4(dx - 0.5f + 0.01f * w,dy - 0.4f + 0.01f * h,0.0f,1.0f) , D3DCOLOR_RGBA(255, 255, 255, fade), D3DXVECTOR2(1.0f, 1.0f) },

	};

	LPDIRECT3DDEVICE9 g_pDevice = Device.Get();
	g_pDevice->SetFVF(FVF_VERTEXSPRITE);
	g_pDevice->SetTexture(0, Texture.Get(textureID));
	g_pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, v, sizeof(Sprite));
}
void tag_Sprite::Draw_Number(int textureID, float dx, float dy, float cut_x, float cut_y, float cut_w, float cut_h,int fade)
{
	int w = Texture.GetWidth(textureID);
	int h = Texture.GetHeight(textureID);

	float u0 = cut_x / (float)w;
	float v0 = cut_y / (float)h;
	float u1 = (cut_x + cut_w) / (float)w;
	float v1 = (cut_y + cut_h) / (float)h;

	Sprite v[] = {
		{ D3DXVECTOR4(dx - 0.5f - 0.5f * cut_w,dy - 0.5f - 0.5f * cut_h,0.0f,1.0f) ,D3DCOLOR_RGBA(255, 255, 255,  fade), D3DXVECTOR2(u0, v0) },
		{ D3DXVECTOR4(dx - 0.5f + 0.5f * cut_w,dy - 0.5f - 0.5f * cut_h,0.0f,1.0f) , D3DCOLOR_RGBA(255, 255, 255,  fade), D3DXVECTOR2(u1, v0) },
		{ D3DXVECTOR4(dx - 0.5f - 0.5f * cut_w,dy - 0.5f + 0.5f * cut_h,0.0f,1.0f) , D3DCOLOR_RGBA(255, 255, 255,  fade), D3DXVECTOR2(u0, v1) },
		{ D3DXVECTOR4(dx - 0.5f + 0.5f * cut_w,dy - 0.5f + 0.5f * cut_h,0.0f,1.0f) , D3DCOLOR_RGBA(255, 255, 255,  fade), D3DXVECTOR2(u1, v1) },

	};
	LPDIRECT3DDEVICE9 g_pDevice = Device.Get();
	g_pDevice->SetFVF(FVF_VERTEXSPRITE);
	g_pDevice->SetTexture(0, Texture.Get(textureID));
	g_pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, v, sizeof(Sprite));
}


