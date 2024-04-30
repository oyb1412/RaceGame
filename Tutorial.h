#pragma once
#include "common.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "C_Ground.h"
#include "Scene.h"

class tag_Tutorial : public tag_Scene
{
public:

	ground Ground_T[GROUND_MAX];
	virtual void Init(void);
	virtual void Update(void);
	virtual void Draw(void);
	virtual void Uninit(void);
	ground Ground_T_Info(int index);
	VECTOR3 Min(int index);
	VECTOR3 Max(int index);
	float difference();
	void Sprite_Ground(int index);



private:
	HWND hWnd;
	int Tex[10];
	VECTOR3 m_Min, m_Max;
	bool Fade_Counter;
	int Counter;
	MESH m_pBox;
	DEVICE m_pd3dDevice = NULL;
	float Trans_difference;


};

extern tag_Tutorial TUTORIAL;
