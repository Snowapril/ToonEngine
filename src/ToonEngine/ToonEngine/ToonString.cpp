#include "stdafx.h"
#include "ToonString.h"
#include "ToonCRC32Hash.h"
#include <unordered_map>
#include <type_traits>

namespace Toon
{
	/****************************************************************************
						ToonString class definition
	****************************************************************************/
	constexpr std::unordered_map<unsigned long, char const*> _TOON_STRING_TABLE {
		{1U, "asdf"}
	};

	constexpr ToonString::ToonString(char const * buf)
		: hashKey(_TOON_HASH_KEY)
	{

	}
	bool ToonString::operator==(ToonString const & other) const
	{
		return hashKey == other.hashKey;
	}

	bool ToonString::operator==(char const * str) const
	{
		return hashKey == CRC32_HASH_RUNTIME(str);
	}

	inline char const * Toon::ToonString::toString(void) const
	{
		return nullptr;
	}

	inline unsigned long Toon::ToonString::getHashKey(void) const
	{
		return 0;
	}
};