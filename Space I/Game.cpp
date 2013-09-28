#include "Game.h"

#include <stack>
#include <sstream>

#include "Screen.h"
#include "MenuScreen.h"
#include "Timer.h"

Game::Game()
{
	this->Window=NULL;
	this->Renderer=NULL;
}

bool Game::Load(SDL_Renderer *const Renderer)
{
	GameFont=TTF_OpenFont(Resources::Fonts::Font1.c_str(), 15);
	if(GameFont==NULL)
	{
		return false;
	}

	return true;
}

bool Game::Init(const std::string &Title, const unsigned int &Width, const unsigned int &Height)
{
	this->Width=Width;
	this->Height=Height;

	if(SDL_Init(SDL_INIT_VIDEO)<0)
	{
		return false;
	}

	// Enable VSync
	if(!SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1"))
	{
		return false;
	}

	// Set texture filtering to linear
	if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
	{
		return false;
	}

	// Create window
	Window=SDL_CreateWindow(Title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Width, Height, SDL_WINDOW_SHOWN);
	if(Window==NULL)
	{
		return false;
	}

	// Create renderer
	Renderer=SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
	if(Renderer==NULL)
	{
		return false;
	}

	// Initialise SDL_image
	int IMGFlags=IMG_INIT_PNG;
	if(!(IMG_Init(IMGFlags) & IMGFlags))
	{
		return false;
	}

	if(TTF_Init()<0)
	{
		return false;
	}

	// Return the result of loading necessary resources
	return Load(Renderer);
}

void Game::Run()
{
	std::stack<Screen *const> GameScreens;
	MenuScreen *MainMenu=new MenuScreen();
	MainMenu->Load(Renderer);
	GameScreens.push(MainMenu);

	// Game loop
	Timer FrameCapper;
	FrameCapper.Start();
	unsigned long Frames=0;
	unsigned long FrameLimit=1000/60; // Convert frames to ticks
	while(!GameScreens.empty())
	{
		if(!GameScreens.top()->Update(&GameScreens))
		{
			// Screen expired - delete it
			delete GameScreens.top();
			GameScreens.pop();
		}
		else
		{
			SDL_SetRenderDrawColor(Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(Renderer);
			GameScreens.top()->Render(Renderer);
		}

		// Limit framerate
		unsigned int FrameTicks=FrameCapper.GetTicks();
		if(FrameTicks<FrameLimit)
		{
			SDL_Delay(FrameLimit-FrameTicks);
		}

#ifdef _DEBUG
		std::stringstream FPS;
		FPS<<Frames/(FrameCapper.GetTicks()/1000.0f);
		Texture FPSRenderer;
		SDL_Color Colour={0xFF, 0xFF, 0xFF, 0xFF};
		FPSRenderer.Load(FPS.str(), GameFont, Colour, Renderer);
		FPSRenderer.Render(Renderer, 0, 0);
#endif
		// Update the screen after all processing has been done
		SDL_RenderPresent(Renderer);
		Frames++;
	}
}