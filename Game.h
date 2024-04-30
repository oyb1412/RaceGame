#pragma once
#include "Cube.h"

class tag_Game
{
private:
	HWND hWnd;
	bool Fade_Counter;
public:
	void Init(SCENE Type);
	void Uninit();
	void Update(SCENE Type);
	void Draw(SCENE Type);

};
extern tag_Game Game;


