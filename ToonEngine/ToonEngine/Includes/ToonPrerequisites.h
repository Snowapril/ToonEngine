/**
 * @file ToonPrerequisites.h
 * @author snowapril (https://github.com/Snowapril)
 * @brief collection of class forward declarations for reducing compile time.
 * @version 0.1
 * @date 2019-05-25
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef _TOON_PREREQUISITES_H
#define _TOON_PREREQUISITES_H

#include <functional>

namespace Toon
{
	class Timer				;
	class Filesystem		;
	class Logger			;
	class RenderSystem		;
	class Bitwise			;
	class AlignedAllocator	;
	class SystemMessage		;
	class SystemMessageBus	;
	class InputSystem		;
	
	using SystemMessageListener = std::function<void(SystemMessage const &)>;
};

#endif // end of _TOON_PREREQUISITES_H