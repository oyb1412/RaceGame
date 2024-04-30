#pragma once

#define PLUSEFFECT_MAX (1024)


void PlusEffect_Init(void);

void PlusEffect_Update(void);

void PlusEffect_Draw(void);

void PlusEffect_Uninit(void);

void PlusEffect_Creat(float x, float y,float z, D3DCOLOR color, int lifeframe, int size);
