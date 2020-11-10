#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Math.hpp"

class GameObject
{
	public:
		GameObject(Vector2f p_pos, int p_w, int p_h, const char* p_filePath, SDL_Renderer* p_renderer);
		//~GameObject();

		Vector2f& getPos(){
			return pos;
		}

		SDL_Texture* getTexture();
		SDL_Rect getCurrentFrame();

		//float getZoom(){
		//	return o_zoom;
		//}

	private:
		Vector2f pos;
		int o_width;
		int o_height;
		//float o_zoom;
		SDL_Rect currentFrame;
		SDL_Texture* texture;
};