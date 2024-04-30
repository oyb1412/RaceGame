
#ifndef INPUT_H_
#define INPUT_H_


#include <Windows.h>
#define DIRECTINPUT_VERSION (0x0800)
#define	NUM_KEY_MAX			(256)	

#include <dinput.h>
#include "Scene.h"

class tag_Keyboard : public tag_Scene
{
private:
	LPDIRECTINPUT8			g_pInput = NULL;					
	LPDIRECTINPUTDEVICE8	g_pDevKeyboard = NULL;				
	BYTE					g_aKeyState[NUM_KEY_MAX];			
	BYTE					g_aKeyStateTrigger[NUM_KEY_MAX];	
	BYTE					g_aKeyStateRelease[NUM_KEY_MAX];
public:



	bool init(HINSTANCE hInstance);
	bool Init(HINSTANCE hInstance, HWND hWnd);


	virtual void Update(void);
	virtual void Uninit(void);


	//
	bool IsPress(int nKey);
	bool IsTrigger(int nKey);
	bool IsRelease(int nKey);
};
extern tag_Keyboard Keyboard;
#endif