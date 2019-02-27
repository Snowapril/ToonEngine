#ifndef DOUBLE_BUFFERED_ALLOCATOR_H
#define DOUBLE_BUFFERED_ALLOCATOR_H

#include "ToonNoncopyable.h"
#include <type_traits>
#include <cstddef>

namespace Toon
{
	/****************************************************************************
				SingleFrameAllocator class declaration
	****************************************************************************/
	template < ::std::size_t Numbytes, typename = typename ::std::enable_if_t<(Numbytes != 0)> >
	class SingleFrameAllocator;

	template < ::std::size_t Numbytes >
	class SingleFrameAllocator<Numbytes> : public Noncopyable
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

	/****************************************************************************
					SingleFrameAllocator class methods definition
	****************************************************************************/
	template<::std::size_t Numbytes>
	SingleFrameAllocator<Numbytes>::SingleFrameAllocator() noexcept
	{
		beginPtr	= (char*)malloc(Numbytes);
		offsetPtr	= beginPtr;
		endPtr		= beginPtr + Numbytes;
	}

	template<::std::size_t Numbytes>
	SingleFrameAllocator<Numbytes>::~SingleFrameAllocator() noexcept
	{
		free(beginPtr);
	}

	template<::std::size_t Numbytes>
	void * SingleFrameAllocator<Numbytes>::allocate(size_type size) noexcept
	{
		if (offsetPtr + size > endPtr) return nullptr;

		void* allocated = offsetPtr;
		offsetPtr = offsetPtr + size;

		return allocated;
	}

	template<::std::size_t Numbytes>
	void SingleFrameAllocator<Numbytes>::clear(void) noexcept
	{
		offsetPtr = beginPtr;
	}

	/****************************************************************************
				DoubleFrameAllocator class declaration
	****************************************************************************/
	template < ::std::size_t Numbytes, typename = typename ::std::enable_if_t<(Numbytes != 0)> >
	class DoubleBufferedAllocator;

	template < ::std::size_t Numbytes >
	class DoubleBufferedAllocator<Numbytes> : public Noncopyable
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

	/****************************************************************************
					DoubleFrameAllocator class methods definition
	****************************************************************************/
	template<std::size_t Numbytes >
	DoubleBufferedAllocator<Numbytes>::DoubleBufferedAllocator() noexcept
		: curBufferIndex(0)
	{
	}

	template<std::size_t Numbytes>
	void * DoubleBufferedAllocator<Numbytes>::allocate(size_type size) noexcept
	{
		void* ptr = buffer[curBufferIndex].allocate(size);
		return ptr;
	}

	template<std::size_t Numbytes>
	void DoubleBufferedAllocator<Numbytes>::clearCurrentBuffer(void) noexcept
	{
		buffer[curBufferIndex].clear();
	}

	template<std::size_t Numbytes>
	void DoubleBufferedAllocator<Numbytes>::swapBuffers(void) noexcept
	{
		curBufferIndex = !curBufferIndex;
	}
};

#endif // end of DOUBLE_BUFFERED_ALLOCATOR_H