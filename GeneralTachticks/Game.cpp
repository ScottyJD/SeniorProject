#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"

GameObject* tile;
Map* map;
GameObject* unit;

SDL_Renderer* Game::mRenderer = nullptr;

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialized" << std::endl;

		mWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (mWindow)
		{
			std::cout << "Window Created" << std::endl;
		}

		mRenderer = SDL_CreateRenderer(mWindow, -1, 0);
		if (mRenderer)
		{
			SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 0);
			std::cout << "Renderer Created" << std::endl;
		}

		mIsRunning = true;
	}
	else
	{
		mIsRunning = false;
	}

	tile = new GameObject("Assets/terrain/mud_normal.png", 0, 0);
	map = new Map();
	unit = new GameObject("Assets/Units/green_heavy_tank.png", 0, 0);
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		mIsRunning = false;
		break;

	default:
		break;
	}
}

void Game::update()
{
	tile->Update();
	unit->Update();
}

void Game::render()
{
	SDL_RenderClear(mRenderer);
	// Add stuff to render here
	map->DrawMap();
	//tile->Render();
	unit->Render();

	SDL_RenderPresent(mRenderer);
}

void Game::clean()
{
	SDL_DestroyWindow(mWindow);
	SDL_DestroyRenderer(mRenderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}

