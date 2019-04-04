#ifndef BASIC_STRING_H
#define BASIC_STRING_H

#include "Vector.h"
#include "StaticString.h"
#include <string_view>

namespace ToonResourceParser
{
	template < typename CharType, std::size_t Size >
	class BasicString : public Vector<CharType, Size>
	{
	public:
		constexpr BasicString(StaticString const&) noexcept;
		constexpr BasicString(std::string_view const&) noexcept;
	private:
	};
};

#endif