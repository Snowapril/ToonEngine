#ifndef TOON_TIMER_H
#define TOON_TIMER_H

#include "ToonHeaderPrefix.h"
#include "ToonSingleton.h"
#include <chrono>

namespace Toon
{
	using time_point_t = std::chrono::time_point< std::chrono::high_resolution_clock >;

	class ToonTimer : public ToonSingleton< ToonTimer >
	{
	private:
		time_point_t	startTime	;
		time_point_t	currentTime	;
		double			pausedTime	;  // represent elapsed time as state "pause"
		double			deltaTime	;
		bool			bPaused		;
	public:
		ToonTimer();
		~ToonTimer();

		void tick	(void);
		void start	(void);
		void reset	(void);
		void pause	(void);

		bool isOnGoing	(void) const;
		bool isPaused	(void) const;

		float getDeltaTime(void) const;
		float getTotalTime(void) const;
	public:
		static ToonTimer const&		getConstInstance	(void);
		static ToonTimer &			getMutableInstance	(void);
		static bool				isDestroyed			(void) { return instance == nullptr; }
	};
};

#include "ToonHeaderPostfix.h"

#endif