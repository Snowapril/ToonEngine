#ifndef TOON_STRING_H
#define TOON_STRING_H

#include "ToonSingleton.h"


namespace Toon
{
	/****************************************************************************
						ToonString class declaration
	****************************************************************************/

	class ToonString
	{
	private:
		unsigned long hashKey;
	public:
		ToonString() = default;
		constexpr ToonString(char const * buf);
		bool operator==(ToonString const &) const;
		bool operator==(char const*) const;
		inline char const* toString(void) const;
		inline unsigned long getHashKey(void) const;
	};
};

#define TOON_STRING(str) (Toon::ToonString((str)))

#endif // end of TOON_STRING_H