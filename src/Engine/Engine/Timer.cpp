#include "stdafx.h"
#include "Timer.h"

Timer::Timer()
	: startTime(), currentTime(), pausedTime(), deltaTime(), bPaused(false)
{
}

void Timer::tick(void)
{
	using namespace std::chrono;

	auto previousTime	= currentTime;
	currentTime			= high_resolution_clock::now();
	auto elapsedTime	= duration_cast<duration<double>>(currentTime - previousTime).count();
	
	if (bPaused)
	{
		pausedTime += elapsedTime;
		deltaTime	= 0.0;
	}
	else
	{
		deltaTime	= elapsedTime;
	}

	if (deltaTime < 0.0) deltaTime = 0.0;
}

void Timer::start(void)
{
	if (bPaused) bPaused = false;
}

void Timer::reset(void)
{
	startTime	= (currentTime = std::chrono::high_resolution_clock::now());
	bPaused		= false;
	deltaTime	= 0.0;
	pausedTime	= 0.0;
}

void Timer::pause(void)
{
	if (!bPaused) bPaused = true; 
}

bool Timer::isOnGoing(void) const
{
	return !bPaused;
}

bool Timer::isPaused(void) const
{
	return  bPaused;
}

float Timer::getDeltaTime(void) const
{
	return static_cast<float>(deltaTime);
}

float Timer::getTotalTime(void) const
{
	using namespace std::chrono;
	auto wholeDuration	= duration_cast<duration<double>>(currentTime - startTime).count();
	
	return static_cast<float>(wholeDuration - pausedTime);
}
