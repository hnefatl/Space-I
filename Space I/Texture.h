#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <string>

class Texture
{
public:
	Texture();
	~Texture();

	bool Load(const std::string &Path, SDL_Renderer *const Renderer);
#ifdef _SDL_TTF_H
	bool Load(const std::string &Text, TTF_Font *const Font, const SDL_Color &TextColour, SDL_Renderer *const Renderer);
#endif

	void Render(SDL_Renderer *const Renderer, const int &x, const int &y, const double &Angle=0.0, SDL_Point *const Centre=NULL, const SDL_RendererFlip &Flip=SDL_FLIP_NONE);

	void SetColour(const unsigned short &Red, const unsigned short &Green, const unsigned short &Blue);
	void SetBlendMode(const SDL_BlendMode &Mode);
	void SetAlpha(const unsigned short &Alpha);

	unsigned int GetWidth() const;
	unsigned int GetHeight() const;

protected:
	void Free();

	SDL_Texture *Image;

	unsigned int Width, Height;
};

#endif