#include "stdafx.h"
#include "ToonAlignedAllocator.h"
#include "ToonPlatform.h"
#include <cassert>
#include "ToonBitwise.h"

namespace Toon
{
	/****************************************************************************
					AlignedAllocator class methods definition
	****************************************************************************/
	void * AlignedAllocator::allocate(std::size_t size, std::size_t alignment)
	{
		assert(0U < alignment && alignment <= 128U && Bitwise::isPO2(alignment));
		char *beginPtr, *endPtr;
		size_type totalSize = size + alignment;
		beginPtr = (char*)malloc(totalSize);
		endPtr = beginPtr + totalSize;

		size_type mask = alignment - 1U;
		size_type misalignment = mask & reinterpret_cast<address_type>(beginPtr);
		size_type adjustment = alignment - misalignment;

		char* retPtr = beginPtr + adjustment;
		char* infoPtr = retPtr - 1;
		*infoPtr = static_cast<char>(adjustment);
		
		return retPtr;
	}

	void * AlignedAllocator::allocate(std::size_t size)
	{
		return AlignedAllocator::allocate(size, TOON_SIMD_ALLIGNMENT);
	}

	void * AlignedAllocator::deallocate(void * ptr)
	{
		if (ptr)
		{
			char* infoPtr = reinterpret_cast<char*>(ptr) - 1;
			char adjustment = *infoPtr;
			void* totalPtr = reinterpret_cast<char*>(ptr) - adjustment;
			free(totalPtr);
		}

		return nullptr;
	}
};