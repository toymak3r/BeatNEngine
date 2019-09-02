#include <iostream>
#include <SDL.h>
#include <XibaEngine.hpp>
#include <XibaData.hpp>

// Main Window - minimal on engine to create graphics
SDL_Window *main_window = NULL;

// Mininmal surface
SDL_Surface *main_surface = NULL;

// Data from game
XibaData *xiba_data;

int XibaEngine::Start(const char *title, int width, int height,
					  const std::string &data_directory)
{
	// Load Data
	xiba_data = new XibaData();
	if (!xiba_data->LoadData(data_directory))
		exit(-1);

	// Checking the SDL Initialization
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	else
	{
		main_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
									   width, height, SDL_WINDOW_SHOWN);
		if (main_window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			main_surface = SDL_GetWindowSurface(main_window); // Get minimal initial interface
		}
	}
	return 0;
}

void XibaEngine::Quit()
{

	// Quit
	SDL_Quit();
}