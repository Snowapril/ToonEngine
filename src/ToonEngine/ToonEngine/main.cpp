#include "stdafx.h"
#include <iostream>
#include "ToonRoot.h"
#include "ToonLogger.h"
#include "ToonString.h"

int main(void)
{ 
	Toon::ToonRoot root;
	root.initialize();

	auto& logger = Toon::Logger::getConstInstance();
	logger.infoMessage("info message here");

	auto str = TOON_STRING("stack-overflow");
	logger.infoMessage("{}", str.toString());
	logger.infoMessage("{:x}", str.toHashKey());

	return 0;
}