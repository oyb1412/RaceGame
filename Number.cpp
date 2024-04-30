#include "texture.h"
#include "mydirect3d.h"
#include <d3d9.h>
#include <tchar.h>
#include <d3dx9.h>
#include "sprite.h"
#include "Number.h"

void tag_Number::Init(void)
{
	NUMBER.size.x = NUMBER_SIZE_X_MAX;
	NUMBER.size.y = NUMBER_SIZE_Y;
	tex[0] = Texture.SetLoadFile("Accet/Texture/Font.png", NUMBER.size.x, NUMBER.size.y);
	NUMBER.Visible = true;
}


void tag_Number::Draw(int number, float x, float y,float Trans_x,int max,int fade)
{
	int Score;
	for (int i =max; i > 0; i--)
	{
		Score = number % 10;
		Sprite.Draw_Number(tex[0], Trans_x+ (x * i), y, Score  * NUMBER_SIZE_X , 0, NUMBER_SIZE_X, NUMBER_SIZE_Y,fade);
		number /= 10;
	}
}
void tag_Number::Draw(int number,int transx,int transy)
{
	Sprite.Draw_Number(tex[0], transx , transy, number  * NUMBER_SIZE_X, 0, NUMBER_SIZE_X, NUMBER_SIZE_Y);

}
void tag_Number::Destroy(void)
{
	NUMBER.Visible = false;
}
void tag_Number::Used(void)
{
	NUMBER.Visible;
}
