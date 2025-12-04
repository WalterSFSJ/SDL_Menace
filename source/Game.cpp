#include "Game.h"
#include "RenderManager.h"
#include "TestObject.h"
#include "Gameplay.h"
#include "MainMenu.h"
#include "SceneManager.h"

Game::Game() {
	for (Object* go : _gameObjects)
		delete go;

	_gameObjects.clear();
}

void Game::Init()
{

	RM->Init();

	RM->LoadTexture("resources/images/fist_0.png");
	RM->LoadTexture("resources/images/fist_1.png");
	RM->LoadTexture("resources/xd.png");
	RM->LoadTexture("resources/images/ship.png");
	RM->LoadTexture("resources/images/background.png");
	RM->LoadFont("resources/fonts/hyperspace.ttf");

	//Carga de escenas
	assert(SM.AddScene("MainMenu", new MainMenu()));
	assert(SM.AddScene("Gameplay", new Gameplay()));

	assert(SM.InitFirstScene("MainMenu"));

	_isRunning = true;
	
}

void Game::InitSDL()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
		throw SDL_GetError();
}

void Game::CreateWindoeAndRenderer()
{
	if (!SDL_CreateWindowAndRenderer("Test main", 512, 512, SDL_WINDOW_RESIZABLE, &_window, &_renderer))
		throw SDL_GetError();
}

void Game::HandleEvents()
{
	_isRunning = !IM->Listen();
}

void Game::Update()
{
	SM.UpdateCurrentScene();
}

void Game::Render()
{
	RM->ClearScreen();
	SM.GetCurrentScene()->Render();
	RM->RenderScreen();
}

void Game::Release()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

bool Game::IsRunning() const
{
	return _isRunning;
}

