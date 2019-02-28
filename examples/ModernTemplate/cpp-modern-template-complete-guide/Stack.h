#pragma once
#include <deque>
#include <cassert>
#include <type_traits>

template <typename Type, template <typename Elem, typename = std::allocator<Type>> typename Cont = std::deque >
class Stack
{
	friend class Stack;
private:
	Cont<Type> elems;
public:
	Stack();
	~Stack();

	template <typename T>
	void push(T&& elem) noexcept;

	void pop(void) noexcept;

	bool empty(void) const noexcept;

	Type const & top(void) const noexcept;

	template <typename Type2, template <typename Elem2, typename = std::allocator<Type2>> typename Cont2>
	Stack<Type, Cont> & operator=(Stack<Type2, Cont2> const &) noexcept;
};

template <typename Type, template <typename Elem, typename = std::allocator<Type>> typename Cont >
Stack<Type, Cont>::Stack()
{

}

template <typename Type, template <typename Elem, typename = std::allocator<Type>> typename Cont >
Stack<Type, Cont>::~Stack()
{

}

template <typename Type, template <typename Elem, typename = std::allocator<Type>> typename Cont >
template <typename T>
void Stack<Type, Cont>::push(T&& elem) noexcept
{
	elems.push_back(std::forward<Type>(elem));
}

template <typename Type, template <typename Elem, typename = std::allocator<Type>> typename Cont >
void Stack<Type, Cont>::pop(void) noexcept
{
	assert(!elems.empty());
	elems.pop_back();
}

template <typename Type, template <typename Elem, typename = std::allocator<Type>> typename Cont >
bool Stack<Type, Cont>::empty(void) const noexcept
{
	return elems.empty();
}

template <typename Type, template <typename Elem, typename = std::allocator<Type>> typename Cont >
Type const & Stack<Type, Cont>::top(void) const noexcept
{
	assert(!elems.empty());
	return elems.back();
}

template <typename Type, template <typename Elem, typename = std::allocator<Type>> typename Cont >
template <typename Type2, template <typename, typename = std::allocator<Type2>> typename Cont2>
Stack<Type, Cont> & Stack<Type, Cont>::operator=(Stack<Type2, Cont2> const & op2) noexcept
{
	elems.clear();
	elems.insert(elems.begin(), op2.elems.begin(), op2.elems.end());
	return *this;
}