#ifndef UTILITY_H
#define UTILITY_H

namespace ToonResourceParser
{
	template <typename Type1, typename Type2>
	class Pair
	{
	public:
		using FirstType  = typename Type1;
		using SecondType = typename Type2;

		template <typename _Ty1, typename _Ty2>
		constexpr Pair(_Ty1&& first, _Ty2&& second) : first(std::forward<_Ty1>(first)), second(std::forward<_Ty2>(second)) noexcept {};

		FirstType  first;
		SecondType second;
	};
};

#endif