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

	using SystemMessageListener = std::function<void(SystemMessage const &)>;
};

#endif // end of _TOON_PREREQUISITES_H