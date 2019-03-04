#include <iostream>
#include "../ToonEngine/ToonEngine/ToonCRC32Hash.h"
using namespace std;


class A
{
public:
	virtual void test(void) { std::cout << "A test" << std::endl; }
public:
	A() { std::cout << "A constructor" << std::endl; }
	~A() { std::cout << "A destructor" << std::endl; }
};

class B : public A
{
public:
	void test(void) { std::cout << "B test" << std::endl; }
public:
	B() { std::cout << "B constructor" << std::endl; }
	~B() { std::cout << "B destructor" << std::endl; }
};

int main(void)
{
	B b;
	b.test();

	cout << sizeof("asfadsf") << endl;
	cout << hex << CRC32_HASH_CONSTEXPR("stack-overflow") << endl;
	cout << hex << CRC32_HASH_RUNTIME("stack-overflow") << endl;
	return 0;
}