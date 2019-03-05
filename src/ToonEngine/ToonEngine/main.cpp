#include "stdafx.h"

//// For enabling optimus feature of laptops.
//extern "C"
//{
//	_declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
//}

#include <iostream>

template <typename... Bits>
void asserts(Bits... bits)
{
	if (!(bits && ...))
	{
		std::cout << "sdfafdsa" << std::endl;
	}
}

int main(void)
{ 
	asserts(true, true, true, true);
	

	return 0;
}