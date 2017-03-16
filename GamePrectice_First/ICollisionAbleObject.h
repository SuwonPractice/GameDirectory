#pragma once
#include "IGameObject.h"

class ICollisionAbleObject
{
public:
	ICollisionAbleObject();
	virtual ~ICollisionAbleObject();

	virtual bool Collision(ICollisionAbleObject* obj) = 0;
};

