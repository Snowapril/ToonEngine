#include "stdafx.h"
#include "ToonAlignedAllocator.h"
#include "ToonPlatform.h"
#include <cassert>
#include "ToonBitwise.h"

namespace Toon
{
	void * ToonAlignedAllocator::allocate(std::size_t size, std::size_t alignment)
	{
		assert(0U < alignment && alignment <= 128U && ToonBitwise::isPO2(alignment));

		return nullptr;
	}

	void * ToonAlignedAllocator::allocate(std::size_t size)
	{
		return ToonAlignedAllocator::allocate(size, TOON_SIMD_ALLIGNMENT);
	}

	void * ToonAlignedAllocator::deallocate(void * ptr)
	{
		if (ptr);

		return nullptr;
	}
};