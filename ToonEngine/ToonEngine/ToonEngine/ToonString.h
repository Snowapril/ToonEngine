#ifndef TOON_STRING_H
#define TOON_STRING_H

#include <unordered_map>
#include "ToonCRC32Hash.h"

namespace Toon
{
	/****************************************************************************
						ToonString class declaration
	****************************************************************************/

	class ToonString
	{
	private:
		static std::unordered_map<unsigned long, char const*> stringTable;
		unsigned long hashKey;
	public:
		ToonString();
		ToonString(char const * buf, unsigned long key);
		bool operator==(char const * str) const noexcept;

		inline bool operator==(unsigned long key) const noexcept
		{
			return hashKey == key;
		}
		inline bool operator==(ToonString const & other) const noexcept
		{
			return hashKey == other.hashKey;
		} 
		inline char const* toString(void) const
		{
			return stringTable[hashKey];
		}
		inline unsigned long toHashKey(void) const noexcept
		{
			return hashKey;
		}
	};
};

#define TOON_STRING(str) (Toon::ToonString((str), CRC32_STRING_HASH((str))))

#endif // end of TOON_STRING_H