#include "stdafx.h"
#include "ToonCRC32Hash.h"


namespace Toon
{
	/****************************************************************************
						CRC32Hasher class definition
	****************************************************************************/

	/* Copyright (C) 1986 Gary S. Brown.  You may use this program, or
	code or tables extracted from it, as desired without restriction.*/
	unsigned long CRC32Hasher::hashRuntime(char const * buf, unsigned long long len)
	{
		unsigned long oldcrc32 = 0xFFFFFFFF;
		for (; len; --len, ++buf)
		{
			oldcrc32 = UPDC32(*buf, oldcrc32);
		}

		return ~oldcrc32;
	}
};