#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <SDL.h>
#include <SDL_image.h>

#include <string>

class Texture
{
public:
	Texture();
	~Texture();

	bool Load(std::string Path);

	void Render(int x, int y, double Angle=0.0, SDL_Point *Centre=NULL, SDL_RendererFlip Flip=SDL_FLIP_NONE);

	unsigned int GetWidth() const;
	unsigned int GetHeight() const;

protected:
	void Free();

	SDL_Texture *Image;

	unsigned int Width, Height;
};

#endif