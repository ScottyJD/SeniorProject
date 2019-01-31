#pragma once
#include "Game.h"

class Map
{
public:
	Map();
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap();

private:
	SDL_Rect mSrc, mDest;
	SDL_Texture* mDirt;
	SDL_Texture* mGrass;
	SDL_Texture* mWater;
	
	int mMap[20][25];
};