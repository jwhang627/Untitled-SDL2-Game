#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include "GameObject.hpp"
#include "Utils.hpp"

class Game{
	public:
		Game(const char* p_title, int p_x, int p_y,int p_w, int p_h, bool fullscreen);

		int getRefreshRate();

		void render(GameObject& p_object, float zoom);
		SDL_Renderer* getRenderer(){ return m_pRenderer;}
		void update();
		void handleEvents();
		void clearScreen();
		void clean();
		void display();

		bool running(){ return m_bRunning;}
	private:

		SDL_Window* m_pWindow;
		SDL_Renderer* m_pRenderer;

		bool m_bRunning;
};