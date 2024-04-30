#pragma once
#include <windows.h>
#include <d3dx9.h>
#include "Scene.h"
#define NUMBER_SIZE_X 133
#define NUMBER_SIZE_Y 64
#define NUMBER_SIZE_X_MAX 1334
#define NUMBER_MAX 2 

class tag_Number : public tag_Scene
{
private:
	int tex[1];
	struct number
	{
		D3DXVECTOR2 size;
		bool Visible;
	};
	number NUMBER;
public:

	virtual void Init(void);
	virtual void Draw(int number, float x, float y, float Trans_x, int max,int fade = 255);
	virtual void Draw(int number, int transx, int transy);

	
	void Destroy(void);
	void Used(void);
};
extern tag_Number Number;