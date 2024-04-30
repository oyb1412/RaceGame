
#ifndef DEBUG_FONT_H_
#define DEBUG_FONT_H_
#define DEBUG_PRINTF_BUFFER_MAX (256)
#include "Scene.h"



class tag_Font:public tag_Scene
{
private:
	LPD3DXFONT g_pD3DXFont;

public:
	virtual void Init(void);
	virtual void Draw(int x, int y, const char* pFormat, ...);
	virtual void Uninit(void);

	
};

extern tag_Font Font;
#endif // DEBUG_FONT_H_