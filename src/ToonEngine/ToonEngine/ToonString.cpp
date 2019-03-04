#include "stdafx.h"
#include "ToonString.h"
#include "ToonCRC32Hash.h"

namespace Toon
{
	/****************************************************************************
						ToonString class definition
	****************************************************************************/
	ToonString::ToonString(unsigned long key)
		: hashKey(key)
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

	std::unordered_map<unsigned long, char const*> VisibleString::stringTable {};

	VisibleString::VisibleString(char const * buf)
	{
		hashKey = CRC32_HASH_RUNTIME(buf);
		stringTable[hashKey] = buf;
	}

	bool VisibleString::operator==(VisibleString const & other) const
	{
		return hashKey == other.hashKey;
	}
};