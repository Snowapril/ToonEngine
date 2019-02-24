#ifndef DOUBLE_ENDED_STACK_ALLOCATOR_H
#define DOUBLE_ENDED_STACK_ALLOCATOR_H

#include "ToonNoncopyable.h"
#include <type_traits>
#include <stack>
#include <cstdlib>

namespace Toon
{
	class DoubleEndedStackAllocator : public ToonNoncopyable
	{
	public:
		using size_type			= typename ::std::size_t;
		using marker			= typename ::std::size_t;
	public:
		DoubleEndedStackAllocator (size_type size)  noexcept;
		~DoubleEndedStackAllocator()				noexcept;

		void*	allocateFront		(size_type size) noexcept;
		void*	allocateBack		(size_type size) noexcept;
		marker	getFrontMarker		(void)			 const noexcept;
		marker	getBackMarker		(void)			 const noexcept;
		void	freeToFrontMarker	(marker mark)	 noexcept;
		void	freeToBackMarker	(marker mark)	 noexcept;
		void	clear				(void)			 noexcept;
	private:
		char* beginPtr;
		char* frontOffsetPtr;
		char* backOffsetPtr;
		char* endPtr;
	};
	
	DoubleEndedStackAllocator::DoubleEndedStackAllocator( size_type size) noexcept
	{
		beginPtr		= (char*)malloc(size);
		frontOffsetPtr	= beginPtr;
		endPtr			= beginPtr + size;
		backOffsetPtr	= endPtr;
	}

	DoubleEndedStackAllocator::~DoubleEndedStackAllocator() noexcept
	{
		size_type size = endPtr - beginPtr;
		free(beginPtr);
	}

	void * DoubleEndedStackAllocator::allocateFront(size_type size) noexcept
	{
		char* offsetPtr = frontOffsetPtr + size;
		if (offsetPtr > backOffsetPtr) return nullptr;

		void* allocated = frontOffsetPtr;
		frontOffsetPtr = offsetPtr;

		return allocated;
	}

	void * DoubleEndedStackAllocator::allocateBack(size_type size) noexcept
	{
		char* offsetPtr = backOffsetPtr - size;
		if (offsetPtr < frontOffsetPtr) return nullptr;

		void* allocated = offsetPtr;
		backOffsetPtr = offsetPtr;

		return allocated;
	}

	typename DoubleEndedStackAllocator::marker DoubleEndedStackAllocator::getFrontMarker(void) const noexcept
	{
		marker mark = static_cast<marker>(frontOffsetPtr - beginPtr);
		return mark;
	}

	typename DoubleEndedStackAllocator::marker DoubleEndedStackAllocator::getBackMarker(void) const noexcept
	{
		marker mark = static_cast<marker>(endPtr - backOffsetPtr);
		return mark;
	}

	void DoubleEndedStackAllocator::freeToFrontMarker(marker mark) noexcept
	{
		frontOffsetPtr = beginPtr + mark;
	}

	void DoubleEndedStackAllocator::freeToBackMarker(marker mark) noexcept
	{
		backOffsetPtr = endPtr - mark;
	}

	void DoubleEndedStackAllocator::clear(void) noexcept
	{
		frontOffsetPtr	= beginPtr;
		backOffsetPtr	= endPtr;
	}

};

#endif