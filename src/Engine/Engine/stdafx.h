#pragma once

#include "targetver.h"

// because of compatibility issue, declare below macro for using std::allocator instead of std::pmr::memory_resource
// if there are improvements on std::pmr compatibility issue, toon engine codes will be refactored.
#define _SILENCE_STDEXT_ALLOCATORS_DEPRECATION_WARNING


#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>

#ifdef _DEBUG
	#pragma comment(lib, "nvToolsExt64_1d.lib")
	#pragma comment(lib, "opengl32.lib")
	#pragma comment(lib, "glfx.lib")
	#pragma comment(lib, "glew32.lib")
	#pragma comment(lib, "glfw3.lib")
#else
	#pragma comment(lib, "glfx.lib")
	#pragma comment(lib, "opengl32.lib")
	#pragma comment(lib, "glfw3.lib")
	#pragma comment(lib, "glew32.lib")
#endif