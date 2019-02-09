#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����
#include <windows.h>

// ignore trivial warning messages
#pragma warning(	   push		 )
#pragma warning( disable : 26451 )
#pragma warning( disable : 26495 )
#pragma warning( disable : 26498 )
#pragma warning( disable :  6387 )	
#pragma warning( disable : 26437 )

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

#pragma warning( pop )