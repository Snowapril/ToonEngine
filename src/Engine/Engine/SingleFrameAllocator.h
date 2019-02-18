#ifndef SINGLE_FRAME_ALLOCATOR_H
#define SINGLE_FRAME_ALLOCATOR_H

#include "NonCopyable.h"
#include <type_traits>
#include <cstddef>

namespace Toon
{
	template < std::size_t Numbytes >
	class SingleFrameAllocator : public NonCopyable
	{
	public:
		using size_type	= typename std::size_t;
	public:
		SingleFrameAllocator() noexcept;
		~SingleFrameAllocator() noexcept;
		
		void* allocate( size_type size ) noexcept;
		void clear(void) noexcept;
	private:
		char* beginPtr;
		char* offsetPtr;
		char* endPtr;
	};

	template<std::size_t Numbytes>
	SingleFrameAllocator<Numbytes>::SingleFrameAllocator() noexcept
	{
		beginPtr	= (char*)malloc(Numbytes);
		offsetPtr	= beginPtr;
		endPtr		= beginPtr + Numbytes;
	}

	template<std::size_t Numbytes>
	SingleFrameAllocator<Numbytes>::~SingleFrameAllocator() noexcept
	{
		free(beginPtr);
	}

	template<std::size_t Numbytes>
	void * SingleFrameAllocator<Numbytes>::allocate(size_type size) noexcept
	{
		if (offsetPtr + size > endPtr) return nullptr;

		void* allocated = offsetPtr;
		offsetPtr = offsetPtr + size;

		return allocated;
	}

	template<std::size_t Numbytes>
	void SingleFrameAllocator<Numbytes>::clear(void) noexcept
	{
		offsetPtr = beginPtr;
	}
};


#endif // end of SINGLE_FRAME_ALLOCATOR_H