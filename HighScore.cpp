#include "texture.h"
#include "sound.h"
#include "Name.h"
#include <stdio.h>
#include "sprite.h"
#include "Fade.h"
#include "Number.h"
#include "input.h"
#include "Scene.h"
#include "HighScore.h"
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
static int Fade_Count  ;
static float Tex_Fade[7] = {0};
static bool Tex_Counter = false;
int z;

void tag_HighScore::Init()
{
	Fade_Count = 0;
	Fade_Counter = false;
	Restart = false;
	Restart_Count = 0;
	for (int i = 0; i < 5; i++)
	{
		Save[5].Name[i] = Name.Save(i);
		T_Temp.Name[i] = Name.Save(i);
	}
	
		Save[5].Time = Name.Time_Info();
		T_Temp.Time = Name.Time_Info();
		FILE* rfp = fopen("Score.txt", "r");
		fscanf(rfp, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &Save[0].Time, &Save[1].Time, &Save[2].Time, &Save[3].Time, &Save[4].Time,
			&Save[0].Name[0], &Save[0].Name[1], &Save[0].Name[2], &Save[0].Name[3], &Save[0].Name[4],
			&Save[1].Name[0], &Save[1].Name[1], &Save[1].Name[2], &Save[1].Name[3], &Save[1].Name[4],
			&Save[2].Name[0], &Save[2].Name[1], &Save[2].Name[2], &Save[2].Name[3], &Save[2].Name[4],
			&Save[3].Name[0], &Save[3].Name[1], &Save[3].Name[2], &Save[3].Name[3], &Save[3].Name[4],
			&Save[4].Name[0], &Save[4].Name[1], &Save[4].Name[2], &Save[4].Name[3], &Save[4].Name[4]
		);
		fclose(rfp);
	

		for (int j = 0; j < 5; j++)
		{
			for (int i = 0; i < 5; i++)
			{
				if (Save[i].Time > Save[i + 1].Time)
				{
					Temp = Save[i];
					Save[i] = Save[i + 1];
					Save[i + 1] = Temp;
				}
			}
		
		}
	

	
		FILE* wfp = fopen("Score.txt", "w");
		fprintf(wfp, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", Save[0].Time, Save[1].Time, Save[2].Time, Save[3].Time, Save[4].Time,
			Save[0].Name[0], Save[0].Name[1], Save[0].Name[2], Save[0].Name[3], Save[0].Name[4],
			Save[1].Name[0], Save[1].Name[1], Save[1].Name[2], Save[1].Name[3], Save[1].Name[4],
			Save[2].Name[0], Save[2].Name[1], Save[2].Name[2], Save[2].Name[3], Save[2].Name[4],
			Save[3].Name[0], Save[3].Name[1], Save[3].Name[2], Save[3].Name[3], Save[3].Name[4],
			Save[4].Name[0], Save[4].Name[1], Save[4].Name[2], Save[4].Name[3], Save[4].Name[4]
		);
		fclose(wfp);
	
	Tex[0] = Texture.SetLoadFile("Accet/Texture/Number/Rank5.png", 650, 300);
	Tex[1] = Texture.SetLoadFile("Accet/Texture/Number/Rank4.png", 650, 300);
	Tex[2] = Texture.SetLoadFile("Accet/Texture/Number/Rank3.png", 650, 300);
	Tex[3] = Texture.SetLoadFile("Accet/Texture/Number/Rank2.png", 650, 300);
	Tex[4] = Texture.SetLoadFile("Accet/Texture/Number/Rank1.png", 650, 300);

	Tex[5] = Texture.SetLoadFile("Accet/Texture/End_Bg.jpg", 4250, 3000);
	Tex[7] = Texture.SetLoadFile("Accet/Texture/Number/Ranking.png",3500, 1700);
	Tex[8] = Texture.SetLoadFile("Accet/Texture/Number/PS.png", 2000, 300);
	Tex[9] = Texture.SetLoadFile("Accet/Texture/Number/Rankingsoto.png", 3000,500);
	Tex[10] = Texture.SetLoadFile("Accet/Texture/Number/Ranking1.png", 3000, 500);
	Tex[11] = Texture.SetLoadFile("Accet/Texture/Number/Ranking2.png", 3000, 500);
	Tex[12] = Texture.SetLoadFile("Accet/Texture/Number/Ranking3.png", 3000, 500);
	Tex[13] = Texture.SetLoadFile("Accet/Texture/Number/Ranking4.png", 3000, 500);
	Tex[14] = Texture.SetLoadFile("Accet/Texture/Number/Ranking5.png", 3000, 500);


	H_Tex[0] = Texture.SetLoadFile("Accet/Texture/Number/Q.png", 300, 300);
	H_Tex[1] = Texture.SetLoadFile("Accet/Texture/Number/W.png", 300, 300);
	H_Tex[2] = Texture.SetLoadFile("Accet/Texture/Number/E.png", 300, 300);
	H_Tex[3] = Texture.SetLoadFile("Accet/Texture/Number/R.png", 300, 300);
	H_Tex[4] = Texture.SetLoadFile("Accet/Texture/Number/T.png", 300, 300);
	H_Tex[5] = Texture.SetLoadFile("Accet/Texture/Number/Y.png", 300, 300);
	H_Tex[6] = Texture.SetLoadFile("Accet/Texture/Number/U.png", 300, 300);
	H_Tex[7] = Texture.SetLoadFile("Accet/Texture/Number/I.png", 300, 300);
	H_Tex[8] = Texture.SetLoadFile("Accet/Texture/Number/O.png", 300, 300);
	H_Tex[9] = Texture.SetLoadFile("Accet/Texture/Number/P.png", 300, 300);
	H_Tex[10] = Texture.SetLoadFile("Accet/Texture/Number/A.png", 300, 300);
	H_Tex[11] = Texture.SetLoadFile("Accet/Texture/Number/S.png", 300, 300);
	H_Tex[12] = Texture.SetLoadFile("Accet/Texture/Number/D.png", 300, 300);
	H_Tex[13] = Texture.SetLoadFile("Accet/Texture/Number/F.png", 300, 300);
	H_Tex[14] = Texture.SetLoadFile("Accet/Texture/Number/G.png", 300, 300);
	H_Tex[15] = Texture.SetLoadFile("Accet/Texture/Number/H.png", 300, 300);
	H_Tex[16] = Texture.SetLoadFile("Accet/Texture/Number/J.png", 300, 300);
	H_Tex[17] = Texture.SetLoadFile("Accet/Texture/Number/K.png", 300, 300);
	H_Tex[18] = Texture.SetLoadFile("Accet/Texture/Number/L.png", 300, 300);
	H_Tex[19] = Texture.SetLoadFile("Accet/Texture/Number/Z.png", 300, 300);
	H_Tex[20] = Texture.SetLoadFile("Accet/Texture/Number/X.png", 300, 300);
	H_Tex[21] = Texture.SetLoadFile("Accet/Texture/Number/C.png", 300, 300);

	H_Tex[22] = Texture.SetLoadFile("Accet/Texture/Number/V.png", 300, 300);
	H_Tex[23] = Texture.SetLoadFile("Accet/Texture/Number/B.png", 300, 300);
	H_Tex[24] = Texture.SetLoadFile("Accet/Texture/Number/N.png", 300, 300);
	H_Tex[25] = Texture.SetLoadFile("Accet/Texture/Number/M.png", 300, 300);

	Texture.Load(hWnd);

}
void tag_HighScore::Update()
{
	if (!Fade_Counter)
	{
		Fade.Fade_Funtion(false);
	}
	if (Keyboard.IsPress(DIK_SPACE)&& Fade_Count == 5)
	{
		Restart = true;
	}
	if (Restart)
	{
		Restart_Count++;
	}
	if (Restart_Count > 60)
	{
		Fade_Counter = true;
	}
	if (Fade_Counter)
	{
		Fade.Fade_Funtion(true);
		if (Fade.Fade_Funtion(false,true) >= 255 && Fade_Counter)
		{
			Sound.Stop();
			Scene.SetNextScene(SCENE_TITLE);
		}
	}



	switch (Fade_Count)
	{
	case 0:
		Tex_Fade[0] += 3.0f;
		if (Tex_Fade[0] >= 255)
		{
			Tex_Fade[0] = 255;

			Fade_Count = 1;
		}
		break;
	case 1:
		Tex_Fade[1] += 3.0f;
		if (Tex_Fade[1] >= 255)
		{
			Tex_Fade[1] = 255;
			Fade_Count = 2;
		}
		break;
	case 2:
		Tex_Fade[2] += 3.0f;
		if (Tex_Fade[2] >= 255)
		{
			Tex_Fade[2] = 255;
			Fade_Count = 3;
		}
		break;
	case 3:
		Tex_Fade[3] += 3.0f;
		if (Tex_Fade[3] >= 255)
		{
			Tex_Fade[3] = 255;
			Fade_Count = 4;
		}
		break;
	case 4:
		Tex_Fade[4] += 3.0f;
		if (Tex_Fade[4] >= 255)
		{
			Tex_Fade[4] = 255;
			Fade_Count = 5;
		}
	case 5:
		if (Tex_Fade[6] < 255)
		{
			Tex_Fade[6] += 5;
		}
		if (Tex_Fade[6] >= 255)
		{
			Tex_Fade[6] = 255;
		}
		if (!Tex_Counter)
		{
			Tex_Fade[5] += 6.0f;
		}
		if (Tex_Fade[5] >= 255 && !Tex_Counter)
		{
			Tex_Fade[5] = 255;
			Tex_Counter = true;
		}
		if (Tex_Counter)
		{
			Tex_Fade[5] -= 6.0f;
		}
		if (Tex_Counter && Tex_Fade[5] <= 0)
		{
			Tex_Fade[5] = 0;
			Tex_Counter = false;
		}
		break;
	default:
		break;
	}
}
void tag_HighScore::Draw()
{
	Sprite.Draw_Tex_x_y(Tex[5], 1260, 850, 1, 1, 1);
	Sprite.Draw_Tex_x_y(Tex[7], 1160, 700, 1, 1, 1);



	Sprite.Draw_Tex_x_y_Fade(Tex[8], 900, 810, Tex_Fade[5]);

	if (Fade_Count == 5)
	{
		if (T_Temp.Time == Save[0].Time)
		{
			Sprite.Draw_Tex_x_y_Fade(Tex[10], 1090, 195, Tex_Fade[6]);
		}
		if (T_Temp.Time == Save[1].Time)
		{
			Sprite.Draw_Tex_x_y_Fade(Tex[11], 1090, 195, Tex_Fade[6]);
		}
		if (T_Temp.Time == Save[2].Time)
		{
			Sprite.Draw_Tex_x_y_Fade(Tex[12], 1090, 195, Tex_Fade[6]);
		}
		if (T_Temp.Time == Save[3].Time)
		{
			Sprite.Draw_Tex_x_y_Fade(Tex[13], 1090, 195, Tex_Fade[6]);
		}
		if (T_Temp.Time == Save[4].Time)
		{
			Sprite.Draw_Tex_x_y_Fade(Tex[14], 1090, 195, Tex_Fade[6]);
		}
		if (T_Temp.Time > Save[4].Time)
		{
			Sprite.Draw_Tex_x_y_Fade(Tex[9], 1090, 195, Tex_Fade[6]);
		}
		//if (Temp.Time > 0)
		{
			for (int i = 0; i < 5; i++)
			{
				Sprite.Draw_Tex_x_y_Fade(H_Tex[T_Temp.Name[i]-1], 520 + (60 * i), 130, Tex_Fade[5]);
			}
			Number.Draw(T_Temp.Time, 90, 85, 780, 3, Tex_Fade[5]);

		}
	}


	for (int i = 0; i < 5; i++)
	{
		Sprite.Draw_Tex_x_y_Fade(Tex[i], 305, 720-(i*87), Tex_Fade[i]);
	}


	for (int q = 0; q < 5; q++)
	{
		if (q == 0)
		{
			z = 4;
		}
		if (q == 1)
		{
			z = 3;
		}
		if (q == 2)
		{
			z = 2;
		}
		if (q == 3)
		{
			z = 1;
		}
		if (q == 4)
		{
			z = 0;
		}
		for (int i = 0; i < 5; i++)
		{
			Sprite.Draw_Tex_x_y_Fade(H_Tex[Save[z].Name[i]-1], 500 + (60 * i), (718 - (87 * q)), Tex_Fade[q]);
		}
		Number.Draw(Save[z].Time, 90, 675 - (87 * q), 840, 3, Tex_Fade[q]);
	
	}

}

int tag_HighScore::F_Time(int index)
{
	return Save[index].Time;
}


int tag_HighScore::namae(int index,int i)
{
	return Save[index].Name[i];
}