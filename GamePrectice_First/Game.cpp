#include "stdafx.h"

#include "BitmapDataManager.h"
#include "GameObject.h"
#include "XScrollingObject.h"
#include "Texture.h"

static CAnimation m_Ani;
CGame::CGame()
{
	
}


CGame::~CGame()
{
}

INT CGame::Init() {
	BitmapDataManager::GetInstance()->CreateTexture("Texture/Player/","png",0,10,"Player_Idle");

	BitmapDataManager::GetInstance()->CreateTexture("Texture/BackGround/background_0.png"	,"BG_base"	 );
	BitmapDataManager::GetInstance()->CreateTexture("Texture/BackGround/background_1.png"	,"BG_Back1"	 );
	BitmapDataManager::GetInstance()->CreateTexture("Texture/BackGround/background_2.png"	,"BG_Back2"	 );
	BitmapDataManager::GetInstance()->CreateTexture("Texture/BackGround/background_3.png"	,"BG_Back3"	 );
	BitmapDataManager::GetInstance()->CreateTexture("Texture/BackGround/background_4.png"	,"BG_Middle" );
	BitmapDataManager::GetInstance()->CreateTexture("Texture/BackGround/background_5.png"	,"BG_Front"	 );
	BitmapDataManager::GetInstance()->CreateTexture("Texture/BackGround/floor.png"			,"BG_Floor"	 );

	m_BackGrounds.push_back(new XScrollingObject(0, 0, 0, 0, new CTexture(BitmapDataManager::GetInstance()->GetTexture("BG_base"))));
	m_BackGrounds.push_back(new XScrollingObject(-1, -1280, 1280, 50, new CTexture(BitmapDataManager::GetInstance()->GetTexture("BG_Back1"))));
	m_BackGrounds.push_back(new XScrollingObject(-1, -1280, 1280, 50,new CTexture(BitmapDataManager::GetInstance()->GetTexture("BG_Back2"))));
	m_BackGrounds.push_back(new XScrollingObject(-1, -1280, 1280, 50,new CTexture(BitmapDataManager::GetInstance()->GetTexture("BG_Back3"))));
	m_BackGrounds.push_back(new XScrollingObject(-1, -1280, 1280, 120,new CTexture(BitmapDataManager::GetInstance()->GetTexture("BG_Middle"))));
	m_BackGrounds.push_back(new XScrollingObject(-1, -1280, 1280, 180,new CTexture(BitmapDataManager::GetInstance()->GetTexture("BG_Front"))));
	m_BackGrounds.push_back(new XScrollingObject(-1, -1200, 0, 200,
		new CTexture(BitmapDataManager::GetInstance()->GetTexture("BG_Floor"),D3DXVECTOR2(0, 720),D3DXVECTOR2(0.0f,1.0f))));

	m_Ani.LoadTexture("Player_Idle");
	m_Ani.InitAnimation(20, 0, 10);
	m_Ani.SetScale(D3DXVECTOR2(1.5f, 1.5f));
	return 0;
}
INT CGame::Update() {

	m_Ani.UpdateAnimation(g_pApp->m_fdeltaTime);

	for (int i = 0; i < 7; ++i)
		m_BackGrounds[i]->Update();

	return 0;
}
INT CGame::Render() {

	if (NULL == m_pd3dDevice)
		return -1;

	// Clear the backbuffer to a blue color
	m_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	// Begin the scene
	if (SUCCEEDED(m_pd3dDevice->BeginScene()))
	{
		// Rendering of scene objects can happen here
		for (int i = 0; i < 7; ++i)
			m_BackGrounds[i]->Render();

		m_Ani.Draw();
		// End the scene
		m_pd3dDevice->EndScene();
	}

	// Present the backbuffer contents to the display
	m_pd3dDevice->Present(NULL, NULL, NULL, NULL);

	return 0;
}
void CGame::Destroy() {

}