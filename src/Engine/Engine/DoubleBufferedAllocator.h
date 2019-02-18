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
		DoubleBufferedAllocator();

		void* allocate(size_type numBytes);
		void  clearCurrentBuffer(void);
		void  swapBuffers(void);
	private:
		SingleFrameAllocator< Numbytes > buffer[2];
		int			curBufferIndex;
	};

	template<std::size_t Numbytes >
	DoubleBufferedAllocator<Numbytes>::DoubleBufferedAllocator()
		: curBufferIndex(0)
	{
	}

	template<std::size_t Numbytes>
	void * DoubleBufferedAllocator<Numbytes>::allocate(size_type size)
	{
		void* ptr = buffer[currentBufferIndex].allocate(size);
		return ptr;
	}

	template<std::size_t Numbytes>
	void DoubleBufferedAllocator<Numbytes>::clearCurrentBuffer(void)
	{
		buffer[currentBufferIndex].clear();
	}

	template<std::size_t Numbytes>
	void DoubleBufferedAllocator<Numbytes>::swapBuffers(void)
	{
		curBufferIndex = !curBufferIndex;
	}
};

#endif // end of DOUBLE_BUFFERED_ALLOCATOR_H