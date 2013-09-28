#ifndef _SCREEN_H
#define _SCREEN_H

#include <stack>

#include "ResourceUser.h"

class Screen
	:public ResourceUser
{
public:
	virtual bool Load(SDL_Renderer *const Renderer)=0;

	virtual bool Update(std::stack<Screen *const> *ScreenStack)=0;
	virtual void Render(SDL_Renderer *Renderer)=0;
};

#endif