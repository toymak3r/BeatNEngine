#include <iostream>
#include <SDL.h>
#include <XibaEngine.hpp>

int XibaEngine::Start() {

    // Checking the SDL Initialization
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	return 0;

}

void XibaEngine::Quit() {

    // Quit
	SDL_Quit();

}