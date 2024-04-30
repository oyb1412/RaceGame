#pragma once
#include "common.h"
#include <d3dx9.h>
enum SCENE
{
	SCENE_TITLE,
	SCENE_S1,
	SCENE_S2,
	SCENE_S3,
	SCENE_S1_WAIT,
	SCENE_S2_WAIT,
	SCENE_S3_WAIT,
	SCENE_NAME,
	SCENE_HIGHSCORE,
	SCENE_TUTORIAL,
	SCENE_CLEAR,
	SCENE_END,
	SCENE_MAX
};

class tag_Scene
{
private:
	bool Ischange = false;
	bool Isfade = false;
public:
	virtual void Init(void);
	virtual void Update(void);
	virtual void Draw(void);
	virtual void Uninit(void);
	void SetNextScene(SCENE nextscene);
	bool Change(void);
	bool Stage_Type(SCENE Type);
protected:
	struct ground
	{
		VECTOR3 Trans;
		VECTOR3 Scale;
		VECTOR3 Min, Max;
	};
};
extern tag_Scene Scene;
