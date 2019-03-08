#include "stdafx.h"

//// For enabling optimus feature of laptops.
//extern "C"
//{
//	_declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
//}

#include <iostream>
#include "ToonRoot.h"
#include "ToonLogger.h"

int main(void)
{ 
	Toon::ToonRoot root;
	root.initialize();

	auto& logger = Toon::Logger::getConstInstance();
	logger.infoMessage("info message here");

	return 0;
}