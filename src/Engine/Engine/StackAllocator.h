#ifndef STACK_ALLOCATOR_H
#define STACK_ALLOCATOR_H

#include "ToonHeaderPrefix.h"
#include "Noncopyable.h"
#include <type_traits>
#include <cassert>
#include <stack>
#include <cstdlib>

namespace Toon
{
	class StackAllocator : public NonCopyable
	{
	public:
		using size_type			= typename ::std::size_t;
		using marker			= typename ::std::size_t;
	public:
		StackAllocator( size_type size);
		~StackAllocator();

		void* allocate( size_type size );
		marker getMarker(void) const;
		void freeToMarker( marker mark );
		void clear(void);
	private:
		char		*beginPtr;
		char		*offsetPtr;
		char		*endPtr;
	};

	StackAllocator::StackAllocator( size_type size)
	{
		beginPtr	= (char*)malloc(size);
		offsetPtr	= beginPtr;
		endPtr		= beginPtr + size;
	}

	StackAllocator::~StackAllocator()
	{
		size_type numBytes = endPtr - beginPtr;
		free(beginPtr);
	}

	void * StackAllocator::allocate(size_type size)
	{
		if (offsetPtr + size > endPtr) return nullptr;
		
		void* allocated = offsetPtr;
		offsetPtr = offsetPtr + size;

		return allocated;
	}

	typename StackAllocator::marker StackAllocator::getMarker(void) const
	{
		marker mark = static_cast<marker>( offsetPtr - beginPtr );
		return mark;
	}

	void StackAllocator::freeToMarker(marker mark)
	{
		offsetPtr = beginPtr + mark;
	}

	void StackAllocator::clear(void)
	{
		offsetPtr = beginPtr;
	}
};

#include "ToonHeaderPostfix.h"

#endif // end of StackAllocator