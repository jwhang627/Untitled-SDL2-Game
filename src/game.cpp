#include "Game.hpp"

using namespace std;

const float timeStep = 0.01f;
float accumulator = 0.0f;
float currentTime = utils::hireTimeInSeconds();
int startTicks = 0;
SDL_Event event;

Game::Game(const char* p_title, int p_x, int p_y, int p_w, int p_h, bool fullscreen):m_pWindow(NULL),m_pRenderer(NULL){

	int flags = 0;

	if (fullscreen){
		flags = SDL_WINDOW_FULLSCREEN;
	}

	m_pWindow = SDL_CreateWindow(p_title,p_x,p_y,p_w,p_h,flags);

/*
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
		std::cout << "> SDL init success!" << std::endl;
		
		// init the window
		m_pWindow = SDL_CreateWindow(title,p_x,p_y,p_w,p_h,flags);
	
		if (m_pWindow != 0){
			std::cout << "> Window creation success!" << std::endl;
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		
			if (m_pRenderer != 0){
				std::out << "> Renderer creation success!" << std::endl;
				SDL_SetRenderDrawColor(m_pRenderer,
					255,255,255,255);
			} else {
				std::cout << "> Renderer init fail." << std::endl;
				return false;
			}
		} else {
			std::cout << "> Window init fail." << std::endl;
			return false;
		}
	} else {
		std::cout << "> SDL init fail." << std::endl;
		return false;
	}
*/

	if (m_pWindow == NULL){
		std::cout << "> Window failed to initialize (game.cpp). Error: " << SDL_GetError() << std::endl;
	}

	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	std::cout << "> Init success! (game.cpp)" << std::endl;

	m_bRunning = true;
}

int Game::getRefreshRate(){
	int displayIndex = SDL_GetWindowDisplayIndex(m_pWindow);

	SDL_DisplayMode mode;
	SDL_GetDisplayMode(displayIndex,0,&mode);

	return mode.refresh_rate;
}

void Game::render(GameObject& p_object,float zoom){
	
	SDL_Rect src;

	src.x = p_object.getCurrentFrame().x;
	src.y = p_object.getCurrentFrame().y;
	src.w = p_object.getCurrentFrame().w;
	src.h = p_object.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = p_object.getPos().x*zoom;
	dst.y = p_object.getPos().y*zoom;
	dst.w = p_object.getCurrentFrame().w*zoom;
	dst.h = p_object.getCurrentFrame().h*zoom;

	SDL_RenderCopy(m_pRenderer,p_object.getTexture(),&src,&dst);
}

void Game::update(){
	
	//startTicks = SDL_GetTicks();
	float newTime = utils::hireTimeInSeconds();
	float frameTime  = newTime - currentTime;

	currentTime = newTime;
	accumulator += frameTime;
}

void Game::handleEvents(){
	
	/*
	if (SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:
				m_bRunning = false;
				break;
			default:
				break;
		}
	}
	*/
	while(accumulator >= timeStep){
		while(SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){
				m_bRunning = false;
			}
		}
		accumulator -= timeStep;
	}
	//const float alpha = accumulator/timeStep;
}

void Game::clearScreen(){
	SDL_RenderClear(m_pRenderer);
}

void Game::clean(){
	std::cout << "> Cleaning game. (game.cpp)" << std::endl;
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::display(){
	// Display the image
	SDL_RenderPresent(m_pRenderer);
	//int frameTicks = SDL_GetTicks() - startTicks;
	
	//if (frameTicks < 1000/getRefreshRate()){
	//	SDL_Delay(1000/getRefreshRate() - frameTicks);
	//}
}