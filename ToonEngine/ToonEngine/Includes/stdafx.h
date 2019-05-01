#pragma once

// because of compatibility issue, declare below macro for using std::allocator instead of std::pmr::memory_resource
// if there are improvements on std::pmr compatibility issue, toon engine codes will be refactored.
#define _SILENCE_STDEXT_ALLOCATORS_DEPRECATION_WARNING

#ifdef _DEBUG
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "opengl/glfx.lib")
#pragma comment(lib, "opengl/glew32.lib")
#pragma comment(lib, "opengl/glfw3.lib")
#pragma comment(lib, "fmt/fmtd.lib")
//#pragma comment(lib, "ToonRendersystem_GL3Plus.lib")
#else
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "opengl/glfx.lib")
#pragma comment(lib, "opengl/glew32.lib")
#pragma comment(lib, "opengl/glfw3.lib")
#pragma comment(lib, "fmt/fmt.lib")
#pragma comment(lib, "ToonRendersystem_GL3Plus.lib")
#endif