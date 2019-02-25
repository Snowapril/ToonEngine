#ifndef TOON_NONCOPYABLE_H
#define TOON_NONCOPYABLE_H

#include "ToonHeaderPrefix.h"

namespace Toon
{
	class Noncopyable
	{
	public:
		Noncopyable() = default;
		Noncopyable(const Noncopyable& other) = delete;
		Noncopyable(Noncopyable&& other) = delete;
		Noncopyable& operator=(const Noncopyable& other) = delete;
		Noncopyable& operator=(Noncopyable&& other) = delete;
	};
};

#include "ToonHeaderPostfix.h"

#endif //TOON_NONCOPYABLE_H