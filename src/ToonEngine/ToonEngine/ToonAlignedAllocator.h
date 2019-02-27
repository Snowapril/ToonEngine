#ifndef TOON_ALIGNED_ALLOCATOR_H
#define TOON_ALIGNED_ALLOCATOR_H

#include "ToonHeaderPrefix.h"
#include <cstddef>
#include "ToonNoncopyable.h"
#include <memory>

namespace Toon
{
	/****************************************************************************
						AlignedAllocator class  declaration
	****************************************************************************/
	class AlignedAllocator
	{
	public:
		using size_type		= typename std::size_t;
		using address_type	= typename std::uintptr_t;
	public:
		static void* allocate(std::size_t size, std::size_t alignment);
		static void* allocate(std::size_t size);
		static void* deallocate(void* ptr);
	};

};



#include "ToonHeaderPostfix.h"

#endif