#include "common.h"
#include "texture.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "mydirect3d.h"
#include "Plane.h"
#include "C_Ground.h"
#include "Player.h"
#include "Cube.h"
#include "Ground.h"
#include "Effect.h"
#include "Scene.h"

void tag_Ground::Init()
{
	Plane.Init(WALL);
	Plane.Init(GROUND);
	Cube.Init();
}
void tag_Ground::Draw(SCENE Type)
{
	if (Type == SCENE_S1)
	{
		for (int i = 86; i > 69; i--)
		{
			if (i == 71 || i == 73 || i == 75 || i == 77 || i == 79 || i == 81 || i == 83)
			{
				Cube.Draw(15, C_Ground.C_Ground_Info(0, i).Scale.x, C_Ground.C_Ground_Info(0, i).Scale.y + 0.5f, C_Ground.C_Ground_Info(0, i).Scale.z, C_Ground.C_Ground_Info(0, i).Trans.x, C_Ground.C_Ground_Info(0, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(0, i).Trans.z);
			}
			else if (i == 72 || i == 74 || i == 76 || i == 78 || i == 80 || i == 82 || i == 84)
			{
				Cube.Draw(15, C_Ground.C_Ground_Info(0, i).Scale.x, C_Ground.C_Ground_Info(0, i).Scale.y + 0.5f, C_Ground.C_Ground_Info(0, i).Scale.z, C_Ground.C_Ground_Info(0, i).Trans.x, C_Ground.C_Ground_Info(0, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(0, i).Trans.z);
			}
			else if (i < 71)
			{
				Cube.Draw(15, C_Ground.C_Ground_Info(0, i).Scale.x, C_Ground.C_Ground_Info(0, i).Scale.y + 0.5f, C_Ground.C_Ground_Info(0, i).Scale.z, C_Ground.C_Ground_Info(0, i).Trans.x, C_Ground.C_Ground_Info(0, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(0, i).Trans.z);
			}
			else if (i >= 85)
			{
				Cube.Draw(15, C_Ground.C_Ground_Info(0, i).Scale.x, C_Ground.C_Ground_Info(0, i).Scale.y + 0.5f, C_Ground.C_Ground_Info(0, i).Scale.z, C_Ground.C_Ground_Info(0, i).Trans.x, C_Ground.C_Ground_Info(0, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(0, i).Trans.z);

			}

		}

		for (int i = 13; i > 10; i--)
		{
			if (i == 11)
			{
				Cube.Draw(15, C_Ground.C_Ground_Info(0, i).Scale.x, C_Ground.C_Ground_Info(0, i).Scale.y + 0.5f, C_Ground.C_Ground_Info(0, i).Scale.z, C_Ground.C_Ground_Info(0, i).Trans.x, C_Ground.C_Ground_Info(0, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(0, i).Trans.z);
			}
			else
			{
				Cube.Draw(15, C_Ground.C_Ground_Info(0, i).Scale.x, C_Ground.C_Ground_Info(0, i).Scale.y + 0.5f, C_Ground.C_Ground_Info(0, i).Scale.z, C_Ground.C_Ground_Info(0, i).Trans.x, C_Ground.C_Ground_Info(0, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(0, i).Trans.z);
			}
		}
		for (int i = 10; i > 6; i--)
		{
			if (i == 7 || i == 10)
			{
				Cube.Draw(15, C_Ground.C_Ground_Info(0, i).Scale.x, C_Ground.C_Ground_Info(0, i).Scale.y + 0.5f, C_Ground.C_Ground_Info(0, i).Scale.z, C_Ground.C_Ground_Info(0, i).Trans.x, C_Ground.C_Ground_Info(0, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(0, i).Trans.z);
			}
			else if (i == 8 || i == 9)
			{
				Cube.Draw(15, C_Ground.C_Ground_Info(0, i).Scale.x, C_Ground.C_Ground_Info(0, i).Scale.y + 0.5f, C_Ground.C_Ground_Info(0, i).Scale.z, C_Ground.C_Ground_Info(0, i).Trans.x, C_Ground.C_Ground_Info(0, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(0, i).Trans.z);
			}
		}
		for (int i = 6; i > -1; i--)
		{
			if (i == 0)
			{
				Cube.Draw(15, C_Ground.C_Ground_Info(0, i).Scale.x, C_Ground.C_Ground_Info(0, i).Scale.y + 0.5f, C_Ground.C_Ground_Info(0, i).Scale.z, C_Ground.C_Ground_Info(0, i).Trans.x, C_Ground.C_Ground_Info(0, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(0, i).Trans.z);
			}
			else
			{
				Cube.Draw(15, C_Ground.C_Ground_Info(0, i).Scale.x, C_Ground.C_Ground_Info(0, i).Scale.y + 0.5f, C_Ground.C_Ground_Info(0, i).Scale.z, C_Ground.C_Ground_Info(0, i).Trans.x, C_Ground.C_Ground_Info(0, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(0, i).Trans.z);
			}
		}
		for (int i = 94; i > 90; i--)
		{
			Cube.Draw(14, C_Ground.C_Ground_Info(0, i).Scale.x * 0.7, C_Ground.C_Ground_Info(0, i).Scale.y, C_Ground.C_Ground_Info(0, i).Scale.z * 0.7, C_Ground.C_Ground_Info(0, i).Trans.x, C_Ground.C_Ground_Info(0, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(0, i).Trans.z);
			Plane.Draw(GROUND, 3, C_Ground.C_Ground_Info(0, i).Trans.x, C_Ground.C_Ground_Info(0, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(0, i).Trans.z, C_Ground.C_Ground_Info(0, i).Scale.x, C_Ground.C_Ground_Info(0, i).Scale.y, C_Ground.C_Ground_Info(0, i).Scale.z);
		}

		for (int i = 49; i > 44; i--)
		{
			Cube.Draw(14, C_Ground.C_Ground_Info(0, i).Scale.x * 0.8, C_Ground.C_Ground_Info(0, i).Scale.y, C_Ground.C_Ground_Info(0, i).Scale.z * 0.8, C_Ground.C_Ground_Info(0, i).Trans.x, C_Ground.C_Ground_Info(0, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(0, i).Trans.z);
			Plane.Draw(GROUND, 2, C_Ground.C_Ground_Info(0, i).Trans.x, C_Ground.C_Ground_Info(0, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(0, i).Trans.z, C_Ground.C_Ground_Info(0, i).Scale.x * 0.7, C_Ground.C_Ground_Info(0, i).Scale.y, C_Ground.C_Ground_Info(0, i).Scale.z * 0.5);
		}
		for (int i = 44; i > 35; i--)
		{
			Cube.Draw(14, C_Ground.C_Ground_Info(0, i).Scale.x * 0.7, C_Ground.C_Ground_Info(0, i).Scale.y, C_Ground.C_Ground_Info(0, i).Scale.z * 0.7, C_Ground.C_Ground_Info(0, i).Trans.x, C_Ground.C_Ground_Info(0, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(0, i).Trans.z);
			Plane.Draw(GROUND, 4, C_Ground.C_Ground_Info(0, i).Trans.x, C_Ground.C_Ground_Info(0, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(0, i).Trans.z, C_Ground.C_Ground_Info(0, i).Scale.x, C_Ground.C_Ground_Info(0, i).Scale.y, C_Ground.C_Ground_Info(0, i).Scale.z);
		}
		for (int i = 35; i > 27; i--)
		{
			Cube.Draw(14, C_Ground.C_Ground_Info(0, i).Scale.x * 0.7, C_Ground.C_Ground_Info(0, i).Scale.y, C_Ground.C_Ground_Info(0, i).Scale.z * 0.7, C_Ground.C_Ground_Info(0, i).Trans.x, C_Ground.C_Ground_Info(0, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(0, i).Trans.z);
			Plane.Draw(GROUND, 3, C_Ground.C_Ground_Info(0, i).Trans.x, C_Ground.C_Ground_Info(0, i).Trans.y - 0.25, C_Ground.C_Ground_Info(0, i).Trans.z, C_Ground.C_Ground_Info(0, i).Scale.x, C_Ground.C_Ground_Info(0, i).Scale.y, C_Ground.C_Ground_Info(0, i).Scale.z);
		}
		Plane.Draw(GROUND, 1, C_Ground.C_Ground_Info(0, 65).Trans.x, C_Ground.C_Ground_Info(0, 65).Trans.y, C_Ground.C_Ground_Info(0, 65).Trans.z, C_Ground.C_Ground_Info(0, 65).Scale.x, 0.1f, C_Ground.C_Ground_Info(0, 65).Scale.z);
		for (int i = 90; i > 86; i--)
		{
			Plane.Draw(WALL, 0, C_Ground.C_Ground_Info(0, i).Trans.x, C_Ground.C_Ground_Info(0, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(0, i).Trans.z, C_Ground.C_Ground_Info(0, i).Scale.x, C_Ground.C_Ground_Info(0, i).Scale.y, C_Ground.C_Ground_Info(0, i).Scale.z);
		}
		for (int i = 69; i > 65; i--)
		{
			Plane.Draw(WALL, 0, C_Ground.C_Ground_Info(0, i).Trans.x, C_Ground.C_Ground_Info(0, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(0, i).Trans.z, C_Ground.C_Ground_Info(0, i).Scale.x, C_Ground.C_Ground_Info(0, i).Scale.y, C_Ground.C_Ground_Info(0, i).Scale.z);
		}
		for (int i = 64; i > 57; i--)
		{
			Plane.Draw(WALL, 2, C_Ground.C_Ground_Info(0, i).Trans.x, C_Ground.C_Ground_Info(0, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(0, i).Trans.z, C_Ground.C_Ground_Info(0, i).Scale.x, C_Ground.C_Ground_Info(0, i).Scale.y, C_Ground.C_Ground_Info(0, i).Scale.z);
		}
		for (int i = 57; i > 49; i--)
		{
			Plane.Draw(WALL, 0, C_Ground.C_Ground_Info(0, i).Trans.x, C_Ground.C_Ground_Info(0, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(0, i).Trans.z, C_Ground.C_Ground_Info(0, i).Scale.x, C_Ground.C_Ground_Info(0, i).Scale.y, C_Ground.C_Ground_Info(0, i).Scale.z);
		}
	}
	if (Type == SCENE_S2)
	{
		for (int i = 16; i > 12; i--)
		{
			Cube.Draw(17, C_Ground.C_Ground_Info(1, i).Scale.x - 0.7f, C_Ground.C_Ground_Info(1, i).Scale.y + 0.5f, C_Ground.C_Ground_Info(1, i).Scale.z, C_Ground.C_Ground_Info(1, i).Trans.x, C_Ground.C_Ground_Info(1, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(1, i).Trans.z);
		}
		for (int i = 12; i > 4; i--)
		{
			Cube.Draw(17, C_Ground.C_Ground_Info(1, i).Scale.x - 0.7f, C_Ground.C_Ground_Info(1, i).Scale.y + 0.5f, C_Ground.C_Ground_Info(1, i).Scale.z, C_Ground.C_Ground_Info(1, i).Trans.x, C_Ground.C_Ground_Info(1, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(1, i).Trans.z);
		}
		for (int i = 4; i > 1; i--)
		{
			Cube.Draw(17, C_Ground.C_Ground_Info(1, i).Scale.x - 0.7f, C_Ground.C_Ground_Info(1, i).Scale.y + 0.5f, C_Ground.C_Ground_Info(1, i).Scale.z, C_Ground.C_Ground_Info(1, i).Trans.x, C_Ground.C_Ground_Info(1, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(1, i).Trans.z);
		}
		for (int i = 1; i > -1; i--)
		{
			Cube.Draw(17, C_Ground.C_Ground_Info(1, i).Scale.x - 0.7f, C_Ground.C_Ground_Info(1, i).Scale.y + 0.5f, C_Ground.C_Ground_Info(1, i).Scale.z, C_Ground.C_Ground_Info(1, i).Trans.x, C_Ground.C_Ground_Info(1, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(1, i).Trans.z);
		}

		for (int i = 74; i > 71; i--)
		{
			Cube.Draw(14, C_Ground.C_Ground_Info(1, i).Scale.x * 0.7, C_Ground.C_Ground_Info(1, i).Scale.y, C_Ground.C_Ground_Info(1, i).Scale.z * 0.7, C_Ground.C_Ground_Info(1, i).Trans.x, C_Ground.C_Ground_Info(1, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(1, i).Trans.z);
			Plane.Draw(GROUND, 2, C_Ground.C_Ground_Info(1, i).Trans.x, C_Ground.C_Ground_Info(1, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(1, i).Trans.z, C_Ground.C_Ground_Info(1, i).Scale.x * 0.7, C_Ground.C_Ground_Info(1, i).Scale.y, C_Ground.C_Ground_Info(1, i).Scale.z * 0.5);


		}
		for (int i = 71; i > 68; i--)
		{
			Cube.Draw(14, C_Ground.C_Ground_Info(1, i).Scale.x * 0.7, C_Ground.C_Ground_Info(1, i).Scale.y, C_Ground.C_Ground_Info(1, i).Scale.z * 0.7, C_Ground.C_Ground_Info(1, i).Trans.x, C_Ground.C_Ground_Info(1, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(1, i).Trans.z);

			Plane.Draw(GROUND, 4, C_Ground.C_Ground_Info(1, i).Trans.x, C_Ground.C_Ground_Info(1, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(1, i).Trans.z, C_Ground.C_Ground_Info(1, i).Scale.x, C_Ground.C_Ground_Info(1, i).Scale.y, C_Ground.C_Ground_Info(1, i).Scale.z);

		}
		for (int i = 68; i > 62; i--)
		{
			Plane.Draw(WALL, 2, C_Ground.C_Ground_Info(1, i).Trans.x, C_Ground.C_Ground_Info(1, i).Trans.y, C_Ground.C_Ground_Info(1, i).Trans.z, C_Ground.C_Ground_Info(1, i).Scale.x, C_Ground.C_Ground_Info(1, i).Scale.y, C_Ground.C_Ground_Info(1, i).Scale.z);
		}
		for (int i = 62; i > 49; i--)
		{
			Cube.Draw(14, C_Ground.C_Ground_Info(1, i).Scale.x * 0.7, C_Ground.C_Ground_Info(1, i).Scale.y, C_Ground.C_Ground_Info(1, i).Scale.z * 0.7, C_Ground.C_Ground_Info(1, i).Trans.x, C_Ground.C_Ground_Info(1, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(1, i).Trans.z);
			Plane.Draw(GROUND, 3, C_Ground.C_Ground_Info(1, i).Trans.x, C_Ground.C_Ground_Info(1, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(1, i).Trans.z, C_Ground.C_Ground_Info(1, i).Scale.x, C_Ground.C_Ground_Info(1, i).Scale.y, C_Ground.C_Ground_Info(1, i).Scale.z);
		}

		Plane.Draw(GROUND, 1, C_Ground.C_Ground_Info(1, 17).Trans.x, C_Ground.C_Ground_Info(1, 17).Trans.y, C_Ground.C_Ground_Info(1, 17).Trans.z, C_Ground.C_Ground_Info(1, 17).Scale.x, 0.1f, C_Ground.C_Ground_Info(1, 17).Scale.z);

		for (int i = 49; i > 17; i--)
		{
			Plane.Draw(WALL, 0, C_Ground.C_Ground_Info(1, i).Trans.x, C_Ground.C_Ground_Info(1, i).Trans.y, C_Ground.C_Ground_Info(1, i).Trans.z, C_Ground.C_Ground_Info(1, i).Scale.x, C_Ground.C_Ground_Info(1, i).Scale.y, C_Ground.C_Ground_Info(1, i).Scale.z);
		}
	}
	if (Type == SCENE_S3)
	{
		for (int i = 31; i > 29; i--)
		{
			Cube.Draw(16, C_Ground.C_Ground_Info(2, i).Scale.x - 0.7f, C_Ground.C_Ground_Info(2, i).Scale.y + 0.5f, C_Ground.C_Ground_Info(2, i).Scale.z, C_Ground.C_Ground_Info(2, i).Trans.x, C_Ground.C_Ground_Info(2, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(2, i).Trans.z);
			for (int i = 29; i > 19; i--)
			{
				Cube.Draw(16, C_Ground.C_Ground_Info(2, i).Scale.x - 0.7f, C_Ground.C_Ground_Info(2, i).Scale.y + 0.5f, C_Ground.C_Ground_Info(2, i).Scale.z, C_Ground.C_Ground_Info(2, i).Trans.x, C_Ground.C_Ground_Info(2, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(2, i).Trans.z);
			}

			for (int i = 19; i > 10; i--)
			{
				Cube.Draw(16, C_Ground.C_Ground_Info(2, i).Scale.x - 0.7f, C_Ground.C_Ground_Info(2, i).Scale.y + 0.5f, C_Ground.C_Ground_Info(2, i).Scale.z, C_Ground.C_Ground_Info(2, i).Trans.x, C_Ground.C_Ground_Info(2, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(2, i).Trans.z);
			}

			for (int i = 10; i > 3; i--)
			{
				Cube.Draw(16, C_Ground.C_Ground_Info(2, i).Scale.x - 0.7f, C_Ground.C_Ground_Info(2, i).Scale.y + 0.5f, C_Ground.C_Ground_Info(2, i).Scale.z, C_Ground.C_Ground_Info(2, i).Trans.x, C_Ground.C_Ground_Info(2, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(2, i).Trans.z);
			}
			for (int i = 3; i > -1; i--)
			{
				Cube.Draw(16, C_Ground.C_Ground_Info(2, i).Scale.x - 0.7f, C_Ground.C_Ground_Info(2, i).Scale.y + 0.5f, C_Ground.C_Ground_Info(2, i).Scale.z, C_Ground.C_Ground_Info(2, i).Trans.x, C_Ground.C_Ground_Info(2, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(2, i).Trans.z);
			}

			Plane.Draw(GROUND, 1, C_Ground.C_Ground_Info(2, 32).Trans.x, C_Ground.C_Ground_Info(2, 32).Trans.y, C_Ground.C_Ground_Info(2, 32).Trans.z, C_Ground.C_Ground_Info(2, 32).Scale.x, C_Ground.C_Ground_Info(2, 32).Scale.y, C_Ground.C_Ground_Info(2, 32).Scale.z);

			for (int i = 79; i > 61; i--)
			{
				Cube.Draw(14, C_Ground.C_Ground_Info(2, i).Scale.x * 0.7, C_Ground.C_Ground_Info(2, i).Scale.y, C_Ground.C_Ground_Info(2, i).Scale.z * 0.7, C_Ground.C_Ground_Info(2, i).Trans.x, C_Ground.C_Ground_Info(2, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(2, i).Trans.z);
				Plane.Draw(GROUND, 3, C_Ground.C_Ground_Info(2, i).Trans.x, C_Ground.C_Ground_Info(2, i).Trans.y - 0.5, C_Ground.C_Ground_Info(2, i).Trans.z, C_Ground.C_Ground_Info(2, i).Scale.x, C_Ground.C_Ground_Info(2, i).Scale.y, C_Ground.C_Ground_Info(2, i).Scale.z);
			}
			for (int i = 83; i > 79; i--)
			{
				Cube.Draw(14, C_Ground.C_Ground_Info(2, i).Scale.x * 0.7, C_Ground.C_Ground_Info(2, i).Scale.y, C_Ground.C_Ground_Info(2, i).Scale.z * 0.7, C_Ground.C_Ground_Info(2, i).Trans.x, C_Ground.C_Ground_Info(2, i).Trans.y - 0.5f, C_Ground.C_Ground_Info(2, i).Trans.z);
				Plane.Draw(GROUND, 4, C_Ground.C_Ground_Info(2, i).Trans.x, C_Ground.C_Ground_Info(2, i).Trans.y - 0.5, C_Ground.C_Ground_Info(2, i).Trans.z, C_Ground.C_Ground_Info(2, i).Scale.x, C_Ground.C_Ground_Info(2, i).Scale.y, C_Ground.C_Ground_Info(2, i).Scale.z);
			}
			Cube.Draw(14, C_Ground.C_Ground_Info(2, 84).Scale.x * 0.7, C_Ground.C_Ground_Info(2, 84).Scale.y, C_Ground.C_Ground_Info(2, 84).Scale.z * 0.7, C_Ground.C_Ground_Info(2, 84).Trans.x, C_Ground.C_Ground_Info(2, 84).Trans.y - 0.5f, C_Ground.C_Ground_Info(2, 84).Trans.z);
			Plane.Draw(GROUND, 2, C_Ground.C_Ground_Info(2, 84).Trans.x, C_Ground.C_Ground_Info(2, 84).Trans.y - 0.5, C_Ground.C_Ground_Info(2, 84).Trans.z, C_Ground.C_Ground_Info(2, 84).Scale.x * 0.7, C_Ground.C_Ground_Info(2, 84).Scale.y, C_Ground.C_Ground_Info(2, 84).Scale.z * 0.5);

			for (int i = 61; i > 32; i--)
			{
				Plane.Draw(WALL, 0, C_Ground.C_Ground_Info(2, i).Trans.x, C_Ground.C_Ground_Info(2, i).Trans.y, C_Ground.C_Ground_Info(2, i).Trans.z, C_Ground.C_Ground_Info(2, i).Scale.x, C_Ground.C_Ground_Info(2, i).Scale.y, C_Ground.C_Ground_Info(2, i).Scale.z);
			}
		}
	}
}
void tag_Ground::Uninit()
{
	if (m_pd3dDevice != NULL)
	{
		m_pd3dDevice->Release();
	}
	Plane.Uninit();

}


