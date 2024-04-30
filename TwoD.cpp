#include "TwoD.h"
#include "texture.h"
#include "common.h"
#include "sprite.h"
#include "Player.h"
#include "Collison.h"
#include "C_Ground.h"
#include "Number.h"
#include <d3d9.h>
#include "Tutorial.h"
#include <d3dx9.h>
#include "Scene.h"

void tag_TwoD::Init()
{
	Tex[0] = Texture.SetLoadFile("Accet/Texture/space2.jpg", SCREEN_WIDTH, SCREEN_HEIGHT);
	Tex[1] = Texture.SetLoadFile("Accet/Texture/3.png", SCREEN_WIDTH*0.1, SCREEN_HEIGHT*0.1);
	Tex[2] = Texture.SetLoadFile("Accet/Texture/2.png", SCREEN_WIDTH * 0.1, SCREEN_HEIGHT * 0.1);
	Tex[3] = Texture.SetLoadFile("Accet/Texture/1.png", SCREEN_WIDTH * 0.1, SCREEN_HEIGHT * 0.1);
	Tex[4] = Texture.SetLoadFile("Accet/Texture/Start.png", SCREEN_WIDTH * 0.2, SCREEN_HEIGHT * 0.2);
	Tex[5] = Texture.SetLoadFile("Accet/Texture/Goal.png", SCREEN_WIDTH * 0.15, SCREEN_HEIGHT * 0.15);
	Tex[6] = Texture.SetLoadFile("Accet/Texture/gray1.jpg", 1950,200);
	Tex[7] = Texture.SetLoadFile("Accet/Texture/murasaki1.jpg", 20, 190);
	Tex[8] = Texture.SetLoadFile("Accet/Texture/Goal_Check.png",500, 300);
	Tex[9] = Texture.SetLoadFile("Accet/Texture/Stage1.png", 400, 300);
	Tex[10] = Texture.SetLoadFile("Accet/Texture/Stage2.png", 400, 300);
	Tex[11] = Texture.SetLoadFile("Accet/Texture/Stage3.png", 400, 300);
	Tex[12] = Texture.SetLoadFile("Accet/Texture/Text_40.png", 900, 300);
	Tex[13] = Texture.SetLoadFile("Accet/Texture/Text_60.png", 900, 300);
	Tex[14] = Texture.SetLoadFile("Accet/Texture/Text_90.png", 900, 300);
	Tex[15] = Texture.SetLoadFile("Accet/Texture/Tutorial1.png", 3000, 300);
	Tex[16] = Texture.SetLoadFile("Accet/Texture/Tutorial2.png", 3000, 350);
	Tex[17] = Texture.SetLoadFile("Accet/Texture/Tutorial3.png", 3000, 400);
	Tex[18] = Texture.SetLoadFile("Accet/Texture/Tutorial4.png", 3000, 300);
	Tex[19] = Texture.SetLoadFile("Accet/Texture/Tutorial5.png", 3000, 300);
	Tex[20] = Texture.SetLoadFile("Accet/Texture/Tutorial6.png", 3000, 350);
	Tex[21] = Texture.SetLoadFile("Accet/Texture/Tutorial7.png", 3000, 350);
	Tex[22] = Texture.SetLoadFile("Accet/Texture/Tutorial8.png", 3000, 300);
	Tex[23] = Texture.SetLoadFile("Accet/Texture/Tutorial9.png", 3000, 400);
	Tex[24] = Texture.SetLoadFile("Accet/Texture/Tutorial10.png", 500, 150);
	Tex[25] = Texture.SetLoadFile("Accet/Texture/Tutorial11.png", 520, 170);
	Tex[26] = Texture.SetLoadFile("Accet/Texture/Warning.png", 200, 200);
	Tex[27] = Texture.SetLoadFile("Accet/Texture/Warning1.png", 200, 200);
	Tex[28] = Texture.SetLoadFile("Accet/Texture/Warning2.png", 200, 200);
	Tex[29] = Texture.SetLoadFile("Accet/Texture/Boost.png", 300, 600);
	Tex[30] = Texture.SetLoadFile("Accet/Texture/ao.jpg", 230, 50);
	Tex[31] = Texture.SetLoadFile("Accet/Texture/Tutorial12.png", 3000, 400);
	Tex[32] = Texture.SetLoadFile("Accet/Texture/Time.png", 1100, 500);
	Tex[33] = Texture.SetLoadFile("Accet/Texture/S1_Text1.png", 1500, 400);
	Tex[34] = Texture.SetLoadFile("Accet/Texture/S1_Text2.png", 2000, 500);
	Tex[35] = Texture.SetLoadFile("Accet/Texture/space3.jpg", 4250, 3000);
	Tex[36] = Texture.SetLoadFile("Accet/Texture/S2_Text1.png", 1500, 400);
	Tex[37] = Texture.SetLoadFile("Accet/Texture/S2_Text2.png", 2000, 500);
	Tex[38] = Texture.SetLoadFile("Accet/Texture/blackholl.jpg", 4250, 3000);
	Tex[39] = Texture.SetLoadFile("Accet/Texture/S3_Text1.png", 1500, 400);
	Tex[40] = Texture.SetLoadFile("Accet/Texture/S3_Text2.png", 2000, 500);
	Tex[41] = Texture.SetLoadFile("Accet/Texture/Pocus.png", 2000, 500);
	Tex[42] = Texture.SetLoadFile("Accet/Texture/Goal_Text.png", 500, 200);
	Tex[43] = Texture.SetLoadFile("Accet/Texture/Clear1_Text.png", 200, 50);
	Tex[44] = Texture.SetLoadFile("Accet/Texture/Clear2_Text.png", 200, 50);
	Tex[45] = Texture.SetLoadFile("Accet/Texture/Clear3_Text.png", 200, 50);
	Tex[46] = Texture.SetLoadFile("Accet/Texture/Warning_Image.png", 200, 200);

	Warning_Fade = 0;
	Warning = false;
	Warning1 = false;
	Tex_Move = 0;
	Counter = 0;
	Tex_Size = 1.5f;
	Goal_Tex_Size = 1.5f;
}
void tag_TwoD::Update()
{
	Counter+=1;
	Tex_Move += 8.0f;
	if (!Tex_Fade_Trigger)
	{
		Tex_Fade -= 10;
	}
	if (Tex_Fade <= 0)
	{
		Tex_Fade_Trigger = true;
	}
	if (Tex_Fade_Trigger)
	{
		Tex_Fade += 10;
	}
	if (Tex_Fade >= 255 && Tex_Fade_Trigger)
	{
		Tex_Fade_Trigger = false;
	}




	if (Tex_Size > 1.0)
	{
		Tex_Size -= 0.02f;
	}
	if (Player.Info().Start_Count == 60)
	{
		Tex_Size = 1.5f;
	}
	if (Player.Info().Start_Count == 120)
	{
		Tex_Size = 1.5f;
	}
	if (Player.Info().Start_Count == 180)
	{
		Tex_Size = 1.5f;
	}
	if (Goal_Tex_Size < 2.0f)
	{
		Goal_Tex_Size += 0.02f;
	}

	if (Player.Info().Trans.z < 100)
	{
		Warning = true;
	}
	if (Warning && !Warning1)
	{
		Warning_Fade += 10;
	}
	if (!Warning1&&Warning && Warning_Fade >= 255)
	{
		Warning_Fade = 255;
		Warning1 =true;
	}
	if (Warning1 && Warning_Fade > 0)
	{
		Warning_Fade -= 10;
	}
	if (Warning1 && Warning_Fade <= 0 )
	{
		Warning_Fade = 0;
		Warning1 = false;
	}

}
void tag_TwoD::Draw()
{
	if (Scene.Stage_Type(SCENE_S1))
	{
		Sprite.Draw_MiddleStandard(Tex[0], SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.5);

	}
	if (Scene.Stage_Type(SCENE_S2))
	{
		Sprite.Draw_Tex_x_y(Tex[35], 1260, 800, 1, 1, 1);
	}
	if (Scene.Stage_Type(SCENE_S3))
	{
		Sprite.Draw_Tex_x_y(Tex[38], 1260, 800, 1, 1, 1);
	}
}
void tag_TwoD::T_Draw()
{


	if (Counter < 200)
	{
		Sprite.Draw_Tex_x_y(Tex[15], 1100, 250, 1, 1, 1);
	}
	if (Counter > 200 && Counter < 400)
	{
		Sprite.Draw_Tex_x_y(Tex[16], 1100, 250, 1, 1, 1);
	}
	if (Counter > 400 && Player.Info().Trans.z <= 50)
	{
		Sprite.Draw_Tex_x_y(Tex[17], 1100, 250, 1, 1, 1);
	}
	if (Player.Info().Trans.z > 50 && Player.Info().Trans.z <=250)
	{
		Sprite.Draw_Tex_x_y(Tex[18], 1100, 250, 1, 1, 1);
	}
	if (Player.Info().Trans.z > 250 && Player.Info().Trans.z <= 450)
	{
		Sprite.Draw_Tex_x_y(Tex[19], 1100, 250, 1, 1, 1);
	}
	if (Player.Info().Trans.z > 450 && Player.Info().Trans.z <= 650)
	{
		Sprite.Draw_Tex_x_y(Tex[20], 1100, 250, 1, 1, 1);
	}
	if (Player.Info().Trans.z > 650 && Player.Info().Trans.z <= 800)
	{
		Sprite.Draw_Tex_x_y(Tex[21], 1100, 250, 1, 1, 1);
	}
	if (Player.Info().Trans.z > 800 && Player.Info().Trans.z <= 900)
	{
		Sprite.Draw_Tex_x_y(Tex[22], 1100, 250, 1, 1, 1);
	}

	if (Player.Info().Trans.z > 950 && Player.Info().Trans.z <= 1300)
	{
		Sprite.Draw_Tex_x_y(Tex[31], 1100, 250, 1, 1, 1);
	}

	if (Player.Info().Trans.z > 1300)
	{
		Sprite.Draw_Tex_x_y(Tex[23], 1100, 250, 1, 1, 1);

	}
	Sprite.Draw_Tex_x_y(Tex[24], 900, 55, 1, 1, 1);
	Sprite.Draw_Tex_x_y(Tex[25], 1140, 700, 1, 1, 1);

}
void tag_TwoD::Tex_Draw()
{
	if (!Scene.Stage_Type(SCENE_TUTORIAL))
	{
		if (Player.Info().Start_Count < 60)
		{
			Sprite.Draw_MiddleStandard(Tex[1], SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.3,Tex_Size);

			//Sprite.Draw_Tex_x_y(Tex[1], SCREEN_WIDTH / 2 + 40, SCREEN_HEIGHT / 2 - 80, Tex_Size, Tex_Size, Tex_Size);
		}
		if (Player.Info().Start_Count > 60 && Player.Info().Start_Count <= 120)
		{
			Sprite.Draw_MiddleStandard(Tex[2], SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.3, Tex_Size);

			//Sprite.Draw_Tex_x_y(Tex[2], SCREEN_WIDTH / 2 + 40, SCREEN_HEIGHT / 2 - 80, Tex_Size, Tex_Size, Tex_Size);
		}
		if (Player.Info().Start_Count > 120 && Player.Info().Start_Count <= 180)
		{
			Sprite.Draw_MiddleStandard(Tex[3], SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.3, Tex_Size);

			//Sprite.Draw_Tex_x_y(Tex[3], SCREEN_WIDTH / 2 + 40, SCREEN_HEIGHT / 2 - 80, Tex_Size, Tex_Size, Tex_Size);
		}
		if (Player.Info().Start_Count <= 300 && Player.Info().Start_Count > 180)
		{
			Sprite.Draw_MiddleStandard(Tex[4], SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.3, Tex_Size);

			//Sprite.Draw_Tex_x_y(Tex[4], SCREEN_WIDTH / 2 + 70, SCREEN_HEIGHT / 2 - 80, Tex_Size, Tex_Size, Tex_Size);
		}
	}
	if (Colision.Collsion_Info().Boost || Player.Type_Boost())
	Sprite.Draw_Tex_x_y(Tex[41], 1400, 730, 3, 5, 3);

	Sprite.Draw_Tex_x_y(Tex[6], 930, 700, 1, 1, 1);
	Sprite.Draw_Tex_x_y(Tex[8], 1080, 660, 1, 1, 1);
	
	if (Colision.Collsion_Info().Goal && Colision.Collsion_Info().Goal_Count <= 300)
	{
		Sprite.Draw_MiddleStandard(Tex[5], SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.3, Goal_Tex_Size);
	}
	if (Colision.Collsion_Info().Goal && Colision.Collsion_Info().Goal_Count > 300)
	{
		if (Scene.Stage_Type(SCENE_S1))
		{
			Sprite.Draw_MiddleStandard(Tex[43], SCREEN_WIDTH * 0.4, SCREEN_HEIGHT * 0.2, Goal_Tex_Size, Tex_Fade);
			if(Colision.Collsion_Info().Time_Save[0] > 0)
			Number.Draw(Colision.Collsion_Info().Time_Save[0], 90, 160, 700, 2, Tex_Fade);
		}
		else
		{
			Sprite.Draw_MiddleStandard(Tex[43], SCREEN_WIDTH * 0.4, SCREEN_HEIGHT * 0.2, Goal_Tex_Size);
			if (Colision.Collsion_Info().Time_Save[0] > 0)
			Number.Draw(Colision.Collsion_Info().Time_Save[0], 90, 160, 700, 2);

		}
		if (Scene.Stage_Type(SCENE_S2))
		{
			Sprite.Draw_MiddleStandard(Tex[44], SCREEN_WIDTH * 0.4, SCREEN_HEIGHT * 0.3, Goal_Tex_Size, Tex_Fade);
			if (Colision.Collsion_Info().Time_Save[1] > 0)
			Number.Draw(Colision.Collsion_Info().Time_Save[1], 90, 240, 700, 2, Tex_Fade);

		}
		else
		{
			Sprite.Draw_MiddleStandard(Tex[44], SCREEN_WIDTH * 0.4, SCREEN_HEIGHT * 0.3, Goal_Tex_Size);
			if (Colision.Collsion_Info().Time_Save[1] > 0)
			Number.Draw(Colision.Collsion_Info().Time_Save[1], 90, 240, 700, 2);

		}
		if (Scene.Stage_Type(SCENE_S3))
		{
			Sprite.Draw_MiddleStandard(Tex[45], SCREEN_WIDTH * 0.4, SCREEN_HEIGHT * 0.4, Goal_Tex_Size, Tex_Fade);
			if (Colision.Collsion_Info().Time_Save[2] > 0)
			Number.Draw(Colision.Collsion_Info().Time_Save[2], 90, 320, 700, 2, Tex_Fade);

		}
		else
		{
			Sprite.Draw_MiddleStandard(Tex[45], SCREEN_WIDTH * 0.4, SCREEN_HEIGHT * 0.4, Goal_Tex_Size);
			if (Colision.Collsion_Info().Time_Save[2] > 0)
			Number.Draw(Colision.Collsion_Info().Time_Save[2], 90, 320, 700, 2);

		}
	

	}

	Sprite.Draw_Tex_x_y(Tex[29], 150,700, 1, 1, 1);
	for (int i = 0; i < Player.Info().Boost_Gage/60; i++)
	{
		Sprite.Draw_Tex_x_y(Tex[30], 138.0f, 702.0f -(18.0f*i), 1.0f, 1.0f, 1.0f);
	}
	Sprite.Draw_Tex_x_y(Tex[32], 630, 110, 1, 1, 1);

	if (Scene.Stage_Type(SCENE_TUTORIAL))
	{
		for (int i = 0; i < 100; i++)
		{
			if (TUTORIAL.difference() < 1000 - (10 * i))
			{
				Sprite.Draw_Tex_x_y(Tex[7], 353.0f + (6.0f * i), 698.0f, 1.0f, 1.0f, 1.0f);
			}
		}
		//Sprite.Draw_Tex_x_y(Tex[14], 740, 55, 1, 1, 1);
	}
	if (Scene.Stage_Type(SCENE_S1))
	{
		for (int i = 0; i < 100; i++)
		{
			if (C_Ground.difference(0) < 1100 - (11 * i))
			{
				Sprite.Draw_Tex_x_y(Tex[7], 353.0f + (6.0f * i), 698.0f, 1.0f, 1.0f, 1.0f);
			}
		}
		Sprite.Draw_Tex_x_y(Tex[9], SCREEN_WIDTH / 2 + 70, SCREEN_HEIGHT / 2 + 240, 1, 1, 1);
		Sprite.Draw_Tex_x_y(Tex[12],930, 75, 1, 1, 1);
		Sprite.Draw_Tex_x_y(Tex[33], 1700- Tex_Move, 200, 1, 1, 1);
		Sprite.Draw_Tex_x_y(Tex[34], 1750-Tex_Move, 500, 1, 1, 1);
	//	Sprite.Draw_Middle(Tex[1], 0, 0, 255);
	}
	if (Scene.Stage_Type(SCENE_S2))
	{
		for (int i = 0; i < 100; i++)
		{
			if (C_Ground.difference(1) < 1500 - (15 * i))
			{
				Sprite.Draw_Tex_x_y(Tex[7], 353.0f + (6.0f * i), 698.0f, 1.0f, 1.0f, 1.0f);
			}
		}
		Sprite.Draw_Tex_x_y(Tex[10], SCREEN_WIDTH / 2 + 70, SCREEN_HEIGHT / 2 + 240, 1, 1, 1);
		Sprite.Draw_Tex_x_y(Tex[14], 930, 75, 1, 1, 1);
		Sprite.Draw_Tex_x_y(Tex[36], 1700 - Tex_Move, 200, 1, 1, 1);
		Sprite.Draw_Tex_x_y(Tex[37], 1750 - Tex_Move, 500, 1, 1, 1);

		if (Player.Info().Trans.z > 150 && Player.Info().Trans.z < 250)
		{
			Sprite.Draw_MiddleStandard(Tex[46], SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.2,1,Warning_Fade);
		}

		if (Player.Info().Trans.z > 250 && Player.Info().Trans.z < 350)
		{
			Sprite.Draw_MiddleStandard(Tex[46], SCREEN_WIDTH * 0.7, SCREEN_HEIGHT * 0.2, 1, Warning_Fade);
		}

		if (Player.Info().Trans.z > 350 && Player.Info().Trans.z < 450)
		{
			Sprite.Draw_MiddleStandard(Tex[46], SCREEN_WIDTH * 0.3, SCREEN_HEIGHT * 0.2, 1, Warning_Fade);
		}

		if (Player.Info().Trans.z > 450 && Player.Info().Trans.z < 530)
		{
			Sprite.Draw_MiddleStandard(Tex[46], SCREEN_WIDTH * 0.7, SCREEN_HEIGHT * 0.2, 1, Warning_Fade);
		}

		if (Player.Info().Trans.z > 500 && Player.Info().Trans.z < 600)
		{
			Sprite.Draw_MiddleStandard(Tex[46], SCREEN_WIDTH * 0.3, SCREEN_HEIGHT * 0.2, 1, Warning_Fade);
			Sprite.Draw_MiddleStandard(Tex[46], SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.2, 1, Warning_Fade);
		}
		if (Player.Info().Trans.z > 600 && Player.Info().Trans.z < 750)
		{
			Sprite.Draw_MiddleStandard(Tex[46], SCREEN_WIDTH * 0.7, SCREEN_HEIGHT * 0.2, 1, Warning_Fade);
			Sprite.Draw_MiddleStandard(Tex[46], SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.2, 1, Warning_Fade);
		}
	}
	if (Scene.Stage_Type(SCENE_S3))
	{
		for (int i = 0; i < 100; i++)
		{
			if (C_Ground.difference(2) < 2300 - (23 * i))
			{
				Sprite.Draw_Tex_x_y(Tex[7], 353.0f + (6.0f * i), 698.0f, 1.0f, 1.0f, 1.0f);
			}
		}
		Sprite.Draw_Tex_x_y(Tex[11], SCREEN_WIDTH / 2 + 70, SCREEN_HEIGHT / 2 + 240, 1, 1, 1);
		Sprite.Draw_Tex_x_y(Tex[14], 930, 75, 1, 1, 1);
		Sprite.Draw_Tex_x_y(Tex[39], 1700 - Tex_Move, 200, 1, 1, 1);
		Sprite.Draw_Tex_x_y(Tex[40], 1750 - Tex_Move, 500, 1, 1, 1);

		if (Player.Info().Trans.z > 800 && Player.Info().Trans.z < 1100)
		{
			Sprite.Draw_MiddleStandard(Tex[26], SCREEN_WIDTH * 0.25, SCREEN_HEIGHT * 0.2, 1, Warning_Fade);
		}
		if (Player.Info().Trans.z > 1400 && Player.Info().Trans.z < 1600)
		{
			Sprite.Draw_MiddleStandard(Tex[27], SCREEN_WIDTH * 0.75, SCREEN_HEIGHT * 0.2, 1, Warning_Fade);
		}
		if (Player.Info().Trans.z > 1900 && Player.Info().Trans.z < 2100)
		{
			Sprite.Draw_MiddleStandard(Tex[28], SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.2, 1, Warning_Fade);
		}
	}

	if (Colision.Collsion_Info().Goal && Colision.Collsion_Info().Goal_Count >= 300)
	{
		Sprite.Draw_MiddleStandard(Tex[42], SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.6,1,Tex_Fade);
	}
	//Sprite.Draw_MiddleStandard(Texture.Tex[GROUND1], SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.6);
}
void tag_TwoD::Uninit()
{

}

int tag_TwoD::Count()
{
	return Counter;
}