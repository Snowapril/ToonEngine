#include "stdafx.h"

//// For enabling optimus feature of laptops.
//extern "C"
//{
//	_declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
//}
#include "StackAllocator.h"

int main(void)
{
	Toon::StackAllocator< 100 > alloc;
	int* a = alloc.allocate<int>(1);

	return 0;
}