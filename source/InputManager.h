#pragma once
#include "SDL3/SDL.h"
#include <unordered_map>
#include <string>
#define IM InputManager::GetInstance()

enum KeyState { EMPTY, DOWN, UP, HOLD, RELEASED };

class InputManager
{
	public:
		static InputManager * GetInstance()
		{
			static InputManager instance;
			return &instance;
		}
	
		void Init(SDL_Window* window);

		bool Listen();
	

		void StartTextInput();
		void StopTextInput();
		std::string GetInputText() const { return _inputText; }
		bool IsTyping() const { return _isTyping; }

		float GetMouseX() const { return _mouseX; }
		float GetMouseY() const { return _mouseY; }
		bool GetLeftClick() const { return _leftClick; }
		bool GetEvent(Sint32 input, KeyState inputValue);
	private:
		InputManager() = default;
		InputManager(InputManager&) = delete;
		InputManager & operator=(const InputManager&) = delete;
		~InputManager() {}

		SDL_Window* _windowRef = nullptr;

			 // Posició del ratolí
		 float _mouseX, _mouseY;
	
		bool _leftClick;
	

		bool _isTyping = false;
		std::string _inputText = "";

	//A cada tecla (key) del teclat li correspondrà un estat
		std::unordered_map<Sint32, KeyState> _keyReference;
};