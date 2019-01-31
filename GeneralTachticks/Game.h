#ifndef _GAME_H_
#define _GAME_H_

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#undef main

class Game
{
public:

	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return mIsRunning; }

	static SDL_Renderer *mRenderer;

private:

	int mCnt = 0;
	bool mIsRunning;
	SDL_Window *mWindow;
};
#endif // !_GAME_H_

