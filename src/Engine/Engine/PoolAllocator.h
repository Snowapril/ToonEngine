#ifndef POOL_ALLOCATOR_H
#define POOL_ALLOCATOR_H

#include "ToonHeaderPrefix.h"
#include <type_traits>
#include <memory>
#include "Noncopyable.h"
#include <list>
#include <cstdlib>

namespace Toon
{
	template < typename Type >
	class PoolAllocator : public NonCopyable
	{
	public:
		using size_type			= typename std::size_t;
		using address_type		= typename std::uintptr_t;
	public:
		PoolAllocator( size_type num, size_type alignment );
		~PoolAllocator();
		
		Type* allocate(void);
		template <typename... Args, typename = std::enable_if_t<std::is_constructible_v<Type, Args...>> >
		Type* allocate(Args&&... args);
		void deallocate(Type* node);

		void sortFreeList(void); // this help PoolAllocator to return contiguous nodes.

		bool empty(void) const
		{
			return freeList.empty();
		}
	private:
		std::list<Type*> freeList; // STL set is impledmented with red black tree. O(logN)
		char* beginPtr;
		char* endPtr;
	};

	template<typename Type>
	PoolAllocator<Type>::PoolAllocator(size_type num, size_type alignment)
	{
		size_type totalSize = sizeof(Type) * num + alignment;
		beginPtr = (char*)malloc(totalSize);
		endPtr = beginPtr + totalSize;

		size_type mask = alignment - 1U;
		size_type misalignment = mask & reinterpret_cast<address_type>(beginPtr);
		size_type adjustment = alignment - misalignment;

		Type* beginNode = reinterpret_cast<Type*>(beginPtr + adjustment);
		Type* endNode = reinterpret_cast<Type*>(beginNode + static_cast<size_type>((totalSize - adjustment) / sizeof(Type)));

		Type* currentNode = beginNode;
		while (currentNode != endNode)
		{
			freeList.push_back(&(*currentNode));
			++currentNode;
		}
	}

	template<typename Type>
	PoolAllocator<Type>::~PoolAllocator()
	{
		for (Type* node : freeList)
			node->~Type();
		freeList.clear();

		size_type size = static_cast<size_type>(endPtr - beginPtr);
		free(beginPtr);
	}

	template<typename Type>
	Type * PoolAllocator<Type>::allocate(void)
	{
		Type* retNode = freeList.pop_front();
		return retNode;
	}

	template<typename Type>
	void PoolAllocator<Type>::deallocate(Type * node)
	{
		node->~Type();
		freeList.push_back(node);
	}

	template<typename Type>
	void PoolAllocator<Type>::sortFreeList(void)
	{
		freeList.sort([](Type* arg1, Type* arg2) {
			return reinterpret_cast<address_type>(arg1) < reinterpret_cast<address_type>(arg2);
		});
	}

	template<typename Type>
	template<typename... Args, typename = std::enable_if_t<std::is_constructible_v<Type, Args...>> >
	Type * PoolAllocator<Type>::allocate(Args&&... args)
	{
		Type* freeNode = freeList.front();
		freeList.pop_front();

		Type *retNode = new (freeNode) Type(std::forward<Args>(args)...);

		return retNode;
	}

};

#include "ToonHeaderPostfix.h"
 
#endif // end of PoolAllocator