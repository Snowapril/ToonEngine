#include "stdafx.h"
#include "ToonString.h"

namespace Toon
{
	/****************************************************************************
						ToonString class definition
	****************************************************************************/
	std::unordered_map<unsigned long, char const*> ToonString::stringTable {};

	ToonString::ToonString()
		: ToonString("", CRC32_STRING_HASH(""))
	{
	}

	ToonString::ToonString(char const * buf, unsigned long key)
		: hashKey(key)
	{
		stringTable[hashKey] = buf;
	}

	bool ToonString::operator==(char const * str) const noexcept
	{
		return hashKey == CRC32_STRING_HASH(str);
	}
};