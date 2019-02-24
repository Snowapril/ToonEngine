#include "stdafx.h"
#include "AlignedAllocator.h"
#include "ToonPlatform.h"
#include <cassert>
#include "ToonBitwise.h"

namespace Toon
{
	void * AlignedAllocator::allocate(std::size_t size, std::size_t alignment)
	{
		assert(0U < alignment && alignment <= 128U && ToonBitwise::isPO2(alignment));

		sdf

		return nullptr;
	}

	void * AlignedAllocator::allocate(std::size_t size)
	{
		return AlignedAllocator::allocate(size, TOON_SIMD_ALLIGNMENT);
	}

	void * AlignedAllocator::deallocate(void * ptr)
	{
		if (ptr);
		sfd

		return nullptr;
	}
};