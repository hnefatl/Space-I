#ifndef _GAME_H
#define _GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <string>

#include "ResourceUser.h"

class Game
	: public ResourceUser
{
public:
	Game();

	virtual bool Load(SDL_Renderer * const Renderer);

	bool Init(const std::string &Title, const unsigned int &Width, const unsigned int &Height);

	void Run();

protected:
	SDL_Window *Window;
	SDL_Renderer *Renderer;

	TTF_Font *GameFont;

	unsigned int Width, Height;
};

#endif