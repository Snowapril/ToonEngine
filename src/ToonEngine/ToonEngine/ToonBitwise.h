#ifndef TOON_BITWISE_H
#define TOON_BITWISE_H

#include "ToonHeaderPrefix.h"
#include "ToonPlatform.h"
#include <cstddef>
#include <type_traits>

namespace Toon
{
	/****************************************************************************
				Bitwise class declaration
	****************************************************************************/
	class Bitwise
	{
	public:
		// return whether if given number is power of two or not.
		template <typename Type, typename = typename std::enable_if_t< std::is_unsigned_v<Type>> >
		static bool TOON_FORCE_INLINE isPO2(Type num)
		{
			return (num & (num - 1)) == 0;
		}
	};
};

#include "ToonHeaderPrefix.h"


#endif