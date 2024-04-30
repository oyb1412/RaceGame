#include "common.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "Scene.h"
#include "Fade.h"
#include "Mesh.h"
#include "sound.h"
#include "Camera.h"
#include "End.h"
#include "Player.h"
void tag_End::Init()
{
	Tex[0] = Texture.SetLoadFile("Accet/Texture/End_Bg.jpg", 4250, 3000);
	Tex[1] = Texture.SetLoadFile("Accet/Texture/End_Tex.png", 1500, 700);
	Tex[2] = Texture.SetLoadFile("Accet/Texture/Title_yajirusi.png", 500, 300);
	Tex[3] = Texture.SetLoadFile("Accet/Texture/End_Name.png", 1800, 800);

	Fade.Init();
	Fade_Counter = false;
	yajirusi_Move = 0.0f;
	End_Bgm = false;
	Pos_Z = -20.0f;
	turm = 0;
	Player.Init();
	Camera.Init();

	Player_Move = false;
	Exit = false;
	Player_Move_Counter = 0;
	Mesh.Set("Accet/Mesh/AV.x", 1);
}
void tag_End::Update()
{
	turm++;
	Camera.Update();
	if (!End_Bgm)
	{
		Sound.Play(SOUND_LABEL_ENDBGM);
		End_Bgm = true;
	}
	if (!Fade_Counter)
	{
	//	Fade.Fade_Out();
		Fade.Fade_Funtion(false);
	}
	if (Keyboard.IsPress(DIK_SPACE) && yajirusi_Move == 0 && !Player_Move)
	{
		Player_Move = true;
		Sound.Play(SOUND_LABEL_SE_CHOICE1);

	}

	if (Keyboard.IsPress(DIK_SPACE) && yajirusi_Move == 120 && !Exit)
	{
		Exit = true;
		Sound.Play(SOUND_LABEL_SE_CHOICE1);
	}
	
	if (Player_Move)
	{
		Player_Move_Counter++;
		Pos_Z += 1.5f;
	}
	if (Player_Move_Counter > 80)
	{
		Player_Move = false;
		Fade_Counter = true;
	}
	if (Fade_Counter)
	{
		//Fade.Fade_In();
		Fade.Fade_Funtion(true);
		if (/*Fade.Fade_Count()*/Fade.Fade_Funtion(false,true) >= 255)
		{
			Sound.Stop();
			Scene.SetNextScene(SCENE_TITLE);
		}
	}

	if (Keyboard.IsPress(DIK_UP) && turm > 0 && yajirusi_Move > 0 &&!Player_Move &&!Exit)
	{
		yajirusi_Move -= 120;
		turm = -20;
		Sound.Play(SOUND_LABEL_SE_CHOICE);

	}
	if (Keyboard.IsPress(DIK_DOWN) && turm > 0 && yajirusi_Move < 120 && !Player_Move && !Exit)
	{
		yajirusi_Move += 120;
		turm = -20;
		Sound.Play(SOUND_LABEL_SE_CHOICE);

	}
}
void tag_End::Draw()
{
	Sprite.Draw_Tex_x_y(Tex[0], 1260, 850, 1, 1, 1);
	Mesh.Create(1, -1, -15, Pos_Z, 0, 0.05, 0.05, 0.05);
	Sprite.Draw_Tex_x_y(Tex[1], 900, 680, 1, 1, 1);
	Sprite.Draw_Tex_x_y_Fade(Tex[2], 400, 555 + yajirusi_Move, 255);
	Sprite.Draw_Tex_x_y_Fade(Tex[3], 920, 300, 255);

}
void tag_End::Uninit()
{
	Mesh.Uninit();
}
bool tag_End::Main_Exit()
{
	return Exit;
}