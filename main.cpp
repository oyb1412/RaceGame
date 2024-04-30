#include <windows.h>
#include <dinput.h>

#include "common.h"
#include "mydirect3d.h"
#include "texture.h"
#include "HighScore.h"
#include "Tutorial.h"
#include "sprite.h"
#include "system_timer.h"
#include "HighScore.h"
#include "TwoD.h"
#include "Effect.h"
#include "Shadow.h"
#include "Plane.h"
#include "debug_font.h"
#include "Name.h"
#include "Number.h"
#include "Ground.h"
#include "Mesh.h"
#include "End.h"
#include "Coin.h"
#include <d3d9.h>
#include <tchar.h>
#include <d3dx9.h>
#include "input.h"
#include "Light.h"
#include "sound.h"
#include "fade.h"
#include "Collison.h"
#include "Camera.h"
#include "Game.h"
#include "Title.h"
#include "Wait.h"
#include "C_Ground.h"
#include "Player.h"
#include "Scene.h"
#pragma comment(lib,"d3d9.lib")
#if defined(DEBUG)||defined(_DEBUG)
#pragma comment(lib,"d3dx9d.lib")
#else
#pragma comment(lib,"d3dx9.lib")
#endif


#define CLASS_NAME       "GameWindow"
#define WINDOW_CAPTION   "Racing Game"
#define r ((unsigned int)100)  
#define pc ((unsigned int)(r * 2 * D3DX_PI))  
#define r1 ((unsigned int)10)  
#define pc1 ((unsigned int)(r1 * 2 * D3DX_PI))  
#define FPS_MEASUREMENT_TIME 1.0
typedef struct Vertex2d_tag
{
	D3DXVECTOR4 position;
	D3DCOLOR color;
	VECTOR2 uv;
}Vertex2d;




static bool Init(HWND hWnd);
static void Uninit(void);
static void Update(void);
static void Draw(void);
static int g_Framecount = 0;
static int g_FPSBaseFrameCount = 0;
static double g_FPSBaseTime = 0.0;
static double g_StaticFramTime = 0.0;
static float g_FPS = 0.0f;
static int Mouse_Move_X = 0;
static int Mouse_Move_Y = 0;

HWND hWnd = NULL;
DEVICE g_pDevice = NULL;
static bool flag = false;
static int flame = 0;
static float count = 0;

tag_Title TITLE;
tag_Tutorial TUTORIAL;
tag_TwoD TwoD;
tag_Wait Wait;
tag_Texture Texture;
tag_System_Timer System_Timer;
tag_Sprite Sprite;
tag_Sound Sound;
tag_Shadow Shadow;
tag_Scene Scene;
tag_Game Game;
tag_Player Player;
tag_Number Number;
tag_Name Name;
tag_MyDirect Device;
tag_Plane Plane;
tag_Mesh Mesh;
tag_Keyboard Keyboard;
tag_HighScore HighScore;
tag_Ground Ground;
tag_Fade Fade;
tag_End End;
tag_Effect Effect;
tag_coin COIN;
tag_Font Font;
tag_Cube Cube;
tag_Colision Colision;
tag_Camera Camera;
tag_C_Ground C_Ground;

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	WNDCLASS wc = {};//Window class
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = CLASS_NAME;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1);

	RegisterClass(&wc);

	DWORD window_style = WS_OVERLAPPEDWINDOW ^ (WS_THICKFRAME | WS_MAXIMIZEBOX);

	RECT window_rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	AdjustWindowRect(&window_rect, window_style, FALSE);

	int window_width = window_rect.right - window_rect.left;
	int window_height = window_rect.bottom - window_rect.top;

	int desktop_width = GetSystemMetrics(SM_CXSCREEN);
	int desktop_height = GetSystemMetrics(SM_CYSCREEN);

	int window_x = max((desktop_width - window_width) / 2, 0);
	int window_y = max((desktop_height - window_height - 150) / 2, 0);

	hWnd = CreateWindow(
		CLASS_NAME,
		WINDOW_CAPTION,
		window_style,
		window_x,
		window_y,
		window_width,
		window_height,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	Keyboard.Init(hInstance, hWnd);
	Sound.Init(hWnd);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	MSG msg = {};
	if (!Init(hWnd))
	{
		return -1;
	}
	while (WM_QUIT != msg.message) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			double time = System_Timer.GetTime();
			if (time - g_StaticFramTime < 1.0 / 60.0)
			{
				Sleep(0);
			}
			else
			{
				g_StaticFramTime = time;
				Update();
				Draw();
				if (TITLE.Main_Exit()|| End.Main_Exit())
				{
					break;
				}
				Scene.Change();
				
			}
		}
	}
	Uninit();
	return(int)msg.wParam;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) {
			SendMessage(hWnd, WM_CLOSE, 0, 0);
		}
		break;
	case WM_CLOSE:
		if (MessageBox(hWnd, "정말로 종료하시겠습니까?", "EXIT", MB_OKCANCEL | MB_DEFBUTTON2) == IDOK) {
			DestroyWindow(hWnd);
		}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	};
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

bool Init(HWND hWnd)
{
	Device.Init(hWnd);
	g_pDevice = Device.Get();
	Number.Init();
	Fade.Init();
	Font.Init();
	Scene.Init();
	Texture.Load(hWnd);

	System_Timer.Init();
	System_Timer.Start();
	g_Framecount = g_FPSBaseFrameCount = 0;
	g_FPS = 0.0f;
	g_FPSBaseTime = System_Timer.GetTime();
	g_StaticFramTime = g_FPSBaseTime;
	return true;
}
void Uninit(void)
{
	Sound.Uninit();
	Camera.Uninit();
	Cube.Uninit();
	Effect.Uninit();
	Player.Uninit();
	Shadow.Uninit();
	Scene.Uninit();
	Texture.Destroy();
	Device.Uninit();
	Font.Uninit();
	Keyboard.Uninit();
}
void Update(void)
{

	g_Framecount++;
	double time = System_Timer.GetTime();
	if (time - g_FPSBaseTime >= FPS_MEASUREMENT_TIME)
	{
		g_FPS = (float)((g_Framecount - g_FPSBaseFrameCount) / (time - g_FPSBaseTime));

		g_FPSBaseFrameCount = g_Framecount;
		g_FPSBaseTime = time;
	}
	Keyboard.Update();
	Scene.Update();

}
void Draw(void)
{	
	g_pDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_RGBA(0,0, 0,255), 1.0f, 0);
	g_pDevice->BeginScene();

	g_pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);

	g_pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	g_pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);

	g_pDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
	g_pDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
	g_pDevice->SetRenderState(D3DRS_ALPHAREF, 140);

	g_pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pDevice->SetRenderState(D3DRS_ZWRITEENABLE,FALSE);
	
	g_pDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);


	g_pDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);
	g_pDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);
	g_pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	Scene.Draw();
	Fade.Draw();

	
	



	g_pDevice->EndScene();
	g_pDevice->Present(NULL, NULL, NULL, NULL);
}
        