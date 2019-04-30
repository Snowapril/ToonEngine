#ifndef TOON_PLATFORM_H
#define TOON_PLATFORM_H

#define TOON_SIMD_ALLIGNMENT 16

#define TOON_FORCE_INLINE __forceinline

#define TOON_KEY_COUNT 104

#ifdef _WIN32
#include <Windows.h>
TOON_FORCE_INLINE void SleepCrossPlatform(unsigned long ms) noexcept
{
	Sleep(ms);
}
#elif __linux__
#include <unistd.h>
TOON_FORCE_INLINE void SleepCrossPlatform(unsigned long ms) noexcept
{
	unsigned long seconds = ms / static_cast<float>(1000);
	sleep(seconds);
}
#endif


#endif