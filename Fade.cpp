#include "sprite.h"
#include "texture.h"
#include <d3d9.h>
#include <tchar.h>
#include <d3dx9.h>
#include <windows.h>
#include "Fade.h"
#include "common.h"
#include "Scene.h"

void tag_Fade::Init(void)
{
	Fade.position.x = FADE_POSITION_X;
	Fade.position.x = FADE_POSITION_Y;
	Fade.size.x = FADE_SIZE_X;
	Fade.size.y = FADE_SIZE_Y;
	Fade_Out_Start = 0;
	Fade_In_Start = 0;
	Fade_Trigger = false;
	Fade_Number = FADE_MAX;
	tex[0] = Texture.SetLoadFile("Accet/Texture/Fade.png", Fade.size.x, Fade.size.y);
}
void tag_Fade::Fade_Out(void)
{
	Fade_Out_Start++;
	if (Fade_Out_Start >= 25)
	{
		Fade_Number -=4;
	}
	if (Fade_Number < 0) 
	{
		Fade_Number = 0;
	}
}

int tag_Fade::Fade_Funtion(bool Trigger,bool kaesi)
{
	if (!kaesi)
	{
		if (!Trigger)
		{
			Fade_Out();
		}
		if (Trigger)
		{
			Fade_In();
		}
	}
	else
	{
		return Fade_Count();
	}

}

void tag_Fade::Fade_In()
{

		Fade_Number += 4;
	
	if (Fade_Number >= 255)
	{
		Fade_Number = 255;
	}
}
void tag_Fade::Draw(void)
{
	Sprite.Draw_Tex_x_y_Fade(tex[0], Fade.position.x, Fade.position.y, Fade_Number);
}
int tag_Fade::Fade_Count()
{
	return Fade_Number;
}