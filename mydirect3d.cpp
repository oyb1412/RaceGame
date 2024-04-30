

#include <d3d9.h>
#include <windows.h>
#include "common.h"
#include "mydirect3d.h"



bool tag_MyDirect::Init(HWND hWnd)
{
	g_pDevice = NULL;
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (g_pD3D == NULL)
	{
		MessageBox(hWnd, "g_pD3D? null?????", "??", MB_OKCANCEL | MB_ICONWARNING | MB_DEFBUTTON2);
		return false;
	}
	D3DPRESENT_PARAMETERS d3dpp = {};
	d3dpp.BackBufferWidth = SCREEN_WIDTH;
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.BackBufferCount = 1;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.Windowed = TRUE; 
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	


	HRESULT hr = g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &g_pDevice);
	if (FAILED(hr))
	{
		MessageBox(hWnd, "CreateDevice??", "??", MB_OKCANCEL | MB_DEFBUTTON2);
		return false;
	}

	return true;
}



void tag_MyDirect::Uninit(void)
{
	if (g_pDevice != NULL)
	{
		g_pDevice->Release();
		g_pDevice = NULL;
	}

	if (g_pD3D != NULL)
	{
		g_pD3D->Release();
		g_pD3D = NULL;
	}
}

DEVICE tag_MyDirect::Get(void)
{
	if (g_pDevice == NULL)
	{
		MessageBox(0, "CreateDevice??", "??", MB_OKCANCEL | MB_DEFBUTTON2);
	}
	return g_pDevice;
}