#pragma once
#include "stdafx.h"

class GameObject;

class IGameObject
{
public:
	IGameObject();
	virtual ~IGameObject();

	virtual INT Init()					   = 0;
	virtual INT Render()				   = 0;
	virtual INT Update()				   = 0;
	virtual INT Collision(GameObject* obj) = 0;
	virtual void Destroy()				   = 0;

	virtual void ThrowMessage() {};
};

enum MessageState
{


} typedef MSGSTATE;

struct Message
{
private:
	//---------- Owner
	const IGameObject* m_From;
	//----------  listener?
	const IGameObject* m_To;

	const MSGSTATE m_MsgState;
	const void*	 m_vpData;
public:

	//if your data type == message data type ? return data : fail
	void GetData(_Out_ void* vpStorage, _In_ void* dataType)
	{
		//if (typeid(dataType)==typeid(m_vpData))

	}


	Message(IGameObject* From_Obj,IGameObject* To_Obj, MSGSTATE state, void* data)
		: m_From(From_Obj),m_To(To_Obj), m_MsgState(state), m_vpData(data)
	{
	}

};