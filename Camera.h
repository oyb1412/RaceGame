#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "common.h"
#include "Scene.h"
#include "Effect.h"
#define CAMERA_FOV (60)


class tag_Camera : virtual public tag_Effect, virtual public tag_Scene
{
public:

	struct camera
	{
		VECTOR3 g_vecFront;
		VECTOR3 g_vecRight;
		VECTOR3 g_vecUp;
		MATRIX mtxView;
		VECTOR3 eye;
		VECTOR3 g_Position;
		VECTOR3 at;
		float Angle_Velocity;
	};
	camera Camera;
	virtual void Init(void);
	virtual void Update(void);
	virtual void Uninit(void);
	camera Camera_Info();
private:
	DEVICE pDevice;
	float g_Fov;
};

extern tag_Camera Camera;