#pragma once

class GameObject;

class CGame
	:public D3DApp
{
	std::vector<GameObject*> m_BackGrounds;
public:
	CGame();
	virtual ~CGame();

	virtual INT Init();
	virtual INT Update();

	//-----------------------------------------------------------------------------
	// Name: Render()
	// Desc: Draws the scene
	//-----------------------------------------------------------------------------
	virtual INT Render();

	virtual void Destroy();
};

extern CGame* g_pApp;

