#ifndef _MENUSCREEN_H
#define _MENUSCREEN_H

#include <SDL.h>

#include "Screen.h"
#include "Texture.h"

class MenuScreen
	: public Screen
{
public:
	MenuScreen();

	virtual bool Load(SDL_Renderer *const Renderer);

	virtual bool Update(std::stack<Screen *const> *ScreenStack);
	virtual void Render(SDL_Renderer *Renderer);

protected:
	Texture Background;
};

#endif