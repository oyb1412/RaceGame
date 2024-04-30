#pragma once

#include "common.h"
#include <d3dx9.h>
#include "Scene.h"
#define FADE_POSITION_X 0
#define FADE_POSITION_Y 0
#define FADE_SIZE_X 1000000
#define FADE_SIZE_Y 1000000
#define FADE_MAX 255
class tag_Fade : public tag_Scene
{
private:
	int tex[TEX_MAX];
	int Fade_Number; 
	int Fade_In_Start;
	int Fade_Out_Start;
	bool Fade_Trigger;
	struct fade
	{
		D3DXVECTOR4 position;
		D3DCOLOR color;
		D3DXVECTOR2 uv;
		D3DXVECTOR2 size;
	};
	fade Fade;
public:
	void Fade_Out(void);
	void Fade_In();
	int Fade_Funtion(bool Trigger,bool kaesi=false);
	virtual void Init(void);
	virtual void Draw(void);
	int Fade_Count();
};

extern tag_Fade Fade;