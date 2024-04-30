/*======================================================================================================
		windows‚Ì?Ž¦  [common.h]
																					Date:2019/6/5
--------------------------------------------------------------------------------------------------------

======================================================================================================*/
#include <d3dx9.h>
#ifndef _COMMON_H_	
#define _COMMON_H_
       
#define SCREEN_WIDTH (1300)   
#define SCREEN_HEIGHT (800)     

#define VECTOR3 D3DXVECTOR3
#define VECTOR2 D3DXVECTOR2
#define MESH LPD3DXMESH
#define DEVICE LPDIRECT3DDEVICE9
#define MATRIX D3DXMATRIX
#define VERTEXBUFFER LPDIRECT3DVERTEXBUFFER9
#define INDEXBUFFER LPDIRECT3DINDEXBUFFER9
#define BUFFER LPD3DXBUFFER
#define MatScaling D3DXMatrixScaling
#define MATERIAL D3DXMATERIAL
#define RADIAN D3DXToRadian 
#define MatTrans D3DXMatrixTranslation
#define MatRotatX D3DXMatrixRotationX
#define MatRotatY D3DXMatrixRotationY
#define MatRotatZ D3DXMatrixRotationZ
#define MatRotatAxis D3DXMatrixRotationAxis
#define Normal3 D3DXVec3Normalize


#define FVF_PCT (D3DFVF_XYZ | D3DFVF_DIFFUSE|D3DFVF_TEX1)
#define FVF_CAMERA (D3DFVF_XYZ|+D3DFVF_DIFFUSE)
#define FVF_PLCT (D3DFVF_XYZ | D3DFVF_NORMAL| D3DFVF_DIFFUSE |D3DFVF_TEX1)
#define FVF_PC (D3DFVF_XYZ|D3DFVF_DIFFUSE)
#define FVF_VERTEXSPRITE (D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1) 
#define TEX_MAX 10

#endif
//#pragma once
