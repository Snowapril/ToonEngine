#include <iostream>
#include "INIParser.h"

using namespace ToonResourceParser;

int main(void)
{
	INIParser parser("ExampleResource/engine_config.ini");

	auto data = parser.getData<std::string>("Common.root_path");
	std::cout << data.value() << std::endl;

	auto width = parser.getData<int>("Rendersystem.client_width");
	std::cout << "width : " << width.value() << std::endl;

	auto height = parser.getData<int>("Rendersystem.client_height");
	std::cout << "height : " << height.value() << std::endl;

    return 0;
}