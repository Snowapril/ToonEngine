#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <type_traits>
#include <array>

namespace ToonResourceParser 
{
    template < typename Type, std::size_t Size >
    class vector
    {
    private:
        using storage_t = std::array<Type, Size>;
        using size_type = std::size_t;

        storage_t storage;
        size_type numElements = 0;
    public:
        constexpr vector() noexcept;
		template < typename... T, typename Enable  = typename std::enable_if_t< std::is_same_v< Type, T >>,
								  typename Enable2 = typename std::enable_if_t< (sizeof...(T) <= Size) >  >
		constexpr vector(T&&...) noexcept;

        template < typename T, typename Enable = typename std::enable_if_t< std::is_same_v< Type, T >> >
        constexpr void push_back(T&&) noexcept;
        constexpr void pop_back(void) noexcept;
        template < typename... T, typename Enable = typename std::enable_if_t< std::is_constructible_v< Type, T >> >
        constexpr void emplace_back(T&&...) noexcept;
        constexpr Type const & front(void) const noexcept;
        constexpr size_type size(void) const noexcept;
        constexpr bool empty(void) const noexcept;
        constexpr auto begin(void) const noexcept;
        constexpr auto end(void) const noexcept;
    };

	template < typename Type, std::size_t Size >
	constexpr vector< Type, Size >::vector() noexcept
		: storage{}, numElements(0)
	{
	}
	template < typename Type, std::size_t Size >
	template < typename... T, typename Enable, typename Enable2>
	constexpr vector< Type, Size >::vector(T&&... args) noexcept
		: storage{ std::forward<Type>(args)... }, numElements(sizeof...(args))
	{	
	}
    template < typename Type, std::size_t Size >
    template < typename T, typename Enable >
    constexpr void vector< Type, Size >::push_back(T&& arg) noexcept 
    {
        storage[numElements++] = std::forward< T >(arg);
    }

    template < typename Type, std::size_t Size >
    constexpr void vector< Type, Size >::pop_back(void) noexcept
    {
        --numElements;
    }

    template < typename Type, std::size_t Size >
    template < typename... T, typename Enable >
    constexpr void vector< Type, Size >::emplace_back(T&&... args) noexcept
    {
        storage[numElements++] = Type( std::forward<T>(args)... );
    }

    template < typename Type, std::size_t Size >
    constexpr Type const & vector< Type, Size >::front(void) const noexcept
    {
        return storage[numElements - 1];
    }

    template < typename Type, std::size_t Size >
    constexpr typename vector<Type, Size>::size_type vector<Type, Size>::size(void) const noexcept
    {
        return numElements;
    }
    template < typename Type, std::size_t Size >
    constexpr bool vector<Type, Size>::empty(void) const noexcept
    {
        return numElements == 0;
    }
    template < typename Type, std::size_t Size >
    constexpr auto vector<Type, Size>::begin(void) const noexcept
    {
        return begin(storage);
    }
    template < typename Type, std::size_t Size >
    constexpr auto vector<Type, Size>::end(void) const noexcept
    {
        return begin(storage) + numElements;
    }
};

#endif