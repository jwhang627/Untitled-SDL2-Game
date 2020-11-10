#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>

#include "Game.hpp"
#include "GameObject.hpp"
#include "Math.hpp"
#include "Utils.hpp"

using namespace std;

//Game* g_game = 0;

//SDL_Window* g_pWindow = 0;
//SDL_Renderer* g_pRenderer = 0;

int main(int argc, char *argv[]){
	
	std::cout << "> Testing. Hello world." << std::endl;


	Game window("UNTITLED v1.0",400,210,640,480,false);

	GameObject firstObj(Vector2f(48,48),48,48,"res/gfx/Terran.png",window.getRenderer());

	int windowRefreshRate = window.getRefreshRate();

	//GameObject* texture = firstObj.getTexture();

	//g_game = new Game();

	//g_game->init("UNTITLED v0.1",400,210,640,480,true);

	/*
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0){
		g_pWindow = SDL_CreateWindow("UNTITLED v0.1",
			SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
			640,480,SDL_WINDOW_SHOWN);

		if (g_pWindow != 0){
			g_pRenderer = SDL_CreateRenderer(g_pWindow,-1,0);
		}

	} else {
		return 1; // sdl could not initialize
	}*/
	/*
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_Init has failed. Error: " << SDL_GetError() << std::endl;


	// everything succeeded lets draw the window

	// set to black
	SDL_SetRenderDrawColor(g_pRenderer,0,0,0,255);

	// clear the window to black
	SDL_RenderClear(g_pRenderer);

	// show the window
	SDL_RenderPresent(g_pRenderer);

	// clean up SDL
	SDL_Quit();
	*/
/*
	while(g_game->running()){
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}

	g_game->clean();
*/

	while(window.running()){

		int startTicks = SDL_GetTicks();

		window.update();
		window.handleEvents();
		window.clearScreen();
		window.render(firstObj,4.0);
		window.display();

		int frameTicks = SDL_GetTicks() - startTicks;
		if (frameTicks < 1000/windowRefreshRate){
			SDL_Delay(1000/windowRefreshRate - frameTicks);
		}
	}

	window.clean();
	SDL_Quit();

/*
	const float timeStep = 0.01f;
	float accumulator = 0.0f;
	float currentTime = utils::hireTimeInSeconds();
*/

	return 0;
}