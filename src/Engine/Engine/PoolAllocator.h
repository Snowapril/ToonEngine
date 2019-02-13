#ifndef POOL_ALLOCATOR_H
#define POOL_ALLOCATOR_H

#include <allocators>
#include <memory>
#include "Singleton.h"

template < typename Type, std::size_t N, typename Allocator = std::allocator<Type> >
class PoolAllocator : public Singleton<PoolAllocator>
{
public:
	using allocator_type	= std::allocator_traits<Allocator>::allocator_type	;
	using value_type		= std::allocator_traits<Allocator>::value_type		;
	using pointer			= std::allocator_traits<Allocator>::pointer			;
	using const_pointer		= std::allocator_traits<Allocator>::const_pointer	;
	using difference_type	= std::allocator_traits<Allocator>::difference_type	;
	using size_type			= std::allocator_traits<Allocator>::size_type		;
public:
	PoolAllocator();
private:
	Allocator alloc;

};

template < typename Type, std::size_t N, typename Allocator >
PoolAllocator<Type, N, Allocator>::PoolAllocator()
{

}

#endif // end of PoolAllocator