#include <ToonEngine/ToonBitwise.h>
#include <iostream>

int main(void)
{
	auto a = Toon::Bitwise::setBitmask<unsigned int>(1, 3, 5);
	std::cout << std::hex << a << std::endl;
	return 0;
}