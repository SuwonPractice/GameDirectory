#pragma once
#include "stdafx.h"
#include "IGameObject.h"

//전방 선언
class CTexture;

class GameObject :
	public IGameObject
{
protected:
	CTexture* m_Tex;

	D3DXVECTOR2 m_Position;
	int			m_Rotate;

	int		  m_Layer;
	int		  m_TAG;
public:
	GameObject();
	virtual ~GameObject();

	virtual INT Init();
	virtual INT Render();
	virtual INT Update();
	virtual void Destroy();

public:

	int GetLayer()
	{
		return m_Layer;
	}
	int GetTAG()
	{
		return m_TAG;
	}
};

