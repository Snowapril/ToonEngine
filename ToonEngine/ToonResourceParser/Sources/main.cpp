#include <iostream>
#include "constexpr/vector.h"

int main(void)
{
    constexpr ToonResourceParser::vector<int, 5> vec { 1, 2, 3 };

    return 0;
}