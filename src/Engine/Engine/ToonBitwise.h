#ifndef TOON_BITWISE_H
#define TOON_BITWISE_H

#include "ToonHeaderPrefix.h"
#include "ToonPlatform.h"
#include <cstddef>
#include <type_traits>

namespace Toon
{
	class ToonBitwise
	{
	public:
		// return whether if given number is power of two or not.
		template <typename Type, typename = typename std::enable_if_t< std::is_integral_v<Type>> >
		static bool TOON_FORCE_INLINE isPO2(Type num)
		{
			SFDDSF
		}
	};
};

#include "ToonHeaderPrefix.h"


#endif