#pragma once
#include "common.h"
#include "Scene.h"
#define SPEED 0.015

struct player
{
	VECTOR3 Trans;
	VECTOR3 Scale;
	VECTOR3 Min, Max;
	BOOL Life;
	float Move_Velocity;
	int Start_Count;
	int Time_Count;
	int Boost_Gage;
};
static player Player_Struct;
class tag_Player :public tag_Scene
{
private:

	MESH m_pBox;
	MESH m_pSpeher;
	DEVICE m_pd3dDevice;
	VECTOR3 m_Min, m_Max;
	float Velocity;
	float Grabity_Speed;
	float Grabity_Velocity;
	VECTOR3 g_vecFront;
	VECTOR3 g_vecRight;
	float Plus_MaxSpeed;
	bool Jump;
	float Jump_Speed;
	float Jump_Velocity;
	int Jump_Type;
	VECTOR3 vecDir;
	VECTOR3 vecUp;
	float Speed;
	float Jump_up ;
	bool Jump_Sound;
	bool Start_Sound;
	bool Start_Bgm;
	bool Boost;
	int Boost_Count;
	float Move_Speed;
public:

	virtual void Init(void);
	virtual void Update(void);
	virtual void Draw(void);
	virtual void Uninit(void);
	player Info();
	//VECTOR3 Position();
	VECTOR3 Min();
	VECTOR3 Max();
	int Plus_Boost(int index);
	float Gravity(float index);
	float PlusSpeed(float index);
	bool Distroy();
	bool Type_Boost();
	float Position_Z(float index);
	float F_Velocity(float index);
	float hyouji_speed();
	//int StartCount();
	//int Time();
	//float F_Speed();
	//bool Life();
	//int Get_Boost();
};
extern tag_Player Player;