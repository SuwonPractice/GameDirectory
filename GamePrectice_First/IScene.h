#pragma once
#include "stdafx.h"

class IScene
{
public:
	IScene();
	virtual ~IScene();

	virtual INT Init()		= 0;
	virtual INT Render()	= 0;
	virtual INT Update()	= 0;
	virtual void Close()	= 0;
};

