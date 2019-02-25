#ifndef TOON_NONCOPYABLE_H
#define TOON_NONCOPYABLE_H

#include "ToonHeaderPrefix.h"

namespace Toon
{
	class ToonNoncopyable
	{
	public:
		ToonNoncopyable() = default;
		ToonNoncopyable(const ToonNoncopyable& other) = delete;
		ToonNoncopyable(ToonNoncopyable&& other) = delete;
		ToonNoncopyable& operator=(const ToonNoncopyable& other) = delete;
		ToonNoncopyable& operator=(ToonNoncopyable&& other) = delete;
	};
};

#include "ToonHeaderPostfix.h"

#endif //TOON_NONCOPYABLE_H