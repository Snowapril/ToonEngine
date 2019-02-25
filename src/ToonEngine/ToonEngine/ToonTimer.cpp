#include "stdafx.h"
#include "ToonTimer.h"
#include "ToonLogger.h"

namespace Toon
{
	template <> ToonTimer* ToonSingleton<ToonTimer>::instance = nullptr;

	ToonTimer::ToonTimer()
		: startTime(), currentTime(), pausedTime(), deltaTime(), bPaused(false)
	{
	}

	ToonTimer::~ToonTimer()
	{
		ToonLogger::getConstInstance().infoMessage( "[Singleton] Timer instnace is released" );
	}

	void ToonTimer::tick(void)
	{
		using namespace std::chrono;

		auto previousTime = currentTime;
		currentTime = high_resolution_clock::now();
		auto elapsedTime = duration_cast< duration<double> >( currentTime - previousTime ).count();

		if (bPaused)
		{
			pausedTime += elapsedTime;
			deltaTime = 0.0;
		}
		else
		{
			deltaTime = elapsedTime;
		}

		if (deltaTime < 0.0) deltaTime = 0.0;
	}

	void ToonTimer::start(void)
	{
		if (bPaused) bPaused = false;
	}

	void ToonTimer::reset(void)
	{
		startTime	= ( currentTime = std::chrono::high_resolution_clock::now() );
		bPaused		= false	;
		deltaTime	= 0.0	;
		pausedTime	= 0.0	;
	}

	void ToonTimer::pause(void)
	{
		if (!bPaused) bPaused = true;
	}

	bool ToonTimer::isOnGoing(void) const
	{
		return !bPaused;
	}

	bool ToonTimer::isPaused(void) const
	{
		return  bPaused;
	}

	float ToonTimer::getDeltaTime(void) const
	{
		return static_cast<float>(deltaTime);
	}

	float ToonTimer::getTotalTime(void) const
	{
		using namespace std::chrono;
		auto wholeDuration = duration_cast< duration<double> >( currentTime - startTime ).count();

		return static_cast<float>( wholeDuration - pausedTime );
	}

	ToonTimer const & ToonTimer::getConstInstance(void)
	{
		return *instance;
	}

	ToonTimer & ToonTimer::getMutableInstance(void)
	{
		return *instance;
	}
};