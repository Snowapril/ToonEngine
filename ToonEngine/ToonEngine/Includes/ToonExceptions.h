#ifndef TOON_EXCEPTIONS_H
#define TOON_EXCEPTIONS_H

#include "ToonHeaderPrefix.h"
#include "ToonPlatform.h"
#include "ToonLogger.h"
#include <cassert>
#include <string>

/****************************************************************************
				ToonAssertion functions here.
****************************************************************************/
namespace Toon
{
	template< typename... Bits >
	TOON_FORCE_INLINE void ToonAssert(char const* msg, Bits... bits)
	{
		if (!(bits && ...))
		{
			Logger::getConstInstance().errorMessage(msg);
			std::terminate();
		}
	}

	template < typename... Logics >
	TOON_FORCE_INLINE bool AnyOf(Logics... logics)
	{
		return ((logics) || ...);
	}

	template < typename... Logics >
	TOON_FORCE_INLINE bool AllOf(Logics... logics)
	{
		return ((logics) && ...);
	}
};

#include "ToonHeaderPostfix.h"

#endif