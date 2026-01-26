#pragma once

#include "SDL3/SDL.h"
#include <cmath>

#define TIME TimeManager::Instance()

class TimeManager
{
private:
	TimeManager()
	{
		_previousElapsedTime = (double)SDL_GetTicks() / 1000.0f;

		_frameTime = 1.0f / (float)_FPS;
	}
	~TimeManager() = default;

	TimeManager(const TimeManager& t) = delete;
	TimeManager& operator = (const TimeManager& t ) = delete;

	//Time control
	float _deltaTime = 0.0f;
	float _elapsedTime = 0.0f;
	float _previousElapsedTime;

	//FPS control
	const int _FPS = 30;
	const int _ANIMATION_FRAME_TIME = 5;
	float _frameTime;
	float _animationFrameTime;


public:
	static TimeManager& Instance ()
	{
		static TimeManager instance;

		return instance;
	}

	float GetDeltaTime() const { return _deltaTime; }
	float GetElapsedTime() const { return _elapsedTime; }
	float GetFrameTime() { return _animationFrameTime; }

	bool ShouldUpdateGame() const { return _deltaTime >= _frameTime; }

	void ResetDeltaTime()
	{
		_deltaTime = _deltaTime - (float)(floor(_deltaTime / _frameTime) * _frameTime);
	}

	void Update()
	{
		_elapsedTime = (double)SDL_GetTicks() / 1000.0;
		_deltaTime += _elapsedTime - _previousElapsedTime;
		_previousElapsedTime = _elapsedTime;
	}
};