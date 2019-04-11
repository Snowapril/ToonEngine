#include <iostream>
#include "INIParser.h"

using namespace ToonResourceParser;

int main(void)
{
	INIParser parser("engine_config.ini");

	auto data = parser.getData<std::string>("Common.root_path");

    return 0;
}