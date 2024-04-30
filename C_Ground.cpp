#include "common.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "mydirect3d.h"
#include "C_Ground.h"
#include "Player.h"
#include <stdlib.h>
#include <time.h>


void tag_C_Ground::Init(SCENE Type)
{
	m_pd3dDevice = Device.Get();
	D3DXCreateBox(m_pd3dDevice, 1.0f, 1.0f, 1.0f, &m_pBox, NULL);
	VECTOR3* pVertices;
	m_pBox->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVertices);
	D3DXComputeBoundingBox(pVertices, m_pBox->GetNumVertices(), m_pBox->GetNumBytesPerVertex(), &m_Min, &m_Max);
	m_pBox->UnlockVertexBuffer();
	srand((unsigned int)time(NULL));
	if (Type == SCENE_S1)
	{
		Trans_difference[0] = 0;

		for (int i = 0; i < 35; i++)
		{
			Mase_Move[i] = false;
		}
		for (int i = 0; i < 55; i++)
		{
			Random_Number[i] = (rand() % 10) + 5;
		}
		{
			Ground[0][0].Trans = VECTOR3(0.0f, 0.0f, 150.0f);
			Ground[0][0].Scale = VECTOR3(10.0f, 0.1f, 300.0f);

			Ground[0][1].Trans = VECTOR3(-10.0f, 0.0f, 50.0f);
			Ground[0][1].Scale = VECTOR3(5.0f, 0.1f, 100.0f);

			Ground[0][2].Trans = VECTOR3(10.0f, 0.0f, 50.0f);
			Ground[0][2].Scale = VECTOR3(5.0f, 0.1f, 100.0f);

			Ground[0][3].Trans = VECTOR3(-10.0f, 0.0f, 160.0f);
			Ground[0][3].Scale = VECTOR3(5.0f, 0.1f, 100.0f);

			Ground[0][4].Trans = VECTOR3(10.0f, 0.0f, 160.0f);
			Ground[0][4].Scale = VECTOR3(5.0f, 0.1f, 100.0f);

			Ground[0][5].Trans = VECTOR3(10.0f, 0.0f, 295.0f);
			Ground[0][5].Scale = VECTOR3(5.0f, 0.1f, 150.0f);

			Ground[0][6].Trans = VECTOR3(-10.0f, 0.0f, 295.0f);
			Ground[0][6].Scale = VECTOR3(5.0f, 0.1f, 150.0f);

			Ground[0][7].Trans = VECTOR3(-4.0f, 0.0f, 410.0f);
			Ground[0][7].Scale = VECTOR3(3.0f, 0.1f, 210.0f);

			Ground[0][8].Trans = VECTOR3(4.0f, 0.0f, 410.0f);
			Ground[0][8].Scale = VECTOR3(3.0f, 0.1f, 210.0f);


			Ground[0][9].Trans = VECTOR3(12.5f, 0.0f, 420.0f);
			Ground[0][9].Scale = VECTOR3(10.0f, 0.1f, 80.0f);

			Ground[0][10].Trans = VECTOR3(-12.5f, 0.0f, 420.0f);
			Ground[0][10].Scale = VECTOR3(10.0f, 0.1f, 80.0f);


			Ground[0][11].Trans = VECTOR3(0.0f, 0.0f, 620.0f);
			Ground[0][11].Scale = VECTOR3(10.0f, 0.1f, 200.0f);

			Ground[0][12].Trans = VECTOR3(-11.0f, 0.0f, 600.0f);
			Ground[0][12].Scale = VECTOR3(5.0f, 0.1f, 100.0f);

			Ground[0][13].Trans = VECTOR3(11.0f, 0.0f, 600.0f);
			Ground[0][13].Scale = VECTOR3(5.0f, 0.1f, 100.0f);

			Ground[0][28].Trans = VECTOR3(-10.0f, 0.5f, 80.0f);
			Ground[0][28].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

			Ground[0][29].Trans = VECTOR3(10.0f, 0.5f, 80.0f);
			Ground[0][29].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

			Ground[0][30].Trans = VECTOR3(-10.0f, 0.5f, 200.0f);
			Ground[0][30].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

			Ground[0][31].Trans = VECTOR3(10.0f, 0.5f, 200.0f);
			Ground[0][31].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

			Ground[0][32].Trans = VECTOR3(-10.0f, 0.5f, 320.0f);
			Ground[0][32].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

			Ground[0][33].Trans = VECTOR3(10.0f, 0.5f, 320.0f);
			Ground[0][33].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

			Ground[0][34].Trans = VECTOR3(-12.0f, 0.5f, 450.0f);
			Ground[0][34].Scale = VECTOR3(6.0f, 0.5f, 15.0f);

			Ground[0][35].Trans = VECTOR3(12.0f, 0.5f, 450.0f);
			Ground[0][35].Scale = VECTOR3(6.0f, 0.5f, 15.0f);

			Ground[0][36].Trans = VECTOR3(-3.0f, 0.5f, 150.0f);
			Ground[0][36].Scale = VECTOR3(3.0f, 0.5f, 15.0f);

			Ground[0][37].Trans = VECTOR3(0.0f, 0.5f, 152.0f);
			Ground[0][37].Scale = VECTOR3(3.0f, 0.5f, 15.0f);

			Ground[0][38].Trans = VECTOR3(3.0f, 0.5f, 150.0f);
			Ground[0][38].Scale = VECTOR3(3.0f, 0.5f, 15.0f);


			Ground[0][39].Trans = VECTOR3(-3.0f, 0.5f, 290.0f);
			Ground[0][39].Scale = VECTOR3(3.5f, 0.5f, 15.0f);

			Ground[0][40].Trans = VECTOR3(3.0f, 0.5f, 290.0f);
			Ground[0][40].Scale = VECTOR3(3.5f, 0.5f, 15.0f);


			Ground[0][41].Trans = VECTOR3(-4.0f, 0.5f, 400.0f);
			Ground[0][41].Scale = VECTOR3(4.0f, 0.5f, 15.0f);

			Ground[0][42].Trans = VECTOR3(4.0f, 0.5f, 400.0f);
			Ground[0][42].Scale = VECTOR3(4.0f, 0.5f, 15.0f);

			Ground[0][43].Trans = VECTOR3(-11.0f, 0.5f, 640.0f);
			Ground[0][43].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

			Ground[0][44].Trans = VECTOR3(11.0f, 0.5f, 640.0f);
			Ground[0][44].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

			Ground[0][45].Trans = VECTOR3(0.0f, 0.5f, 220.0f);
			Ground[0][45].Scale = VECTOR3(5.0f, 0.5f, 20.0f);

			Ground[0][46].Trans = VECTOR3(0.0f, 0.0f, 420.0f);
			Ground[0][46].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

			Ground[0][47].Trans = VECTOR3(0.0f, 0.0f, 350.0f);
			Ground[0][47].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

			Ground[0][48].Trans = VECTOR3(-11.0f, 0.0f, 562.0f);
			Ground[0][48].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

			Ground[0][49].Trans = VECTOR3(11.0f, 0.0f, 562.0f);
			Ground[0][49].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

			Ground[0][50].Trans = VECTOR3(3.0f, 2.0f, 80.0f);
			Ground[0][50].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

			Ground[0][51].Trans = VECTOR3(-3.0f, 2.0f, 80.0f);
			Ground[0][51].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

			Ground[0][52].Trans = VECTOR3(-11.0f, 2.0f, 280.0f);
			Ground[0][52].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

			Ground[0][53].Trans = VECTOR3(11.0f, 2.0f, 280.0f);
			Ground[0][53].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

			Ground[0][54].Trans = VECTOR3(10.0f, 2.0f, 420.0f);
			Ground[0][54].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

			Ground[0][55].Trans = VECTOR3(-10.0f, 2.0f, 420.0f);
			Ground[0][55].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

			Ground[0][56].Trans = VECTOR3(-13.0f, 2.0f, 600.0f);
			Ground[0][56].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

			Ground[0][57].Trans = VECTOR3(13.0f, 2.0f, 600.0f);
			Ground[0][57].Scale = VECTOR3(3.0f, 3.0f, 1.0f);


			Ground[0][58].Trans = VECTOR3(-10.0f, 2.0f, 110.0f);
			Ground[0][58].Scale = VECTOR3(2.0f, 2.0f, 3.0f);

			Ground[0][59].Trans = VECTOR3(10.0f, 2.0f, 110.0f);
			Ground[0][59].Scale = VECTOR3(2.0f, 2.0f, 3.0f);

			Ground[0][60].Trans = VECTOR3(-10.0f, 2.0f, 350.0f);
			Ground[0][60].Scale = VECTOR3(2.0f, 2.0f, 3.0f);

			Ground[0][61].Trans = VECTOR3(10.0f, 2.0f, 350.0f);
			Ground[0][61].Scale = VECTOR3(2.0f, 2.0f, 3.0f);

			Ground[0][62].Trans = VECTOR3(0.0f, 2.0f, 400.0f);
			Ground[0][62].Scale = VECTOR3(2.0f, 2.0f, 3.0f);

			Ground[0][63].Trans = VECTOR3(7.0f, 2.0f, 580.0f);
			Ground[0][63].Scale = VECTOR3(2.0f, 2.0f, 3.0f);

			Ground[0][64].Trans = VECTOR3(-7.0f, 2.0f, 580.0f);
			Ground[0][64].Scale = VECTOR3(2.0f, 2.0f, 3.0f);

			Ground[0][65].Trans = VECTOR3(0.0f, 0.1f, 1110.0f);
			Ground[0][65].Scale = VECTOR3(15.0f, 10.0f, 5.0f);

			Ground[0][66].Trans = VECTOR3(0.0f, 1.5f, 620.0f);
			Ground[0][66].Scale = VECTOR3(5.0f, 3.0f, 5.0f);

			Ground[0][67].Trans = VECTOR3(0.0f, 1.5f, 630.0f);
			Ground[0][67].Scale = VECTOR3(5.0f, 3.0f, 5.0f);

			Ground[0][68].Trans = VECTOR3(0.0f, 1.5f, 640.0f);
			Ground[0][68].Scale = VECTOR3(5.0f, 3.0f, 5.0f);

			Ground[0][69].Trans = VECTOR3(0.0f, 1.5f, 650.0f);
			Ground[0][69].Scale = VECTOR3(5.0f, 3.0f, 5.0f);

			Ground[0][70].Trans = VECTOR3(0.0f, 0.0f, 515.0f);
			Ground[0][70].Scale = VECTOR3(5.0f, 0.1f, 5.0f);

			Ground[0][71].Trans = VECTOR3(-6.0f, 0.0f, 735.0f);
			Ground[0][71].Scale = VECTOR3(5.0f, 0.1f, 25.0f);

			Ground[0][72].Trans = VECTOR3(6.0f, 0.0f, 735.0f);
			Ground[0][72].Scale = VECTOR3(5.0f, 0.1f, 25.0f);

			Ground[0][73].Trans = VECTOR3(-11.0f, 0.0f, 760.0f);
			Ground[0][73].Scale = VECTOR3(5.0f, 0.1f, 35.0f);

			Ground[0][74].Trans = VECTOR3(11.0f, 0.0f, 760.0f);
			Ground[0][74].Scale = VECTOR3(5.0f, 0.1f, 35.0f);

			Ground[0][75].Trans = VECTOR3(-16.0f, 0.0f, 785.0f);
			Ground[0][75].Scale = VECTOR3(5.0f, 0.1f, 35.0f);

			Ground[0][76].Trans = VECTOR3(16.0f, 0.0f, 785.0f);
			Ground[0][76].Scale = VECTOR3(5.0f, 0.1f, 35.0f);

			Ground[0][77].Trans = VECTOR3(-21.0f, 0.0f, 810.0f);
			Ground[0][77].Scale = VECTOR3(5.0f, 0.1f, 35.0f);

			Ground[0][78].Trans = VECTOR3(21.0f, 0.0f, 810.0f);
			Ground[0][78].Scale = VECTOR3(5.0f, 0.1f, 35.0f);

			Ground[0][79].Trans = VECTOR3(-16.0f, 0.0f, 835.0f);
			Ground[0][79].Scale = VECTOR3(5.0f, 0.1f, 35.0f);

			Ground[0][80].Trans = VECTOR3(16.0f, 0.0f, 835.0f);
			Ground[0][80].Scale = VECTOR3(5.0f, 0.1f, 35.0f);

			Ground[0][81].Trans = VECTOR3(-11.0f, 0.0f, 860.0f);
			Ground[0][81].Scale = VECTOR3(5.0f, 0.1f, 35.0f);

			Ground[0][82].Trans = VECTOR3(11.0f, 0.0f, 860.0f);
			Ground[0][82].Scale = VECTOR3(5.0f, 0.1f, 35.0f);

			Ground[0][83].Trans = VECTOR3(-6.0f, 0.0f, 885.0f);
			Ground[0][83].Scale = VECTOR3(5.0f, 0.1f, 35.0f);

			Ground[0][84].Trans = VECTOR3(6.0f, 0.0f, 885.0f);
			Ground[0][84].Scale = VECTOR3(5.0f, 0.1f, 35.0f);

			Ground[0][85].Trans = VECTOR3(0.0f, 0.0f, 1000.0f);
			Ground[0][85].Scale = VECTOR3(5.0f, 0.1f, 200.0f);

			Ground[0][86].Trans = VECTOR3(0.0f, 0.0f, 1105.0f);
			Ground[0][86].Scale = VECTOR3(15.0f, 0.1f, 15.0f);

			Ground[0][87].Trans = VECTOR3(-10.0f, 1.5f, 950.0f);
			Ground[0][87].Scale = VECTOR3(5.0f, 3.0f, 5.0f);

			Ground[0][88].Trans = VECTOR3(10.0f, 1.5f, 1000.0f);
			Ground[0][88].Scale = VECTOR3(5.0f, 3.0f, 5.0f);

			Ground[0][89].Trans = VECTOR3(-10.0f, 1.5f, 1050.0f);
			Ground[0][89].Scale = VECTOR3(5.0f, 3.0f, 5.0f);

			Ground[0][90].Trans = VECTOR3(10.0f, 1.5f, 1080.0f);
			Ground[0][90].Scale = VECTOR3(5.0f, 3.0f, 5.0f);

			Ground[0][91].Trans = VECTOR3(-15.0f, 0.5f, 785.0f);
			Ground[0][91].Scale = VECTOR3(3.0f, 0.5f, 15.0f);

			Ground[0][92].Trans = VECTOR3(15.0f, 0.5f, 785.0f);
			Ground[0][92].Scale = VECTOR3(3.0f, 0.5f, 15.0f);


			Ground[0][93].Trans = VECTOR3(-6.0f, 0.5f, 885.0f);
			Ground[0][93].Scale = VECTOR3(3.0f, 0.5f, 15.0f);


			Ground[0][94].Trans = VECTOR3(6.0f, 0.5f, 885.0f);
			Ground[0][94].Scale = VECTOR3(3.0f, 0.5f, 15.0f);
		}
	}
	if (Type == SCENE_S2)
	{
		for (int i = 0; i < 16; i++)
		{
			Random_Number[i] = (rand() % 10) + 5;
		}

		Ground[1][0].Trans = VECTOR3(0.0f, 0.0f, 20.0f);
		Ground[1][0].Scale = VECTOR3(50.0f, 0.1f, 50.0f);

		Ground[1][1].Trans = VECTOR3(0.0f, 0.0f, 150.0f);
		Ground[1][1].Scale = VECTOR3(5.0f, 0.1f, 205.0f);

		Ground[1][2].Trans = VECTOR3(0.0f, 0.0f, 550.0f);
		Ground[1][2].Scale = VECTOR3(5.0f, 0.1f, 600.0f);

		Ground[1][3].Trans = VECTOR3(-7.0f, 0.0f, 565.0f);
		Ground[1][3].Scale = VECTOR3(5.0f, 0.1f, 600.0f);

		Ground[1][4].Trans = VECTOR3(7.0f, 0.0f, 565.0f);
		Ground[1][4].Scale = VECTOR3(5.0f, 0.1f, 600.0f);

		Ground[1][5].Trans = VECTOR3(0.0f, 0.0f, 880.0f);
		Ground[1][5].Scale = VECTOR3(30.0f, 0.1f, 30.0f);

		Ground[1][6].Trans = VECTOR3(-7.0f, 0.0f, 930.0f);
		Ground[1][6].Scale = VECTOR3(3.0f, 0.1f, 60.0f);

		Ground[1][7].Trans = VECTOR3(7.0f, 0.0f, 930.0f);
		Ground[1][7].Scale = VECTOR3(3.0f, 0.1f, 60.0f);

		Ground[1][8].Trans = VECTOR3(-4.0f, 0.0f, 990.0f);
		Ground[1][8].Scale = VECTOR3(3.0f, 0.1f, 60.0f);

		Ground[1][9].Trans = VECTOR3(4.0f, 0.0f, 990.0f);
		Ground[1][9].Scale = VECTOR3(3.0f, 0.1f, 60.0f);

		Ground[1][10].Trans = VECTOR3(0.0f, 0.0f, 1050.0f);
		Ground[1][10].Scale = VECTOR3(3.0f, 0.1f, 60.0f);

		Ground[1][11].Trans = VECTOR3(4.0f, 0.0f, 1120.0f);
		Ground[1][11].Scale = VECTOR3(3.0f, 0.1f, 60.0f);

		Ground[1][12].Trans = VECTOR3(-4.0f, 0.0f, 1120.0f);
		Ground[1][12].Scale = VECTOR3(3.0f, 0.1f, 60.0f);

		Ground[1][13].Trans = VECTOR3(6.0f, 0.0f, 1260.0f);
		Ground[1][13].Scale = VECTOR3(3.0f, 0.1f, 200.0f);

		Ground[1][14].Trans = VECTOR3(0.0f, 0.0f, 1260.0f);
		Ground[1][14].Scale = VECTOR3(3.0f, 0.1f, 200.0f);

		Ground[1][15].Trans = VECTOR3(-6.0f, 0.0f, 1260.0f);
		Ground[1][15].Scale = VECTOR3(3.0f, 0.1f, 200.0f);

		Ground[1][16].Trans = VECTOR3(0.0f, 0.0f, 1435.0f);
		Ground[1][16].Scale = VECTOR3(10.0f, 0.1f, 150.0f);

		Ground[1][17].Trans = VECTOR3(0.0f, 0.1f, 1500.0f);
		Ground[1][17].Scale = VECTOR3(9.5f, 10.0f, 5.0f);

		Ground[1][18].Trans = VECTOR3(6.0f, 2.0f, 140.0f);
		Ground[1][18].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[1][19].Trans = VECTOR3(-6.0f, 2.0f, 170.0f);
		Ground[1][19].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[1][20].Trans = VECTOR3(6.0f, 2.0f, 200.0f);
		Ground[1][20].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[1][21].Trans = VECTOR3(-6.0f, 2.0f, 230.0f);
		Ground[1][21].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[1][22].Trans = VECTOR3(0.0f, 1.5f, 300.0f);
		Ground[1][22].Scale = VECTOR3(4.0f, 3.0f, 1.0f);

		Ground[1][23].Trans = VECTOR3(0.0f, 4.5f, 300.0f);
		Ground[1][23].Scale = VECTOR3(4.0f, 3.0f, 1.0f);

		Ground[1][24].Trans = VECTOR3(0.0f, 7.5f, 300.0f);
		Ground[1][24].Scale = VECTOR3(4.0f, 3.0f, 1.0f);

		Ground[1][25].Trans = VECTOR3(7.0f, 1.5f, 400.0f);
		Ground[1][25].Scale = VECTOR3(4.0f, 3.0f, 1.0f);

		Ground[1][26].Trans = VECTOR3(7.0f, 4.5f, 400.0f);
		Ground[1][26].Scale = VECTOR3(4.0f, 3.0f, 1.0f);

		Ground[1][27].Trans = VECTOR3(7.0f, 7.5f, 400.0f);
		Ground[1][27].Scale = VECTOR3(4.0f, 3.0f, 1.0f);

		Ground[1][28].Trans = VECTOR3(-7.0f, 1.5f, 500.0f);
		Ground[1][28].Scale = VECTOR3(4.0f, 3.0f, 1.0f);

		Ground[1][29].Trans = VECTOR3(-7.0f, 4.5f, 500.0f);
		Ground[1][29].Scale = VECTOR3(4.0f, 3.0f, 1.0f);

		Ground[1][30].Trans = VECTOR3(-7.0f, 7.5f, 500.0f);
		Ground[1][30].Scale = VECTOR3(4.0f, 3.0f, 1.0f);

		Ground[1][31].Trans = VECTOR3(-7.0f, 1.5f, 600.0f);
		Ground[1][31].Scale = VECTOR3(4.0f, 3.0f, 1.0f);

		Ground[1][32].Trans = VECTOR3(-7.0f, 4.5f, 600.0f);
		Ground[1][32].Scale = VECTOR3(4.0f, 3.0f, 1.0f);

		Ground[1][33].Trans = VECTOR3(-7.0f, 7.5f, 600.0f);
		Ground[1][33].Scale = VECTOR3(4.0f, 3.0f, 1.0f);

		Ground[1][34].Trans = VECTOR3(0.0f, 1.5f, 600.0f);
		Ground[1][34].Scale = VECTOR3(4.0f, 3.0f, 1.0f);

		Ground[1][35].Trans = VECTOR3(0.0f, 4.5f, 600.0f);
		Ground[1][35].Scale = VECTOR3(4.0f, 3.0f, 1.0f);

		Ground[1][36].Trans = VECTOR3(0.0f, 7.5f, 600.0f);
		Ground[1][36].Scale = VECTOR3(4.0f, 3.0f, 1.0f);

		Ground[1][37].Trans = VECTOR3(7.0f, 1.5f, 550.0f);
		Ground[1][37].Scale = VECTOR3(4.0f, 3.0f, 1.0f);

		Ground[1][38].Trans = VECTOR3(7.0f, 4.5f, 550.0f);
		Ground[1][38].Scale = VECTOR3(4.0f, 3.0f, 1.0f);

		Ground[1][39].Trans = VECTOR3(7.0f, 7.5f, 550.0f);
		Ground[1][39].Scale = VECTOR3(4.0f, 3.0f, 1.0f);

		Ground[1][40].Trans = VECTOR3(0.0f, 1.5f, 700.0f);
		Ground[1][40].Scale = VECTOR3(4.0f, 3.0f, 1.0f);

		Ground[1][41].Trans = VECTOR3(0.0f, 4.5f, 700.0f);
		Ground[1][41].Scale = VECTOR3(4.0f, 3.0f, 1.0f);

		Ground[1][42].Trans = VECTOR3(0.0f, 7.5f, 700.0f);
		Ground[1][42].Scale = VECTOR3(4.0f, 3.0f, 1.0f);

		Ground[1][43].Trans = VECTOR3(7.0f, 1.5f, 700.0f);
		Ground[1][43].Scale = VECTOR3(4.0f, 3.0f, 1.0f);

		Ground[1][44].Trans = VECTOR3(7.0f, 4.5f, 700.0f);
		Ground[1][44].Scale = VECTOR3(4.0f, 3.0f, 1.0f);

		Ground[1][45].Trans = VECTOR3(7.0f, 7.5f, 700.0f);
		Ground[1][45].Scale = VECTOR3(4.0f, 3.0f, 1.0f);

		Ground[1][46].Trans = VECTOR3(-10.0f, 2.0f, 1240.0f);
		Ground[1][46].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[1][47].Trans = VECTOR3(10.0f, 2.0f, 1290.0f);
		Ground[1][47].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[1][48].Trans = VECTOR3(-10.0f, 2.0f, 1340.0f);
		Ground[1][48].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[1][49].Trans = VECTOR3(10.0f, 2.0f, 1390.0f);
		Ground[1][49].Scale = VECTOR3(3.0f, 3.0f, 1.0f);



		Ground[1][50].Trans = VECTOR3(0.0f, 0.5f, 40.0f);
		Ground[1][50].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[1][51].Trans = VECTOR3(0.0f, 0.5f, 130.0f);
		Ground[1][51].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[1][52].Trans = VECTOR3(0.0f, 0.5f, 230.0f);
		Ground[1][52].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[1][53].Trans = VECTOR3(7.0f, 0.5f, 320.0f);
		Ground[1][53].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[1][54].Trans = VECTOR3(-7.0f, 0.5f, 400.0f);
		Ground[1][54].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[1][55].Trans = VECTOR3(0.0f, 0.5f, 500.0f);
		Ground[1][55].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[1][56].Trans = VECTOR3(7.0f, 0.5f, 600.0f);
		Ground[1][56].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[1][57].Trans = VECTOR3(0.0f, 0.5f, 880.0f);
		Ground[1][57].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[1][58].Trans = VECTOR3(0.0f, 0.5f, 1055.0f);
		Ground[1][58].Scale = VECTOR3(3.0f, 0.5f, 15.0f);

		Ground[1][59].Trans = VECTOR3(-6.0f, 0.5f, 1220.0f);
		Ground[1][59].Scale = VECTOR3(3.0f, 0.5f, 15.0f);

		Ground[1][60].Trans = VECTOR3(6.0f, 0.5f, 1220.0f);
		Ground[1][60].Scale = VECTOR3(3.0f, 0.5f, 15.0f);

		Ground[1][61].Trans = VECTOR3(-6.0f, 0.5f, 1320.0f);
		Ground[1][61].Scale = VECTOR3(3.0f, 0.5f, 15.0f);

		Ground[1][62].Trans = VECTOR3(6.0f, 0.5f, 1320.0f);
		Ground[1][62].Scale = VECTOR3(3.0f, 0.5f, 15.0f);

		Ground[1][63].Trans = VECTOR3(-7.0f, 2.0f, 330.0f);
		Ground[1][63].Scale = VECTOR3(2.0f, 2.0f, 3.0f);

		Ground[1][64].Trans = VECTOR3(7.0f, 2.0f, 500.0f);
		Ground[1][64].Scale = VECTOR3(2.0f, 2.0f, 3.0f);

		Ground[1][65].Trans = VECTOR3(-7.0f, 2.0f, 810.0f);
		Ground[1][65].Scale = VECTOR3(2.0f, 2.0f, 3.0f);

		Ground[1][66].Trans = VECTOR3(7.0f, 2.0f, 810.0f);
		Ground[1][66].Scale = VECTOR3(2.0f, 2.0f, 3.0f);

		Ground[1][67].Trans = VECTOR3(-4.0f, 2.0f, 1130.0f);
		Ground[1][67].Scale = VECTOR3(2.0f, 2.0f, 3.0f);

		Ground[1][68].Trans = VECTOR3(4.0f, 2.0f, 1130.0f);
		Ground[1][68].Scale = VECTOR3(2.0f, 2.0f, 3.0f);

		Ground[1][69].Trans = VECTOR3(0.0f, 0.5f, 280.0f);
		Ground[1][69].Scale = VECTOR3(3.0f, 0.5f, 15.0f);

		Ground[1][70].Trans = VECTOR3(0.0f, 0.5f, 380.0f);
		Ground[1][70].Scale = VECTOR3(3.0f, 0.5f, 15.0f);

		Ground[1][71].Trans = VECTOR3(0.0f, 0.5f, 1330.0f);
		Ground[1][71].Scale = VECTOR3(3.0f, 0.5f, 15.0f);

		Ground[1][72].Trans = VECTOR3(0.0f, 0.5f, 550.0f);
		Ground[1][72].Scale = VECTOR3(3.0f, 0.5f, 15.0f);

		Ground[1][73].Trans = VECTOR3(0.0f, 0.5f, 750.0f);
		Ground[1][73].Scale = VECTOR3(3.0f, 0.5f, 15.0f);

		Ground[1][74].Trans = VECTOR3(0.0f, 0.5f, 1250.0f);
		Ground[1][74].Scale = VECTOR3(3.0f, 0.5f, 15.0f);
	}
	if (Type == SCENE_S3)
	{
		for (int i = 0; i < 35; i++)
		{
			Mase_Move[i] = false;
		}
		for (int i = 0; i < 55; i++)
		{
			Random_Number[i] = (rand() % 15) + 8;
		}

		Ground[2][0].Trans = VECTOR3(0.0f, 0.0f, 50.0f);
		Ground[2][0].Scale = VECTOR3(5.0f, 0.1f, 100.0f);

		Ground[2][1].Trans = VECTOR3(-8.0f, 0.0f, 610.0f);
		Ground[2][1].Scale = VECTOR3(5.0f, 0.1f, 1000.0f);

		Ground[2][2].Trans = VECTOR3(0.0f, 0.0f, 610.0f);
		Ground[2][2].Scale = VECTOR3(5.0f, 0.1f, 1000.0f);

		Ground[2][3].Trans = VECTOR3(8.0f, 0.0f, 610.0f);
		Ground[2][3].Scale = VECTOR3(5.0f, 0.1f, 1000.0f);

		Ground[2][4].Trans = VECTOR3(-13.0f, 0.0f, 1140.0f);
		Ground[2][4].Scale = VECTOR3(5.0f, 0.1f, 60.0f);

		Ground[2][5].Trans = VECTOR3(0.0f, 0.0f, 1140.0f);
		Ground[2][5].Scale = VECTOR3(5.0f, 0.1f, 60.0f);

		Ground[2][6].Trans = VECTOR3(13.0f, 0.0f, 1140.0f);
		Ground[2][6].Scale = VECTOR3(5.0f, 0.1f, 60.0f);

		Ground[2][7].Trans = VECTOR3(-18.0f, 0.0f, 1195.0f);
		Ground[2][7].Scale = VECTOR3(5.0f, 0.1f, 60.0f);

		Ground[2][8].Trans = VECTOR3(0.0f, 0.0f, 1195.0f);
		Ground[2][8].Scale = VECTOR3(5.0f, 0.1f, 60.0f);

		Ground[2][9].Trans = VECTOR3(18.0f, 0.0f, 1195.0f);
		Ground[2][9].Scale = VECTOR3(5.0f, 0.1f, 60.0f);

		Ground[2][10].Trans = VECTOR3(-23.0f, 0.0f, 1300.0f);
		Ground[2][10].Scale = VECTOR3(5.0f, 0.1f, 150.0f);

		Ground[2][11].Trans = VECTOR3(-31.0f, 0.0f, 1480.0f);
		Ground[2][11].Scale = VECTOR3(5.0f, 0.1f, 200.0f);

		Ground[2][12].Trans = VECTOR3(-23.0f, 0.0f, 1480.0f);
		Ground[2][12].Scale = VECTOR3(5.0f, 0.1f, 200.0f);

		Ground[2][13].Trans = VECTOR3(-15.0f, 0.0f, 1480.0f);
		Ground[2][13].Scale = VECTOR3(5.0f, 0.1f, 200.0f);

		Ground[2][14].Trans = VECTOR3(-36.0f, 0.0f, 1610.0f);
		Ground[2][14].Scale = VECTOR3(5.0f, 0.1f, 60.0f);

		Ground[2][15].Trans = VECTOR3(-23.0f, 0.0f, 1610.0f);
		Ground[2][15].Scale = VECTOR3(5.0f, 0.1f, 60.0f);

		Ground[2][16].Trans = VECTOR3(-10.0f, 0.0f, 1610.0f);
		Ground[2][16].Scale = VECTOR3(5.0f, 0.1f, 60.0f);

		Ground[2][17].Trans = VECTOR3(-41.0f, 0.0f, 1665.0f);
		Ground[2][17].Scale = VECTOR3(5.0f, 0.1f, 60.0f);

		Ground[2][18].Trans = VECTOR3(-23.0f, 0.0f, 1665.0f);
		Ground[2][18].Scale = VECTOR3(5.0f, 0.1f, 60.0f);

		Ground[2][19].Trans = VECTOR3(-5.0f, 0.0f, 1665.0f);
		Ground[2][19].Scale = VECTOR3(5.0f, 0.1f, 60.0f);

		Ground[2][20].Trans = VECTOR3(0.0f, 0.0f, 1770.0f);
		Ground[2][20].Scale = VECTOR3(5.0f, 0.1f, 150.0f);

		Ground[2][21].Trans = VECTOR3(-8.0f, 0.0f, 1950.0f);
		Ground[2][21].Scale = VECTOR3(5.0f, 0.1f, 210.0f);

		Ground[2][22].Trans = VECTOR3(0.0f, 0.0f, 1950.0f);
		Ground[2][22].Scale = VECTOR3(5.0f, 0.1f, 210.0f);

		Ground[2][23].Trans = VECTOR3(8.0f, 0.0f, 1950.0f);
		Ground[2][23].Scale = VECTOR3(5.0f, 0.1f, 210.0f);

		Ground[2][24].Trans = VECTOR3(-13.0f, 0.0f, 2080.0f);
		Ground[2][24].Scale = VECTOR3(5.0f, 0.1f, 60.0f);

		Ground[2][25].Trans = VECTOR3(0.0f, 0.0f, 2080.0f);
		Ground[2][25].Scale = VECTOR3(5.0f, 0.1f, 60.0f);

		Ground[2][26].Trans = VECTOR3(13.0f, 0.0f, 2080.0f);
		Ground[2][26].Scale = VECTOR3(5.0f, 0.1f, 60.0f);

		Ground[2][27].Trans = VECTOR3(-18.0f, 0.0f, 2135.0f);
		Ground[2][27].Scale = VECTOR3(5.0f, 0.1f, 60.0f);

		Ground[2][28].Trans = VECTOR3(0.0f, 0.0f, 2135.0f);
		Ground[2][28].Scale = VECTOR3(5.0f, 0.1f, 60.0f);

		Ground[2][29].Trans = VECTOR3(18.0f, 0.0f, 2135.0f);
		Ground[2][29].Scale = VECTOR3(5.0f, 0.1f, 60.0f);

		Ground[2][30].Trans = VECTOR3(0.0f, 0.0f, 2240.0f);
		Ground[2][30].Scale = VECTOR3(5.0f, 0.1f, 150.0f);

		Ground[2][31].Trans = VECTOR3(0.0f, 0.0f, 2370.0f);
		Ground[2][31].Scale = VECTOR3(30.0f, 0.1f, 110.0f);

		Ground[2][32].Trans = VECTOR3(0.0f, 0.1f, 2370.0f);
		Ground[2][32].Scale = VECTOR3(30.0f, 10.0f, 5.0f);//goal

		Ground[2][33].Trans = VECTOR3(-15.0f, 2.0f, 100.0f);
		Ground[2][33].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][34].Trans = VECTOR3(-15.0f, 2.0f, 200.0f);
		Ground[2][34].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][35].Trans = VECTOR3(-15.0f, 2.0f, 300.0f);
		Ground[2][35].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][36].Trans = VECTOR3(-15.0f, 2.0f, 400.0f);
		Ground[2][36].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][37].Trans = VECTOR3(-15.0f, 2.0f, 500.0f);
		Ground[2][37].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][38].Trans = VECTOR3(-15.0f, 2.0f, 500.0f);
		Ground[2][38].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][39].Trans = VECTOR3(-15.0f, 2.0f, 700.0f);
		Ground[2][39].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][40].Trans = VECTOR3(-15.0f, 2.0f, 800.0f);
		Ground[2][40].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][41].Trans = VECTOR3(-15.0f, 2.0f, 900.0f);
		Ground[2][41].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][42].Trans = VECTOR3(-15.0f, 2.0f, 1000.0f);
		Ground[2][42].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][43].Trans = VECTOR3(15.0f, 2.0f, 50.0f);
		Ground[2][43].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][44].Trans = VECTOR3(15.0f, 2.0f, 150.0f);
		Ground[2][44].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][45].Trans = VECTOR3(15.0f, 2.0f, 250.0f);
		Ground[2][45].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][46].Trans = VECTOR3(15.0f, 2.0f, 350.0f);
		Ground[2][46].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][47].Trans = VECTOR3(15.0f, 2.0f, 450.0f);
		Ground[2][47].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][48].Trans = VECTOR3(15.0f, 2.0f, 550.0f);
		Ground[2][48].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][49].Trans = VECTOR3(15.0f, 2.0f, 650.0f);
		Ground[2][49].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][50].Trans = VECTOR3(15.0f, 2.0f, 750.0f);
		Ground[2][50].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][51].Trans = VECTOR3(15.0f, 2.0f, 850.0f);
		Ground[2][51].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][52].Trans = VECTOR3(15.0f, 2.0f, 950.0f);
		Ground[2][52].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][53].Trans = VECTOR3(-35.0f, 2.0f, 1250.0f);
		Ground[2][53].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][54].Trans = VECTOR3(-35.0f, 2.0f, 1350.0f);
		Ground[2][54].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][55].Trans = VECTOR3(-10.0f, 2.0f, 1300.0f);
		Ground[2][55].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][56].Trans = VECTOR3(-10.0f, 2.0f, 1400.0f);
		Ground[2][56].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][57].Trans = VECTOR3(-31.0f, 1.5f, 1450.0f);
		Ground[2][57].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][58].Trans = VECTOR3(-23.0f, 1.5f, 1530.0f);
		Ground[2][58].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][59].Trans = VECTOR3(-15.0f, 1.5f, 1450.0f);
		Ground[2][59].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		//Ground_S3[60].Trans = VECTOR3(-15.0f, 2.0f, 1750.0f);
		//Ground_S3[60].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		//Ground_S3[61].Trans = VECTOR3(15.0f,2.0f, 1800.0f);
		//Ground_S3[61].Scale = VECTOR3(3.0f, 3.0f, 1.0f);

		Ground[2][62].Trans = VECTOR3(0.0f, 0.5f, 80.0f);
		Ground[2][62].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[2][63].Trans = VECTOR3(-8.0f, 0.5f, 200.0f);
		Ground[2][63].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[2][64].Trans = VECTOR3(-8.0f, 0.5f, 500.0f);
		Ground[2][64].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[2][65].Trans = VECTOR3(-8.0f, 0.5f, 800.0f);
		Ground[2][65].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[2][66].Trans = VECTOR3(-8.0f, 0.5f, 1100.0f);
		Ground[2][66].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[2][67].Trans = VECTOR3(0.0f, 0.5f, 350.0f);
		Ground[2][67].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[2][68].Trans = VECTOR3(0.0f, 0.5f, 650.0f);
		Ground[2][68].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[2][69].Trans = VECTOR3(0.0f, 0.5f, 950.0f);
		Ground[2][69].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[2][70].Trans = VECTOR3(8.0f, 0.5f, 200.0f);
		Ground[2][70].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[2][71].Trans = VECTOR3(8.0f, 0.5f, 500.0f);
		Ground[2][71].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[2][72].Trans = VECTOR3(8.0f, 0.5f, 800.0f);
		Ground[2][72].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[2][73].Trans = VECTOR3(8.0f, 0.5f, 1100.0f);
		Ground[2][73].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[2][74].Trans = VECTOR3(-23.0f, 0.5f, 1240.0f);
		Ground[2][74].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[2][75].Trans = VECTOR3(-23.0f, 0.5f, 1360.0f);
		Ground[2][75].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[2][76].Trans = VECTOR3(-31.0f, 0.5f, 1490.0f);
		Ground[2][76].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[2][77].Trans = VECTOR3(-15.0f, 0.5f, 1490.0f);
		Ground[2][77].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[2][78].Trans = VECTOR3(0.0f, 0.5f, 1710.0f);
		Ground[2][78].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[2][79].Trans = VECTOR3(0.0f, 0.5f, 1830.0f);
		Ground[2][79].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[2][80].Trans = VECTOR3(-8.0f, 0.5f, 650.0f);
		Ground[2][80].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[2][81].Trans = VECTOR3(8.0f, 0.5f, 650.0f);
		Ground[2][81].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[2][82].Trans = VECTOR3(0.0f, 0.5f, 1130.0f);
		Ground[2][82].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[2][83].Trans = VECTOR3(-23.0f, 0.5f, 1500.0f);
		Ground[2][83].Scale = VECTOR3(5.0f, 0.5f, 15.0f);

		Ground[2][84].Trans = VECTOR3(0.0f, 0.5f, 450.0f);
		Ground[2][84].Scale = VECTOR3(5.0f, 0.5f, 15.0f);
	}
}
void tag_C_Ground::Update(SCENE Type)
{
	if (Type == SCENE_S1)
	{
		Trans_difference[0] = Ground[0][65].Trans.z - Player.Info().Trans.z;
		if (Player.Info().Start_Count > 180)
		{
			if (Ground[0][69].Trans.x <= -15.0f)
			{
				Mase_Move[0] = false;
			}
			if (!Mase_Move[0])
			{
				Ground[0][69].Trans.x += Random_Number[0] / 100;
			}
			if (Ground[0][69].Trans.x >= 15.0f)
			{
				Mase_Move[0] = true;
			}
			if (Mase_Move[0])
			{
				Ground[0][69].Trans.x -= Random_Number[1] / 100;
			}

			if (Ground[0][67].Trans.x <= -15.0f)
			{
				Mase_Move[1] = false;
			}
			if (!Mase_Move[1])
			{
				Ground[0][67].Trans.x += Random_Number[2] / 100;
			}
			if (Ground[0][67].Trans.x >= 15.0f)
			{
				Mase_Move[1] = true;
			}
			if (Mase_Move[1])
			{
				Ground[0][67].Trans.x -= Random_Number[3] / 100;
			}

			if (Ground[0][66].Trans.x <= -15.0f)
			{
				Mase_Move[2] = false;
			}
			if (!Mase_Move[2])
			{
				Ground[0][66].Trans.x += Random_Number[4] / 100;
			}
			if (Ground[0][66].Trans.x >= 15.0f)
			{
				Mase_Move[2] = true;
			}
			if (Mase_Move[2])
			{
				Ground[0][66].Trans.x -= Random_Number[5] / 100;
			}

			if (Ground[0][68].Trans.x <= -15.0f)
			{
				Mase_Move[3] = false;
			}
			if (!Mase_Move[3])
			{
				Ground[0][68].Trans.x += Random_Number[6] / 100;
			}
			if (Ground[0][68].Trans.x >= 15.0f)
			{
				Mase_Move[3] = true;
			}
			if (Mase_Move[3])
			{
				Ground[0][68].Trans.x -= Random_Number[7] / 100;
			}


			if (Ground[0][87].Trans.x <= -15.0f)
			{
				Mase_Move[4] = false;
			}
			if (!Mase_Move[4])
			{
				Ground[0][87].Trans.x += Random_Number[8] / 100;
			}
			if (Ground[0][87].Trans.x >= 15.0f)
			{
				Mase_Move[4] = true;
			}
			if (Mase_Move[4])
			{
				Ground[0][87].Trans.x -= Random_Number[9] / 100;
			}

			if (Ground[0][89].Trans.x <= -15.0f)
			{
				Mase_Move[5] = false;
			}
			if (!Mase_Move[5])
			{
				Ground[0][89].Trans.x += Random_Number[10] / 100;
			}
			if (Ground[0][89].Trans.x >= 15.0f)
			{
				Mase_Move[5] = true;
			}
			if (Mase_Move[5])
			{
				Ground[0][89].Trans.x -= Random_Number[11] / 100;
			}

			if (Ground[0][88].Trans.x >= 15.0f)
			{
				Mase_Move[6] = false;
			}
			if (!Mase_Move[6])
			{
				Ground[0][88].Trans.x -= Random_Number[12] / 100;
			}
			if (Ground[0][88].Trans.x <= -15.0f)
			{
				Mase_Move[6] = true;
			}
			if (Mase_Move[6])
			{
				Ground[0][88].Trans.x += Random_Number[13] / 100;
			}

			if (Ground[0][90].Trans.x >= 15.0f)
			{
				Mase_Move[7] = false;
			}
			if (!Mase_Move[7])
			{
				Ground[0][90].Trans.x -= Random_Number[14] / 100;
			}
			if (Ground[0][90].Trans.x <= -15.0f)
			{
				Mase_Move[7] = true;
			}
			if (Mase_Move[7])
			{
				Ground[0][90].Trans.x += Random_Number[15] / 100;
			}
		}
	}
	if (Type == SCENE_S2)
	{
		float PZ = Player.Info().Trans.z;
		Trans_difference[1] = Ground[1][17].Trans.z - PZ;
		if (Player.Info().Start_Count > 180)
		{
			if (Ground[1][19].Trans.x <= -15.0f)
			{
				Mase_Move[0] = false;
			}
			if (!Mase_Move[0])
			{
				Ground[1][19].Trans.x += Random_Number[0] / 100;
			}
			if (Ground[1][19].Trans.x >= 15.0f)
			{
				Mase_Move[0] = true;
			}
			if (Mase_Move[0])
			{
				Ground[1][19].Trans.x -= Random_Number[1] / 100;
			}


			if (Ground[1][20].Trans.x >= 15.0f)
			{
				Mase_Move[1] = false;
			}
			if (!Mase_Move[1])
			{
				Ground[1][20].Trans.x -= Random_Number[2] / 100;
			}
			if (Ground[1][20].Trans.x <= -15.0f)
			{
				Mase_Move[1] = true;
			}
			if (Mase_Move[1])
			{
				Ground[1][20].Trans.x += Random_Number[3] / 100;
			}


			if (Ground[1][21].Trans.x <= -15.0f)
			{
				Mase_Move[2] = false;
			}
			if (!Mase_Move[2])
			{
				Ground[1][21].Trans.x += Random_Number[4] / 100;
			}
			if (Ground[1][21].Trans.x >= 15.0f)
			{
				Mase_Move[2] = true;
			}
			if (Mase_Move[2])
			{
				Ground[1][21].Trans.x -= Random_Number[5] / 100;
			}

			if (Ground[1][18].Trans.x >= 15.0f)
			{
				Mase_Move[3] = false;
			}
			if (!Mase_Move[3])
			{
				Ground[1][18].Trans.x -= Random_Number[6] / 100;
			}
			if (Ground[1][18].Trans.x <= -15.0f)
			{
				Mase_Move[3] = true;
			}
			if (Mase_Move[3])
			{
				Ground[1][18].Trans.x += Random_Number[7] / 100;
			}



			if (Ground[1][46].Trans.x <= -15.0f)
			{
				Mase_Move[4] = false;
			}
			if (!Mase_Move[4])
			{
				Ground[1][46].Trans.x += Random_Number[8] / 100;
			}
			if (Ground[1][46].Trans.x >= 15.0f)
			{
				Mase_Move[4] = true;
			}
			if (Mase_Move[4])
			{
				Ground[1][46].Trans.x -= Random_Number[9] / 100;
			}

			if (Ground[1][48].Trans.x <= -15.0f)
			{
				Mase_Move[5] = false;
			}
			if (!Mase_Move[5])
			{
				Ground[1][48].Trans.x += Random_Number[10] / 100;
			}
			if (Ground[1][48].Trans.x >= 15.0f)
			{
				Mase_Move[5] = true;
			}
			if (Mase_Move[5])
			{
				Ground[1][48].Trans.x -= Random_Number[11] / 100;
			}

			if (Ground[1][47].Trans.x >= 15.0f)
			{
				Mase_Move[6] = false;
			}
			if (!Mase_Move[6])
			{
				Ground[1][47].Trans.x -= Random_Number[12] / 100;
			}
			if (Ground[1][47].Trans.x <= -15.0f)
			{
				Mase_Move[6] = true;
			}
			if (Mase_Move[6])
			{
				Ground[1][47].Trans.x += Random_Number[13] / 100;
			}

			if (Ground[1][49].Trans.x >= 15.0f)
			{
				Mase_Move[7] = false;
			}
			if (!Mase_Move[7])
			{
				Ground[1][49].Trans.x -= Random_Number[14] / 100;
			}
			if (Ground[1][49].Trans.x <= -15.0f)
			{
				Mase_Move[7] = true;
			}
			if (Mase_Move[7])
			{
				Ground[1][49].Trans.x += Random_Number[15] / 100;
			}
		}
	}
	if (Type == SCENE_S3)
	{
		float PZ = Player.Info().Trans.z;
		Trans_difference[2] = Ground[2][32].Trans.z - PZ;
		int q = 0;
		int w = 0;
		if (Player.Info().Start_Count > 180)
		{
			for (int i = 33; i < 57; i++)
			{
				if (i < 43)
				{
					if (Ground[2][i].Trans.x <= -20.0f)
					{
						Mase_Move[q] = false;
					}
					if (!Mase_Move[q])
					{
						Ground[2][i].Trans.x += Random_Number[w] / 100;
					}
					w++;
					if (Ground[2][i].Trans.x >= 20.0f)
					{
						Mase_Move[q] = true;
					}
					if (Mase_Move[q])
					{
						Ground[2][i].Trans.x -= Random_Number[w] / 100;
					}
					q++;
					w++;
				}
				else if (i >= 43 && i < 53)
				{
					if (Ground[2][i].Trans.x >= 20.0f)
					{
						Mase_Move[q] = false;
					}
					if (!Mase_Move[q])
					{
						Ground[2][i].Trans.x -= Random_Number[w] / 100;
					}
					w++;
					if (Ground[2][i].Trans.x <= -20.0f)
					{
						Mase_Move[q] = true;
					}
					if (Mase_Move[q])
					{
						Ground[2][i].Trans.x += Random_Number[w] / 100;
					}
					q++;
					w++;
				}
				else if (i == 53 || i == 54)
				{
					if (Ground[2][i].Trans.x <= -40.0f)
					{
						Mase_Move[q] = false;
					}
					if (!Mase_Move[q])
					{
						Ground[2][i].Trans.x += Random_Number[w] / 100;
					}
					w++;
					if (Ground[2][i].Trans.x >= -5.0f)
					{
						Mase_Move[q] = true;
					}
					if (Mase_Move[q])
					{
						Ground[2][i].Trans.x -= Random_Number[w] / 100;
					}
					q++;
					w++;
				}
				else if (i == 55 || i == 56)
				{
					if (Ground[2][i].Trans.x >= -5.0f)
					{
						Mase_Move[q] = false;
					}
					if (!Mase_Move[q])
					{
						Ground[2][i].Trans.x -= Random_Number[w] / 100;
					}
					w++;
					if (Ground[2][i].Trans.x <= -50.0f)
					{
						Mase_Move[q] = true;
					}
					if (Mase_Move[q])
					{
						Ground[2][i].Trans.x += Random_Number[w] / 100;
					}
					q++;
					w++;
				}
			}
		}
	}
}
void tag_C_Ground::Uninit()
{
	if (m_pd3dDevice != NULL)
	{
		m_pd3dDevice->Release();
	}
	if (m_pBox != NULL)
	{
		m_pBox->Release();
	}
}
void tag_C_Ground::Draw(SCENE Type)
{
	if (Type == SCENE_S1)
	{
		for (int i = 0; i < 95; i++)
		{
			Sprite_Ground(Ground[0], i);
		}
	}
	if (Type == SCENE_S2)
	{
		for (int i = 0; i < 75; i++)
		{
			Sprite_Ground(Ground[1], i);
		}
	}
	if (Type == SCENE_S3)
	{
		for (int i = 0; i < 85; i++)
		{
			Sprite_Ground(Ground[2], i);
		}
	}
}



