#pragma once
#include "stdafx.h"

class GameObject;
class ICollisionAbleObject;


enum PopState
{
	PS_REMOVE,
	RS_POP
};

struct Pop
{
	GameObject* m_obj;
	PopState m_state;
};

class ObjectManager
{
private:
	std::list<GameObject*> m_ObjList;
	std::list<Pop> m_PopList;

	std::list<ICollisionAbleObject*> m_ColliderList;
public:
	ObjectManager();
	virtual ~ObjectManager();

	void AddObject(GameObject* obj);
	BOOL RemoveObject(GameObject* obj);
	GameObject* PopObject(GameObject* obj);

	bool operator ()(GameObject* left, GameObject* right)
	{
		return left > right;
	}

	INT UpdateAll();
	INT RenderAll();
	INT Collision();

	void Clear();
};

