#include "Texture.h"

Texture::Texture()
	:Width(0),
	Height(0),
	Image(NULL)
{

}
Texture::~Texture()
{

}

bool Texture::Load(const std::string &Path, SDL_Renderer *const Renderer)
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
			SDL_FreeSurface(Surface);
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

#ifdef _SDL_TTF_H
bool Texture::Load(const std::string &Text, TTF_Font *const Font, const SDL_Color &TextColour, SDL_Renderer *const Renderer)
{
	Free();

	SDL_Surface *Surface=TTF_RenderText_Solid(Font, Text.c_str(), TextColour);
	if(Surface==NULL)
	{
		return false;
	}

	SDL_Texture *New=NULL;
	New=SDL_CreateTextureFromSurface(Renderer, Surface);
	if(New==NULL)
	{
		SDL_FreeSurface(Surface);
		return false;
	}

	Image=New;
	Width=Surface->w;
	Height=Surface->h;

	SDL_FreeSurface(Surface);

	return true;
}
#endif

void Texture::Render(SDL_Renderer *const Renderer, const int &x, const int &y, const double &Angle, SDL_Point *const Centre, const SDL_RendererFlip &Flip)
{
	SDL_Rect RenderQuad={x, y, Width, Height};

	SDL_RenderCopyEx(Renderer, Image, NULL, &RenderQuad, Angle, Centre, Flip);
}

void Texture::SetColour(const unsigned short &Red, const unsigned short &Green, const unsigned short &Blue)
{
	SDL_SetTextureColorMod(Image, (Uint8)Red, (Uint8)Green, (Uint8)Blue);
}
void Texture::SetBlendMode(const SDL_BlendMode &Mode)
{
	SDL_SetTextureBlendMode(Image, Mode);
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