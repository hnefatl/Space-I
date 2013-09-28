#ifndef _CONTROL_H
#define _CONTROL_H

#include "ResourceUser.h"

class Control
	: public ResourceUser
{
public:
	virtual void Update()=0;
	virtual void Draw()=0;

protected:

};

#endif