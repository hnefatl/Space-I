#include "Timer.h"

#include <SDL.h>

Timer::Timer()
{
	Paused=false;
	Stopped=true;

	StartTicks=0;
	PausedTicks=0;
}

void Timer::Start()
{
	Stopped=false;
	Paused=false;

	StartTicks=SDL_GetTicks();
	PausedTicks=0;
}
void Timer::Stop()
{
	Stopped=true;
	Paused=false;

	StartTicks=0;
	PausedTicks=0;
}
void Timer::Pause()
{
	if(!Stopped && !Paused)
	{
		Paused=true;

		PausedTicks=SDL_GetTicks()-StartTicks;
		StartTicks=0;
	}
}
void Timer::Resume()
{
	if(!Stopped && Paused)
	{
		Paused=false;

		StartTicks=SDL_GetTicks()-PausedTicks;
		PausedTicks=0;
	}
}

unsigned long Timer::GetTicks() const
{
	if(!Stopped)
	{
		if(Paused)
		{
			return PausedTicks;
		}
		else
		{
			return SDL_GetTicks()-StartTicks;
		}
	}

	return 0;
}
bool Timer::IsPaused() const
{
	return Paused;
}
bool Timer::IsStopped() const
{
	return Stopped;
}