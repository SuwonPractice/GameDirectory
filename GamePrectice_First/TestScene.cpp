#include "TestScene.h"

#include "XScrollingObject.h"
#include "Texture.h"
#include "Input.h"

TestScene::TestScene()
{
}


TestScene::~TestScene()
{

}

INT TestScene::Init()
{
	m_Input = new CInput;

	BitmapDataManager::GetInstance()->CreateTexture("Texture/BackGround/background_0.png", "BG_base");
	BitmapDataManager::GetInstance()->CreateTexture("Texture/BackGround/background_1.png", "BG_Back1");
	BitmapDataManager::GetInstance()->CreateTexture("Texture/BackGround/background_2.png", "BG_Back2");
	BitmapDataManager::GetInstance()->CreateTexture("Texture/BackGround/background_3.png", "BG_Back3");
	BitmapDataManager::GetInstance()->CreateTexture("Texture/BackGround/background_4.png", "BG_Middle");
	BitmapDataManager::GetInstance()->CreateTexture("Texture/BackGround/background_5.png", "BG_Front");
	BitmapDataManager::GetInstance()->CreateTexture("Texture/BackGround/floor.png", "BG_Floor");

	m_BackGrounds.push_back(new XScrollingObject(0, 0, 0, 0, new CTexture(BitmapDataManager::GetInstance()->GetTexture("BG_base"))));
	m_BackGrounds.push_back(new XScrollingObject(-1, -1280, 1280, 480, new CTexture(BitmapDataManager::GetInstance()->GetTexture("BG_Back1"))));
	m_BackGrounds.push_back(new XScrollingObject(-1, -1280, 1280, 480, new CTexture(BitmapDataManager::GetInstance()->GetTexture("BG_Back2"))));
	m_BackGrounds.push_back(new XScrollingObject(-1, -1280, 1280, 480, new CTexture(BitmapDataManager::GetInstance()->GetTexture("BG_Back3"))));
	m_BackGrounds.push_back(new XScrollingObject(-1, -1280, 1280, 500, new CTexture(BitmapDataManager::GetInstance()->GetTexture("BG_Middle"))));
	m_BackGrounds.push_back(new XScrollingObject(-1, -1280, 1280, 580, new CTexture(BitmapDataManager::GetInstance()->GetTexture("BG_Front"))));
	m_BackGrounds.push_back(new XScrollingObject(-1, -2560, 0, 650,
		new CTexture(BitmapDataManager::GetInstance()->GetTexture("BG_Floor"), D3DXVECTOR2(0, 720), D3DXVECTOR2(0.0f, 1.0f))));

	return 0;
}
INT TestScene::Update()
{
 	m_Input->Update();

	if (m_Input->KeyPress('A'))
	{
		for (int i = 0; i < 7; ++i)
			m_BackGrounds[i]->Update();
	}
	return 0;
}
INT TestScene::Render()
{
	for (int i = 0; i < 7; ++i)
		m_BackGrounds[i]->Render();
	return 0;
}
void TestScene::Close()
{
	if (m_Input != nullptr)
		delete m_Input;

	for (int i = 0; m_BackGrounds[i] != nullptr; ++i)
		delete m_BackGrounds[i];

	m_BackGrounds.clear();
}