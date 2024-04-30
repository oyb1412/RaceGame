#include"mydirect3d.h"
#include<d3d9.h>
#include<d3dx9.h>
#include"common.h"
#include "Player.h"
#include"input.h"
#include "Camera.h"
#include "Collison.h"
void tag_Camera::Init()
{
	Camera.g_vecFront =VECTOR3(0.0f, 0.0f, 1.0f);
	Camera.g_vecRight = VECTOR3(1.0f, 0.0f, 0.0f);
	Camera.g_vecUp = VECTOR3(0.0f, 1.0f, 0.0f);
	pDevice = NULL;
	Camera.g_Position = VECTOR3(0.0f, 1.0f, -5.0f);
	Camera.at = VECTOR3(0.0f, 0.0f, 0.0f);
	g_Fov = 30.0f;
	Camera.Angle_Velocity = 0.0f;
}
void tag_Camera::Uninit()
{
	if (pDevice != NULL)
	{
		pDevice->Release();
	}
}
void tag_Camera::Update()//update
{
	pDevice = Device.Get();
	MATRIX mtxRotation;
	VECTOR3 vecDir(0.0f, 0.0f, 0.0f);

	Normal3(&Camera.g_vecFront, &Camera.g_vecFront);
	Normal3(&Camera.g_vecRight, &Camera.g_vecRight);
	Normal3(&vecDir, &vecDir);
	if (!Colision.Collsion_Info().Goal)
	{
		Camera.g_Position.x = Player.Info().Trans.x;
		Camera.g_Position.y = Player.Info().Trans.y + 1.5f;
		Camera.g_Position.z = Player.Info().Trans.z - 8.0f;
		Camera.at = Player.Info().Trans;
	}


	if (Colision.Collsion_Info().Goal)
	{
		MatRotatY(&mtxRotation, RADIAN(0.5));
		//	D3DXVec3TransformNormal(&g_vecUp, &g_vecUp, &mtxRotation);
		D3DXVec3TransformNormal(&Camera.g_vecFront, &Camera.g_vecFront, &mtxRotation);
		D3DXVec3TransformNormal(&Camera.g_vecRight, &Camera.g_vecRight, &mtxRotation);
		Camera.g_Position = Camera.at - (Camera.g_vecFront * 7.0);
		Camera.g_Position.y = 1.5f;
		Camera.at.y = Player.Info().Trans.y;
	}
	Camera.eye = Camera.g_Position;
	VECTOR3 up = Camera.g_vecUp;
	D3DXMatrixLookAtLH(&Camera.mtxView, &Camera.eye, &Camera.at, &up);

	pDevice->SetTransform(D3DTS_VIEW, &Camera.mtxView);
	MATRIX mtxProjection;

	D3DXMatrixPerspectiveFovLH(&mtxProjection, RADIAN(g_Fov), (float)SCREEN_WIDTH / SCREEN_HEIGHT, 0.1f, 100.0f);

	pDevice->SetTransform(D3DTS_PROJECTION, &mtxProjection);
	pDevice->SetFVF(FVF_CAMERA);
}
tag_Camera::camera tag_Camera::Camera_Info()
{
	return Camera;
}
