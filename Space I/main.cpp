#include <SDL.h>
#ifdef _DEBUG
#include <iostream>
#endif

#include "Game.h"

int main(int argc, char *argv[])
{
	Game Main;
	if(!Main.Init("Space", 800, 600))
	{
		return -1;
	}
	Main.Run();

	return 0;
}