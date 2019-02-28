#pragma once
#include <type_traits>
#include <iostream>

class X
{ };

template <typename G>
void f(G& g) { std::cout << "f() for variable" << std::endl; }

template <typename G>
void f(G const & g) { std::cout << "f() for constant" << std::endl; }

template <typename G>
void f(G&& g) { std::cout << "f() for movable object" << std::endl; }

template <typename T>
void g(T&& t) { f(std::forward<T>(t)); }