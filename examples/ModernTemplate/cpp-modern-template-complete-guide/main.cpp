#include <iostream>
#include <bitset>
#include <numeric>
#include "Stack.h"
#include <vector>
#include "MoveSemantics.h"

template<unsigned long N>
void printBitset(std::bitset<N> const & bs)
{
	std::cout << bs.template to_string<char, std::char_traits<char>, std::allocator<char>>();
}

template <typename Type>
constexpr bool isSigned = std::numeric_limits<Type>::is_signed;


int main(void)
{
	std::bitset<6> bs;
	bs.set(3);
	bs.set(5);

	printBitset(bs);
	std::cout << std::boolalpha << isSigned<unsigned int> << std::endl;

	Stack<int, std::vector> s;

	s.push(3);
	std::cout << s.top() << std::endl;

	Stack<float> s2;
	s2.push(3.01f); s2.push(-3.12f);

	s = s2;

	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	X x1;
	X const x2;

	g(x1);
	g(x2);
	g(X());

	return 0;
}