#ifndef STACK_ALLOCATOR_H
#define STACK_ALLOCATOR_H

#include "ToonHeaderPrefix.h"
#include "ToonNoncopyable.h"
#include <type_traits>
#include <cassert>
#include <stack>
#include <cstdlib>

namespace Toon
{
	class StackAllocator : public Noncopyable
	{
	public:
		using size_type			= typename ::std::size_t;
		using marker			= typename ::std::size_t;
	public:
		StackAllocator( size_type size) noexcept;
		~StackAllocator() noexcept;

		void* allocate( size_type size ) noexcept;
		marker getMarker(void) const noexcept;
		void freeToMarker( marker mark ) noexcept;
		void clear(void) noexcept;
	private:
		char		*beginPtr;
		char		*offsetPtr;
		char		*endPtr;
	};

	StackAllocator::StackAllocator( size_type size) noexcept
	{
		beginPtr	= (char*)malloc(size);
		offsetPtr	= beginPtr;
		endPtr		= beginPtr + size;
	}

	StackAllocator::~StackAllocator() noexcept
	{
		size_type numBytes = endPtr - beginPtr;
		free(beginPtr);
	}

	void * StackAllocator::allocate(size_type size) noexcept
	{
		if (offsetPtr + size > endPtr) return nullptr;
		
		void* allocated = offsetPtr;
		offsetPtr = offsetPtr + size;

		return allocated;
	}

	typename StackAllocator::marker StackAllocator::getMarker(void) const noexcept
	{
		marker mark = static_cast<marker>( offsetPtr - beginPtr );
		return mark;
	}

	void StackAllocator::freeToMarker(marker mark) noexcept
	{
		offsetPtr = beginPtr + mark;
	}

	void StackAllocator::clear(void) noexcept
	{
		offsetPtr = beginPtr;
	}
};

#include "ToonHeaderPostfix.h"

#endif // end of StackAllocator