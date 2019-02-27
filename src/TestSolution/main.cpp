#include <iostream>

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
	return 0;
}