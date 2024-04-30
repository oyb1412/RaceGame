#include "Light.h"
#include <d3d9.h>
#include "common.h"
#include "mydirect3d.h"
static DEVICE m_pd3dDevice;

void Light_SetUp_Cube()
{
	m_pd3dDevice = Device.Get();
	
	D3DLIGHT9 light = {};
	
	light.Type = D3DLIGHT_DIRECTIONAL;
	light.Diffuse.r =1.0f;
	light.Diffuse.g = 1.0f;
	light.Diffuse.b = 1.0f;
	light.Diffuse.a = 1.0f;
	VECTOR3 vecDirLight(1.0f,1.0f, 1.0f); 
	Normal3((VECTOR3*)&light.Direction, &vecDirLight);
	m_pd3dDevice->SetLight(0, &light);
	m_pd3dDevice->LightEnable(0, TRUE); 
	m_pd3dDevice->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_COLOR1);
	m_pd3dDevice->SetRenderState(D3DRS_NORMALIZENORMALS, TRUE);
	m_pd3dDevice->SetRenderState(D3DRS_AMBIENT, D3DCOLOR_RGBA(230, 230, 230, 1));
	m_pd3dDevice->SetRenderState(D3DRS_AMBIENTMATERIALSOURCE, D3DMCS_COLOR1);
}
void Light_SetUp_Model()
{
	m_pd3dDevice = Device.Get();
	D3DLIGHT9 light = {};
	
	light.Type = D3DLIGHT_DIRECTIONAL;
	light.Diffuse.r = 1.0f;
	light.Diffuse.g = 1.0f;
	light.Diffuse.b = 1.0f;
	light.Diffuse.a = 1.0f;

	light.Ambient.r = 0.23f;
	light.Ambient.g = 0.23f;
	light.Ambient.b = 0.23f;
	light.Ambient.a = 0.23f;
	
	VECTOR3 vecDirLight(1.0f, 1.0f, -1.0f); 	
	Normal3((VECTOR3*)&light.Direction, &vecDirLight);
	m_pd3dDevice->SetLight(1, &light);
	m_pd3dDevice->LightEnable(1, TRUE); 
	m_pd3dDevice->SetRenderState(D3DRS_DIFFUSEMATERIALSOURCE, D3DMCS_MATERIAL);
	m_pd3dDevice->SetRenderState(D3DRS_NORMALIZENORMALS, TRUE);
	m_pd3dDevice->SetRenderState(D3DRS_AMBIENT, D3DCOLOR_RGBA(230, 230, 230, 200));
	m_pd3dDevice->SetRenderState(D3DRS_AMBIENTMATERIALSOURCE, D3DMCS_MATERIAL);
}
void Light_Uninit()
{
	if (m_pd3dDevice != NULL)
	{
		m_pd3dDevice->Release();
	}
}