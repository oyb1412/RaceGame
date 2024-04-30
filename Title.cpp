#include "common.h"
#include "texture.h"
#include "sprite.h"
#include "input.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "Scene.h"
#include "Fade.h"
#include "Mesh.h"
#include "Effect.h"
#include "Title.h"
#include "Cube.h"
#include "Player.h"
#include "Camera.h"
#include "sound.h"
#include "pluseffect.h"
void tag_Title::Init()
{
	Tex[0] = Texture.SetLoadFile("Accet/Texture/End_Bg.jpg", SCREEN_WIDTH, SCREEN_HEIGHT+100);
	Tex[1] = Texture.SetLoadFile("Accet/Texture/Title_Tex.png", SCREEN_WIDTH*0.5, SCREEN_HEIGHT*0.3);
	Tex[2] = Texture.SetLoadFile("Accet/Texture/Title_yajirusi.png", SCREEN_WIDTH*0.1, SCREEN_HEIGHT*0.1);
	Tex[3] = Texture.SetLoadFile("Accet/Texture/Title_Name.png", SCREEN_WIDTH * 0.6, SCREEN_HEIGHT * 0.3);
	

	Mesh.Set("Accet/Mesh/space ship .blend.x", 1);
	Fade.Init();
	Player.Init();
	Camera.Init();
	Cube.Init();
	Effect.Init();
	PlusEffect_Init();

	Fade_Counter = false;
	Fade_Counter1 = false;
	Player_Mesh.Trans = VECTOR3(-0.1f, 1.5f, 1.0f);
	Player_Mesh.Move_Counter[2] = {0};
	Player_Mesh.Move[2] = { false };
	Player_Mesh.Jump_Speed = 0.0f;
	Player_Mesh.Jump_Strong = 0.001f;
	yajirusi_Move = 0.0f;
	turm = 0;
	Exit = false;
	Start_Effect = false;
	Title_Bgm = false;
	Effect_Count = 0;
}
void tag_Title::Update()
{
	Camera.Update();
	Effect.Update();

	turm++;
	if (!Title_Bgm)
	{
		Sound.Play(SOUND_LABEL_TITLEBGM);
		Title_Bgm = true;
	}
	if (!Fade_Counter && !Fade_Counter1)
	{
		Fade.Fade_Funtion(false);
	}
	if (!Start_Effect)
	{
		if (Keyboard.IsPress(DIK_SPACE) && yajirusi_Move == 0 && !Player_Mesh.Move[0])
		{
			Player_Mesh.Move[0] = true;
			Sound.Stop();
			Sound.Play(SOUND_LABEL_SE_CHOICE1);
			Start_Effect = true;
		}

		if (Keyboard.IsPress(DIK_SPACE) && yajirusi_Move == 80 && !Player_Mesh.Move[1])
		{
			Player_Mesh.Move[1] = true;
			Sound.Stop();
			Sound.Play(SOUND_LABEL_SE_CHOICE1);
			Start_Effect = true;

		}
		if (Keyboard.IsPress(DIK_SPACE) && yajirusi_Move == 160 && !Exit)
		{
			Exit = true;
			Sound.Stop();
			Sound.Play(SOUND_LABEL_SE_CHOICE1);
			Start_Effect = true;

		}
	}
	if (Start_Effect)
	{
		Effect_Count++;
	}
	if (Effect_Count <= 30 && Start_Effect)
	{
		Effect.Create(SPEED_UP,0, Player_Mesh.Trans.y, Player_Mesh.Trans.z/*Trans_Y, Pos_Z*/);
	}
	if (Effect_Count > 30)
	{
		Start_Effect = false;
	}

	if (Player_Mesh.Move[0])
	{

		Player_Mesh.Move_Counter[0]++;
		Player_Mesh.Trans.z += 2.0f;
	}
	if (Player_Mesh.Move_Counter[0] > 60)
	{
		Player_Mesh.Move[0] = false;
		Fade_Counter = true;
	}
	if (Fade_Counter && !Fade_Counter1)
	{
		Fade.Fade_Funtion(true);
		if (Fade.Fade_Funtion(false,true) >= 255 && Fade_Counter)
		{
			Sound.Stop();
			Scene.SetNextScene(SCENE_S1);
			Player_Mesh.Move_Counter[0] = 0;
		}
	}
	if (Player_Mesh.Move[1])
	{
	
		Player_Mesh.Move_Counter[1] ++;
		Player_Mesh.Trans.z += 2.0f;
	}
	if (Player_Mesh .Move_Counter[1]> 60)
	{
		Player_Mesh.Move[1] = false;
		Fade_Counter1 = true;
	}
	if (Fade_Counter1 && !Fade_Counter)
	{
		Fade.Fade_In();
		if (Fade.Fade_Count() >= 255 && Fade_Counter1)
		{
			Sound.Stop();
			Scene.SetNextScene(SCENE_TUTORIAL);
			Player_Mesh.Move_Counter[1] = 0;
			Fade_Counter1 = false;
		}
	}
	if (Keyboard.IsPress(DIK_UP) && turm > 0 && yajirusi_Move > 0 && !Player_Mesh.Move[0] && !Exit)
	{
		Sound.Play(SOUND_LABEL_SE_CHOICE);
		yajirusi_Move -= 80;
		turm = -10;
	}
	if (Keyboard.IsPress(DIK_DOWN) && turm > 0 && yajirusi_Move < 180 && !Player_Mesh.Move[0] && !Exit)
	{
		Sound.Play(SOUND_LABEL_SE_CHOICE);

		yajirusi_Move += 80;
		turm = -10;
	}


	Player_Mesh.Trans.y += Player_Mesh.Jump_Speed;
	if (Player_Mesh.Trans.y > 0.0f)
	{
		Player_Mesh.Jump_Speed -= Player_Mesh.Jump_Strong;
	}
	else if (Player_Mesh.Trans.y <= 0.0f)
	{
		Player_Mesh.Jump_Speed = -Player_Mesh.Jump_Speed;
	}
	PlusEffect_Creat(Player_Mesh.Trans.x, Player_Mesh.Trans.y, Player_Mesh.Trans.z, D3DCOLOR_XRGB(240, 255, 255), 20, 60);
	PlusEffect_Update();

}
void tag_Title::Draw()
{
	Sprite.Draw_MiddleStandard(Tex[0], SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.5);
	PlusEffect_Draw();

	Cube.Draw(7, 3, 1, 10, 0, 0, 1);
	Mesh.Create(1, Player_Mesh.Trans.x, Player_Mesh.Trans.y, Player_Mesh.Trans.z, 0, 0.07, 0.07, 0.07);
	Sprite.Draw_MiddleStandard(Tex[1], SCREEN_WIDTH*0.5,SCREEN_HEIGHT*0.7);
	Sprite.Draw_MiddleStandard(Tex[2], SCREEN_WIDTH * 0.2, SCREEN_HEIGHT * 0.6 + yajirusi_Move);
	Sprite.Draw_MiddleStandard(Tex[3], SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.2);
	Effect.Draw();

}
void tag_Title::Uninit()
{
	Mesh.Uninit();
}
bool tag_Title::Main_Exit()
{
	return Exit;
}
VECTOR3 tag_Title::GetPlayerPosition()
{
	return Player_Mesh.Trans;
}
