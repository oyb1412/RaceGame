#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <d3d9.h>
#include <windows.h>
#include "common.h"
#define TEXTURENAME_MAX (256)
#define TEXTUREDATA_MAX (256)
enum
{
	GROUND1,
};
class tag_Texture 
{
private:
	struct TextureData
	{
		char filename[TEXTURENAME_MAX];
		float width;
		float height;
		LPDIRECT3DTEXTURE9 pTexture;
	};
	DEVICE g_pDevice = NULL;
	TextureData g_TextureData[TEXTUREDATA_MAX] = {};
	HRESULT hr[TEXTUREDATA_MAX] = {};
public:
	void Init();
	int SetLoadFile(const char* pFilename, float width, float height);
	void Load(HWND hWnd);
	LPDIRECT3DTEXTURE9 Get(int id);
	void Destroy(int texIds[], int count);
	//                      
	void Destroy(void);
	float GetWidth(int id);
	float GetHeight(int id);
	int Tex[50];

};
extern tag_Texture Texture;
#endif

