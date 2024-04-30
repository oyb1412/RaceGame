#include "texture.h"
#include <d3d9.h>
#include <d3dx9.h>
#include <windows.h>
#include "mydirect3d.h"
void tag_Texture::Init()
{
	Tex[GROUND1] = SetLoadFile("Accet/Texture/Fade.png", 1000,1000);
}


int tag_Texture::SetLoadFile(const char* pFilename, float width, float height)
{
	for (int i = 0; i < TEXTUREDATA_MAX; i++)
	{
		if (strcmp(g_TextureData[i].filename, pFilename) == 0)
		{
			return i;
		}
	}
	for (int i = 0; i < TEXTUREDATA_MAX; i++)
	{
		if (g_TextureData[i].filename[0] != 0)
		{
			continue;
		}
		strcpy_s(g_TextureData[i].filename, pFilename);
		g_TextureData[i].width = width;
		g_TextureData[i].height = height;
		return i;
	}
	return -1;
}

void tag_Texture::Load(HWND hWnd)
{
	g_pDevice = Device.Get();
	for (int i = 0; i < TEXTUREDATA_MAX; i++)
	{
		if (g_TextureData[i].pTexture != NULL)
		{
			continue;
		}
		if (g_TextureData[i].filename[0] == 0)
		{
			continue;
		}
		
		hr[i] = D3DXCreateTextureFromFile(g_pDevice, g_TextureData[i].filename, &g_TextureData[i].pTexture);

		if (FAILED(hr[i])) 
		{
			MessageBox(hWnd, "??? ?? ??", "??", MB_OKCANCEL | MB_DEFBUTTON2);
		}
	}
}

void tag_Texture::Destroy(int texIds[], int count)
{
	for (int i = 0; i < count; i++)
	{
		if (g_TextureData[texIds[i]].pTexture != NULL)
		{
			g_TextureData[texIds[i]].pTexture->Release();
			g_TextureData[texIds[i]].pTexture = NULL;
			g_TextureData[texIds[i]].filename[0] = 0;
			g_TextureData[texIds[i]].width = 0;
			g_TextureData[texIds[i]].height = 0;
		}
	}
}

void tag_Texture::Destroy(void)
{
	for (int i = 0; i < TEXTUREDATA_MAX; i++)
	{
		if (g_TextureData[i].pTexture != NULL)
		{
			g_TextureData[i].pTexture->Release();
			g_TextureData[i].pTexture = NULL;
			g_TextureData[i].filename[0] = 0;
			g_TextureData[i].width = 0;
			g_TextureData[i].height = 0;
		}
	}
}


LPDIRECT3DTEXTURE9 tag_Texture::Get(int id)
{
	return g_TextureData[id].pTexture;
}

float tag_Texture::GetWidth(int id)
{
	return g_TextureData[id].width;
}

float tag_Texture::GetHeight(int id)
{
	return g_TextureData[id].height;
}
