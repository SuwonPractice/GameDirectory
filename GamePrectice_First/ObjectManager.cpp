#include "ObjectManager.h"
#include "IGameObject.h"


ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
}

void ObjectManager::AddObject(IGameObject* obj)
{

}
BOOL ObjectManager::RemoveObject(IGameObject* obj)
{

}
IGameObject* ObjectManager::PopObject(IGameObject* obj)
{

	
}

INT ObjectManager::UpdateAll()
{

}
INT ObjectManager::RenderAll()
{

}
INT ObjectManager::Collision()
{
	for (auto it_from = m_ObjList.begin(); it_from != m_ObjList.end(); ++it_from)
	{
		for (auto it_to = it_from; it_to != m_ObjList.end(); ++it_to)
		{

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
