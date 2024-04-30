#pragma once
#include "common.h"
#include "Scene.h"
class tag_Ground
{
private:
	DEVICE m_pd3dDevice;

public:
	void Init();
	void Draw(SCENE Type);
	void Uninit();


};
extern tag_Ground Ground;