#pragma once

#include "targetver.h"



// because of compatibility issue, declare below macro for using std::allocator instead of std::pmr::memory_resource
// if there are improvements on std::pmr compatibility issue, toon engine codes will be refactored.
#define _SILENCE_STDEXT_ALLOCATORS_DEPRECATION_WARNING


#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����
#include <windows.h>