#pragma once
#include "Scene.h"
class tag_Colision : public tag_Scene
{
public:
	struct collison
	{
		bool Chaos;
		bool GameOver;
		bool Distory;
		bool Jump;
		bool Goal;
		int Time_Save[3];
		int Goal_Count;
		bool Hit;
		int Boost_Count;
		bool Boost;
		int Slow_Count;
		bool Slow;
		int Jump_Count;
		int Chaos_Count;
	};
	collison Collision;
	virtual void Init(void);
	virtual void Update(void);
	BOOL CheckSphereIntersect(VECTOR3 vCenter1, float fRadius1, VECTOR3 vCenter2, float fRadius2);
	BOOL CheckCubelntersection(VECTOR3 *vMin1, VECTOR3 *vMax1, VECTOR3 *vMin2, VECTOR3 *vMax2);
	bool Ground_S1(int index_start, int index_end);
	bool Ground_S2(int index_start, int index_end);
	bool Ground_S3(int index_start, int index_end);
	bool Hit_Coin(int index_start, int index_end);

	bool Ground_T(int index_start, int index_end);
	collison  Collsion_Info();

private:
	int turm;
	bool Fade_Trigger = false;


};

extern tag_Colision Colision;