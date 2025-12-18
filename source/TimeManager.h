#pragma once

#include "SDL3/SDL.h"
#include <cmath>

#define TIME TimeManager::Instance()

class TimeManager
{
private:
	TimeManager()
	{
		_deltaTime = 0.0f;
		_elapsedTime = (double)SDL_GetTicks() / 1000.0f;
		_previousElapsedTime = 0.0f;

		_frameTime = 1.0f / (float)_FPS;
		_animationFrameTime = 1.0f / (float)_ANIMATION_FRAME_TIME;
	}
	~TimeManager() = default;

	TimeManager(const TimeManager& t) = delete;
	TimeManager& operator = (const TimeManager& t ) = delete;

	//Time control
	float _deltaTime;
	float _elapsedTime;
	float _previousElapsedTime;

	//FPS control
	const int _FPS = 60;
	const int _ANIMATION_FRAME_TIME = 5;
	float _frameTime;
	float _animationFrameTime;


public:
	static TimeManager& Instance ()
	{
		static TimeManager instance;

		return instance;
	}

	float GetDeltaTime() { return _deltaTime; }
	float GetElapsedTime() { return _elapsedTime; }
	float GetFrameTime() { return _animationFrameTime; }

	bool ShouldUpdateGame() { return _deltaTime >= _frameTime; }

	void ResetDeltaTime()
	{
		_deltaTime -= (float)floor(_deltaTime / _frameTime) * _frameTime;
	}

	void Update()
	{
		_elapsedTime = (double)SDL_GetTicks() / 1000.0;
		_deltaTime += _elapsedTime - _previousElapsedTime;
		_previousElapsedTime = _elapsedTime;
	}
};