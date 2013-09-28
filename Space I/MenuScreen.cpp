#include "MenuScreen.h"

#include "Resources.h"

MenuScreen::MenuScreen()
{

}

bool MenuScreen::Load(SDL_Renderer *Renderer)
{
	if(!Background.Load(Resources::Sprites::Backgrounds::Background1, Renderer))
		return false;

	return true;
}

bool MenuScreen::Update(std::stack<Screen *const> *ScreenStack)
{
	SDL_Event Event;
	while(SDL_PollEvent(&Event))
	{
		switch(Event.type)
		{
		case SDL_QUIT: return false;
		}
	}

	return true;
}

void MenuScreen::Render(SDL_Renderer *Renderer)
{
	// Draw the background
	Background.Render(Renderer, 0, 0);
}