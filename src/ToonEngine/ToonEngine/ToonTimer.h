#ifndef TOON_TIMER_H
#define TOON_TIMER_H

#include "ToonHeaderPrefix.h"
#include "ToonSingleton.h"
#include <chrono>

namespace Toon
{
	/****************************************************************************
						Timer class declaration
	****************************************************************************/
	using time_point_t = std::chrono::time_point< std::chrono::high_resolution_clock >;

	class Timer : public Singleton< Timer >
	{
	private:
		time_point_t	startTime	;
		time_point_t	currentTime	;
		double			pausedTime	;  // represent elapsed time as state "pause"
		double			deltaTime	;
		bool			bPaused		;
	public:
		Timer();
		~Timer();

		void tick	(void);
		void start	(void);
		void reset	(void);
		void pause	(void);

		bool isOnGoing	(void) const;
		bool isPaused	(void) const;

		float getDeltaTime(void) const;
		float getTotalTime(void) const;
	};
};

#include "ToonHeaderPostfix.h"

#endif