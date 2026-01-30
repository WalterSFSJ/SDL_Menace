#include "Game.h"
#include "RenderManager.h"
#include "TestObject.h"
#include "Gameplay.h"
#include "MainMenu.h"
#include "ScoreBoard.h"
#include "SceneManager.h"
#include "AudioManager.h"
#include "SplashScreen.h"
#include "LevelSelector.h"
#include "NameInputScene.h"
#include "LevelTwo.h"

Game::Game() {
	for (Object* go : _gameObjects)
		delete go;

	_gameObjects.clear();
}

Game::~Game() {
	
	delete(_window);
	_window = nullptr;

	delete(_renderer);
	_renderer = nullptr;

	for (Object* o : _gameObjects)
	{
		delete(o);
	}
}

void Game::Init()
{

	RM->Init();
	AM->Init();

	RM->LoadTexture("resources/images/fist_0.png");
	RM->LoadTexture("resources/images/fist_1.png");
	RM->LoadTexture("resources/xd.png");
	RM->LoadTexture("resources/images/ship.png");
	RM->LoadTexture("resources/images/background.png");
	RM->LoadTexture("resources/images/projectile.png");
	RM->LoadTexture("resources/images/daniel.png");
	RM->LoadTexture("resources/images/sample_spritesheet.png");
	RM->LoadTexture("resources/images/explosion.png");
	RM->LoadTexture("resources/images/space.png");
	RM->LoadFont("resources/fonts/hyperspace.ttf");

	

	RM->LoadTexture("resources/images/up.png");
	RM->LoadTexture("resources/images/horizontal.png");
	RM->LoadTexture("resources/images/beholder.png");
	RM->LoadTexture("resources/images/bubble.png");
	RM->LoadTexture("resources/images/whale.png");
	RM->LoadTexture("resources/images/chomper.png");
	RM->LoadTexture("resources/images/amoeba.png");
	RM->LoadTexture("resources/images/circle.png");
	RM->LoadTexture("resources/images/button.png");
	RM->LoadTexture("resources/images/button_1.png");
	RM->LoadTexture("resources/images/score.png");
	RM->LoadTexture("resources/images/healt.png");
	RM->LoadTexture("resources/images/canon.png");
	RM->LoadTexture("resources/images/speed.png");
	RM->LoadTexture("resources/images/laser.png");
	RM->LoadTexture("resources/images/torrets.png");
	RM->LoadTexture("resources/images/biotitan.png");
	RM->LoadTexture("resources/images/turboChainsaw.png");
	RM->LoadTexture("resources/images/ufo.png");
	RM->LoadTexture("resources/images/torpedo.png");
	RM->LoadTexture("resources/images/chainsaw.png");
	RM->LoadTexture("resources/images/nuke.png");
	RM->LoadTexture("resources/images/misile.png");
	RM->LoadTexture("resources/images/cave.png");
	RM->LoadTexture("resources/images/angry.png");
	RM->LoadTexture("resources/images/robokrabs.png");
	RM->LoadTexture("resources/images/spaceBoss.png");


	AM->LoadSoundData("resources/audio/music/froggerSong.wav");
	AM->LoadSoundData("resources/audio/music/nebula.wav");
	AM->LoadSoundData("resources/audio/music/nebula.wav");
	AM->LoadSoundData("resources/audio/music/F16.wav");
	AM->LoadSoundData("resources/audio/sfx/defeat.wav");

	//Carga de escenas
	assert(SM.AddScene("SplashScreen", new SplashScreen()));
	assert(SM.AddScene("MainMenu", new MainMenu()));
	assert(SM.AddScene("Gameplay", new Gameplay()));
	assert(SM.AddScene("LevelTwo", new LevelTwo()));
	assert(SM.AddScene("ScoreBoard", new ScoreBoard()));
	SM.AddScene("LevelSelector", new LevelSelector());

	assert(SM.InitFirstScene("SplashScreen"));

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
	IM->Init(_window);
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

	RM->Release();
	AM->HaltAudio();

	SDL_Quit();
}

bool Game::IsRunning() const
{
	return _isRunning;
}

