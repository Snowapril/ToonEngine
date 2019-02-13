#ifndef STACK_ALLOCATOR_H
#define STACK_ALLOCATOR_H

#include <allocators>
#include <memory>
#include "Singleton.h"
#include <type_traits>
#include <cassert>

template < std::size_t N, typename Allocator = std::allocator<char> >
class StackAllocator : public Singleton<StackAllocator>
{
public:
	using allocator_type = std::allocator_traits<Allocator>::allocator_type;
	using value_type = std::allocator_traits<Allocator>::value_type;
	using pointer = std::allocator_traits<Allocator>::pointer;
	using const_pointer = std::allocator_traits<Allocator>::const_pointer;
	using difference_type = std::allocator_traits<Allocator>::difference_type;
	using size_type = std::allocator_traits<Allocator>::size_type;
public:
	StackAllocator();

	template < typename Type, std::size_t AllocNum, typename... Args >
	Type* allocate(void);
	template < typename Type, std::size_t DestroyNum >
	void destroy(void);
private:
	Allocator	alloc;
	char		*beginPtr;
	char		*offsetPtr;
	char		*endPtr;
};

template < std::size_t N, typename Allocator >
StackAllocator< N, Allocator >::StackAllocator()
{
	beginPtr	= alloc.allocate(N, 0);
	offsetPtr	= beginPtr;
	endPtr		= beginPtr + N;
}

template < std::size_t N, typename Allocator >
template < typename Type, std::size_t AllocNum, typename... Args >
Type* StackAllocator< N, Allocator >::allocate(void)
{
	static_assert(N >= sizeof(Type) * AllocNum, "You are tyring to allocate objects as bigger size than pre-allocated");
	assert(static_cast<Type*>(offsetPtr) + AllocNum <= endPtr);
}

template < std::size_t N, typename Allocator >
template < typename Type, std::size_t DestroyNum >
void StackAllocator< N, Allocator >::destroy(void)
{
	static_assert(N >= sizeof(Type) * AllocNum, "You are tyring to destroy objects as bigger size than pre-allocated");

}

#endif // end of PoolAllocator