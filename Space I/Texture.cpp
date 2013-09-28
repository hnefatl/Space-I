#include "Texture.h"

#include "Globals.h"

Texture::Texture()
	:Width(0),
	Height(0),
	Image(NULL)
{

}
Texture::~Texture()
{

}

bool Texture::Load(std::string Path)
{
	Free();

	SDL_Texture *New=NULL;
	SDL_Surface *Surface=NULL;
	// Load the surface
	Surface=IMG_Load(Path.c_str());

	if(Surface!=NULL)
	{
		// Set the transparent colour
		SDL_SetColorKey(Surface, SDL_TRUE, SDL_MapRGB(Surface->format, 0x00, 0xFF, 0xFF));

		// Create texture
		New=SDL_CreateTextureFromSurface(Renderer, Surface);
		if(New==NULL)
		{
			return false;
		}

		// Store the texture dimensions
		Width=Surface->w;
		Height=Surface->h;

		// Free up the memory
		SDL_FreeSurface(Surface);

		// Store the fully loaded texture
		Image=New;
	}

	return Image!=NULL;
}

unsigned int Texture::GetWidth() const
{
	return Width;
}
unsigned int Texture::GetHeight() const
{
	return Height;
}

void Texture::Free()
{
	if(Image!=NULL)
	{
		SDL_DestroyTexture(Image);
		Image=NULL;
	}
	Width=0;
	Height=0;
}