#ifndef DOUBLE_BUFFERED_ALLOCATOR_H
#define DOUBLE_BUFFERED_ALLOCATOR_H

#include "NonCopyable.h"
#include "SingleFrameAllocator.h"
#include <type_traits>
#include <cstddef>

namespace Toon
{
	template < std::size_t Numbytes >
	class DoubleBufferedAllocator : public NonCopyable
	{
	public:
		using size_type			= typename std::size_t;
	public:
		DoubleBufferedAllocator() noexcept;

		void* allocate(size_type numBytes) noexcept;
		void  clearCurrentBuffer(void) noexcept;
		void  swapBuffers(void) noexcept;
	private:
		SingleFrameAllocator< Numbytes > buffer[2];
		int			curBufferIndex;
	};

	template<std::size_t Numbytes >
	DoubleBufferedAllocator<Numbytes>::DoubleBufferedAllocator() noexcept
		: curBufferIndex(0)
	{
	}

	template<std::size_t Numbytes>
	void * DoubleBufferedAllocator<Numbytes>::allocate(size_type size) noexcept
	{
		void* ptr = buffer[currentBufferIndex].allocate(size);
		return ptr;
	}

	template<std::size_t Numbytes>
	void DoubleBufferedAllocator<Numbytes>::clearCurrentBuffer(void) noexcept
	{
		buffer[currentBufferIndex].clear();
	}

	template<std::size_t Numbytes>
	void DoubleBufferedAllocator<Numbytes>::swapBuffers(void) noexcept
	{
		curBufferIndex = !curBufferIndex;
	}
};

#endif // end of DOUBLE_BUFFERED_ALLOCATOR_H