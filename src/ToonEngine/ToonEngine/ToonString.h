#ifndef TOON_STRING_H
#define TOON_STRING_H

#include "ToonSingleton.h"
#include <unordered_map>
#include <type_traits>

namespace Toon
{
	/****************************************************************************
						ToonString class declaration
	****************************************************************************/
	enum class _TOON_STRING_TABLE : unsigned long;

	class ToonString
	{
	protected:
		unsigned long hashKey;
	public:
		ToonString() = default;
		ToonString(unsigned long);
		bool operator==(ToonString const &) const;
		bool operator==(char const*) const;
	};
	
	/****************************************************************************
						VisibleStirng class declaration
	****************************************************************************/
	class VisibleString : public ToonString
	{
	private:
		static std::unordered_map<unsigned long, char const*> stringTable;
	public:
		VisibleString(char const*);
		bool operator==(VisibleString const &) const;

		inline char const* toString(void) const
		{
			return stringTable[hashKey];
		}
		inline unsigned long getHashKey(void) const
		{
			return hashKey;
		}
	};

#define _TOON_STRING_INTERNAL(str) 
#define TOON_STRING(key) (ToonString((key)))
#define VISIBLE_STRING(str) (VisibleString((str)))

};


#endif // end of TOON_STRING_H