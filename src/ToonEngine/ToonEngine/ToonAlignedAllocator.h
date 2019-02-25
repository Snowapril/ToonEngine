#ifndef TOON_ALIGNED_ALLOCATOR_H
#define TOON_ALIGNED_ALLOCATOR_H

#include "ToonHeaderPrefix.h"
#include <cstddef>

namespace Toon
{
	class ToonAlignedAllocator
	{
	public:
		static void* allocate(std::size_t size, std::size_t alignment);
		static void* allocate(std::size_t size);
		static void* deallocate(void* ptr);
	};
};



#include "ToonHeaderPostfix.h"

#endif