#include <d3dx9.h>
#include "mydirect3d.h"
#include "common.h"
#include "debug_font.h"
#include <stdio.h>

#if defined(_DEBUG) || defined(DEBUG)
//static LPD3DXFONT g_pD3DXFont = NULL;
#endif // _DEBUG || DEBUG


void tag_Font::Init(void)
{
#if defined(_DEBUG) || defined(DEBUG)
	g_pD3DXFont = NULL;
	DEVICE pDevice = Device.Get();

	D3DXCreateFont(pDevice,
		15, 0, 0, 0,
		FALSE,
		SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS, 
		DEFAULT_QUALITY, 
		DEFAULT_PITCH, 
		"Arial",
		&g_pD3DXFont);
#endif // _DEBUG || DEBUG
}


void tag_Font::Uninit(void)
{
#if defined(_DEBUG) || defined(DEBUG)
	if( g_pD3DXFont!=NULL ) {
		g_pD3DXFont->Release();
		g_pD3DXFont = NULL;
	}
#endif // _DEBUG || DEBUG
}


void tag_Font::Draw(int x, int y, const char* pFormat, ...)
{
#if defined(_DEBUG) || defined(DEBUG)
	RECT rect = { x, y, SCREEN_WIDTH, SCREEN_HEIGHT 
	};
	
	va_list argp;
	va_start(argp, pFormat);
	char buf[DEBUG_PRINTF_BUFFER_MAX];
	vsprintf_s(buf, DEBUG_PRINTF_BUFFER_MAX, pFormat, argp);
	va_end(argp);

	g_pD3DXFont->DrawText(NULL,
		buf,
		-1, &rect, DT_LEFT,
		D3DCOLOR_RGBA(255, 255, 255, 255));
#else
	UNREFERENCED_PARAMETER(pFormat);
	UNREFERENCED_PARAMETER(x);
	UNREFERENCED_PARAMETER(y);
#endif // _DEBUG || DEBUG
}
