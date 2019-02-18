#ifndef DOUBLE_ENDED_STACK_ALLOCATOR_H
#define DOUBLE_ENDED_STACK_ALLOCATOR_H

#include "NonCopyable.h"
#include <type_traits>
#include <stack>
#include <cstdlib>

namespace Toon
{
	class DoubleEndedStackAllocator : public NonCopyable
	{
	public:
		using size_type			= typename ::std::size_t;
		using marker			= typename ::std::size_t;
	public:
		DoubleEndedStackAllocator( size_type size) ;
		~DoubleEndedStackAllocator();

		void* allocateFront(size_type size);
		void* allocateBack(size_type size);
		marker getFrontMarker(void) const;
		marker getBackMarker(void) const;
		void freeToFrontMarker(marker mark);
		void freeToBackMarker(marker mark);
		void clear(void);
	private:
		char* beginPtr;
		char* frontOffsetPtr;
		char* backOffsetPtr;
		char* endPtr;
	};
	
	DoubleEndedStackAllocator::DoubleEndedStackAllocator( size_type size)
	{
		beginPtr		= (char*)malloc(size);
		frontOffsetPtr	= beginPtr;
		endPtr			= beginPtr + size;
		backOffsetPtr	= endPtr;
	}

	DoubleEndedStackAllocator::~DoubleEndedStackAllocator()
	{
		size_type size = endPtr - beginPtr;
		free(beginPtr);
	}

	void * DoubleEndedStackAllocator::allocateFront(size_type size)
	{
		char* offsetPtr = frontOffsetPtr + size;
		if (offsetPtr > backOffsetPtr) return nullptr;

		void* allocated = frontOffsetPtr;
		frontOffsetPtr = offsetPtr;

		return allocated;
	}

	void * DoubleEndedStackAllocator::allocateBack(size_type size)
	{
		char* offsetPtr = backOffsetPtr - size;
		if (offsetPtr < frontOffsetPtr) return nullptr;

		void* allocated = offsetPtr;
		backOffsetPtr = offsetPtr;

		return allocated;
	}

	typename DoubleEndedStackAllocator::marker DoubleEndedStackAllocator::getFrontMarker(void) const
	{
		marker mark = static_cast<marker>(frontOffsetPtr - beginPtr);
		return mark;
	}

	typename DoubleEndedStackAllocator::marker DoubleEndedStackAllocator::getBackMarker(void) const
	{
		marker mark = static_cast<marker>(endPtr - backOffsetPtr);
		return mark;
	}

	void DoubleEndedStackAllocator::freeToFrontMarker(marker mark)
	{
		frontOffsetPtr = beginPtr + mark;
	}

	void DoubleEndedStackAllocator::freeToBackMarker(marker mark)
	{
		backOffsetPtr = endPtr - mark;
	}

	void DoubleEndedStackAllocator::clear(void)
	{
		frontOffsetPtr	= beginPtr;
		backOffsetPtr	= endPtr;
	}

};

#endif