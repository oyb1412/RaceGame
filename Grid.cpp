#include "Gird.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "common.h"
#include "mydirect3d.h"
static VERTEXBUFFER m_pVB;
static DEVICE m_pd3dDevice;

struct Grid
{
	VECTOR3 Position;
	D3DCOLOR Color;
};
Grid m_Grid[44]; 
void Grid_Init()
{
	m_pd3dDevice = Device.Get();
	int x = 0;

/*	for (int i = 0; i < 11; i++)
	{ 
		m_Grid[i * 2].Position = VECTOR3(-5.0f, -1.0f, 5.0f-i-20);
		m_Grid[i * 2].Color = D3DCOLOR_RGBA(255, 255, 255, 255);
		m_Grid[i * 2 + 1].Position = VECTOR3(5.0f, -1.0f, 5.0f-i - 20);
		m_Grid[i * 2 + 1].Color = D3DCOLOR_RGBA(255, 255, 255, 255);
	}
	for (int i = 11; i < 22; i++)
	{
		m_Grid[i * 2 ].Position = VECTOR3(-5.0f+x, -1.0f, 5.0f - 20);
		m_Grid[i * 2 ].Color = D3DCOLOR_RGBA(255, 255, 255, 255);
		m_Grid[i * 2 + 1 ].Position = VECTOR3(-5.0f+x, -1.0f,- 5.0f - 20);
		m_Grid[i * 2 + 1].Color = D3DCOLOR_RGBA(255, 255, 255, 255);
		x++;
	}*/
	for (int i = 0; i < 11; i++)
	{
		m_Grid[i *  (2 + 2)].Position = VECTOR3(-5.0f, 0.0f, 5.0f-i);
		m_Grid[i *  (2 + 2)+1].Position = VECTOR3(5.0f, 0.0f, 5.0f-i);
		m_Grid[i *  (2 + 2)+2].Position = VECTOR3(-5.0f+i, 0.0f, 5.0f);
		m_Grid[i *  (2 + 2)+3].Position = VECTOR3(-5.0f+i, 0.0f, -5.0f);
		m_Grid[i * (2 + 2)].Color = D3DCOLOR_RGBA(255, 255, 255, 255);
		m_Grid[i * (2 + 2)+1].Color = D3DCOLOR_RGBA(255, 255, 255, 255);
		m_Grid[i * (2 + 2)+2].Color = D3DCOLOR_RGBA(255, 255, 255, 255);
		m_Grid[i * (2 + 2)+3].Color = D3DCOLOR_RGBA(255, 255, 255, 255);		
	}

	m_pd3dDevice->CreateVertexBuffer(sizeof(m_Grid), 0, FVF_PC, D3DPOOL_DEFAULT, &m_pVB, NULL);
	void *pVertex;
	m_pVB->Lock(0, sizeof(pVertex), &pVertex, 0);
	memcpy(pVertex, m_Grid, sizeof(m_Grid));
	m_pVB->Unlock();

	

}
void Grid_Draw()
{
	m_pd3dDevice = Device.Get();
	m_pd3dDevice->SetStreamSource(0, m_pVB, 0, sizeof(Grid));
	MATRIX mtxWorld;
	D3DXMatrixIdentity(&mtxWorld);
	m_pd3dDevice->SetTransform(D3DTS_WORLD, &mtxWorld);
	m_pd3dDevice->SetFVF(FVF_PC);
	m_pd3dDevice->SetTexture(0, NULL);
	m_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);//ライティングしない
	//m_pd3dDevice->DrawPrimitiveUP(D3DPT_LINELIST, 22, &m_Grid, sizeof(Grid));
	m_pd3dDevice->DrawPrimitive(D3DPT_LINELIST, 0,22);

}
void Grid_Uninit()
{
	if (m_pd3dDevice)
	{
		m_pd3dDevice->Release();
	}
	if (m_pVB)
	{
		m_pVB->Release();
	}
}