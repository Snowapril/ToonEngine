#include "stdafx.h"
#include "ToonRoot.h"
#include "ToonObfuscator.h"

int main(void)
{ 
	Toon::ToonRoot root;

	if (!root.initialize(true, OBFUSCATE("ToonEngine"), OBFUSCATE("../Resources/engine_config.ini")))
	{
		return -1;
	}

	int exitCode = root.runMainLoop();
	return exitCode;
}