#include "GameObject.hpp"
#include "Game.hpp"

GameObject::GameObject(Vector2f p_pos, int p_w, int p_h, const char* p_filePath, SDL_Renderer* p_renderer):pos(p_pos),o_width(p_w),o_height(p_h){

	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = p_w;
	currentFrame.h = p_h;

	texture = IMG_LoadTexture(p_renderer,p_filePath);

	if (texture == NULL)
	{
		std::cout << "> Failed to load texture. Error: " << SDL_GetError() << std::endl;
	}
}

SDL_Texture* GameObject::getTexture(){
	return texture;

}

SDL_Rect GameObject::getCurrentFrame(){
	return currentFrame;
}