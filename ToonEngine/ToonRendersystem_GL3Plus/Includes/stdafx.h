// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 특정 포함 파일이 들어 있는
// 포함 파일입니다.
//

#pragma once

#ifdef _DEBUG
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "opengl/glfx.lib")
#pragma comment(lib, "opengl/glew32.lib")
#pragma comment(lib, "opengl/glfw3.lib")
#pragma comment(lib, "fmt/fmtd.lib")
#pragma comment(lib, "nvidia/nvToolsExt64_1.lib")
#else
#pragma comment(lib, "opengl/glfx.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "opengl/glfw3.lib")
#pragma comment(lib, "opengl/glew32.lib")
#pragma comment(lib, "fmt/fmt.lib")
#endif