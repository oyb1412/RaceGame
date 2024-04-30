#pragma once
#include "common.h"
#include <d3dx9.h>
#include "Scene.h"
#define GROUND_MAX 200



class tag_C_Ground:public tag_Scene
{
public:
	void Init(SCENE Type);
	void Update(SCENE Type);
	void Uninit();
	void Draw(SCENE Type);

	VECTOR3 Min(int Ground_Number, int index);
	VECTOR3 Max(int Ground_Number, int index);
	float difference(int Ground_Number);
	void Sprite_Ground(ground *pDate, int index);
	ground C_Ground_Info(int Ground_Number, int index);


private:

	MESH m_pBox;
	DEVICE m_pd3dDevice = NULL;
	VECTOR3 m_Min, m_Max;
	float Trans_difference[3];
	bool Mase_Move[35];
	float Random_Number[55];
	ground Ground[3][GROUND_MAX] = { };

};
extern tag_C_Ground C_Ground;
