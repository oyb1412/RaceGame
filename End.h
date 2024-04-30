#pragma once
#include "common.h"
#include "Scene.h"

class tag_End : public tag_Scene
{
private:
	int Tex[10];
	HWND hWnd;
	bool Fade_Counter;
	float yajirusi_Move;
	float Pos_Z;
	int turm;
	bool Player_Move;
	bool Exit;
	int Player_Move_Counter;
	bool End_Bgm;
public:

	bool Main_Exit();

	virtual void Init(void);
	virtual void Update(void);
	virtual void Draw(void);
	virtual void Uninit(void);
};

extern tag_End End;