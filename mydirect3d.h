#ifndef _MYDIRECT3D_H_	
#define _MYDIRECT3D_H_

#include <windows.h>
#include <d3d9.h>
#include "common.h"



class tag_MyDirect 
{
private:
	LPDIRECT3D9 g_pD3D;
	DEVICE g_pDevice;
public:
	

	bool Init(HWND hWnd);
	void Uninit(void);
	DEVICE Get(void);
};

extern tag_MyDirect Device;
#endif

