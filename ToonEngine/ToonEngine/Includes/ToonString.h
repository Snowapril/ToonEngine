/**
 * @file ToonString.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief the string class of the toon engine. 
 * 
 * because comparing whole characters in the manual string will be highly computative, hashing the string into the integer value in advance.
 * comparing the single integer values will be absolutely more time efficient than comparing the whole characters
 * 
 * @version 0.1
 * @date 2019-05-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef TOON_STRING_H
#define TOON_STRING_H

#include <unordered_map>
#include "ToonPlatform.h"
#include "ToonCRC32Hash.h"

namespace Toon
{
	/****************************************************************************
						ToonString class declaration
	****************************************************************************/

	/**
	 * @brief string class of the toon engine.
	 * 
	 */
	class ToonString
	{
	private:
		static std::unordered_map<unsigned long, char const*> stringTable;
		unsigned long hashKey;
	public:
		ToonString();
		ToonString(char const * buf, unsigned long key);
		bool operator==(char const * str) const noexcept;

		TOON_FORCE_INLINE bool operator==(unsigned long key) const noexcept
		{
			return hashKey == key;
		}
		TOON_FORCE_INLINE bool operator==(ToonString const & other) const noexcept
		{
			return hashKey == other.hashKey;
		} 
		TOON_FORCE_INLINE char const* toString(void) const
		{
			return stringTable[hashKey];
		}
		TOON_FORCE_INLINE unsigned long toHashKey(void) const noexcept
		{
			return hashKey;
		}
	};
};

#define TOON_STRING(str) (Toon::ToonString((str), CRC32_STRING_HASH((str))))

#endif // end of TOON_STRING_H