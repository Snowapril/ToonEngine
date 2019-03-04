#ifndef TOON_STRING_H
#define TOON_STRING_H

#include "ToonSingleton.h"
#include <unordered_map>

#define CRC32_CONSTEXPR(str) {}
#define CRC32_RUNTIME(str) {}

namespace Toon
{
	class ToonString
	{
	private:
		static std::unordered_map<unsigned long, char*> stringTable;
		unsigned long hashKey;
	public:
		ToonString(unsigned long);
		ToonString(char const*);
		bool operator==(ToonString const &) const;
		bool operator==(char const*) const;

		template <typename Type>
		bool compareTo(Type const &other) const;

		inline char const* toString(void) const
		{
			return stringTable[hashKey];
		}
		inline unsigned long getHashKey(void) const
		{
			return hashKey;
		}
	};
	
	template<typename Type>
	inline bool ToonString::compareTo(Type const & other) const
	{
		return (*this == other);
	}
};

#endif // end of TOON_STRING_H