void tag_C_Ground::Sprite_Ground(ground *pDate,int index)
{
	m_pd3dDevice = Device.Get();
	m_pd3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	MATRIX World, Trans, Scale;
	D3DXMatrixTranslation(&Trans, pDate[index].Trans.x, pDate[index].Trans.y, pDate[index].Trans.z);
	D3DXMatrixScaling(&Scale, pDate[index].Scale.x, pDate[index].Scale.y, pDate[index].Scale.z);
	World = Scale * Trans;
	D3DXVec3TransformCoord(&pDate[index].Min, &m_Min, &World);
	D3DXVec3TransformCoord(&pDate[index].Max, &m_Max, &World);
	m_pd3dDevice->SetTransform(D3DTS_WORLD, &World);
	//m_pBox->DrawSubset(0);
	m_pd3dDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
}
VECTOR3 tag_C_Ground::Min(int Ground_Number, int index)
{
	return Ground[Ground_Number][index].Min;
}
VECTOR3 tag_C_Ground::Max(int Ground_Number, int index)
{
	return Ground[Ground_Number][index].Max;
}

tag_C_Ground::ground tag_C_Ground::C_Ground_Info(int Ground_Number, int index)
{
	return Ground[Ground_Number][index];
}
float tag_C_Ground::difference(int Ground_Number)
{
	return Trans_difference[Ground_Number];
}