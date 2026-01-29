#include "InputManager.h"

void InputManager::Init(SDL_Window* window) {
	_windowRef = window;
}

void InputManager::StartTextInput() {
	_inputText = "";
	_isTyping = true;
	if (_windowRef) SDL_StartTextInput(_windowRef);
}

void InputManager::StopTextInput() {
	_isTyping = false;
	if (_windowRef) SDL_StopTextInput(_windowRef);
}

bool InputManager::Listen()
{
	// 1) Actualitzar les tecles del frame anterior
	for (std::unordered_map<Sint32, KeyState>::iterator it = _keyReference.begin();
		it != _keyReference.end();
		it++)
	{
		// Si el en frame anterior just s'ha apretat la tecla ...
		if (it->second == DOWN)
		{
			//...ara estarà sent aguantada.
			it->second == HOLD;
		}
		// Si en el frame anterior just s'ha deixat de prémer la tecla ...
		else if (it->second == UP)
		{
			// ... ara estarà lliure.
			it->second = RELEASED;
		}
	}

	//Obtenir la posició del ratolí
	SDL_GetMouseState(&_mouseX, &_mouseY);

	// Escoltar events
	//(hi ha nou input ?)
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		// Retornar true per acabar l'execució del programa
		if (event.type == SDL_EVENT_QUIT)
			return true;

		if (_isTyping) {
			if (event.type == SDL_EVENT_TEXT_INPUT) {
				if (_inputText.length() < 15) {
					_inputText += event.text.text;
				}
			}
			else if (event.type == SDL_EVENT_KEY_DOWN) {
				if (event.key.key == SDLK_BACKSPACE && !_inputText.empty()) {
					_inputText.pop_back();
				}
				if (_keyReference[event.key.key] != HOLD)
					_keyReference[event.key.key] = DOWN;
			}
		}

		// Si s'ha fet clic
		else if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN)
		{
			// Si el botó és l'esquerre
			if (event.button.button == SDL_BUTTON_LEFT)
				_leftClick = true;
		}

		// Si s'ha deixat de fer clic
		else if (event.type == SDL_EVENT_MOUSE_BUTTON_UP)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
				_leftClick = false;
		}

		// Si s'ha començat a prémer una tecla ...
		else if (event.type == SDL_EVENT_KEY_DOWN)
		{
			// ... i no s'està aguantant ja la tecla
			if (_keyReference[event.key.key] != HOLD)
				_keyReference[event.key.key] = DOWN;

		}
		
			// Si s'ha deixat de prémer una tecla ...
			else if (event.type == SDL_EVENT_KEY_UP)
			{
				_keyReference[event.key.key] = UP;
			}
	}
	
		// Retornar false per seguir amb l'execució del programa
		return false;
	
}


bool InputManager::GetEvent(Sint32 input, KeyState inputValue)
{
	return _keyReference[input] == inputValue;
}
