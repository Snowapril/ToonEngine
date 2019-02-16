#ifndef STACK_ALLOCATOR_H
#define STACK_ALLOCATOR_H

#include "ToonHeaderPrefix.h"
#include <allocators>
#include <memory>
#include "Noncopyable.h"
#include <type_traits>
#include <cassert>

namespace Toon
{
	template < std::size_t N, typename Allocator = std::allocator<char> >
	class StackAllocator : public NonCopyable
	{
	public:
		using allocator_type	= typename std::allocator_traits<Allocator>::allocator_type;
		using value_type		= typename std::allocator_traits<Allocator>::value_type;
		using pointer			= typename std::allocator_traits<Allocator>::pointer;
		using const_pointer		= typename std::allocator_traits<Allocator>::const_pointer;
		using difference_type	= typename std::allocator_traits<Allocator>::difference_type;
		using size_type			= typename std::allocator_traits<Allocator>::size_type;
		using allocator_impl    = typename std::allocator_traits<Allocator>;
	public:
		StackAllocator();

		template < typename Type, typename... Args >
		Type* allocate( Args&&... args );
		template < typename Type >
		void destroy(void);
	private:
		std::allocator_traits<Allocator> alloc;
		char		*beginPtr;
		char		*offsetPtr;
		char		*endPtr;
	};

	template < std::size_t N, typename Allocator >
	StackAllocator< N, Allocator >::StackAllocator()
	{
		beginPtr	= alloc.allocate(N, 0);
		offsetPtr	= beginPtr;
		endPtr		= beginPtr + N;]
		
	}

	template < std::size_t N, typename Allocator >
	template < typename Type, typename... Args >
	Type* StackAllocator< N, Allocator >::allocate( Args&&... args )
	{
		if ( offsetPtr == endPtr ) return nullptr;

		Type* instance = static_cast<Type*>(offsetPtr);
		alloc.construct( instance, std::forward(Args)... );
		offsetPtr = offsetPtr + sizeof(Type);

		return instance;
	}

	template < std::size_t N, typename Allocator >
	template < typename Type >
	void StackAllocator< N, Allocator >::destroy(void)
	{
		if ( offsetPtr == beginPtr ) return;

		offsetPtr = offsetPtr - sizeof(Type);
		Type* instance = static_cast<Type*>(offsetPtr);
		alloc.destroy(instance);
	}
};

#include "ToonHeaderPostfix.h"

#endif // end of PoolAllocator