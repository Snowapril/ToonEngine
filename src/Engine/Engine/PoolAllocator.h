#ifndef POOL_ALLOCATOR_H
#define POOL_ALLOCATOR_H

#include "ToonHeaderPrefix.h"
#include <allocators>
#include <memory>
#include "Noncopyable.h"
namespace Toon
{
	template < typename Type, std::size_t N, typename Allocator = std::allocator<Type> >
	class PoolAllocator : public NonCopyable
	{
	public:
		using allocator_type	= std::allocator_traits<Allocator>::allocator_type;
		using value_type		= std::allocator_traits<Allocator>::value_type;
		using pointer			= std::allocator_traits<Allocator>::pointer;
		using const_pointer		= std::allocator_traits<Allocator>::const_pointer;
		using difference_type	= std::allocator_traits<Allocator>::difference_type;
		using size_type			= std::allocator_traits<Allocator>::size_type;
	public:
		PoolAllocator();
		~PoolAllocator();
	private:
		Allocator alloc;
		// rbtree tree; this can be replaced by std::map or std::multimap
	};

	template < typename Type, std::size_t N, typename Allocator >
	PoolAllocator< Type, N, Allocator >::PoolAllocator()
	{

	}

	template < typename Type, std::size_t N, typename Allocator >
	PoolAllocator< Type, N, Allocator >::~PoolAllocator()
	{

	}
};

#include "ToonHeaderPostfix.h"
 
#endif // end of PoolAllocator