#ifndef TOON_EXCEPTIONS_H
#define TOON_EXCEPTIONS_H

#include "ToonHeaderPrefix.h"
#include <cassert>
#include <string>

namespace Toon
{
	template < typename... Logics >
	inline void ToonAssert( std::string const& msg, Logics... bits )
	{
		assert( (... && bits) );
	}
};

#include "ToonHeaderPostfix.h"

#endif