#include "stdafx.h"

// For enabling optimus feature of laptops.
extern "C"
{
	_declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
}