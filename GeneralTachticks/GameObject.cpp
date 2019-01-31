#pragma once
#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y)
{
	mXpos = x;
	mYpos = y;
	mObjTexture = TextureManager::LoadTexture(texturesheet);
}

GameObject::~GameObject()
{

}

void GameObject::Update()
{
	mSrcRect.h = 395;
	mSrcRect.w = 1059;
	mSrcRect.x = 0;
	mSrcRect.y = 0;

	mDestRect.x = mXpos;
	mDestRect.y = mYpos;
	mDestRect.w = 64;
	mDestRect.h = 32;
}

void GameObject::Render()
{
	SDL_RenderCopy(Game::mRenderer, mObjTexture, &mSrcRect, &mDestRect);
}

