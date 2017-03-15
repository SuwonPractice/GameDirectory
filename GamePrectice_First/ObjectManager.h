#pragma once
#include "stdafx.h"

class IGameObject;

enum PopState
{
	PS_REMOVE,
	RS_POP
};

class ObjectManager
{
private:
	std::list<IGameObject*> m_ObjList;
	std::list<IGameObject*> m_RemoveList;
public:
	ObjectManager();
	virtual ~ObjectManager();

	void AddObject(IGameObject* obj);
	BOOL RemoveObject(IGameObject* obj);
	IGameObject* PopObject(IGameObject* obj);

	INT UpdateAll();
	INT RenderAll();
	INT Collision();

	void Clear();
};

