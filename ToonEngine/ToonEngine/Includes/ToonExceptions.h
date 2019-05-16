/**
 * @file ToonExceptions.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief provide useful functions which can deal with assertion and exception.
 * @version 0.1
 * @date 2019-05-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */
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
	template <typename... Bits>
	TOON_FORCE_INLINE void _ToonAssert(char const* msg, char const* file, int line, Bits... conditions)
	{
		if (!(conditions && ...))
		{
			auto const & logger = Logger::getConstInstance();
			logger.errorMessage(msg);
			logger.errorMessage("At file ({0}) in line number ({1})", file, line);
			std::abort();
		}
	}

	template < typename... Logics >
	TOON_FORCE_INLINE bool AnyOf(Logics... conditions)
	{
		return ((conditions) || ...);
	}

	template < typename... Logics >
	TOON_FORCE_INLINE bool AllOf(Logics... conditions)
	{
		return ((conditions) && ...);
	}
};

#define	ToonAssert(msg, ...) Toon::_ToonAssert(msg, __FILE__, __LINE__, (##__VA_ARGS__))

#include "ToonHeaderPostfix.h"

#endif