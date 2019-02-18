#include "stdafx.h"

//// For enabling optimus feature of laptops.
//extern "C"
//{
//	_declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
//}
#include "StackAllocator.h"
#include "DoubleBufferedAllocator.h"
#include "SingleFrameAllocator.h"
#include "DoubleEndedStackAllocator.h"
#include <iostream>
#include <list>
#include "PoolAllocator.h"

#include <vector>
class A
{
public:
	A(int a, int B)
		: v1(a), v2(B) {};

	void print(void) const
	{
		std::cout << v1 << ' ' << v2 << std::endl;
	}
	void _Construct(int a, int b)
	{
		v1 = a;
		v2 = b;
	}
public:
	int v1, v2;
};

int main(void)
{
	int* arr;


	Toon::StackAllocator alloc(100);
	auto mark = alloc.getMarker();
	arr = reinterpret_cast<int*>(alloc.allocate(64));
	
	for (int i = 0; i < 16; i++)
	{
		arr[i] = (i + 1) * (i + 1);
	}

	for (int i = 0; i < 16; i++)
	{
		std::cout << arr[i] << std::endl;
	}

	alloc.freeToMarker(mark);

	double* arr2 = reinterpret_cast<double*>(alloc.allocate(64));

	for (int i = 0; i < 8; i++)
	{
		arr2[i] = (i + 1) * (i + 1);
	}

	for (int i = 0; i < 16; i++)
	{
		std::cout << arr[i] << std::endl;
	}
	return 0;
}