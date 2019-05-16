#include <type_traits>
#include <iostream>

template < typename RetType, typename... Bits, typename = typename std::enable_if_t< std::is_integral_v<RetType>> >
static auto inline setBitmask(Bits... bits) -> std::decay_t<RetType>
{
	RetType mask = ((1 << bits) | ...);
	return mask;
}

int main(void)
{
	unsigned int mask = setBitmask<unsigned int>(0, 3, 7, 9);
	std::cout << std::hex << mask << std::endl;
	return 0;
}