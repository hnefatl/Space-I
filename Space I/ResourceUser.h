#ifndef _RESOURCEUSER_H
#define _RESOURCEUSER_H

#include <SDL.h>

#include "Resources.h"

class ResourceUser
{
public:
	virtual bool Load(SDL_Renderer *const Renderer)=0;
};

#endif