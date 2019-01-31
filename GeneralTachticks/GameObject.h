#pragma once
#include "Game.h"

class GameObject
{
public:
	GameObject(const char* texturesheet, int x, int y);
	~GameObject();

	void Update();
	void Render();

private:
	
	int mXpos;
	int mYpos;

	SDL_Texture* mObjTexture;
	SDL_Rect mSrcRect, mDestRect;
};