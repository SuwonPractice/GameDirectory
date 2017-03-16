#include "ObjectManager.h"
#include "GameObject.h"
#include "ICollisionAbleObject.h"

ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
}

void ObjectManager::AddObject(GameObject* obj)
{
	m_ObjList.push_back(obj);

	m_ObjList.sort(ObjectManager());

	ICollisionAbleObject* pCollider = nullptr;
	pCollider = dynamic_cast<ICollisionAbleObject*>(obj);

	if (pCollider != nullptr)
		m_ColliderList.push_back(pCollider);
	
}
BOOL ObjectManager::RemoveObject(GameObject* obj)
{
	Pop pp = { obj,PS_REMOVE };
	
	m_PopList.push_back(pp);
}
GameObject* ObjectManager::PopObject(GameObject* obj)
{
	Pop pp = { obj,RS_POP };

	m_PopList.push_back(pp);
	return obj;
}

INT ObjectManager::UpdateAll()
{
	for (auto it = m_ObjList.begin(); it != m_ObjList.end(); ++it)
	{
		(*it)->Update();
	}

	Collision();

	return 0;
}
INT ObjectManager::RenderAll()
{
	for (auto it = m_ObjList.begin(); it != m_ObjList.end(); ++it)
	{
		(*it)->Render();
	}

	return 0;
}
INT ObjectManager::Collision()
{
	for (auto it_from = m_ColliderList.begin(); it_from != m_ColliderList.end(); ++it_from)
	{
		for (auto it_to = it_from; it_to != m_ColliderList.end(); ++it_to)
		{
			if (it_to == it_from)
				continue;

			if ((*it_from)->Collision((*it_to)))
			{
				(*it_to)->Collision((*it_from));
			}
		}
	}
}

void ObjectManager::Clear()
{
	for (auto it = m_ObjList.begin(); it != m_ObjList.end(); ++it)
	{
		(*it)->Destroy();
		delete (*it);
	}

	m_ObjList.clear();
	m_RemoveList.clear();
}
