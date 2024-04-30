#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "Scene.h"


class tag_TwoD : public tag_Scene
{
private:
	int Tex[47];
	float Tex_Size = 1.5f;
	float Goal_Tex_Size = 1.0f;
	int Counter;
	int Warning_Fade;
	bool Warning;
	bool Warning1;
	float Tex_Move;
	int Tex_Fade = 255;
	bool Tex_Fade_Trigger = false;
public:
	virtual void Init(void);
	virtual void Update(void);
	virtual void Draw(void);
	virtual void Uninit(void);

	void Tex_Draw();
	void T_Draw();
	int Count();
};
extern tag_TwoD TwoD;