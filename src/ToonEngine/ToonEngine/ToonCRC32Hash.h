#ifndef TOON_CRC32_HASH_H
#define TOON_CRC32_HASH_H

#include <array>
#include <string_view>

namespace Toon
{
	/****************************************************************************
						CRC32Hasher class declaration
	****************************************************************************/
	class CRC32Hasher
	{
	private:
		static unsigned long UPDC32(char octet, unsigned long crc);
	public:
		template <typename String>
		static constexpr unsigned long hashConstexpr(String const& str);
	};

	/* Copyright (C) 1986 Gary S. Brown.  You may use this program, or
	code or tables extracted from it, as desired without restriction.*/
	template <typename String>
	constexpr unsigned long CRC32Hasher::hashConstexpr(String const& str)
	{
		unsigned long oldcrc32 = 0xFFFFFFFF;
		for (char c : str)
		{
			oldcrc32 = UPDC32(c, oldcrc32);
		}
		return ~oldcrc32;
	}

};

#define CRC32_STRING_HASH(str)	(Toon::CRC32Hasher::hashConstexpr(std::string_view((str)))) 

#endif