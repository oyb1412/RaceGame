#pragma once
#include "common.h"
#include "Scene.h"
#include "Mesh.h"
#include <d3d9.h>
#include <d3dx9.h>
struct Player_tag
{
	VECTOR3 Trans;
	int Move_Counter[2];
	bool Move[2];
	float Jump_Speed;
	float Jump_Strong;
		
};
static Player_tag Player_Mesh;
class tag_Title:public tag_Scene
{
private:
	int Tex[10];
	bool Fade_Counter;
	bool Fade_Counter1;
	float yajirusi_Move;
	int turm;
	bool Exit;
	bool Title_Bgm;
	bool Start_Effect = false;
	int Effect_Count;
public:
	virtual void Init(void);
	virtual void Update(void);
	virtual void Draw(void);
	virtual void Uninit(void);

	VECTOR3 GetPlayerPosition(void);
	bool Main_Exit();
	
};
extern tag_Title TITLE;
