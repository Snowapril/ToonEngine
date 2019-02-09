#ifndef TIMER_H
#define TIMER_H

#include "NonCopyable.h"
#include <chrono>

using time_point_t = std::chrono::time_point<std::chrono::high_resolution_clock>;

class Timer : public NonCopyable
{
private:
	time_point_t	startTime;
	time_point_t	currentTime;
	double			pausedTime;  // represent elapsed time as state "pause"
	double			deltaTime;
	bool			bPaused;
public:
	Timer();

	void tick (void);
	void start(void);
	void reset(void);
	void pause(void);
	
	bool isOnGoing(void) const;
	bool isPaused (void) const;

	float getDeltaTime(void) const;
	float getTotalTime(void) const;
};

#endif