#ifndef ALIGNED_ALLOCATOR_H
#define ALIGNED_ALLOCATOR_H

#include "ToonHeaderPrefix.h"
#include <cstddef>

namespace Toon
{
	class AlignedAllocator
	{
	public:
		static void* allocate(std::size_t size, std::size_t alignment);
		static void* allocate(std::size_t size);
		static void* deallocate(void* ptr);
	};
};



#include "ToonHeaderPostfix.h"

#endif