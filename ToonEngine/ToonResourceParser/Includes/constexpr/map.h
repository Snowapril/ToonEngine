#ifndef MAP_H
#define MAP_H

#include <array>
#include "Utility.h"

namespace ToonResourceParser 
{
	template <typename Key, typename Value, std::size_t Size>
	class Map
	{
	public:
		using storage_t  = std::array<Pair<Key, Value>, Size>;
		using size_type  = std::size_t;
		using key_type   = typename Key;
		using value_type = typename Value;

		constexpr Map() = default;
	public:
		constexpr Value& operator[](Key const&) noexcept;
		constexpr Value const& operator[](Key const&) const noexcept;

		constexpr auto begin(void) noexcept;
		constexpr auto end(void) noexcept;

		constexpr auto find(key_type const&) const noexcept;
	private:
		storage_t storage{};
		size_type numElements{ 0 };
	};

	template <typename Key, typename Value, std::size_t Size>
	constexpr Value& Map<Key, Value, Size>::operator[](key_type const& key) noexcept
	{
		auto iter = find(key);
		auto end_iter = end();

		static_assert(iter != end_iter);

		return iter->second;
	}
	template <typename Key, typename Value, std::size_t Size>
	constexpr Value const& Map<Key, Value, Size>::operator[](key_type const& key) const noexcept
	{
		auto iter = find(key);
		auto end_iter = end();

		static_assert(iter != end_iter);

		return iter->second;
	}
	template <typename Key, typename Value, std::size_t Size>
	constexpr auto Map<Key, Value, Size>::begin(void) noexcept
	{
		return begin(storage);
	}
	template <typename Key, typename Value, std::size_t Size>
	constexpr auto Map<Key, Value, Size>::end(void) noexcept
	{
		return begin(storage) + numElements;
	}

	template <typename Key, typename Value, std::size_t Size>
	constexpr auto Map<Key, Value, Size>::find(key_type const& key) const noexcept
	{
		for (auto iter = begin(); iter != end(); ++iter)
		{
			if (p.first == key) return p;
		}

		return end();
	}
};

#endif