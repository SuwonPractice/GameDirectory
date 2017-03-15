#pragma once
#include "stdafx.h"
#include "IGameObject.h"

//���� ����
class CTexture;

class GameObject :
	public IGameObject
{
protected:
	CTexture* m_Tex;
public:
	GameObject();
	virtual ~GameObject();

	virtual INT Init();
	virtual INT Render();
	virtual INT Update();
	virtual void Destroy();
};

